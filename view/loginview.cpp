#include "loginview.h"

#include "../screen.h"

LoginView::LoginView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}

const char *LoginView::content()
{
    return "login.qml";
}

const char *LoginView::menu()
{
    return "loginMenu.qml";
}

void LoginView::enter(QObject *content,QObject * menu)
{
    QObject * item=content->findChild<QObject*>("login_button");
    connect(item,SIGNAL(clicked()),this,SLOT(login()));
    /*
    item=menu->findChild<QObject*>("login_button");
    connect(item,SIGNAL(clicked()),this,SLOT(goLogin()));*/

    head->speak("Log in by filling your credentials in or use your isic card.");
}

void LoginView::leave()
{
    head->stop();
}

void LoginView::login()
{
    screen->loginTo();
}
