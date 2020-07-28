#include <iostream>
#include <string>
#include "setup - glfw.h"		// Allows creation of GLFWwindow
#include "playerInput.h"		// Gets input (in this case, numpad keys)
#include "TextureLoader.h"		// Allows us to load textures

#include "Camera.h"
#include <glm/gtc/type_ptr.hpp>	// glm types to opengl types

#include "MeshObj.h"
#include <list>					//Linked lists


using namespace std;

//-------------------------------  Functions  ---------------------------------------------------//
void Rendering(Shader shaderProgramCube, unsigned int texture1, unsigned int texture2, unsigned int texture3, list<MeshObj> sqrPyramids, list<MeshObj> hexPyramids);
void Render(MeshObj meshObj, unsigned int texture1, unsigned int texture2, unsigned int texture3, float vertexColourMixing);
void mouse_Callback(GLFWwindow* window, double xPos, double yPos);
void scroll_Callback(GLFWwindow* window, double xOffset, double yOffset);


//-------------------------------  Variables  ---------------------------------------------------//
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));	// Camera position
float lastX = 1280 / 2, lastY = 720 / 2;	// Center of the screen
bool firstMouse = true;						// Make sure camera position doesn't shift when the game starts

float deltaTime = 0;
float lastFrame = 0;


//======================  void main()  ======================================//
int main() {
	//-----------------  Setup glfw window  -------------------------------------//
	GLFWwindow* window = SetupGLFWwindow();

	//------------  Setup GLAD, find all openGL ---------------------------------//
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		cout << "GlAD failed to load ?!?!?!" << endl;
		glfwTerminate();
		system("pause");
		return 0;			//exit main early
	}

	//tell openGL how much of the window to use
	glViewport(0, 0, 1280, 720); //xOffset, yOffset, w, h

	//-------------  Refgister window callbacks  ------------------------------------//
	glfwSetCursorPosCallback(window, mouse_Callback);
	glfwSetScrollCallback(window, scroll_Callback);

	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	//-------------  SHADERS!!!!!  ------------------------------------------------------//
	Shader shaderVertMix("vertexShaderProjection.txt", "fragmentShaderTextures.txt");
	Shader shaderSecondTexture("vertexShaderProjection.txt", "fragmentShaderMultipleTextures.txt");
	Shader shaderLit("vertexShaderProjection.txt", "fragmentShaderLit.txt");
	Shader shaderLamp("vertexShaderProjection.txt", "fragmentShaderLamp.txt");

	//------------------  TEXTURES!!!!!!!!  --------------------------------------//
	stbi_set_flip_vertically_on_load(true);

	unsigned int texture1 = LoadTexture("Texture_crate.jpg", GL_RGB);
	unsigned int texture2 = LoadTexture("Texture_concrete.jpg", GL_RGB);
	unsigned int texture3 = LoadTexture("Texture_faces.png", GL_RGBA);

	//------------------  Cubes  --------------------------------------//
	list<MeshObj> sqrPyramids;
	list<MeshObj> hexPyramids;

	glm::vec3 meshPositions[] = {
		glm::vec3(0.0f, 0.0f, 0.0f),
		glm::vec3(2.0f, 2.5f, -5.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -3.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f, 3.0f, -4.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f, 2.0f, -2.5f),
		glm::vec3(1.5f, 0.2f, -1.5f),
		glm::vec3(-1.3f, 1.0f, -1.5f)
	};

	for (int i = 0; i < 5; i++) {
		MeshObj meshObj;
		meshObj.GenerateVBOandVAO(sqrPyramid);
		meshObj.pos = meshPositions[i];
		meshObj.shader = &shaderVertMix;

		sqrPyramids.push_back(meshObj);
	}
	for (int i = 5; i < 10; i++) {
		MeshObj meshObj;
		meshObj.GenerateVBOandVAO(hexPyramid);
		meshObj.pos = meshPositions[i];
		meshObj.shader = &shaderSecondTexture;

		hexPyramids.push_back(meshObj);
	}

	MeshObj lampCube;

	//------------------ z-buffering  -----------------------------------------//
	glEnable(GL_DEPTH_TEST);

	//------------------  GAME LOOP  -------------------------------------------//
	while (!glfwWindowShouldClose(window)) //While window should NOT close
	{
		// 1 - Get deltaTime
		float currentFrame = (float)glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// 2 - Get input
		ProcessInputs(window, &camera, deltaTime);

		// 3- Render clear clour
		glClearColor(0.75f, 0.75f, 0.75f, 1);		//rgba values - Max blue
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 4 - Render
		Rendering(shaderVertMix, texture1, texture2, texture3, sqrPyramids, hexPyramids);

		// 5 - Process polled events
		glfwPollEvents();

		// 6 - Swap buffers
		glfwSwapBuffers(window); //using double buffering. Draw back buffer, then swap to current (to see it)
	}

	glfwTerminate();	//Clean up

	return 0;
}

