#pragma once
//------------------------------------------------------------------------------
/**
	Application class used for example application.
	
	(C) 2015-2016 Individual contributors, see AUTHORS file
*/
//------------------------------------------------------------------------------
#include "core/app.h"
#include "render/window.h"
#include "model.h"
#include "textureResource.h"

namespace Example
{
class ExampleApp : public Core::App
{
public:
	/// constructor
	ExampleApp();
	/// destructor
	~ExampleApp();

	/// open app
	bool Open();
    model m;
	/// run app
	void Run();
private:
    TextureResource tex;

    GLuint rotation;
	GLint  jointArr;
	GLint jointIndices;
	GLuint vbo;
	GLuint program;
	GLuint vertexShader;
	GLuint pixelShader;
	GLuint triangle;
	fdMatrix rot;

	GLuint mat;
	GLuint nMat;
	Display::Window* window;
};
} // namespace Example