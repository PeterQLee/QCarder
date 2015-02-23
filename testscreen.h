#ifndef TESTSCREEN_H
#define TESTSCREEN_H


#include <QWidget>
namespace Ui {
class TestScreen;
}
class TestScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TestScreen(QWidget *parent = 0);
    ~TestScreen();
    void giveFileArg(const char **m);
signals:

public slots:

private:
    Ui::TestScreen *ui;
};

#endif // TESTSCREEN_H
