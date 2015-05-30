#include "colordisplay.h"

/*colorDisplay::colorDisplay(QWidget *parent) : QOpenGLWidget(parent)
{

}*/

colorDisplay::~colorDisplay()
{

}

void colorDisplay::resizeGL(int width, int height){

}
void colorDisplay::paintGL(){

    glClear(GL_COLOR_BUFFER_BIT);
glClearColor(red/255.0f,green/255.0f,blue/255.0f,1.0f);
glFlush();
}

void colorDisplay::closeEvent(QCloseEvent *event){}
void colorDisplay::initializeGL(){
    initializeOpenGLFunctions();
    paintGL();
    //printf("mycof %f",red/255.0f);

    glMatrixMode(GL_PROJECTION);
glLoadIdentity();
}
void colorDisplay::changeColor(int r, int g, int b) {
    red=r;
    green=g;
    blue=b;

    repaint();
}
