#include "mainwindow.h"
#include "useragedialog.h"
#include "dialogmanager.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Main Window"));

    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open an existing file"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    QToolBar *toolBar2 = addToolBar(tr("Tool Bar 2"));
    toolBar2->addAction(openAction);

    // 添加一个 QLabel 用于显示用户年龄
    ageLabel = new QLabel(tr("User Age: N/A"));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(ageLabel);

    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);


    statusBar() ;
}

MainWindow::~MainWindow() {}

void MainWindow::setUserAge(const int &age){
    // userAge = age;
    ageLabel->setText(tr("User Age: %1").arg(age));
}

void MainWindow::showUserAgeDialog()
{
    UserAgeDialog *dialog = new UserAgeDialog(nullptr);
    QObject::connect(dialog, &QDialog::finished, [=]() {
        // UserAgeDialog* dialog = qobject_cast<UserAgeDialog *>(sender());
        // if (sender()){
        //     DialogManager::instance().closeDialog(dialog);
        // }
        DialogManager::instance().closeDialog(dialog);
    });

    // UserAgeDialog *dialog = new UserAgeDialog(nullptr);
    // UserAgeDialog dialog(this);//模态对话框阻塞，exec()有返回值，简单。但非模态show()就要用信号槽了。
    // if (dialog.exec() == QDialog::Accepted) {
    //     int userAge = dialog.getUserAge();
    //     QMessageBox::information(this, tr("User Age"), tr("User age is: %1").arg(userAge));
    // } else{
    //     qDebug() << "Dialog rejected";
    // }

    QObject::connect(dialog, &UserAgeDialog::userAgeChanged, this, &MainWindow::setUserAge);
    // dialog->setAttribute(Qt::WA_DeleteOnClose);//关闭对话框时销毁，防止内存泄漏。
    DialogManager::instance().openDialog(dialog);
    // dialog->show();
}

void MainWindow::open()
{
    //栈：
    // QDialog dialog(nullptr);
    // // QDialog dialog(this);
    // dialog.setWindowTitle(tr("Hello, dialog!"));
    // // dialog.show();
    // dialog.exec();
    // qDebug() << dialog.result();

    //堆：（主要问题是exec()阻塞后释放对象dialog后，result()找不到对象而崩溃的问题。）
    // // QDialog *dialog = new QDialog(0);
    // // dialog->setAttribute(Qt::WA_DeleteOnClose);//搭配exec()阻塞后删除会崩溃~
    // QDialog *dialog = new QDialog(this);//这就是所谓的用 parent 指针的方式构建对话框，
    // // 避免设置WA_DeleteOnClose属性。不过当我们将主窗口作为 parent 时，主窗口不关闭，
    // // 对话框就不会被销毁，所以会一直占用内存。
    // dialog->setWindowTitle(tr("Hello, dialog!"));
    // // dialog->show();
    // dialog->exec();
    // qDebug() << dialog->result();


    // 连接对话框的 finished 信号到一个 lambda 槽
    // QObject::connect(dialog, &QDialog::finished, this, [dialog]() {
    //     if (dialog->result() == QDialog::Accepted) {
    //         qDebug() << "Dialog accepted";
    //     } else {
    //         qDebug() << "Dialog rejected";
    //     }
    // });

    MainWindow::showUserAgeDialog();

}
