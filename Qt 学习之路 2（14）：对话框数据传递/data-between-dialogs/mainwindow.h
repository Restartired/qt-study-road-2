#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <dialogmanager.h>
#include <QMainWindow>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void showUserAgeDialog();
    void setUserAge(const int &age);

private:
    void open();
    QAction *openAction;
    QLabel *ageLabel;
    // int userAge;//这个也是可以用其他组件替代，虽然初学根本不认识多少个组件笑死，随便搜了一个label。
};
#endif // MAINWINDOW_H
