#ifndef USERAGEDIALOG_H
#define USERAGEDIALOG_H

#include <QObject>
#include <QDialog>
#include <QSpinBox>
class UserAgeDialog : public QDialog
{
//还有Q_OBJECT似乎全局只能有一个，mainwindows.h里面已经有了。
//误解了，其实是qmake的问题，请先执行qmake预处理Q_OBJECT，在菜单栏的 构建 列表里面 执行qmake。
//似乎路径带中文还有一个错误Failed to resolve include "xxx/debug/moc_predefs.h" for moc file ../useragedialog.h
    Q_OBJECT
public:
    UserAgeDialog();
    UserAgeDialog(QWidget *parent = nullptr);
    void accept()override;//太难了，初学豆子直接给了个简单的模板而已，为什么不能重载啊，编译报错。
    //似乎是和Q_OBJECT一个意思，qmake一下
    int getUserAge() const { return ageSpinBox->value(); }

signals:
    void userAgeChanged(const int &age);

private:
    QSpinBox *ageSpinBox;
    // int age;//可以用其他的组件替代，看豆子在评论区下面说好像要用QLineEdit，都可以换的。
};

#endif // USERAGEDIALOG_H
