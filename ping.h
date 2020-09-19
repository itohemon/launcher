#ifndef PING_H
#define PING_H

#include <QObject>
#include "mainwindow.h"

class Ping : public QObject
{
    Q_OBJECT
private:
    QTabWidget *tab;

public:
    Ping(QTabWidget *tab);

signals:
    void processEnd();

public slots:
    void process();

};

#endif // PING_H
