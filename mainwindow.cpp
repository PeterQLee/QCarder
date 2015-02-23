#include "testscreen.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnBrowse,SIGNAL(released()),this,SLOT(browseFile()));
    connect(ui->btnNewCard,SIGNAL(released()),this,SLOT(newFile()));
    connect(ui->btnGo,SIGNAL(released()),this,SLOT(tmpGo()));
}
void MainWindow::browseFile() {
    QString file=QFileDialog::getOpenFileName(this,tr("Open Image"), "/", tr("Image Files (*.qcard)"));
    ui->txtFileName->setText(file);
}
void MainWindow::newFile() {
    QString file=QFileDialog::getSaveFileName(this);
}
void MainWindow::tmpGo() {
    //QWidget *wid=new QWidget();
    QString f=ui->txtFileName->text();
    const char *m=f.toLatin1().data();
    TestScreen *tst=new TestScreen();
    printf("mah stuff: %s\n",m);
    tst->giveFileArg(&m);
    ////Ui::testscUI bi;
    ////bi.setupUi(wid);
    tst->show();



}
MainWindow::~MainWindow()
{
    delete ui;
}
