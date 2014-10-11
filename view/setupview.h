#ifndef SETUPVIEW_H
#define SETUPVIEW_H

#include "view.h"
class SetupView : public View
{
    Q_OBJECT
public:
    explicit SetupView(Screen * screen,QObject *parent = 0);
    const char *content();
    const char *menu();
    void enter(QObject *content, QObject *menu);
signals:

public slots:

};

#endif // SETUPVIEW_H
