#ifndef VIEW_H
#define VIEW_H

#include <QObject>

#include "./head.h"
class Screen;

class View : public QObject
{
    Q_OBJECT
public:
    explicit View(Screen * screen,QObject *parent = 0);
    virtual const char * content()=0;
    virtual const char * menu()=0;
    virtual void enter(QObject */*content*/,QObject */*menu*/);
    virtual void leave();


signals:

public slots:

protected:
    Screen * screen;
    Head * head;

};

#endif // VIEW_H
