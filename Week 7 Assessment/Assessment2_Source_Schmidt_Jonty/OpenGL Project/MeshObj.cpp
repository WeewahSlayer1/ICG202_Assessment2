#include "MeshObj.h"

MeshObj::MeshObj()
{
}

void MeshObj::GenerateVBOandVAO(Primitive primitive)
{
	glGenBuffers(1, &vbo);
	glGenVertexArrays(1, &vao);

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	if (primitive == sqrPyramid)
		glBufferData(GL_ARRAY_BUFFER, sizeof(sqrPyramidVertices), sqrPyramidVertices, GL_STATIC_DRAW);	// Data to GFX card
	if (primitive == hexPyramid)
		glBufferData(GL_ARRAY_BUFFER, sizeof(hexPyramidVertices), hexPyramidVertices, GL_STATIC_DRAW);	// Data to GFX card

	// location = 0, XYZ
	glVertexAttribPointer(
		0, 
		3, 
		GL_FLOAT, GL_FALSE, 
		10 * sizeof(float), 
		(void*)0);
	glEnableVertexAttribArray(0);

	// location = 1, vertex Colours
	glVertexAttribPointer(
		1, 
		3, 
		GL_FLOAT, GL_FALSE, 
		10 * sizeof(float), 
		(void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

	// location = 2, texture coordinates
	glVertexAttribPointer(
		2, 
		2, 
		GL_FLOAT, GL_FALSE, 
		10 * sizeof(float), 
		(void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	// location = 2, texture coordinates
	glVertexAttribPointer(
		3,
		2,
		GL_FLOAT, GL_FALSE,
		10 * sizeof(float),
		(void*)(8 * sizeof(float)));
	glEnableVertexAttribArray(3);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void MeshObj::draw()
{
	shader->use();

	glBindVertexArray(vao);

	glDrawArrays(GL_TRIANGLES, 0, 36);
}