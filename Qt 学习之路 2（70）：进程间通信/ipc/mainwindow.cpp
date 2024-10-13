#include "mainwindow.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QFileDialog>
#include <QBuffer>

const char *KEY_SHARED_MEMORY = "Shared";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      sharedMemory(new QSharedMemory(KEY_SHARED_MEMORY, this))
{
    QWidget *mainWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
    setCentralWidget(mainWidget);

    QPushButton *saveButton = new QPushButton(tr("Save"), this);
    mainLayout->addWidget(saveButton);

    QHBoxLayout *piclayout = new QHBoxLayout(this);
    piclayout->setDirection(QBoxLayout::LeftToRight);
    QLabel *picLabel1 = new QLabel(this);
    QLabel *picLabel2 = new QLabel(this);
    piclayout->addWidget(picLabel1);
    piclayout->addWidget(picLabel2);
    mainLayout->addLayout(piclayout);

    QPushButton *loadButton = new QPushButton(tr("Load"), this);
    mainLayout->addWidget(loadButton);

    connect(saveButton, &QPushButton::clicked, [=]() {
        if (sharedMemory->isAttached()) {
            sharedMemory->detach();
        }
        QString filename = QFileDialog::getOpenFileName(this);
        QPixmap pixmap(filename);
        picLabel1->setPixmap(pixmap);

        QBuffer buffer;
        QDataStream out(&buffer);
        buffer.open(QBuffer::ReadWrite);
        out << pixmap;

        int size = buffer.size();
        if (!sharedMemory->create(size)) {
            qDebug() << tr("Create Error: ") << sharedMemory->errorString();
        } else {
            sharedMemory->lock();
            char *to = static_cast<char *>(sharedMemory->data());
            const char *from = buffer.data().constData();
            memcpy(to, from, qMin(size, sharedMemory->size()));
            sharedMemory->unlock();
        }
    });

    connect(loadButton, &QPushButton::clicked, [=]() {
        if (sharedMemory->error()!=QSharedMemory::NoError) {
            qDebug() << tr("Attach Error: ") << sharedMemory->errorString();
        } else {
            QBuffer buffer;
            QDataStream in(&buffer);
            QPixmap pixmap;
            sharedMemory->lock();
            buffer.setData(static_cast<const char *>(sharedMemory->constData()), sharedMemory->size());
            buffer.open(QBuffer::ReadWrite);
            in >> pixmap;
            sharedMemory->unlock();
            sharedMemory->detach();
            picLabel2->setPixmap(pixmap);
        }
    });
}

MainWindow::~MainWindow() {}