void mouse_Callback(GLFWwindow* window, double xPos, double yPos) {
	if (firstMouse) {
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}

	float xOffset = xPos - lastX;
	float yOffset = lastY - yPos;	//Swap this to invert up-down

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset);
}

void scroll_Callback(GLFWwindow* window, double xOffset, double yOffset){
	camera.ProcessMouseScroll(yOffset);		//Change FOV
}

//======================  Secondary Functions  ======================================//
void Rendering(Shader shader, unsigned int texture1, unsigned int texture2, unsigned int texture3, list<MeshObj> sqrPyramids, list<MeshObj> hexPyramids)
{
	shader.use();

	float mixer = sin(glfwGetTime()) / 2.0f + 0.5f;

	for (MeshObj pyramid : sqrPyramids)
		Render(pyramid, texture1, texture2, texture3, mixer);

	for (MeshObj pyramid : hexPyramids)
		Render(pyramid, texture1, texture2, texture3, mixer);
}

//------------------  Render a particular meshObj  -----------------------------//
void Render(MeshObj meshObj, unsigned int texture1, unsigned int texture2, unsigned int texture3, float vertexColourMixing)
{
	glm::mat4 model = glm::mat4(1.0);
	model = glm::translate(model, meshObj.pos);
	model = glm::rotate(model, (float)(glfwGetTime()), glm::vec3(0.0f, 1.0f, 0.0f));

	//---------------------------------------  View Matrix  ---------------------------------------------------//
	glm::mat4 view = camera.GetViewMatrix();

	glm::mat4 projection = glm::mat4(1.0f);
	projection = glm::perspective(
		glm::radians(camera.Zoom),	// FOV
		1280.0f / 720.0f,			// Aspect ratio
		0.1f, 100.0f);				// clipping planes

	glUniformMatrix4fv(glGetUniformLocation(meshObj.shader->ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(glGetUniformLocation(meshObj.shader->ID, "view"), 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(glGetUniformLocation(meshObj.shader->ID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

	int uniformLocation;

	//-----------  "vertexColourMixing"  ----------//
	uniformLocation = glGetUniformLocation(meshObj.shader->ID, "vertexColourMixing");
	glUniform1f(uniformLocation, vertexColourMixing);

	//-----------  Texture1  ----------//
	glActiveTexture(GL_TEXTURE0);				// Set slot as active texture slot
	glBindTexture(GL_TEXTURE_2D, texture1); 	// bind our texture to that slot
	uniformLocation = glGetUniformLocation(meshObj.shader->ID, "texture1");
	glUniform1i(uniformLocation, 0);

	//-----------  Texture2  ----------//
	glActiveTexture(GL_TEXTURE1);				// Set slot as active texture slot
	glBindTexture(GL_TEXTURE_2D, texture2); 	// bind our texture to that slot
	uniformLocation = glGetUniformLocation(meshObj.shader->ID, "texture2");
	glUniform1i(uniformLocation, 1);

	//-----------  Texture3  ----------//
	glActiveTexture(GL_TEXTURE2);				// Set slot as active texture slot
	glBindTexture(GL_TEXTURE_2D, texture3); 	// bind our texture to that slot
	uniformLocation = glGetUniformLocation(meshObj.shader->ID, "texture3");
	glUniform1i(uniformLocation, 2);

	//-----------  Draw  ----------//
	meshObj.draw();
}