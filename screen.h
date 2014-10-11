#ifndef SCREEN_H
#define SCREEN_H

#include <QObject>
#include <QVariant>
#include <QUrl>
#include <QStack>

#include "view/loginview.h"
#include "view/mapview.h"
#include "view/mealtodayview.h"
#include "view/homeview.h"
#include "view/mymealview.h"
#include "view/infoview.h"
#include "view/setupview.h"
#include "view/historyview.h"

class Kiosek;

class Screen : public QObject
{
    Q_OBJECT
public:
    explicit Screen(Kiosek * kiosek,QObject *parent = 0);

    void load(QObject *root);
    void unload();
    void switchView(View * view);
    void loginTo();
    void logoutTo();
    bool isLogged();
    Head * head();

    LoginView * login;
    MapView * map;
    MealTodayView * meal_today;
    HomeView * home;
    InfoView * info;
    MyMealView * mymeal;
    SetupView * setup;
    HistoryView * history;

    ~Screen();
public slots:

    void goBack();
    void goIntro();
    void goHome();
    void switchSound();

private slots:
    void loaded();
    void lock();
private:
    QObject *menu_loader,*content_loader;
    View * current_view;

    int loaded_num;
    void openView(View *view);
    QObject * item(const char * name);
    QObject * root;
    Kiosek * kiosek;
    QStack<View*> page_stack;
};

#endif // SCREEN_H
