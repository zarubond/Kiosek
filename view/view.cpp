#include "view.h"

#include "../screen.h"
View::View(Screen *screen, QObject *parent) :
    QObject(parent),screen(screen)
{
    head=screen->head();
}

void View::enter(QObject *, QObject *)
{

}

void View::leave()
{

}
