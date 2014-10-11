#ifndef MAPVIEW_H
#define MAPVIEW_H

#include "view.h"

class MapView: public View
{
    Q_OBJECT
public:
    MapView(Screen * screen,QObject *parent = 0);
    const char *content();
    const char *menu();
    void enter(QObject * content,QObject * menu);
    void leave();

private:
};

#endif // MAPVIEW_H
