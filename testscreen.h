#ifndef TESTSCREEN_H
#define TESTSCREEN_H

#include <QWidget>

class TestScreen : public QWidget
{
    Q_OBJECT
public:
    explicit TestScreen(QWidget *parent = 0);
    ~TestScreen();

signals:

public slots:
};

#endif // TESTSCREEN_H
