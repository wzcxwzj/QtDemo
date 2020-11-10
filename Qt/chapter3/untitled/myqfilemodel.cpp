#include "myqfilemodel.h"
#include <QDir>
#include <QDebug>
#include <QCheckBox>

MyqFileModel::MyqFileModel()
{

}
//QVariant MyqFileModel::data( const QModelIndex& index, int role) const
//{
//    if( role == Qt::DecorationRole )
//    {
//        QFileInfo info = MyqFileModel::fileInfo(index);

//        if(info.isFile())
//        {
//            if(info.suffix() == "dat")
//                return QPixmap("C:/Users/Administrator/Documents/canBeDeleted/task4/build-DEF-Desktop_Qt_5_10_0_MinGW_32bit-Debug/debug/favicon.ico");//I pick the icon depending on the extension
//            else if(info.suffix() == "mcr")
//                return QPixmap(":/icons/Region_Icon.png");
//        }
//        if(info.isDir())
//        {
//                return QPixmap("C:/Users/Administrator/Documents/canBeDeleted/task4/build-DEF-Desktop_Qt_5_10_0_MinGW_32bit-Debug/debug/favicon.ico");//I pick the icon depending on the extension
//        }
//    }
//    return QFileSystemModel::data(index, role);
//}


QVariant MyqFileModel::data( const QModelIndex &index, int role/*= Qt::DisplayRole*/ ) const
{
//    if (!index.isValid())
//    {
//        return QVariant();
//    }

//    //first column is checkbox
//    if (index.column() == 0 && role == Qt::CheckStateRole)
//    {

//        // setLayoutDirection(Qt::RightToLeft);
//        if (m_indexMap.contains(index))
//        {
//            return m_indexMap[index] ? Qt::Checked : Qt::Unchecked;
//            qDebug()<<"未执行...";
//        }
//        else
//        {
//           int iChecked = Qt::Unchecked;
//            QModelIndex _parentIndex = index.parent();

//            //check if this node's parent is checked
//            while(_parentIndex.isValid())
//            {
//                if (m_indexMap[_parentIndex])
//                {
//                    iChecked = Qt::Checked;
//                    break;
//                }
//                else
//                {
//                    _parentIndex = _parentIndex.parent();
//                }
//            }

//            if (iChecked == Qt::Checked)
//            {
//                m_indexMap[index] = true;
//            }
//            else
//            {

//                m_indexMap[index] = false;
//            }

//            return iChecked;
//        }
//    }

//    if (role != Qt::DisplayRole)
//    {
//        return QVariant();
//    }
    if( role == Qt::DecorationRole )
   {
       QFileInfo info = MyqFileModel::fileInfo(index);

       if(info.isFile())
       {
           if(info.suffix() == "dat")
               return QPixmap("C:/Users/Administrator/Documents/canBeDeleted/task4/build-DEF-Desktop_Qt_5_10_0_MinGW_32bit-Debug/debug/favicon.ico");//I pick the icon depending on the extension
           else if(info.suffix() == "mcr")
               return QPixmap(":/icons/Region_Icon.png");
       }
       if(info.isDir())
       {
//               return QPixmap("C:/Users/Administrator/Documents/canBeDeleted/task4/build-DEF-Desktop_Qt_5_10_0_MinGW_32bit-Debug/debug/favicon.ico");//I pick the icon depending on the extension
               return QPixmap("F:/10.png");
       }
   }

    return QFileSystemModel::data(index, role);
}



//QVariant MyqFileModel::dataX( const QModelIndex &index, int role/*= Qt::DisplayRole*/ ) const
//{
//qDebug()<<"cccc";
//    if (index.column() == 0 && role == Qt::CheckStateRole)
//    {

//        // setLayoutDirection(Qt::RightToLeft);
//        if (m_indexMap.contains(index))
//        {
//            return m_indexMap[index] ? Qt::Checked : Qt::Unchecked;

//        }
//        else
//        {
//            qDebug()<<"rrrrrrrrrrrrr";
//           int iChecked = Qt::Unchecked;
//            QModelIndex _parentIndex = index.parent();

//            //check if this node's parent is checked
//            while(_parentIndex.isValid())
//            {
//                if (m_indexMap[_parentIndex])
//                {
//                    iChecked = Qt::Checked;
//                    break;
//                }
//                else
//                {
//                    _parentIndex = _parentIndex.parent();
//                }
//            }

//            if (iChecked == Qt::Checked)
//            {
//                m_indexMap[index] = true;
//            }
//            else
//            {
//                m_indexMap[index] = false;
//            }

//            return iChecked;
//        }
//    }


//    return QFileSystemModel::data(index, role);
//}













bool MyqFileModel::setData( const QModelIndex &index, const QVariant &value, int role /*= Qt::EditRole*/ )
{
    //dataX(index,Qt::CheckStateRole);
    qDebug()<<"gggg";

    if (role == Qt::CheckStateRole && index.column() == 0)
    {

        if (value == Qt::Unchecked)
        {qDebug()<<"UnChecked";

            m_indexMap[index] = false;
            //refresh it's child node
            emit dataChanged(index, index);
        }
        else if (value == Qt::Checked)
        {qDebug()<<"Checked";
            m_indexMap[index] = true;
            //refresh it's child node
            emit dataChanged(index, index);
        }

        //能不能在setdata里面   把复选框显示出来  10:12   10:20
        //如果不能那这个方案就否决了
        //现在做事情就是在训练方法,不着急

        if (hasChildren(index))
        {qDebug()<<"hasChildren";
           // QString strFilePath = filePath(index);
           // setFileCheckState(strFilePath, value);

            int iChildCount = rowCount(index);
            qDebug()<<iChildCount;
            if (iChildCount > 0)
            {qDebug()<<"iChildCount";

                for (int i = 0; i < iChildCount; i++)
                {  // m_indexMap[index]=false;
                    QModelIndex _child = this->index(i, 0, index);
                    m_indexMap[_child]=false;
                    setData(_child, value,Qt::CheckStateRole);
                    qDebug()<<"_child";
                }
            }
        }
    }

    return QFileSystemModel::setData(index, value, role);
}
