//------------------------------------------------------------------------------
// exampleapp.cc
// (C) 2015-2016 Individual contributors, see AUTHORS file
//------------------------------------------------------------------------------
#include "config.h"
#include "exampleapp.h"
#include <cstring>
#include "chrono"
const GLchar* vs =
        "#version 430\n"
                "layout(location=0) in vec3 pos;\n"
				"layout(location=1) in vec3 norm;\n"
                "layout(location=2) in vec2 uv;\n"
                "layout(location=0) out vec2 UV;\n"
                "layout(location=1) out vec3 vertPos;\n"
                "layout(location=2) out vec3 NORM;\n"
                "uniform mat4 matrix;\n"
                "void main()\n"
                "{\n"
                "    gl_Position = matrix * vec4(pos, 1);\n"
                "   UV.x = uv.x;\n"
                "   UV.y = uv.y;\n"
                "   vec4 vp4 = matrix * vec4(pos, 1);\n"
                "   vertPos = vec3(vp4) /vp4.w;\n"
                "   NORM = norm;\n"
//"    Color = color;\n"
                "}\n";

const GLchar* ps =
        "#version 430\n"
                "layout(location=0) in vec2 uv;\n"
                "layout(location=1) in vec3 vertPos;\n"
                "layout(location=2) in vec3 NORM;\n"
                "out vec3 Color;\n"
                "uniform sampler2D texSampler;\n"
                "void main()\n"
                "{\n"
                "    Color = texture(texSampler,uv).rgb;\n"
                "}\n";


const GLchar* vs2 =
        "#version 430\n"
                "layout(location=0) in vec3 pos;\n"
                "layout(location=1) in vec4 norm;\n"
                "layout(location=2) in vec2 uv;\n"
				"layout(location=3) in vec4 tangent;\n"
				"layout(location=4) in vec4 binormal;\n"
				"layout(location=5) in vec4 weights;\n"
				"layout(location=6) in ivec4 indices;\n"
                "layout(location=0) out vec2 UV;\n"
                "layout(location=1) out vec3 vertPos;\n"
                "layout(location=2) out vec3 NORM;\n"
                "layout(location=3) out vec4 lightpos;\n"
                "layout(location=4) out vec4 speccolor;\n"
				"uniform float test;\n"
                "uniform mat4 rotation;\n"
                "uniform mat4 cameraRotation;\n"
                "uniform mat4 jointPalette[255];\n"

                "uniform vec4 lightPos, specColor, diffuseColor;\n"
                "const int jInd[21] = {19, 18, 17, 0, 20, 15, 13, 1, 12, 9, 2, 10, 3, 11, 14, 16, 4, 5, 8, 6, 7};\n"
                "void main()\n"
                "{\n"
                "   UV.x = uv.x;\n"
                "   UV.y = uv.y;\n"
                "   vec4 normWeights=weights/dot(weights, vec4(1.0));\n"
                "   mat4 joint = jointPalette[jInd[indices[0]]]*normWeights[0] + "
				"				 jointPalette[jInd[indices[1]]]*normWeights[1] + "
				"				 jointPalette[jInd[indices[2]]]*normWeights[2] + "
				"				 jointPalette[jInd[indices[3]]]*normWeights[3];\n"
                "   vec4 vertexNormal_cameraspace = rotation * joint * normalize(norm);\n"
                "   vec4 vertexTangent_cameraspace = rotation * joint * normalize(tangent);\n"
                "   vec4 vertexBitangent_cameraspace = rotation * joint * normalize(binormal);\n"
				"	mat3 TBN = transpose(mat3("
				"        vec3(vertexTangent_cameraspace),"
				"        vec3(vertexBitangent_cameraspace),"
				"        vec3(vertexNormal_cameraspace)));\n"
                "   vec4 vp4 = rotation * joint * vec4(pos, 1);\n"
                "   vp4.x *= 0.3;\n"
                "   vp4.y *= 0.3;\n"
                "   vp4.z *= 0.3;\n"
                "   vertPos = TBN*(vec3(vp4) / vp4.w);\n"
				"   gl_Position = vp4;\n"
                "   NORM = vec3(vertexNormal_cameraspace);\n"
                "   lightpos = vec4(TBN*vec3(0, 0,-1),1.0);\n"
                "   speccolor = vec4(1,1,1,1.0);\n"
                "}\n";

