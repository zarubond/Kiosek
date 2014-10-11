#include "kiosek.h"

Kiosek::Kiosek()
{
    tmp_view=NULL;
    logged=false;
    root=NULL;

    head=new Head();
#ifdef Q_OS_WIN
    head->setup((HWND)winId());
#endif
    screen=new Screen(this);
    intro=new Intro(this);
}

Kiosek::~Kiosek()
{
    delete screen;
    delete intro;
    delete head;
}

void Kiosek::load()
{
    setWidth(800);
    setHeight(600);
    connect(this,SIGNAL(statusChanged(QQuickView::Status)),this,SLOT(statuss(QQuickView::Status)));
    setMainQmlFile(QStringLiteral("qml/kiosek/main.qml"));
    show();
    head->start();
    head->resize(300,300);
}

void Kiosek::openQml(const QString &path)
{
    QString new_path=adjustPath(path);

    QVariant returnedValue;
    QVariant msg(new_path);
    QMetaObject::invokeMethod(loader, "openView",
            Q_RETURN_ARG(QVariant, returnedValue),
                              Q_ARG(QVariant, msg));
}

void Kiosek::statuss(QQuickView::Status status)
{
    if(status==QQuickView::Ready && root==NULL)
    {
        loader = rootObject()->findChild<QObject*>("pageLoader");
        if(loader!=NULL)
            connect(loader,SIGNAL(loaded()),this,SLOT(qmlLoaded()),Qt::DirectConnection);
        else
            std::cout<<"error"<<std::endl;

        if(root==NULL)
        {
            root = rootObject();//->findChild<QObject*>("rootx");
            if(root==NULL)
                std::cout<<"error"<<std::endl;
        }

        switchToIntro();
        showExpanded();
    }
    else if(status==QQuickView::Error)
    {
        QList<QQmlError> list=errors();
        QList<QQmlError>::iterator i;
        for (i = list.begin(); i != list.end(); ++i)
            std::cout<< (*i).toString().toUtf8().constData() << std::endl;
    }
}


void Kiosek::switchToScreen(View *view)
{
    intro_switch=false;
    tmp_view=view;
    intro->unload();
    openQml("Screen.qml");

    QObject * item=rootObject()->findChild<QObject*>("head_rect");
    int w=item->property("width").toInt();
    int h=item->property("height").toInt();
    head->resize(w,h);
    int y=height();
    y-=h;
    head->setPosition(0,y);
}

void Kiosek::switchToIntro()
{
    logout();
    intro_switch=true;
    screen->unload();
    openQml("Intro.qml");

    head->resize(300,300);
    int h=height();
    int w=width();
    int x=(w-300)/2;
    int y=(h-300)/2;
    head->setPosition(x,y);
}

bool Kiosek::login()
{
    logged=true;
    root->setProperty("logged", true);
    return true;
}

void Kiosek::logout()
{
    if(root!=NULL)
    {
        logged=false;
        root->setProperty("logged", false);
    }
}

bool Kiosek::isLogged()
{
    return logged;
}

void Kiosek::resizeEvent(QResizeEvent *ev)
{
    QtQuick2ApplicationViewer::resizeEvent(ev);
    if(intro_switch)
    {
        head->resize(300,300);
        int h=ev->size().height();
        int w=ev->size().width();
        int x=(w-300)/2;
        int y=(h-300)/2;
        head->setPosition(x,y);
    }
    else
    {
        QObject * item=rootObject()->findChild<QObject*>("head_rect");
        int w=item->property("width").toInt();
        int h=item->property("height").toInt();
        head->resize(w,h);
        int y=ev->size().height();
        y-=h;
        head->setPosition(0,y);
    }
}

QString Kiosek::adjustPath(const QString &path)
{
#if defined(Q_OS_MAC)
    if (!QDir::isAbsolutePath(path))
        return QString::fromLatin1("%1/../Resources/%2")
                .arg(QCoreApplication::applicationDirPath(), path);
#elif defined(Q_OS_BLACKBERRY)
    if (!QDir::isAbsolutePath(path))
        return QString::fromLatin1("app/native/%1").arg(path);
#elif !defined(Q_OS_ANDROID)
    QString pathInInstallDir =
            QString::fromLatin1("%1/../%2").arg(QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return pathInInstallDir;
    pathInInstallDir =
            QString::fromLatin1("%1/%2").arg(QCoreApplication::applicationDirPath(), path);
    if (QFileInfo(pathInInstallDir).exists())
        return pathInInstallDir;
#endif
    return path;
}

void Kiosek::qmlLoaded()
{
    if(intro_switch==true)
        intro->load(rootObject());
    else
    {
        screen->load(rootObject());
        screen->switchView(tmp_view);
    }
}

void Kiosek::keyPressEvent(QKeyEvent * key)
{
    if(key->key()==Qt::Key_Escape)
        QCoreApplication::quit();
    else if(key->key()==Qt::Key_F11)
        showFullScreen();
    else
        QtQuick2ApplicationViewer::keyPressEvent(key);
}
