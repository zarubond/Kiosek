#include "historyview.h"

HistoryView::HistoryView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}

const char *HistoryView::content()
{
    return "history.qml";
}

const char *HistoryView::menu()
{
    return "historyMenu.qml";
}

void HistoryView::enter(QObject *content,QObject * menu)
{/*
    QObject * item=menu->findChild<QObject*>("meal_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goMealToday()));
    item=menu->findChild<QObject*>("login_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goLogin()));
    item=menu->findChild<QObject*>("info_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goInfo()));
    item=menu->findChild<QObject*>("map_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goMap()));
    item=menu->findChild<QObject*>("meal_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goMeal()));
    item=menu->findChild<QObject*>("diet_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goDiet()));*/
    head->speak("As you can see, you ve been eating too much fats in last month.\
                You should change your diet. See info about healthy food, please.");
}

void HistoryView::leave()
{
    head->stop();
}
