#include "mapview.h"

MapView::MapView(Screen * screen,QObject *parent):
     View(screen,parent)
{
}


const char *MapView::content()
{
    return "map.qml";
}

const char *MapView::menu()
{
    return "mapMenu.qml";
}

void MapView::enter(QObject *content, QObject *menu)
{
    head->speak("Pick a canteen and then check its menu by clicking on it.");
}

void MapView::leave()
{
    head->stop();
}
