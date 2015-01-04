#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_testscreen.h"
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
    QWidget *wid=new QWidget;
    Ui::Form bi;
    bi.setupUi(wid);
    wid->show();
    bi.openGLWidget->sayVal();
    bi.openGLWidget->setVal();
    bi.openGLWidget->sayVal();
}
MainWindow::~MainWindow()
{
    delete ui;
}
