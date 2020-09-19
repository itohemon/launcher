#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_ssh_clicked();

    void on_pushButton_rviz_clicked();

    void on_pushButton_rd_clicked();

    void subFunction();

    void on_pushButton_commit_clicked();

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