const GLchar* ps2 =
        "#version 430\n"
                "layout(location=0) in vec2 uv;\n"
                "layout(location=1) in vec3 vertPos;\n"
                "layout(location=2) in vec3 NORM;\n"
                "layout(location=3) in vec4 lightPos;\n"
                "layout(location=4) in vec4 specColor;\n"
                "out vec3 Color;\n"
                "uniform sampler2D texSampler;\n"
                "uniform sampler2D normSampler;\n"
				"uniform sampler2D specSampler;\n"
                "const vec3 diffuseColor = vec3(0.4, 0.4, 0.4);\n"
                "const float shininess = 22.0;\n"
                "const float screenGamma = 2.2;\n"
                "void main()\n"
                "{\n"
                "	 vec3 normal = normalize(texture(normSampler, uv ).rgb * 2.0 - 1.0);\n"
                "    vec3 lightDir = normalize(vec3(lightPos) - vertPos);\n"
                " \n"
                "    float lambertian = max(dot(lightDir,normal), 0.0);\n"
                "    float specular = 16;\n"
                "if(lambertian > 0.0)\n"
                "    {  \n"
                "        vec3 viewDir = normalize(-vertPos);\n"
                " \n"
                "        vec3 halfDir = normalize(lightDir + viewDir);\n"
                "        float specAngle = max(dot(halfDir, normal), 0.0);\n"
                "            specular = pow(specAngle, shininess);\n"
                " \n"
                "    }\n"
                "   \n"
                "    vec3 colorLinear = lambertian * diffuseColor + specular * normalize(texture(specSampler, uv ).rgb);\n"
                "    vec3 colorGammaCorrected = pow(colorLinear, vec3(1.0/screenGamma));\n"
                "    Color = texture(texSampler,uv).rgb * colorGammaCorrected;\n"

                "}\n";



