#include "intro.h"

#include "kiosek.h"
#include "screen.h"

Intro::Intro(Kiosek *kiosek, QObject *parent) :
    QObject(parent),kiosek(kiosek)
{
}

void Intro::load(QObject *root)
{
    QObject * item=root->findChild<QObject*>("enter");
    if(item!=NULL) connect(item,SIGNAL(clicked()),this,SLOT(showEnter()));

    item=root->findChild<QObject*>("login");
    if(item!=NULL) connect(item,SIGNAL(clicked()),this,SLOT(showLogin()));

    //item=root->findChild<QObject*>("soundSwitch");
    //if(item!=NULL) connect(item,SIGNAL(clicked()),this,SLOT(soundSwitch()));
}

void Intro::unload()
{

}

void Intro::showEnter()
{
    kiosek->switchToScreen(kiosek->screen->home);
}

void Intro::showLogin()
{
    kiosek->switchToScreen(kiosek->screen->login);
}
/*
void Intro::soundSwitch()
{
    kiosek->head->switchSound(!kiosek->head->soundStatus());
}
*/
