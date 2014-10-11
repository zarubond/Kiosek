#ifndef HISTORYVIEW_H
#define HISTORYVIEW_H

#include "view.h"

class HistoryView : public View
{
    Q_OBJECT
public:
    explicit HistoryView(Screen * screen,QObject *parent = 0);

    void enter(QObject *content, QObject *menu);
    void leave();
    const char *menu();
    const char *content();
signals:

public slots:
private:

};

#endif // HISTORYVIEW_H
