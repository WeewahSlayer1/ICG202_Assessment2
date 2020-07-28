#pragma once

enum Primitive { sqrPyramid, hexPyramid };

const float sqrPyramidVertices[] = 
{
	// Bottom #1
	-0.5f, -0.5f, -0.5f,	1, 0, 0,	1.0f, 0.0f,		1.0f, 0.0f,		// Back left
	0.5f, -0.5f, -0.5f,		1, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Back right
	-0.5f, -0.5f, 0.5f,		1, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// Front left

	// Bottom #2
	-0.5f, -0.5f, 0.5f,		1, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// Front left
	0.5f, -0.5f, 0.5f,		1, 0, 0,	0.0f, 1.0f,		1.0f, 0.0f,		// Front right
	0.5f, -0.5f, -0.5f,		1, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Back right

	// Back
	-0.5f, -0.5f, -0.5f,	1, 0, 0,	0.9f, 1.0f,		0.0f, 0.7f,		// Back left
	0.5f, -0.5f, -0.5f,		1, 0, 0,	0.1f, 1.0f,		0.33f, 0.7f,	// Back right
	0.0, 0.5f, -0.0f,		1, 1, 1,	0.5f, 0.0f,		0.16f, 1.05f,	// Top middle

	// Left
	-0.5f, -0.5f, 0.5f,		1, 0, 0,	0.9f, 1.0f,		0.32f, 0.7f,	// Front left
	-0.5f, -0.5f, -0.5f,	1, 0, 0,	0.1f, 1.0f,		0.67f, 0.7f,	// Back left
	0.0, 0.5f, -0.0f,		1, 1, 1,	0.5f, 0.0f,		0.5f, 1.05f,		// Top middle

	// Right
	0.5f, -0.5f, -0.5f,		1, 0, 0,	0.9f, 1.0f,		0.0f, 0.35f,	// Back right
	0.5f, -0.5f, 0.5f,		1, 0, 0,	0.1f, 1.0f,		0.32f, 0.35f,	// Front right
	0.0, 0.5f, -0.0f,		1, 1, 1,	0.5f, 0.0f,		0.17f, 0.75f,	// Top middle

	// Front
	-0.5f, -0.5f, 0.5f,		1, 0, 0,	0.9f, 1.0f,		0.65f, 0.7f,	// Front left
	0.5f, -0.5f, 0.5f,		1, 0, 0,	0.1f, 1.0f,		1.0f, 0.7f,		// Front right
	0.0, 0.5f, -0.0f,		1, 1, 1,	0.5f, 0.0f,		0.84f, 1.05f,	// Top middle
};

const float hexPyramidVertices[] =
{
	// Bottom #1
	0.0f, -0.5f, 0.5f,		0, 0, 0,	1.0f, 0.0f,		1.0f, 0.0f,		// Top center
	-0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Upper left
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Bottom #2
	-0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Upper left
	-0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Lower left
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Bottom #3
	-0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Lower left
	0.0f, -0.5f, -0.5f,		0, 0, 0,	1.0f, 0.0f,		1.0f, 0.0f,		// Bottom center
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Bottom #4
	0.0f, -0.5f, 0.5f,		0 ,0, 0,	1.0f, 0.0f,		1.0f, 0.0f,		// Top center
	0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Upper right
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Bottom #5
	0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Upper right
	0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Lower right
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Bottom #6
	0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		1.0f, 0.0f,		// Lower right
	0.0f, -0.5f, -0.5f,		0, 0, 0,	1.0f, 0.0f,		1.0f, 0.0f,		// Bottom center
	0.0f, -0.5f, 0.0f,		0, 0, 0,	1.0f, 1.0f,		1.0f, 0.0f,		// middle

	// Side #1
	0.0f, -0.5f, 0.5f,		0, 0, 0,	0.0f, 0.0f,		0.69f, 0.31f,	// Top center 
	-0.43f, -0.5f, 0.25f,	0, 0, 0,	1.0f, 0.0f,		0.33f, 0.31f,	// Upper left
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.5f, 0.75f,	// middle

	// Side #2
	-0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		0.61f, 0.3f,	// Upper left
	-0.43f, -0.5f, -0.25f,	0, 0, 0,	1.0f, 0.0f,		1.0f, 0.3f,		// Lower left
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.83f, 0.75f,	// middle

	// Side #3
	-0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		0.0f, -0.035f,	// Lower left
	0.0f, -0.5f, -0.5f,		0, 0, 0,	1.0f, 0.0f,		0.39f, -0.035f,	// Bottom center
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.17f, 0.41f,	// middle

	// Side #4
	0.0f, -0.5f, 0.5f,		0, 0, 0,	0.0f, 0.0f,		0.29f, -0.035f,		// Top center
	0.43f, -0.5f, 0.25f,	0, 0, 0,	1.0f, 0.0f,		0.74f, -0.035f,		// Upper right
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.51f, 0.4f,		// middle

	// Side #5
	0.43f, -0.5f, 0.25f,	0, 0, 0,	0.0f, 0.0f,		0.6f, -0.035f,		// Upper right
	0.43f, -0.5f, -0.25f,	0, 0, 0,	1.0f, 0.0f,		1.045f, -0.035f,	// Lower right
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.82f, 0.4f,		// middle

	// Side #6
	0.43f, -0.5f, -0.25f,	0, 0, 0,	0.0f, 0.0f,		0.0f, -0.035f,	// Lower right
	0.0f, -0.5f, -0.5f,		0, 0, 0,	1.0f, 0.0f,		0.39f, -0.035f, // Bottom center
	0.0f, 0.25f, 0.0f,		1, 1, 1,	0.5f, 1.0f,		0.17f, 0.41f,	// middle
};