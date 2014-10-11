#include "homeview.h"
#include "../screen.h"
HomeView::HomeView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}

const char *HomeView::content()
{
    return "home.qml";
}

const char *HomeView::menu()
{
    return "homeMenu.qml";
}

void HomeView::enter(QObject *content,QObject * menu)
{
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
    connect(item,SIGNAL(clicked()),this,SLOT(goDiet()));
    item=menu->findChild<QObject*>("history_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goHistory()));

    if(screen->isLogged())
        head->speak("Welcome. Now, you can create or check your personal menu and send it to your email address. \
                    If you want to check meals for today, have a look into today\'s menu. Or find the nearest canteen in a map. \
                    If you are interested in a healthy diet, check info.");
    else
        head->speak("Welcome. For creating your personal menu, log in please. \
                    If you want to check meals for today, have a look into today\' menu. \
                Or find the nearest canteen in a map. If you are interested in a healthy diet, check info.");
}

void HomeView::leave()
{
    head->stop();
}

void HomeView::goMealToday()
{
    screen->switchView(screen->meal_today);
}

void HomeView::goLogin()
{
    screen->switchView(screen->login);
}

void HomeView::goInfo()
{
    screen->switchView(screen->info);
}

void HomeView::goMap()
{
    screen->switchView(screen->map);
}

void HomeView::goMeal()
{
    screen->switchView(screen->meal_today);
}

void HomeView::goDiet()
{
    screen->switchView(screen->mymeal);
}

void HomeView::goHistory()
{
    screen->switchView(screen->history);
}
