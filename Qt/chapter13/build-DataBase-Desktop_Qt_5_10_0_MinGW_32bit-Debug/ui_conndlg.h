/********************************************************************************
** Form generated from reading UI file 'conndlg.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNDLG_H
#define UI_CONNDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ConnDlg
{
public:
    QGroupBox *groupBox;

    void setupUi(QDialog *ConnDlg)
    {
        if (ConnDlg->objectName().isEmpty())
            ConnDlg->setObjectName(QStringLiteral("ConnDlg"));
        ConnDlg->resize(400, 300);
        groupBox = new QGroupBox(ConnDlg);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(70, 100, 120, 80));

        retranslateUi(ConnDlg);

        QMetaObject::connectSlotsByName(ConnDlg);
    } // setupUi

    void retranslateUi(QDialog *ConnDlg)
    {
        ConnDlg->setWindowTitle(QApplication::translate("ConnDlg", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("ConnDlg", "GroupBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnDlg: public Ui_ConnDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNDLG_H
