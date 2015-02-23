#include "ui_testscreen.h"
#include "testscreen.h"

TestScreen::TestScreen(QWidget *parent) : QWidget(parent),ui(new Ui::TestScreen)
{
    ui->setupUi(this);


}
void TestScreen::giveFileArg(const char **file){
    printf("sec %s\n",*file);
    ui->openGLWidget->initialize(file); //just need to double pointer pass

    printf("hiyoud\n");

}
TestScreen::~TestScreen()
{

}

