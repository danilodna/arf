CXX = g++
CXXFLAGS = -std=c++1y
CFLAGS = -O2 -Wall -pthread -std=c++1y

EXECDIR = bin/x64_release/
OBJDIR = bin/intermediate/
SRCDIR = src/
INCDIR = include/
DEPDIR = dependencies/
TESTDIR = tests/

EXEC = oglTestingTool
TARGET = $(EXECDIR)$(EXEC)

# Change here the compilation unit with the main function 
MAIN = AppTeste

SRC  = $(addprefix $(SRCDIR), $(MAIN).cpp Renderer.cpp ResourceManager.cpp Camera.cpp \
		 Window.cpp Collision.cpp InputHandler.cpp Texture.cpp Shader.cpp) 
TEST = $(addsufix .cpp, $(addprefix $(TESTDIR), TestMenu TestClearColor))
INC  = $(addprefix $(INCDIR), Renderer.h ResourceManager.h Camera.h Window.h Collision.h \
		InputHandler.h Texture.h Shader.h Mesh.hpp Vertex.hpp)
OBJ  = $(addprefix $(OBJDIR), $(MAIN).o Renderer.o ResourceManager.o Camera.o \
		Window.o Collision.o InputHandler.o Texture.o Shader.o \
		TestMenu.o TestClearColor.o)
LIBS = -lglfw3 -lrt -lm -ldl -lXrandr -lXinerama -lXi -lXcursor -lXrender -lGL -lm -ldl -ldrm \
			-lXdamage -lXfixes -lX11-xcb -lxcb-glx -lxcb-dri2 -lXxf86vm -lXext -lX11 -lxcb -lXau -lXdmcp
DEP = $(addprefix $(DEPDIR), glad/glad.c stb/stb_image.cpp) \
			$(addprefix $(DEPDIR)imgui/, imgui_impl_glfw_gl3.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp)

###################################

all: $(TARGET)

$(EXECDIR)$(EXEC): $(OBJ) $(DEP) $(TEST)
	$(CXX) $^ -o $@ $(CFLAGS) $(LIBS)

$(OBJDIR)$(MAIN).o: $(SRCDIR)$(MAIN).cpp $(INC)
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)TestMenu.o: $(TESTDIR)TestMenu.cpp $(TESTDIR)Test.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)TestClearColor.o: $(TESTDIR)TestClearColor.cpp $(TESTDIR)TestClearColor.hpp
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Renderer.o: $(SRCDIR)Renderer.cpp $(INCDIR)Renderer.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)ResourceManager.o: $(SRCDIR)ResourceManager.cpp $(INCDIR)ResourceManager.h
	$(CXX) -c $< -o $@ $(CFLAGS)

$(OBJDIR)Camera.o: $(SRCDIR)Camera.cpp $(INCDIR)Camera.h
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

.PHONY: clean run
clean:
	rm -rf $(EXEC) $(OBJDIR)*

run:
	./$(TARGET)
