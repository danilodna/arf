CXX = g++
CXXFLAGS = -std=c++11
CFLAGS = -O2 -Wall -pthread -std=c++11

EXECDIR = bin/x64_release/
OBJDIR = bin/intermediate/
SRCDIR = src/
INCDIR = include/
DEPDIR = dependencies/

EXEC = oglTestingTool
TARGET = $(EXECDIR)$(EXEC)

SRC = $(addprefix $(SRCDIR), Main.cpp Renderer.cpp ResourceManager.cpp Window.cpp Collision.cpp InputHandler.cpp Texture.cpp Shader.cpp)
INC = $(addprefix $(INCDIR), Renderer.h ResourceManager.h Window.h Collision.h InputHandler.h Texture.h Shader.h)
OBJ = $(addprefix $(OBJDIR), Main.o Renderer.o ResourceManager.o Window.o Collision.o InputHandler.o Texture.o Shader.o)
LIBS = -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama -lXi -lXcursor -lXrender -lGL -lm -ldl -ldrm \
			-lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lX11 -lxcb -lXau -lXdmcp
DEP = $(addprefix $(DEPDIR), glad/glad.c stb/stb_image.cpp) \
			$(addprefix $(DEPDIR)imgui/, imgui_impl_glfw_gl3.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp)

###################################

all: $(TARGET)

$(EXECDIR)$(EXEC): $(OBJ) $(DEP)
	$(CXX) $^ -o $@ $(CFLAGS) $(LIBS)

$(OBJDIR)Main.o: $(SRCDIR)Main.cpp
	$(CXX) -c $^ -o $@ $(CFLAGS)

$(OBJDIR)Renderer.o: $(SRCDIR)Renderer.cpp $(INCDIR)Renderer.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)ResourceManager.o: $(SRCDIR)ResourceManager.cpp $(INCDIR)ResourceManager.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Window.o: $(SRCDIR)Window.cpp $(INCDIR)Window.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Collision.o: $(SRCDIR)Collision.cpp $(INCDIR)Collision.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)InputHandler.o: $(SRCDIR)InputHandler.cpp $(INCDIR)InputHandler.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Texture.o: $(SRCDIR)Texture.cpp $(INCDIR)Texture.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Shader.o: $(SRCDIR)Shader.cpp $(INCDIR)Shader.h
	$(CXX) -c $< -o $@ $(CFLAGS)

####################################

.PHONY:
clean:
	rm -rf $(EXEC) $(OBJDIR)*
