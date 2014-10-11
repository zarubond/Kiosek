#ifndef INFOVIEW_H
#define INFOVIEW_H

#include "view.h"
#include <iostream>

class InfoView : public View
{
    Q_OBJECT
public:
    explicit InfoView(Screen * screen,QObject *parent = 0);

    const char *content();
    const char *menu();
    void enter(QObject *content, QObject *menu);
signals:

private slots:
    void showAbout();
    void showDiet();
private:
    QObject * diet,*about;
};

#endif // INFOVIEW_H
