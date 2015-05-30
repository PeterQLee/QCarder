#ifndef COLORDISPLAY_H
#define COLORDISPLAY_H

#include <QObject>
#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class colorDisplay : public QOpenGLWidget, protected QOpenGLFunctions
{

    Q_OBJECT
public:
    colorDisplay(QWidget *parent) : QOpenGLWidget(parent){
        red=140;
        green=0;
        blue=0;
    }



    ~colorDisplay();
protected:
    void initializeGL();
    void closeEvent(QCloseEvent *event);
    void resizeGL(int w, int h);
    void paintGL();
private:
    int red;
    int green;
    int blue;
public slots:
    void changeColor(int r,int g,int b);

};

#endif // COLORDISPLAY_H
