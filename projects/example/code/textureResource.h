#pragma once

#include "core/app.h"
#include "render/window.h"
struct DDS_PIXELFORMAT {
	unsigned int dwSize;
	unsigned int dwFlags;
	unsigned int dwFourCC;
	unsigned int dwRGBBitCount;
	unsigned int dwRBitMask;
	unsigned int dwGBitMask;
	unsigned int dwBBitMask;
	unsigned int dwABitMask;
};

struct DDSHeaderEXTD
{
//	unsigned int magic;
	unsigned int dxgiformat;
	unsigned int resourceDim;
	unsigned int miscFlag;
	unsigned int arraySize;
	unsigned int miscFlags2;
};
struct DDSHeader
{
	unsigned int magic;
	unsigned int size;
	unsigned int flags;
	unsigned int height;
	unsigned int width;
	unsigned int linearSize;
	unsigned int depth;
	unsigned int mipMapCount;
	unsigned int reserved1[11];
	DDS_PIXELFORMAT pfmt;
};



class TextureResource {
private:
	GLuint texture;
    GLuint textureID;
    GLuint normalsID;
    GLuint NormalTextureID;
    GLuint specID;
    GLuint specTextureID;

public:

	void generateTexture();
	void setUp(char*);
	void loadDDS(char *textureF, GLuint prog, int type);
	void setUp2(char*, int, int);
	unsigned char* getImg(char*);
};