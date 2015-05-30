#include "drawstack.h"
#include "createscreen.h"
#include "colordisplay.h"
#include "ui_createscreen.h"
CreateScreen::CreateScreen(QWidget *parent) : QWidget(parent),ui(new Ui::CreateScreen)
{
    ui->setupUi(this);
    connect(ui->btnNext,SIGNAL(released()),ui->oglPicture,SLOT(nextCard()));
    connect(ui->btnPrev,SIGNAL(released()),ui->oglPicture,SLOT(prevCard()));
    connect(ui->btnBackFront,SIGNAL(released()),ui->oglPicture,SLOT(showBack()));

    connect(ui->sldBlue,SIGNAL(sliderMoved(int)),this,SLOT(updateColor()));
    connect(ui->sldGreen,SIGNAL(sliderMoved(int)),this,SLOT(updateColor()));
    connect(ui->sldRed,SIGNAL(sliderMoved(int)),this,SLOT(updateColor()));

    connect(this,SIGNAL(sendColor(int,int,int)),ui->oglSample,SLOT(changeColor(int,int,int)));
    //connect(ui->textBrowser,SIGNAL(textChanged(),ui->openGLWit,SLOT(updateText())));
}

void CreateScreen::giveFileArg(char **file){
    printf("sec %s\n",*file);
    ui->oglPicture->initialize(file); //just need to double pointer pass

    printf("hiyoud\n");

}
void CreateScreen::updateColor() {
    //update GUI color values, and update color sampler
    int b=ui->sldBlue->value();
    int g=ui->sldGreen->value();
    int r=ui->sldRed->value();
    //printf("COLROS %d %d %d",r,g,b);
    emit sendColor(r,g,b);

}

CreateScreen::~CreateScreen()
{

}

