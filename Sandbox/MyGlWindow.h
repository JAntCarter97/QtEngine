#pragma once 
#include <qopenglwidget.h>
#include <qtimer.h>

class MyGlWindow : public QOpenGLWidget
{
	Q_OBJECT

	GLuint vertexBufferID;
	QTimer myTimer;

protected:
	void initializeGL();
	void paintGL();

private slots:
	void myUpdate();
	void rotateShip();
	void updateVelocity();

public:
	bool initialize();
	bool shutdown();
};