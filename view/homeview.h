#ifndef HOMEVIEW_H
#define HOMEVIEW_H

#include <iostream>

#include "view.h"

class HomeView : public View
{
    Q_OBJECT
public:
    explicit HomeView(Screen * screen,QObject *parent = 0);
    const char *content();
    const char *menu();
    void enter(QObject *content, QObject *menu);
    void leave();

signals:

private slots:
    void goMealToday();
    void goLogin();
    void goInfo();
    void goMap();
    void goMeal();
    void goDiet();
    void goHistory();

};

#endif // HOMEVIEW_H
