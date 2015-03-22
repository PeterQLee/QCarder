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
        Q_OBJECT

public:
    int val=0;
 drawStack(QWidget *parent) : QOpenGLWidget(parent){


     /*rgb=(unsigned char *)malloc(sizeof(unsigned char));

     initializePython("/Users/Peter/go.qcard");
     newFrame();*/

 }

    ~drawStack();
    void draw(); //draws picture to screen
    void initialize(char **name);
    void regenTexture();
    void loadImage(int index);
    void clearImage(); //ununsed
    void newFrame();
    void changeStack(int pos);
    int initializePython(char **name);
protected:
    void initializeGL();
    void closeEvent(QCloseEvent *event);
    void resizeGL(int w, int h);
    void paintGL();
private:
        GLuint *filePictures;
        int filePicturessize=0;
        int pictureIndex=0;
        int curPictureWidth;
        int curPictureHeight;
        int colorSize=3;
        unsigned char *rgb;
        PyObject *object;
        PyThreadState *tstate;
        float picturecoords[8]={-0.5f,-0.5f,0.5f,-0.5f,0.5f,0.5f,-0.5f,0.5f};
public slots:
        void nextCard();
        void prevCard();


};

#endif // DRAWSTACK_H
