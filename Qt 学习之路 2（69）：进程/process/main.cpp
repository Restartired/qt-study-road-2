// #include "mainwindow.h"

// #include <QApplication>
#include <QString>
#include <QProcess>
#include <QTextCodec>//逆天7.62不包含core5compat，所以换了7.63的Kit。
#include <QDebug>

int main(int argc, char *argv[])
{
    // QApplication a(argc, argv);
    // MainWindow w;
    // w.show();
    // return a.exec();

    //!!! Qt5
    QString program = "C:/Windows/System32/cmd.exe";
    QStringList arguments;
    arguments << "/c" << "dir" << "C:\\";
    QProcess *cmdProcess = new QProcess;
    QObject::connect(cmdProcess, &QProcess::readyRead, [=] () {
        QTextCodec *codec = QTextCodec::codecForName("GBK");
        QString dir = codec->toUnicode(cmdProcess->readAll());
        qDebug() << dir;
    });
    cmdProcess->start(program, arguments);

    cmdProcess->waitForFinished(-1);

    // qDebug() << "Exit code: " << cmdProcess->exitCode();

    return 0;
}
