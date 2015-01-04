#ifndef DRAWSTACK_H
#define DRAWSTACK_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

#ifdef __APPLE__
#include <Python.h>
elif __linux__
#include <python3.4m/Python.h>
#endif

class drawStack: public QOpenGLWidget
{
public:
    int val=0;
    drawStack(QWidget *parent) : QOpenGLWidget(parent){}

    ~drawStack();
    void setVal();//test
    void sayVal();//test
    void regenTexture();
    void loadImage(int index);
    void clearImage(); //ununsed
    void newFrame();
    void changeStack(int pos);
    int initializePython(char *name);
protected:
    void initializeGL();


        void resizeGL(int w, int h);


        void paintGL();
private:
        GLuint filePictures*;
        int filePicturesize=0;
        int pictureIndex;
        int curPictureWidth;
        int curPictureHeight;
        int colorSize=3;
        unsigned char *rgb;
        PyObject *object;
        //float picturecoords[]=

};

#endif // DRAWSTACK_H
