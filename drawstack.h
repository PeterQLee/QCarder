#ifndef DRAWSTACK_H
#define DRAWSTACK_H

#ifdef __APPLE__
#include <Python.h>
#elif __linux__
#include <python3.4m/Python.h>
#endif
#undef B0
#include <handlePython.h>
#include <QWidget>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <signal.h>

class drawStack: public QOpenGLWidget, protected QOpenGLFunctions
{
public:
    int val=0;
 drawStack(QWidget *parent) : QOpenGLWidget(parent){
     /*rgb=(unsigned char *)malloc(sizeof(unsigned char));

     initializePython("/Users/Peter/go.qcard");
     newFrame();*/

 }

    ~drawStack();
    void initialize(const char **name);
    void regenTexture();
    void loadImage(int index);
    void clearImage(); //ununsed
    void newFrame();
    void changeStack(int pos);
    int initializePython(const char **name);
protected:
    void initializeGL();
    void closeEvent(QCloseEvent *event);
    void resizeGL(int w, int h);
    void paintGL();
private:
        GLuint *filePictures;
        int filePicturessize=0;
        int pictureIndex;
        int curPictureWidth;
        int curPictureHeight;
        int colorSize=3;
        unsigned char *rgb;
        PyObject *object;
        PyThreadState *tstate;
        float picturecoords[];
    //private slots:


};

#endif // DRAWSTACK_H
