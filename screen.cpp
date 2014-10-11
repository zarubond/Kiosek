#include "screen.h"

#include "kiosek.h"


Screen::Screen(Kiosek *kiosek, QObject *parent) :
    QObject(parent),kiosek(kiosek)
{
    login=new LoginView(this);
    map=new MapView(this);
    meal_today=new MealTodayView(this);
    home=new HomeView(this);
    info=new InfoView(this);
    mymeal=new MyMealView(this);
    setup=new SetupView(this);
    history=new HistoryView(this);
    loaded_num=0;
    current_view=NULL;
}

Screen::~Screen()
{
    delete login;
    delete map;
    delete meal_today;
    delete home;
    delete info;
    delete mymeal;
    delete setup;
    delete history;
}

void Screen::load(QObject *root)
{
    this->root=root;
    content_loader=item("contentLoader");
    menu_loader=item("menuLoader");
    connect(content_loader,SIGNAL(loaded()),this,SLOT(loaded()));
    connect(menu_loader,SIGNAL(loaded()),this,SLOT(loaded()));
    connect(item("back_button"),SIGNAL(clicked()),this,SLOT(goBack()));
    connect(item("home_button"),SIGNAL(clicked()),this,SLOT(goHome()));
    connect(item("sound_button"),SIGNAL(clicked()),this,SLOT(switchSound()));
    connect(item("lock_button"),SIGNAL(clicked()),this,SLOT(lock()));
/*
    if(head()->soundStatus())
        item("sound_button")->setProperty("source","./img/audio-on.png");
    else
        item("sound_button")->setProperty("source","./img/audio-off.png");*/
}

void Screen::openView(View * view)
{
    if(current_view!=NULL)
        current_view->leave();
    current_view=view;
    loaded_num=0;

    QVariant returnedValue;
    QVariant msg(view->content());
    QMetaObject::invokeMethod(content_loader, "openView",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, msg));

    msg=view->menu();
    QMetaObject::invokeMethod(menu_loader, "openView",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, msg));
}

QObject *Screen::item(const char * name)
{
    return root->findChild<QObject*>(name);
}

void Screen::unload()
{

}

void Screen::switchView(View *view)
{
    if(current_view!=view)
        openView(view);
}

void Screen::loginTo()
{
    if(kiosek->login())
        goHome();
}

void Screen::logoutTo()
{
    kiosek->logout();
    goIntro();
}

bool Screen::isLogged()
{
    return kiosek->isLogged();
}

Head *Screen::head()
{
    return kiosek->head;
}

void Screen::goBack()
{
    if(page_stack.size()>1)
    {
        if(current_view==home)
        {
            goIntro();
        }
        else
        {
            page_stack.pop();
            switchView(page_stack.top());
        }
    }
    else
        goIntro();
}

void Screen::goHome()
{
    if(current_view!=home)
    {
        page_stack.clear();
        switchView(home);
    }
    else
    {
        goIntro();
    }
}

void Screen::switchSound()
{
    head()->switchSound(!head()->soundStatus());
    QVariant returnedValue;
    QVariant msg = head()->soundStatus();
    QMetaObject::invokeMethod(item("sound_button"), "switchSound",
            Q_RETURN_ARG(QVariant, returnedValue),
            Q_ARG(QVariant, msg));
}

void Screen::goIntro()
{
    current_view=NULL;
    page_stack.clear();
    kiosek->switchToIntro();
}

void Screen::loaded()
{
    loaded_num++;
    if(loaded_num==2)
    {
        page_stack.push(current_view);
        current_view->enter(content_loader,menu_loader);
        loaded_num=0;
    }
}

void Screen::lock()
{
    if(kiosek->isLogged())
    {
        kiosek->logout();
        goIntro();
    }
    else
    {
        switchView(login);
    }
}
