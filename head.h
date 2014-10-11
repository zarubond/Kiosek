#ifndef HEAD_H
#define HEAD_H

#include <QObject>
#include <QAbstractSocket>

#include <QTcpSocket>
#include <QWindow>
#include <QDir>

#include <QTcpSocket>
#include <QString>
#include <QFileInfo>
#include <iostream>

#ifdef Q_OS_WIN
#include <windef.h>
#include <windows.h>
#include <tchar.h>
#endif

class Head : public QObject
{
    Q_OBJECT
public:
    explicit Head(QObject *parent = 0);
    ~Head();
#ifdef Q_OS_WIN
    void setup(HWND win);
#endif

    void speak(const QString &text);
    void send(const QString & command);
    void stop();

    void resize(int w,int h);
    void setPosition(int x,int y);
    void switchSound(bool status);
    bool soundStatus();

    bool start();
    void close();

    static int x,y,w,h;

signals:

public slots:
private slots:
    void error(QAbstractSocket::SocketError socketError);
    void connected();
    void readyRead();
    void disconnect();
    void disconnected();
private:
    bool status;
#ifdef Q_OS_WIN
    HANDLE StartNewProcess(QString &program, QString &args);
    HANDLE handle;
#endif
    QTcpSocket * socket;

};

#endif // HEAD_H
