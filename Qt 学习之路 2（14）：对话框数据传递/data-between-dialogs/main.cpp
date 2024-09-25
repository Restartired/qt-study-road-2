#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
//太爽了，卡了我一天了这个教程。
//请认真看：
// Qt 学习之路 2（5）：自定义信号槽：这里写了自定义信号槽的机制。
// Qt 学习之路 2（8）：添加动作：我这里懒得重写，所以复用了这里的widget。
// Qt 学习之路 2（13）：对话框简介：这里讲了模态和非模态对话框的区别，以及构建时候parent是this还是nullptr的区别。
// Qt 学习之路 2（14）：对话框数据传递：这就是本节内容，就是最后的模板太抽象了。看评论区多多少少提到怎么做了。

// 实现一个只能打开一个的非模态对话框（方法就是在对话框打开时在一个对话框映射表中记录下标记，
// 在对话框关闭时利用sender()函数判断是不是该对话框，然后从映射表中将其删除）。
// 这里我问了一下 GPT-3.5-Turbo ，不然写不出来。（也不知道写对没有笑死XD

// 似乎有点不规范啊，看得难受。
// 写得很丑陋，就是用了一个表，