using namespace Display;
namespace Example
{

//------------------------------------------------------------------------------
/**
*/
ExampleApp::ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
ExampleApp::~ExampleApp()
{
	// empty
}

//------------------------------------------------------------------------------
/**
*/
bool
ExampleApp::Open()
{
	App::Open();https://www.youtube.com/playlist?list=WL
	this->window = new Display::Window;

    m.parse_model("/home/bill/Downloads/Unit_Footman.constants");
    m.setupAnim("/home/bill/Downloads/Unit_Footman.nax3", "/home/bill/Downloads/Unit_Footman.nvx2");
    m.anim.animClip = 1;

	window->SetKeyPressFunction([this](int32 key, int32, int32 action, int32)
	{

        if (key == GLFW_KEY_0 && action == GLFW_PRESS)
        {
            m.anim.animClip = 0;
        }
        if (key == GLFW_KEY_1 && action == GLFW_PRESS)
        {
            m.anim.animClip = 1;
        }
        if (key == GLFW_KEY_2 && action == GLFW_PRESS)
        {
            m.anim.animClip = 2;
        }
        if (key == GLFW_KEY_3 && action == GLFW_PRESS)
        {
            m.anim.animClip = 3;
        }
        if (key == GLFW_KEY_4 && action == GLFW_PRESS)
        {
            m.anim.animClip = 4;
        }
        if (key == GLFW_KEY_5 && action == GLFW_PRESS)
        {
            m.anim.animClip = 5;
        }
        if (key == GLFW_KEY_6 && action == GLFW_PRESS)
        {
            m.anim.animClip = 6;
        }
        if (key == GLFW_KEY_7 && action == GLFW_PRESS)
        {
            m.anim.animClip = 7;
        }

        if (key == GLFW_KEY_Z && action == GLFW_REPEAT)
        {
            m.rotate_X();
        }
        if (key == GLFW_KEY_X && action == GLFW_REPEAT)
        {
            m.rotate_Y();
        }
        if (key == GLFW_KEY_C && action == GLFW_REPEAT)
        {
            m.rotate_Z();
        }

        else if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        {
            this->window->Close();
        }
	});
    window->SetMouseMoveFunction([this](float64 ym, float64 xm)
                                 {
                                     fdMatrix x;
                                     fdMatrix y;
                                     x.set_RotationX(xm * 0.01);
                                     y.set_RotationY(-ym * 0.01);
                                     rot = x*y;
                                 });

	GLfloat buf[] =
	{
		-0.5f,	-0.5f,	-1,			// pos 0
		1,		0,		0,		1,	// color 0
		0,		0.5f,	-1,			// pos 1
		0,		1,		0,		1,	// color 0
		0.5f,	-0.5f,	-1,			// pos 2
		0,		0,		1,		1	// color 0
	};



	if (this->window->Open())
	{
		// set clear color to gray
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		// setup vertex shader
		this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		GLint length = std::strlen(vs2);
		glShaderSource(this->vertexShader, 1, &vs2, &length);
		glCompileShader(this->vertexShader);

		// get error log
		GLint shaderLogSize;
		glGetShaderiv(this->vertexShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->vertexShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// setup pixel shader
		this->pixelShader = glCreateShader(GL_FRAGMENT_SHADER);
		length = std::strlen(ps2);
		glShaderSource(this->pixelShader, 1, &ps2, &length);
		glCompileShader(this->pixelShader);

		// get error log
		shaderLogSize;
		glGetShaderiv(this->pixelShader, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetShaderInfoLog(this->pixelShader, shaderLogSize, NULL, buf);
			printf("[SHADER COMPILE ERROR]: %s", buf);
			delete[] buf;
		}

		// create a program object
		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->pixelShader);
		glLinkProgram(this->program);
		glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &shaderLogSize);
		if (shaderLogSize > 0)
		{
			GLchar* buf = new GLchar[shaderLogSize];
			glGetProgramInfoLog(this->program, shaderLogSize, NULL, buf);
			printf("[PROGRAM LINK ERROR]: %s", buf);
			delete[] buf;
		}

		// setup vbo

		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBufferData(GL_ARRAY_BUFFER, m.anim.nvx2pars.vertexDataSize, m.anim.nvx2pars.vertexDataPtr, GL_STATIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

		float strideSize = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						   m.anim.nvx2pars.vertexComponents[1].byteOffset+
						   m.anim.nvx2pars.vertexComponents[2].byteOffset+
						   m.anim.nvx2pars.vertexComponents[3].byteOffset+
						   m.anim.nvx2pars.vertexComponents[4].byteOffset+
						   m.anim.nvx2pars.vertexComponents[5].byteOffset+
						   m.anim.nvx2pars.vertexComponents[6].byteOffset;

		uint offset0 = m.anim.nvx2pars.vertexComponents[0].byteOffset;

		uint offset1 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset;

		uint offset2 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset+
						m.anim.nvx2pars.vertexComponents[2].byteOffset;

		uint offset3 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset+
						m.anim.nvx2pars.vertexComponents[2].byteOffset+
						m.anim.nvx2pars.vertexComponents[3].byteOffset;

		uint offset4 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset+
						m.anim.nvx2pars.vertexComponents[2].byteOffset+
						m.anim.nvx2pars.vertexComponents[3].byteOffset+
						m.anim.nvx2pars.vertexComponents[4].byteOffset;

		uint offset5 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset+
						m.anim.nvx2pars.vertexComponents[2].byteOffset+
						m.anim.nvx2pars.vertexComponents[3].byteOffset+
						m.anim.nvx2pars.vertexComponents[4].byteOffset+
						m.anim.nvx2pars.vertexComponents[5].byteOffset;

		uint offset6 = m.anim.nvx2pars.vertexComponents[0].byteOffset+
						m.anim.nvx2pars.vertexComponents[1].byteOffset+
						m.anim.nvx2pars.vertexComponents[2].byteOffset+
						m.anim.nvx2pars.vertexComponents[3].byteOffset+
						m.anim.nvx2pars.vertexComponents[4].byteOffset+
						m.anim.nvx2pars.vertexComponents[5].byteOffset+
						m.anim.nvx2pars.vertexComponents[6].byteOffset;
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);
		glEnableVertexAttribArray(3);
		glEnableVertexAttribArray(4);
		glEnableVertexAttribArray(5);
		glEnableVertexAttribArray(6);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, strideSize, NULL);
		glVertexAttribPointer(1,4,GL_BYTE,GL_TRUE,strideSize,(GLvoid*)offset0);
		glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,strideSize,(GLvoid*)offset1);
		glVertexAttribPointer(3,4,GL_BYTE,GL_TRUE,strideSize,(GLvoid*)offset2);
		glVertexAttribPointer(4,4,GL_BYTE,GL_TRUE,strideSize,(GLvoid*)offset3);
		glVertexAttribPointer(5,4,GL_UNSIGNED_BYTE,GL_TRUE,strideSize,(GLvoid*)offset4);
		glVertexAttribIPointer(6,4,GL_UNSIGNED_BYTE,strideSize,(GLvoid*)offset5);


        mat = glGetUniformLocation(this->program,"rotation");
        nMat = glGetUniformLocation(this->program,"cameraRotation");
		jointArr = glGetUniformLocation(this->program, "jointPalette");



		//jointIndices = glGetUniformLocation(this->program, "jInd");

        glEnable(GL_DEPTH_TEST);
		return true;
	}
	return false;
}

