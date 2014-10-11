#include "head.h"

#ifdef Q_OS_WIN
HWND m_hWnd;
HWND apphwnd;
#endif

bool second;

Head::Head(QObject *parent) :
    QObject(parent)
{
    socket=new QTcpSocket(this);
    connect(socket,SIGNAL(connected()),this,SLOT(connected()));
    connect(socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));
#ifdef QT_DEBUG
    second=true;
#else
    second=true;
#endif

    status=true;
}

Head::~Head()
{
#ifdef Q_OS_WIN
    // HACK gives unknown error
    //TerminateProcess(handle,0);
    ::SetParent(apphwnd,NULL);
    send("<act><quit/></act>");
#endif
    socket->close();
    delete socket;
}

#ifdef Q_OS_WIN
void Head::setup(HWND win)
{
    m_hWnd=(HWND)win;
}
#endif

void Head::speak(const QString &text)
{
    if(!status) return;
    QString str="<speak>";
    str+=text;
    str+="</speak>";
    send(str);
}

void Head::send(const QString &command)
{
    QByteArray data=command.toUtf8().constData();
    data.append('\0');
#ifdef Q_OS_WIN
    if(socket->isOpen())
    {
        socket->write(data);
        socket->flush();
    }
#endif
}

void Head::stop()
{
    QString str="<act><stop/></act>";
    send(str);
}

void Head::resize(int w, int h)
{
    this->w=w;
    this->h=h;
#ifdef Q_OS_WIN
    ::MoveWindow(apphwnd, x, y, w, h, true);
#endif
}

void Head::setPosition(int x, int y)
{
    this->x=x;
    this->y=y;
#ifdef Q_OS_WIN
    ::MoveWindow(apphwnd, x, y, w, h, true);
#endif
}

void Head::switchSound(bool status)
{
    if(status==false)
        stop();
    this->status=status;
}

bool Head::soundStatus()
{
    return status;
}

bool Head::start()
{
#ifdef Q_OS_WIN
    //QString file="C:\\Documents and Settings\\suvl suvl\\Plocha\\NUR\\head\\Talking_head_rel_emb.exe";
    QString file="head\\Talking_head_rel_emb.exe";
    QString args=" p v 40000 >> out.txt 2>&1";
    handle=StartNewProcess(file, args);
    //handle=StartNewProcess(TEXT("C:\\Documents and Settings\\suvl suvl\\Plocha\\NUR\\head\\Talking_head_rel_emb.exe")
      //                   ,TEXT(" p v 40000 >> out.txt 2>&1"));
   // handle=StartNewProcess(TEXT("C:\\windows\\notepad.exe")
     //                        ,NULL);

    QString ip="127.0.0.1";
    int port=6222;

    if(handle!=NULL)
    {
        socket->abort();
        socket->connectToHost(ip,port);
        return true;
    }
#endif

    return false;
}

void Head::close()
{

}

void Head::error(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        qDebug()<<"Error";
        break;
    case QAbstractSocket::HostNotFoundError:
        qDebug()<<"The host was not found. Please check the "
                                    "host name and port settings.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        qDebug()<<"The connection was refused by the peer. "
                                    "Make sure the server is running, "
                                    "and check that the host name and port "
                                    "settings are correct.";
        break;
    default:
        qDebug()<<QString("The following error occurred: %1.").arg(socket->errorString());
    }

    disconnect();
}

void Head::readyRead()
{
    QByteArray data = socket->readAll();
    QString str=data;
    /*
    ui->log_text->appendPlainText(str);
    if(sending)
    {
        if(message_id<0)
        {
            message_id=str.toInt();
        }
        else if(message_id==str.toInt())
        {
            message_id=-1;
            sending=false;
            ui->send_button->setEnabled(true);
        }
        else
            qDebug()<<"error";
    }*/
}

void Head::connected()
{
    /*
    QString url=":> connected to ";
    url+=ui->address_ip->text();
    url+=":";
    url+=ui->address_port->text();
    ui->log_text->appendPlainText(url);
    ui->disconnect_button->setEnabled(true);
    ui->send_button->setEnabled(true);*/
}

void Head::disconnect()
{
    socket->close();
}

void Head::disconnected()
{/*
    ui->disconnect_button->setEnabled(false);
    ui->send_button->setEnabled(false);
    ui->connect_button->setEnabled(true);
    ui->address_ip->setEnabled(true);
    ui->address_port->setEnabled(true);
    ui->log_text->appendPlainText(":> disconnected");*/
}

//http://www.codeproject.com/Articles/18724/Hosting-exe-applications-into-a-dialog
#ifdef Q_OS_WIN
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{

    DWORD pID;
    DWORD TpID = GetWindowThreadProcessId(hwnd, &pID);
    //ECAF
    wchar_t name[512];
    GetWindowText(hwnd,name,512);
    if (TpID == (DWORD)lParam && wcsstr(name,L"ECAF")!=NULL)
    {
            apphwnd=hwnd;
            LONG style=GetWindowLong(apphwnd,GWL_STYLE);
            style = (style & ~(WS_POPUP) & ~(WS_CAPTION)) & ~(WS_THICKFRAME) | WS_CHILD;

            ::SetParent(apphwnd,m_hWnd);

            ::MoveWindow(apphwnd, Head::x, Head::y,Head::w, Head::h, true);
            Head::x=0;
            Head::y=0;
            Head::w=300;
            Head::h=300;
            ::SetWindowLong(apphwnd, GWL_STYLE,style);
            ::ShowWindow(apphwnd, SW_SHOW);
            //::MoveWindow(apphwnd, rect.left, rect.top,rect.right, rect.bottom, true);
        return false;
    }
    else if (TpID == (DWORD)lParam) second=true;

    return true;
}

HANDLE Head::StartNewProcess(QString & program, QString & args)
{
    QFileInfo info(program);
    if(!info.exists())
    {
        std::cerr<<"Unable to find head program: "<<info.absoluteFilePath().toUtf8().constData()<<std::endl;
        return NULL;
    }
    HANDLE hProcess = NULL;
    PROCESS_INFORMATION processInfo;
    STARTUPINFO startupInfo;
    ::ZeroMemory(&startupInfo, sizeof(startupInfo));
    ::ZeroMemory( &processInfo, sizeof(processInfo) );
    startupInfo.cb = sizeof(startupInfo);

    QString program_t=info.absoluteFilePath().replace(QString("/"),QString("\\\\"));
    QString dir_t=info.absolutePath().replace(QString("/"),QString("\\\\"));
    QString args_t=args;
    //LPCTSTR args_t=TEXT(" p v 40000 >> out.txt 2>&1");

    if(::CreateProcess((LPCTSTR)program_t.utf16(), (LPTSTR)args_t.utf16(),
                                NULL,  // process security
                                NULL,  // thread security
                                FALSE, // no inheritance
                                0,     // no startup flags
                                NULL,  // no special environment
                                (LPCTSTR)dir_t.utf16(),  // default startup directory
                                &startupInfo,
                                &processInfo))
    { /* success */
        Sleep(5000);//wait for the window of exe application created
        ::EnumWindows(&EnumWindowsProc, processInfo.dwThreadId);
        hProcess = processInfo.hProcess;
    }
    else
    {
        std::cout<<"Unable to start head"<<std::endl;
    }
    return hProcess;//Return HANDLE of process.
}
#endif

int Head::x=-100;
int Head::y=-100;
int Head::w=300;
int Head::h=300;

