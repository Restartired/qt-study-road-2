#include "useragedialog.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

UserAgeDialog::UserAgeDialog() {}
UserAgeDialog::UserAgeDialog(QWidget *parent) : QDialog(parent)
{
    // setWindowTitle(tr("Enter User Age"));

    QLabel *label = new QLabel(tr("Enter your age:"));
    ageSpinBox = new QSpinBox;
    ageSpinBox->setRange(0, 120);

    QPushButton *okButton = new QPushButton(tr("OK"));
    connect(okButton, &QPushButton::clicked, this, &UserAgeDialog::accept);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(ageSpinBox);
    layout->addWidget(okButton);

    setLayout(layout);

    // 设置标题为 ageSpinBox 的地址，验证是否不是同一个非模态对话框
    setWindowTitle(tr("Enter User Age: %1").arg(reinterpret_cast<qulonglong>(ageSpinBox), 16));
}

void UserAgeDialog::accept()
{
    emit userAgeChanged(getUserAge()); // newAge is an int
    QDialog::accept();
}

