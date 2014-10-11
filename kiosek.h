#ifndef KIOSEK_H
#define KIOSEK_H


#include "qtquick2applicationviewer.h"
#include <QCoreApplication>
#include <QFileInfo>
#include <iostream>

#include "head.h"
#include "intro.h"
#include "screen.h"


class Kiosek: public QtQuick2ApplicationViewer
{
    Q_OBJECT
public:
    Kiosek();
    ~Kiosek();
    void load();
    void keyPressEvent(QKeyEvent *key);

    Intro * intro;
    Screen * screen;
    Head * head;

    void switchToScreen(View * view);
    void switchToIntro();
    bool login();
    void logout();
    bool isLogged();
    void resizeEvent(QResizeEvent * ev);

private:
    void openQml(const QString &path);



public slots:
    void qmlLoaded();
private slots:
    void statuss(QQuickView::Status status);
private:
   // QtQuick2ApplicationViewer viewer;

    QObject * loader,*root;
    View *tmp_view;
    bool logged;

    QString adjustPath(const QString &path);
    bool intro_switch;
};

#endif // KIOSEK_H
