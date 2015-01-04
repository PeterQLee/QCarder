#ifndef TMPSCREEN_H
#define TMPSCREEN_H
#include <QMainWindow>

namespace Ui {
class tmpScreen;
}

class tmpScreen : public QMainWindow//QWidget//MainWindow
{
    Q_OBJECT

public:
    explicit tmpScreen(QWidget *parent = 0);
    ~tmpScreen();
/*private slots:
    void browseFile();
    void newFile();*/
private:
    Ui::tmpScreen *bi;
    //QPushButton *browseButton;
};


#endif // TMPSCREEN_H
