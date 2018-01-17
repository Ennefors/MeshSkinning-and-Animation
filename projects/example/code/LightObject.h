#pragma once
#include "core/app.h"
#include "config.h"
#include "tdMathLibNew.h"
#include "GraphicsNode.h"

class LightObject {
private:
	fdVector color;
	fdVector pos;
	fdVector dif;
	float intensity;
	GraphicsNode* addres;

public:
	void setColor(float r, float g, float b) { color.set_Vector(r, g, b); }
	void setPos(float x, float y, float z) { pos.set_Vector(x, y, z); }
	void setIntensity(float i) { intensity = i; color = color*intensity; }
	void setDif(float x, float y, float z) { dif.set_Vector(x, y, z); }
	void setNode(GraphicsNode& node) { addres = &node; }
	void setUniform() {
		addres->getShader()->setUniVec("specColor", color); 
		addres->getShader()->setUniVec("lightPos", pos);
		addres->getShader()->setUniVec("diffuseColor", dif);
	}

	float* getColor() { return color.retVec(); }
	float* getPos() { return pos.retVec(); }
	float getIntensity() { return intensity; }
	float* getDif() { return dif.retVec(); }
	GraphicsNode* getGnode() { return addres; }
};