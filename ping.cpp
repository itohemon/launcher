#include "ping.h"
#include <unistd.h>
#include <QProcess>
#include <QTabWidget>
#include <QDebug>

Ping::Ping(QTabWidget *tab)
{
    this->tab = tab;
}

void Ping::process()
{
    QString countOpt = "-c";
    QString pingCount = "1";
    QString timeoutOpt = "-w";
    QString pingWaitTimeSec = "1";
    QString host[2] = {"192.168.1.1", "127.0.0.1"};
    QProcess *pingProcess = new QProcess();
    while (1)
    {
        for (int i = 0; i < 2; i++)
        {
            int exitCode = pingProcess->execute("ping",
                                                QStringList () << host[i]
                                                << countOpt << pingCount
                                                << timeoutOpt << pingWaitTimeSec);
            if (exitCode == 0)
            {
                tab->setTabIcon(i, QIcon("/home/itohemon/launcher/green.png"));
            }
            else
            {
                tab->setTabIcon(i, QIcon("/home/itohemon/launcher/red.png"));
            }
        }
        sleep(1);
    }

    emit this->processEnd();
}
