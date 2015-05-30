#ifndef CREATESCREEN_H
#define CREATESCREEN_H

#include <QObject>
#include <QWidget>
#include "colordisplay.h"
namespace Ui {
class CreateScreen;
}
class CreateScreen :public QWidget

{
     Q_OBJECT
public:
    explicit CreateScreen(QWidget *parent=0);
    ~CreateScreen();
    void giveFileArg(char **m);
private:
    Ui::CreateScreen *ui;
private slots:
    void updateColor();
signals:
    void sendColor(int r, int g, int b);
};

#endif // CREATESCREEN_H
