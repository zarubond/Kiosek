#include "mymealview.h"

#include "../screen.h"

MyMealView::MyMealView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}


const char *MyMealView::content()
{
    return "mymeal.qml";
}

const char *MyMealView::menu()
{
    return "mymealMenu.qml";
}

void MyMealView::enter(QObject *content, QObject *menu)
{
    QObject * item=content->findChild<QObject*>("change_fri");
    connect(item,SIGNAL(clicked()),this,SLOT(changeFri()));

    item=content->findChild<QObject*>("change_thur");
    connect(item,SIGNAL(clicked()),this,SLOT(changeThur()));
    head->speak("If you are done with your personal menu, let me show you recommendations about healthy diet.\
                You can also send the list to your email address.");
}

void MyMealView::leave()
{
    head->stop();
}

void MyMealView::changeFri()
{
    screen->switchView(screen->meal_today);
}

void MyMealView::changeThur()
{
    screen->switchView(screen->meal_today);
}
