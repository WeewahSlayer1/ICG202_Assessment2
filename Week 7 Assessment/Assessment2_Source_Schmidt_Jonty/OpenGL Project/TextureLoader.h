#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

#include "stb_image.h"

using namespace std;

// Returns texture ID from graphics card
unsigned int LoadTexture(const char* filename, int RGBType);