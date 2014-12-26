#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtGui/QMainWindow> qt4
//#include <QtGui/QPushButton>
//For Qt5
#include <QPushButton>//For Qt5
#include <QFileDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void browseFile();
    void newFile();
private:
    Ui::MainWindow *ui;
    //QPushButton *browseButton;
};

#endif // MAINWINDOW_H
