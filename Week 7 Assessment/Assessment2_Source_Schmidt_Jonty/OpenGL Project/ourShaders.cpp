#include <glad/glad.h>
#include "ourShaders.h"
#include <iostream>
using namespace std;

//==============  Variable - Vertex shader source code  ================================//
const char* vertexShaderSource =
"#version 330 core \n"
"layout(location = 0) in vec3 aPos;\n"				//We'll be passing vertex xyz into aPos variable
"out vec4 vertexColour; \n"
"void main()\n"
"{\n"
"gl_Position = vec4(aPos, 1);"	//vertex shader must set gl_Position for shape assembly
"\n"
"vertexColour = vec4(1.0, 1.0, 0.0, 1.0);"
"\n"
"}\n\0";

//==============  Variable - Fragment shader source code  =============================//
const char* fragmentShaderSource =
"#version 330 core \n"
"out vec4 FragColour; \n"
"\n"
"in vec4 vertexColour; \n"
"\n"
"void main()\n"
"{\n"
"FragColour = vertexColour; \n" 
"}\n\0";

//==============  Variables - error recognition =======================================//
int success;
char infoLog[512];

//==============================================  Functions ============================================================//
int CreateVertexShader(const char* vShaderSrc)
{
	int vertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	//2 - Pass shader code to the shader on the gfx card
	glShaderSource(vertexShaderID, 1, &vShaderSrc, NULL);
	//3 - Compile it!
	glCompileShader(vertexShaderID);
	//4 - Check for errors
	glGetShaderiv(vertexShaderID, GL_COMPILE_STATUS, &success);
	if (!success) //success can be 0 or 1
	{
		//get error log info
		glGetShaderInfoLog(vertexShaderID, 512, NULL, infoLog);
		cout << "Vertex shader error: " << infoLog << endl;
		system("pause");
	}

	return vertexShaderID;
}

int CreateFragmentShader(const char* fShaderSrc)
{
	//1 - Generate fragment shader on GFX card and return id of that shader
	int fragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	//2 - Pass shader code to the shader on the gfx card
	glShaderSource(fragmentShaderID, 1, &fShaderSrc, NULL);
	//3 - Compile it!
	glCompileShader(fragmentShaderID);
	//4 - Check for errors
	glGetShaderiv(fragmentShaderID, GL_COMPILE_STATUS, &success);
	if (!success) //success can be 0 or 1
	{
		//get error log info
		glGetShaderInfoLog(fragmentShaderID, 512, NULL, infoLog);
		cout << "Fragment shader error: " << infoLog << endl;
		system("pause");
	}

	return fragmentShaderID;
}

int ShadersToProgram(int vShaderID, int fShaderID)
{

	//SHADER PROGRAM (links multiple shader into 1 program)
	int shaderProgramID = glCreateProgram();
	// 1 - attach shaders
	glAttachShader(shaderProgramID, vShaderID);
	glAttachShader(shaderProgramID, fShaderID);
	// 2 - link
	glLinkProgram(shaderProgramID);
	// 3 - check for errors
	glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shaderProgramID, 512, NULL, infoLog);
		cout << "Shader program linking error: " << infoLog << endl;
		system("pause");
	}

	return shaderProgramID;
}

int CreateShaderProgram(const char* vShaderSrc, const char* fShaderSrc)
{
	// 1 - Create vertex shader
	int vertexShaderID = CreateVertexShader(vShaderSrc);

	// 2 - Create fragment shader
	int fragmentShaderID = CreateFragmentShader(fShaderSrc);

	// 3 - Compile 2 shaders into 1 program
	int shaderProgramID = ShadersToProgram(vertexShaderID, fragmentShaderID);

	// 4 - delete individual shaders
	glDeleteShader(vertexShaderID);
	glDeleteShader(fragmentShaderID);

	return shaderProgramID;
}