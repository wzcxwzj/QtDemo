#ifndef MYQFILEMODEL_H
#define MYQFILEMODEL_H

#include <QFileSystemModel>
#include <QSet>

class MyqFileModel : public QFileSystemModel
{
public:
    MyqFileModel();
    QVariant data(const QModelIndex &index, int role) const;
   // QVariant dataX(const QModelIndex &index, int role) const;
    bool setData( const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/ );
private:
    mutable QMap<QModelIndex, bool> m_indexMap;
        QSet<QString> m_checkedFileList;
};

#endif // MYQFILEMODEL_H
