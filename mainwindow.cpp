#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnBrowse,SIGNAL(released()),this,SLOT(browseFile()));
    connect(ui->btnNewCard,SIGNAL(released()),this,SLOT(newFile()));
}
void MainWindow::browseFile() {
    QString file=QFileDialog::getOpenFileName(this,tr("Open Image"), "/", tr("Image Files (*.qcard)"));
    ui->txtFileName->setText(file);
}
void MainWindow::newFile() {
    QString file=QFileDialog::getSaveFileName(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
