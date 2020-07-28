#pragma once
#include <cmath>
#include "Shader.h"
#include <glm/glm.hpp>
#include "geometry.h"

class MeshObj {
	public:
		unsigned int vbo;
		unsigned int vao;

		Shader*				shader;

		glm::vec3			pos;

		MeshObj();
		void draw();
		void GenerateVBOandVAO(Primitive primitive);
};