//------------------------------------------------------------------------------
/**
*/

void
ExampleApp::Run()
{
    float dt;

    std::chrono::time_point<std::chrono::system_clock> start,end;


	float arr[m.joints.size()][16];
	//const int jI[] = {19, 18, 17, 0, 20, 15, 13, 1, 12, 9, 2, 10, 3, 11, 14, 16, 4, 5, 8, 6, 7};
	//glUniform1iv(jointIndices, (GLsizei)m.joints.size(), &jI[0]);






    //tex.loadDDS("/home/bill/Downloads/Footman_Normal.dds");

    //tex.loadDDS("/home/bill/Downloads/Footman_Diffuse.dds");

    //tex.loadDDS("/home/bill/Downloads/Footman_Normal.dds");
    glUseProgram(this->program);
	tex.loadDDS("/home/bill/Downloads/Footman_Diffuse.dds", this->program, 0);
	tex.loadDDS("/home/bill/Downloads/Footman_Specular.dds", this->program, 1);
    tex.loadDDS("/home/bill/Downloads/Footman_Normal.dds", this->program, 2);
//    fdVector eye(0, 0, -1);
//    fdVector target(0, 0, 0);
//    fdVector up(0, 1, 0);
//
//    fdVector zAxis(target - eye);
//    zAxis.normalize();
//    fdVector xAxis = up.Cross(zAxis);
//    xAxis.normalize();
//    fdVector yAxis = zAxis.Cross(xAxis);
//
//    fdMatrix viewMatrix = fdMatrix(xAxis.get_X(),    xAxis.get_Y(),    xAxis.get_Z(),    -(xAxis * eye),
//                                   yAxis.get_X(),    yAxis.get_Y(),    yAxis.get_Z(),    -(yAxis * eye),
//                                   zAxis.get_X(),    zAxis.get_Y(),    zAxis.get_Z(),    -(zAxis * eye),
//                                   0,            0,            0,            1);
//
//    float fov = 90.0f;        //Field of view
//    float near = 1.0f;        //Near clipping plane
//    float far = 10.0f;        //Far clipping plane
//    float S = 1 / (tan((fov / 2) * (M_PI / 180)));
//    fdMatrix projectionMatrix = fdMatrix( S,    0,    0,    0,
//                                          0,    S,    0,    0,
//                                          0,    0,    /*-*/1 * (far / (far - near)),    -1 * ((far * near) / (far - near)),
//                                          0,    0,    /*-*/1,    0);

    while (this->window->IsOpen())
	{
//        tex.setUp2((char*)tx, 200, 200);





        fdMatrix camMat;
        //camMat.set_Position(0,0,2);

        start = std::chrono::system_clock::now();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		this->window->Update();
		glUseProgram(this->program);
        m.anim.playAnim(&m, dt);

        camMat.set_Position(0,0,0);
        fdMatrix pvm = rot;

        m.draw_model();

		fdMatrix matra;
		for (int i = 0; i < m.joints.size(); ++i)
		{


			fdMatrix rotated = m.joints[i].transform;
			fdMatrix inverseBP = matra.makeminverse(m.basePmultiplied[i].transform);

			fdMatrix fcomp = rotated*inverseBP;
			int z = 0;
			for (int j = 0; j < 4; ++j) {
				for (int k = 0; k < 4; ++k) {
					arr[i][z] = fcomp[j][k];
					z++;
				}
			}
		}



        m.reset();

		glUniformMatrix4fv(jointArr, m.joints.size(), true, *arr);
		glUniformMatrix4fv(mat, 1, GL_TRUE, pvm.retMat());
		glUniformMatrix4fv(nMat, 1, GL_TRUE, camMat.retMat());
		glDrawArrays(GL_TRIANGLES, 0, m.anim.nvx2pars.numVertices);
		glBindBuffer(GL_ARRAY_BUFFER, 0);



		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);




		this->window->SwapBuffers();
        end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;
        dt = elapsed_seconds.count()*1000;
	}
}

} // namespace Example