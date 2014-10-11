#ifndef MEALTODAYVIEW_H
#define MEALTODAYVIEW_H

#include "view.h"
#include <iostream>

class MealTodayView: public View
{
    Q_OBJECT
public:
    MealTodayView(Screen * screen,QObject *parent = 0);
    const char * content();
    const char * menu();
    void enter(QObject * content,QObject * menu);
    void leave();
public slots:
    void showStud();
    void showStrahov();
    void showMasaryk();
    void showt();
    void showk();
    void showp();
private:
    QObject * list_view,*dum_model,*strahov_model,*masarik_model;
    QObject * current;
    QObject * smenu;
};

#endif // MEALTODAYVIEW_H
