#include "infoview.h"

InfoView::InfoView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}

const char *InfoView::content()
{
    return "info.qml";
}

const char *InfoView::menu()
{
    return "infoMenu.qml";
}

void InfoView::enter(QObject *content,QObject * menu)
{
    QObject * item=menu->findChild<QObject*>("diett_button");
    connect(item,SIGNAL(clicked()),this,SLOT(showDiet()));
    item=menu->findChild<QObject*>("about_button");
    connect(item,SIGNAL(clicked()),this,SLOT(showAbout()));

    diet=content->findChild<QObject*>("diet_page");
    about=content->findChild<QObject*>("about_page");
}

void InfoView::showAbout()
{
    diet->setProperty("visible",false);
    about->setProperty("visible",true);
}

void InfoView::showDiet()
{
    about->setProperty("visible",false);
    diet->setProperty("visible",true);

}
