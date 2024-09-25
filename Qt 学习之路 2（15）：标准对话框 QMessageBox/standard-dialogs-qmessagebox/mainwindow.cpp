#include "mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // if (QMessageBox::Yes == QMessageBox::question(this,
    //                                               tr("Question"),
    //                                               tr("Are you OK?"),
    //                                               QMessageBox::Yes | QMessageBox::No,
    //                                               QMessageBox::Yes)) {
    //     QMessageBox::information(this, tr("Hmmm..."), tr("I'm glad to hear that!"));
    // } else {
    //     QMessageBox::information(this, tr("Hmmm..."), tr("I'm sorry!"));
    // }


    QMessageBox msgBox;
    msgBox.setText(tr("The document has been modified."));
    msgBox.setInformativeText(tr("Do you want to save your changes?"));
    msgBox.setDetailedText(tr("Differences here..."));
    msgBox.setStandardButtons(QMessageBox::Save
                              | QMessageBox::Discard
                              | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();
    switch (ret) {
    case QMessageBox::Save:
        qDebug() << "Save document!";
        break;
    case QMessageBox::Discard:
        qDebug() << "Discard changes!";
        break;
    case QMessageBox::Cancel:
        qDebug() << "Close document!";
        break;
    }
}

MainWindow::~MainWindow() {}
