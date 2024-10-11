#ifndef CLIPBOARDDEMO_H
#define CLIPBOARDDEMO_H

#include <QWidget>
#include <QTextEdit>

class ClipboardDemo : public QWidget
{
    Q_OBJECT
public:
    ClipboardDemo(QWidget *parent = 0);
private slots:
    void setClipboardContent();
    void getClipboardContent();
private:
    QTextEdit *editor;
};

#endif // CLIPBOARDDEMO_H
