#pragma once 
#include <qopenglwidget.h>

class MyGlWindow : public QOpenGLWidget
{
	GLuint vertexBufferID;
protected:
	void initializeGL();
	void paintGL();
};
