#include "sortview.h"
#include <QLineEdit>
#include <QLabel>
#include <QHBoxLayout>
// #include <QRegExp>
#include <QRegularExpression>  // 使用 QRegularExpression

SortView::SortView(QWidget *parent)
    : QWidget(parent)
{
    model = new QStringListModel(QColor::colorNames(), this);

    modelProxy = new QSortFilterProxyModel(this);
    modelProxy->setSourceModel(model);
    modelProxy->setFilterKeyColumn(0);

    view = new QListView(this);
    view->setModel(modelProxy);

    QLineEdit *filterInput = new QLineEdit;
    QLabel *filterLabel = new QLabel(tr("Filter"));
    QHBoxLayout *filterLayout = new QHBoxLayout;
    filterLayout->addWidget(filterLabel);
    filterLayout->addWidget(filterInput);

    syntaxBox = new QComboBox;
    syntaxBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);


    // syntaxBox->addItem(tr("Regular expression"), QRegExp::QRegExp);
    // syntaxBox->addItem(tr("Wildcard"), QRegExp::Wildcard);
    // syntaxBox->addItem(tr("Fixed string"), QRegExp::FixedString);


    syntaxBox->addItem(tr("Regular expression"), QRegularExpression::PatternOption::NoPatternOption);  // 修改为 QRegularExpression
    syntaxBox->addItem(tr("Wildcard"), QRegularExpression::WildcardConversionOption());  // 使用 QRegularExpression 的 WildcardOption
    syntaxBox->addItem(tr("Fixed string"), QRegularExpression::NoPatternOption); // 固定字符串不使用任何模式选项


    QLabel *syntaxLabel = new QLabel(tr("Syntax"));
    QHBoxLayout *syntaxLayout = new QHBoxLayout;
    syntaxLayout->addWidget(syntaxLabel);
    syntaxLayout->addWidget(syntaxBox);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(view);
    layout->addLayout(filterLayout);
    layout->addLayout(syntaxLayout);

    connect(filterInput, SIGNAL(textChanged(QString)),
            this, SLOT(filterChanged(QString)));
}



void SortView::filterChanged(const QString &text)
{
    // QRegExp::PatternSyntax syntax = QRegExp::PatternSyntax(
    //     syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    // QRegExp regExp(text, Qt::CaseInsensitive, syntax);
    // modelProxy->setFilterRegExp(regExp);


    // 获取当前的过滤模式
    QRegularExpression::PatternOption syntax = static_cast<QRegularExpression::PatternOption>(
        syntaxBox->itemData(syntaxBox->currentIndex()).toInt());
    QRegularExpression regExp(text, syntax);  // 使用 QRegularExpression 代替 QRegExp
    modelProxy->setFilterRegularExpression(regExp);  // 使用 setFilterRegularExpression 代替 setFilterRegExp
}
