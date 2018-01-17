//#define STB_IMAGE_IMPLEMENTATION
#include "config.h"
#include "textureResource.h"
#include "stb_image.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <fcntl.h>
#include <string.h>
#include <iostream>

typedef unsigned int U32;
typedef unsigned char U8;
#define MakeFourCC(ch0, ch1, ch2, ch3) \
   ((U32)(U8)(ch0) | ((U32)(U8)(ch1) << 8) |         \
   ((U32)(U8)(ch2) << 16) | ((U32)(U8)(ch3) << 24 ))

#define FOURCC_DXT1 (MakeFourCC('D','X','T','1'))
#define FOURCC_DX10 (MakeFourCC('D','X','1','0'))
#define FOURCC_DXT3 (MakeFourCC('D','X','T','3'))
#define FOURCC_DXT4 (MakeFourCC('D','X','T','4'))
#define FOURCC_DXT5 (MakeFourCC('D','X','T','5'))
#define FOURCC_DXT6 (MakeFourCC('D','X','T','6'))
#define FOURCC_DXT7 (MakeFourCC('D','X','T','7'))
#define FOURCC_DXT8 (MakeFourCC('D','X','T','8'))
#define FOURCC_DXT9 (MakeFourCC('D','X','T','9'))
void TextureResource::generateTexture()
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	
}

void TextureResource::setUp(char *textureF) 
{

	glGenTextures(1, &texture);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,
		GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	int x, y, n;

	unsigned char *data = stbi_load(textureF, &x, &y, &n, 4);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);

	glGenerateMipmap(GL_TEXTURE_2D);
	glGenerateTextureMipmap(texture);
}


void TextureResource::setUp2(char *text, int x, int y)
{
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, x, y, 0, GL_RGB, GL_UNSIGNED_BYTE, text);
	glBindTexture(GL_TEXTURE_2D, 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture);
	glGenerateMipmap(GL_TEXTURE_2D);
	glGenerateTextureMipmap(texture);
}

size_t getFilesizeb(const char* filename) {
	struct stat st;
	stat(filename, &st);
	return st.st_size;
}

void TextureResource::loadDDS(char *textureF, GLuint prog, int type)
{
	void* texPTR;

	size_t fsize = getFilesizeb(textureF);

	int isOpen = open(textureF, O_RDONLY, 0);

	assert(isOpen != -1);

	texPTR = mmap(NULL, fsize, PROT_READ, MAP_PRIVATE | MAP_POPULATE, isOpen, 0);
	assert(texPTR != MAP_FAILED);
	DDSHeader* head = (DDSHeader*)texPTR;
	DDSHeaderEXTD* extdHead;

	texPTR += head->size + sizeof(uint);
    if (head->pfmt.dwFourCC == FOURCC_DXT1)
    {
        std::cout << "bananjan" << std::endl;
    }
    if (head->pfmt.dwFourCC == FOURCC_DXT3)
    {
        std::cout << "bananjan" << std::endl;
    }
    if (head->pfmt.dwFourCC == FOURCC_DXT5)
    {
        glActiveTexture(GL_TEXTURE1);
        glGenTextures(1, &normalsID);
        glBindTexture(GL_TEXTURE_2D, normalsID);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        NormalTextureID  = glGetUniformLocation(prog, "normSampler");
        glUniform1i(NormalTextureID, 1);
        unsigned int blockSize = 16;
        unsigned int offset = 0;

        int oh = head->height;
        int ow = head->width;

        for (unsigned int level = 0; level < head->mipMapCount && (head->width || head->height); ++level)
        {
            unsigned int size = ((ow+3)/4)*((oh+3)/4)*blockSize;
            glCompressedTexImage2D(GL_TEXTURE_2D, level, GL_COMPRESSED_RGBA_S3TC_DXT5_EXT, ow, oh,
                                   0, size, texPTR + offset);

            offset += size;
            oh  /= 2;
            ow /= 2;
        }

    }
	if(head->pfmt.dwFourCC == FOURCC_DX10) {
        extdHead = (DDSHeaderEXTD *) texPTR;
        texPTR += sizeof(DDSHeaderEXTD);
        if (type == 0) {
            glActiveTexture(GL_TEXTURE0);
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            textureID = glGetUniformLocation(prog, "texSampler");
            glUniform1i(textureID, 0);
        } else
        {
            glActiveTexture(GL_TEXTURE3);
            glGenTextures(1, &specID);
            glBindTexture(GL_TEXTURE_2D, specID);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            specTextureID = glGetUniformLocation(prog, "specSampler");
            glUniform1i(specTextureID, 0);
        }

		unsigned int blockSize = (GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
		unsigned int offset = 0;

		int oh = head->height;
		int ow = head->width;

		for (unsigned int level = 0; level < head->mipMapCount && (head->width || head->height); ++level)
		{
			unsigned int size = ((ow+3)/4)*((oh+3)/4)*blockSize;
			glCompressedTexImage2D(GL_TEXTURE_2D, level, GL_COMPRESSED_SRGB_ALPHA_S3TC_DXT3_EXT, ow, oh,
								   0, size, texPTR + offset);

			offset += size;
			oh  /= 2;
			ow /= 2;
		}
	}
}

unsigned char * TextureResource::getImg(char* textureF)
{
	int x, y, n;

	unsigned char *data = stbi_load(textureF, &x, &y, &n, 3);

	return data;
}
