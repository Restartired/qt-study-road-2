#ifndef DIALOGMANAGER_H
#define DIALOGMANAGER_H
#include "useragedialog.h"
#include <QDialog>
#include <QMap>
#include <QDebug>
#include <QObject>

class DialogManager : public QObject
{
    Q_OBJECT
public:
    DialogManager();
    static DialogManager& instance() {
        static DialogManager instance;
        return instance;
    }

    void openDialog(UserAgeDialog* dialog) {
        if (!m_openedDialogs.isEmpty()) {
            // Close the previously opened dialog
            closeDialog(m_openedDialogs.begin().key());
        }

        m_openedDialogs.insert(dialog, true);
        dialog->show();
    }

    void closeDialog(UserAgeDialog* dialog) {
        if (m_openedDialogs.contains(dialog)) {
            m_openedDialogs.remove(dialog);
            dialog->close();
            delete dialog; // 释放对话框对象的内存
        }
    }

private:
    QMap<UserAgeDialog*, bool> m_openedDialogs;
    //这里可能只需要一个指针就可以完成了，因为只需要一个位置。
    // UserAgeDialog* m_openedDialog = nullptr;
};

#endif // DIALOGMANAGER_H
