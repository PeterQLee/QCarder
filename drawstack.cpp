#include "drawstack.h"

/*drawStack::drawStack()
{

}*/
void drawStack::paintGL()
    {
        // Draw the scene:
        QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
        f->glClear(GL_COLOR_BUFFER_BIT);

    }
void drawStack::initializeGL() {
    // Set up the rendering context, load shaders and other resources, etc.:
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    f->glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

}
void drawStack::resizeGL(int w, int h){
    // Update projection matrix and other size related settings:
    /*m_projection.setToIdentity();
    m_projection.perspective(45.0f, w / float(h), 0.01f, 100.0f);*/

}
void drawStack::setVal() {
    this->val=2;
}
void drawStack::sayVal() {
  printf("%d\n",this->val);
}

drawStack::~drawStack()
{

}

