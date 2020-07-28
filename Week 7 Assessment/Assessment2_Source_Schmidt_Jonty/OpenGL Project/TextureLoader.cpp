#define STB_IMAGE_IMPLEMENTATION	//makes sure stb doesn't go trying to compile the rest of the library

#include "TextureLoader.h"

unsigned int LoadTexture(const char* fileName, int RGBType)
{
	unsigned int textureID = 0;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);

	// Wrapping options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);			// s = xCoords, normalised
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);	// t = yCoords, normalised

	// Filtering options
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);		// stretch to use bilinear filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);		// stretch to use nearest neighbour

	int width, height, numberOfChannels;
	unsigned char* imageData = stbi_load(fileName, &width, &height, &numberOfChannels, 0);

	if (imageData)
	{
		//SUCCESS! Pass imageData into texture on gfx card
		glTexImage2D(
			GL_TEXTURE_2D,		// Texture type
			0,					// Default mipmap level
			RGBType,			// Format to store on gfx card
			width, height,		// Dimensions
			0,					// border	
			RGBType,			// colour type (RED, RGB, RGBA)
			GL_UNSIGNED_BYTE,	// data type, stored in an array
			imageData);

		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(imageData);	//Image copied to vRam, remove from ram 

		return textureID;
	}
	else
		cout << "Texture failed to load: " << fileName << endl;

	return 0;
} 