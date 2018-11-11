#include "GeometricObject.h"
#include "pch.h"
#include "GeometricObject.h"

GeometricObject::GeometricObject()
{
	color = RGBColor();
	this->is_reflective = false;
	this->is_transparent = false;
}

GeometricObject::GeometricObject(const RGBColor & color) {
	this->color = RGBColor(color.r, color.g, color.b);
	this->is_reflective = false;
	this->is_transparent = false;
}

GeometricObject::~GeometricObject()
{
}
