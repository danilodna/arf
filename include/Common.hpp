#ifndef COMMON_HPP_
#define COMMON_HPP_

// C Libs
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <pthread.h>

// C++ Libs
#include <algorithm>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

//	OpenGL/Window Lib
#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_glfw_gl3.h"
#include "../dependencies/glad/glad.h"
#include <GLFW/glfw3.h>

//	Some mathematical functions lib
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// 	Library to load textures
#include "../dependencies/stb/stb_image.h"

#define KINECT_RESOLUTION_WIDTH 640
#define KINECT_RESOLUTION_HEIGHT 480

#endif // COMMON_HPP_