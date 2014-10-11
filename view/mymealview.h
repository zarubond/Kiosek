#ifndef MYMEALVIEW_H
#define MYMEALVIEW_H

#include "view.h"

class MyMealView : public View
{
    Q_OBJECT
public:
    explicit MyMealView(Screen * screen,QObject *parent = 0);

    const char *content();
    const char *menu();
    void enter(QObject *content, QObject *menu);
    void leave();
signals:

public slots:
    void changeFri();
    void changeThur();
private:

};

#endif // MYMEALVIEW_H
