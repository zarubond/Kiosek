#include "setupview.h"

SetupView::SetupView(Screen *screen, QObject *parent) :
    View(screen,parent)
{
}

const char *SetupView::content()
{
    return "setup.qml";
}

const char *SetupView::menu()
{
    return "setupMenu.qml";
}

void SetupView::enter(QObject *content, QObject *menu)
{

}
