include CommonDefs.mak

BIN_DIR = bin

INC_DIRS = $(OPENNI2_INCLUDE) $(NITE2_INCLUDE) \

SRCDIR = src/
DEPDIR = dependencies/
OBJDIR = bin/intermediate/

# MAIN = Main.cpp

EXEC = oglTestingTool
TARGET = $(EXECDIR)$(EXEC)

SRC_FILES = $(addprefix $(SRCDIR), vTest.cpp Renderer.cpp ResourceManager.cpp \
		 		Window.cpp DetectCollision.cpp InputHandler.cpp Texture.cpp Shader.cpp \
				Object.cpp Kinect.cpp Skeleton.cpp ) $(DEP)

DEP = $(addprefix $(DEPDIR), glad/glad.c stb/stb_image.cpp) \
		$(addprefix $(DEPDIR)imgui/, imgui_impl_glfw_gl3.cpp imgui.cpp imgui_demo.cpp imgui_draw.cpp)

ifeq ("$(OSTYPE)","Darwin")
	CFLAGS += -DMACOS
	LDFLAGS += -framework OpenGL
else
	CFLAGS += -DUNIX -DGLX_GLXEXT_LEGACY
	USED_LIBS += glfw3 rt m dl Xrandr Xinerama Xi Xcursor Xrender GL m pthread dl drm Xdamage Xfixes X11-xcb xcb-glx xcb-dri2 Xxf86vm Xext X11 pthread xcb Xau Xdmcp
endif

LIB_DIRS += $(OPENNI2_REDIST) $(NITE2_REDIST64) \

USED_LIBS += OpenNI2 NiTE2

EXE_NAME = Prototype

CFLAGS += -pthread -std=c++11

include CommonCppMakefile

.PHONY: run 

run:
	$(BIN_DIR)/x64-Release/$(EXE_NAME)
