#ifndef INTRO_H
#define INTRO_H

#include <QObject>

#include <QQuickItem>

#include "view/view.h"

class Kiosek;

class Intro : public QObject
{
    Q_OBJECT
public:
    explicit Intro(Kiosek * kiosek,QObject *parent = 0);
    void load(QObject *item);
    void unload();
signals:
    void switchToScreen();
public slots:
    void showEnter();
    void showLogin();
private:
    Kiosek * kiosek;
};

#endif // INTRO_H
