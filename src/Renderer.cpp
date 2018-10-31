#include "../include/Renderer.h"

#include <iostream>
#include <memory>

void Renderer::buildMesh(Mesh &mesh)
{
	// Use shader binded to this mesh
	mesh.getShader().use();

	// Create and bound the Array Object
	GLuint VAO, VBO[1];
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO); // === Like glBegin() === //

	// Create and bound the Buffer Object
	glGenBuffers(1, VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);

	// "Send" the data to the GPU
	// glBufferData(GL_ARRAY_BUFFER, mesh.getDrawCount() * sizeof(mesh.getVertexList()[0]),
				//  &(mesh.getVertexList()[0]), mesh.getUsage());
	glBufferData(GL_ARRAY_BUFFER, mesh.getVertexList().size() * sizeof(mesh.getVertexList()[0]),
				 &(mesh.getVertexList()[0]), mesh.getUsage());

	// Set VAO and VBO
	mesh.setVAO(VAO);
	mesh.setVBO(VBO, 1);

	// Telling to OpenGL how to manipulate the data in GPU
	// for (unsigned int i = 0; i < mesh.getNumAttr(); ++i)
	// {
	// 	// Enable or disable a generic vertex attribute array
	// 	glEnableVertexAttribArray(i);

	// 	// Define an array of generic vertex attribute data
	// 	glVertexAttribPointer(i,
	// 						  mesh.getSizeAttr(),
	// 						  GL_FLOAT,
	// 						  GL_FALSE,
	// 						  mesh.getNumAttr() * mesh.getSizeAttr() * sizeof(GLfloat),
	// 						  (void *)(i * mesh.getSizeAttr() * sizeof(GLfloat)));
	// }
	
	
	for (unsigned int i = 0; i < mesh.getLayout().size(); ++i)
	{
		auto layout = mesh.getLayout()[i];

		// Enable or disable a generic vertex attribute array
		glEnableVertexAttribArray(i);

		// Offset to define where that attrib begins in the buffer
		intptr_t offset = 0;

		// Define an array of generic vertex attribute data
		glVertexAttribPointer(i,
							  layout.m_count,
							  layout.m_type,
							  layout.m_normalized,
							  mesh.getStride(),
							  (void *)(i * layout.m_count * sizeof(layout.m_type)));
	}

	// for (unsigned int i = 0; i < mesh.getLayout().size(); ++i)
	// {
	// 	const auto& layout = mesh.getLayout()[i];

	// 	// Enable or disable a generic vertex attribute array
	// 	glEnableVertexAttribArray(i);

	// 	// Offset to define where that attrib begins in the buffer
	// 	intptr_t offset = 0;

	// 	// Define an array of generic vertex attribute data
	// 	glVertexAttribPointer(i,
	// 						  layout.m_count,
	// 						  layout.m_type,
	// 						  layout.m_normalized,
	// 						  mesh.getStride(),
	// 						  (void *) offset);

	// 	offset += layout.m_count * sizeof(layout.m_type);
	// }

	glBindVertexArray(0); // ===	Like glEnd() === //
}

void Renderer::draw(Object &obj, const Mesh &mesh, Texture texture, GLenum mode)
{
	// Make the shader active and set the model matrix
	mesh.getShader().use().setMatrix4("model", obj.getModelMatrix());

	// Set slot of the active texture
	mesh.getShader().setInteger("uTexture", 0);

	// Bind the texture
	texture.bind();

	// Bind the VAO of this mesh
	glBindVertexArray(mesh.getVAO());
	glDrawArrays(mode, 0, mesh.getDrawCount());
	glBindVertexArray(0);
}

void Renderer::draw(Object &obj, const Mesh &mesh, GLenum mode)
{
	// Make the shader active
	mesh.getShader().use().setMatrix4("model", obj.getModelMatrix());

	// Bind the VAO of this mesh
	glBindVertexArray(mesh.getVAO());
	glDrawArrays(mode, 0, mesh.getDrawCount());
	glBindVertexArray(0);
}

void Renderer::draw(const Mesh &mesh, GLenum mode)
{
	// Make the shader active
	mesh.getShader().use();

	// Bind the VAO of this mesh
	glBindVertexArray(mesh.getVAO());
	glDrawArrays(mode, 0, mesh.getDrawCount());
	glBindVertexArray(0);
}

// m_mesh.getShader().setMatrix4("model", model);

// Render textured quad
// m_shader.setVector3f("objectColor", glm::vec3(0.0f, 1.0f, 0.0f));

// glActiveTexture(GL_TEXTURE0);
// texture.bind();

// void Mesh::drawElements(GLenum mode)
// {
// 	glBindVertexArray(m_VertexArrayObject);

// 	glDrawElements(mode, m_IndicesCount, GL_UNSIGNED_INT, 0);

// 	glBindVertexArray(0);
// }