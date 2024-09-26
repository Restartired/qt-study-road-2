#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event);
    void closeEvent(QCloseEvent *event);

private slots:
    void openFile();
    void saveFile();

private:
    QAction *openAction;
    QAction *saveAction;
    QTextEdit *textEdit;
};
#endif // MAINWINDOW_H
