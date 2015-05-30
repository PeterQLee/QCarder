#include "ui_testscreen.h"
#include "testscreen.h"
#include "drawstack.h"

TestScreen::TestScreen(QWidget *parent) : QWidget(parent),ui(new Ui::TestScreen)
{
    ui->setupUi(this);

    connect(ui->btnNext,SIGNAL(released()),ui->openGLWidget,SLOT(nextCard()));
    connect(ui->btnPrev,SIGNAL(released()),ui->openGLWidget,SLOT(prevCard()));
    connect(ui->btnShowBack,SIGNAL(released()),ui->openGLWidget,SLOT(showBack()));
    //connect(ui->textBrowser,SIGNAL(textChanged(),ui->openGLWidget,SLOT(updateText())));
}
void TestScreen::giveFileArg(char **file){
    printf("sec %s\n",*file);
    ui->openGLWidget->initialize(file); //just need to double pointer pass

    printf("hiyoud\n");

}
TestScreen::~TestScreen()
{

}



