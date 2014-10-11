#include "mealtodayview.h"


#include "../screen.h"
MealTodayView::MealTodayView(Screen * screen,QObject *parent):
    View(screen,parent)
{
}

const char *MealTodayView::content()
{
    return "mealtoday.qml";
}

const char *MealTodayView::menu()
{
    return "mealtodaymenu.qml";
}

void MealTodayView::enter(QObject *content, QObject *menu)
{
    list_view=content->findChild<QObject*>("list_view");
    dum_model=content->findChild<QObject*>("dum_model");
    masarik_model=content->findChild<QObject*>("masarik_model");
    strahov_model=content->findChild<QObject*>("strahov_model");

    QObject * item=menu->findChild<QObject*>("stud_dum");
    current=item;
    connect(item,SIGNAL(clicked()),this,SLOT(showStud()));
    item=menu->findChild<QObject*>("strahov");
    connect(item,SIGNAL(clicked()),this,SLOT(showStrahov()));
    item=menu->findChild<QObject*>("masarik");
    connect(item,SIGNAL(clicked()),this,SLOT(showMasaryk()));

    item=menu->findChild<QObject*>("technicka");
    connect(item,SIGNAL(clicked()),this,SLOT(showt()));
    item=menu->findChild<QObject*>("karlovka");
    connect(item,SIGNAL(clicked()),this,SLOT(showk()));
    item=menu->findChild<QObject*>("podoli");
    connect(item,SIGNAL(clicked()),this,SLOT(showp()));

    this->smenu=menu;

    if(screen->isLogged())
        head->speak("Choose your favorite canteen and then check what meals they prepared for you today. \
                    You can add meals to your personal menu.");
    else
        head->speak("Choose your favorite canteen and then check which meals they prepared for you today.");
}

void MealTodayView::leave()
{
    head->stop();
}

void MealTodayView::showStud()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("stud_dum");
    current->setProperty("underline",true);
    list_view->setProperty("model",QVariant::fromValue(dum_model));
}

void MealTodayView::showStrahov()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("strahov");
    current->setProperty("underline",true);
    list_view->setProperty("model",QVariant::fromValue(strahov_model));
}

void MealTodayView::showMasaryk()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("masarik");
    current->setProperty("underline",true);
    list_view->setProperty("model",QVariant::fromValue(masarik_model));
}

void MealTodayView::showt()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("technicka");
    current->setProperty("underline",true);
}

void MealTodayView::showk()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("karlovka");
    current->setProperty("underline",true);
}

void MealTodayView::showp()
{
    current->setProperty("underline",false);
    current=smenu->findChild<QObject*>("podoli");
    current->setProperty("underline",true);
}
