#include "combodelegate.h"

ComboDelegate::ComboDelegate()
{

}

QWidget ComboDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    //插入控件 安装事件过滤器

}

void ComboDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    //更新Delegate中控件中的数据显示
}

void ComboDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    //更新了model中的数据
}
