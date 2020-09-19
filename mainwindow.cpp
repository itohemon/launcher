#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ping.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QThread *pingThread = new QThread();
    Ping *ping = new Ping(ui->tabWidget);

    ping->moveToThread(pingThread);

    connect(pingThread, SIGNAL(started()), ping, SLOT(process()));
    connect(ping, SIGNAL(processEnd()), pingThread, SLOT(quit()));
    connect(ping, SIGNAL(processEnd()), ping, SLOT(deleteLater()));
    connect(pingThread, SIGNAL(finished()), pingThread, SLOT(deleteLater()));

    pingThread->start();
}

void MainWindow::subFunction()
{

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_ssh_clicked()
{
    subFunction();
}

void MainWindow::on_pushButton_rviz_clicked()
{
    subFunction();
}

void MainWindow::on_pushButton_rd_clicked()
{
    subFunction();
}


void MainWindow::on_pushButton_commit_clicked()
{

}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    /*
    for (int i = 0; i < ui->tabWidget->count(); i++) {
        if (i == index) {
            ui->tabWidget->setTabIcon(i, QIcon("/home/itohemon/launcher/green.png"));
        } else {
            ui->tabWidget->setTabIcon(i, QIcon("/home/itohemon/launcher/red.png"));
        }
    }
    */
}

void ping_typeA()
{

}
