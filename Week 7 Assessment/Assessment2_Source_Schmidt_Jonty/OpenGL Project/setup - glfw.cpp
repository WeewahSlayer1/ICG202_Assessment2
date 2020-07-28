#include "setup - glfw.h"
#include <iostream>

GLFWwindow* SetupGLFWwindow()
{
	glfwInit();
	//tell glfw we are working with opengl version 3.3 core
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);	//first 3.0 of 3.3 core
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);	//last 0.3 of 3.3 core
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //core

	//build window
	GLFWwindow* window = glfwCreateWindow(1280, 720, "ThisIsOurWindow", NULL, NULL);

	//did it fail to build
	if (window == NULL)
	{
		std::cout << "Window was null, awww man :(" << std::endl;
		glfwTerminate();
		system("pause");
		return 0;			//exit main early
	}
	//make this window the current window :D
	glfwMakeContextCurrent(window);

	return window;
}