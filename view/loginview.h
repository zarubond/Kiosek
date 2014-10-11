#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include "view.h"
class LoginView : public View
{
    Q_OBJECT
public:
    explicit LoginView(Screen * screen,QObject *parent = 0);
    const char *content();
    const char *menu();


    void enter(QObject *content, QObject *menu);
    void leave();
signals:

public slots:
    void login();
private:

};

#endif // LOGINVIEW_H
