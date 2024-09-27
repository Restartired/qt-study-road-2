#include "mainwindow.h"
#include "customwidget.h"
#include <QTextEdit>
#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // CustomWidget cw = CustomWidget(this);//笑死，居然犯了这么低级的错误，在栈上创建，
    // 出了这个MainWindow的构造函数作用域直接就把cw给析构了，所以才不会显示。

    CustomWidget *cw = new CustomWidget(nullptr);
    cw->setAttribute(Qt::WA_DeleteOnClose);
    cw->setWindowTitle("CustomWidget");
    cw->show();

    // CustomWidget *cw = new CustomWidget(this);

    // QPushButton *b1 = new QPushButton(cw);
    // b1->setText(tr("Button1"));

    // QPushButton *b2 = new QPushButton(cw);
    // b2->setText(tr("Button2"));

    // QTextEdit *textEdit = new QTextEdit(cw);
    // connect(textEdit, &QTextEdit::textChanged, [=]() {
    //     this->setWindowModified(true);
    // });
    // setWindowTitle("TextPad [*]");

    // QVBoxLayout *widgetLayout = new QVBoxLayout(cw);//布局
    // widgetLayout->addWidget(b1);
    // widgetLayout->addWidget(b2);
    // widgetLayout->addWidget(textEdit);

    // this->setCentralWidget(cw);


    //总结：
    //1：如果widget里面没有任何一个组件，那么如果以mainwindow为父组件，就不会显示出来。

    //2：组件会影响event()事件，接收了信号但没有继续传递给父组件widget。
    //如果单独创建b1在widget里面的话，会吞掉空格键的event()信号，
    //因为空格可能被QT或者Windows设置成了一种触发，这里就是触发了点击Button的效果。

    //如果创建两个Button，b1和b2；那么这次连Tab的信号也被吞掉了，
    //因为Tab被设置成了，切换焦点，在两个Button组件之间来回切换。

    //如果再创建了一个TextEdit的话，当焦点不在TextEdit里面的时候，
    //可显示字符（就是数字字母字符等等）的信号都没有被吞，而焦点在TextEdit的话，就被当成字符输入。

    //3：有时候不显示Keyevent，是因为被app的全局快捷键拦截了，就像添加这三个组件一样。
}

MainWindow::~MainWindow() {}
