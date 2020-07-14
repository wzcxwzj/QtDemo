/****************************************************************************
** Meta object code from reading C++ file 'basewindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../untitled/basewindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'basewindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BaseWindow_t {
    QByteArrayData data[9];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BaseWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BaseWindow_t qt_meta_stringdata_BaseWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "BaseWindow"
QT_MOC_LITERAL(1, 11, 17), // "advanceModelIndex"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 18), // "onButtonMinClicked"
QT_MOC_LITERAL(4, 49, 22), // "onButtonRestoreClicked"
QT_MOC_LITERAL(5, 72, 18), // "onButtonMaxClicked"
QT_MOC_LITERAL(6, 91, 20), // "onButtonCloseClicked"
QT_MOC_LITERAL(7, 112, 22), // "onButtonAdvanceClicked"
QT_MOC_LITERAL(8, 135, 19) // "onButtonBackClicked"

    },
    "BaseWindow\0advanceModelIndex\0\0"
    "onButtonMinClicked\0onButtonRestoreClicked\0"
    "onButtonMaxClicked\0onButtonCloseClicked\0"
    "onButtonAdvanceClicked\0onButtonBackClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BaseWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    1,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QModelIndex,    2,

       0        // eod
};

void BaseWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BaseWindow *_t = static_cast<BaseWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->advanceModelIndex(); break;
        case 1: _t->onButtonMinClicked(); break;
        case 2: _t->onButtonRestoreClicked(); break;
        case 3: _t->onButtonMaxClicked(); break;
        case 4: _t->onButtonCloseClicked(); break;
        case 5: _t->onButtonAdvanceClicked(); break;
        case 6: _t->onButtonBackClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (BaseWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BaseWindow::advanceModelIndex)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject BaseWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_BaseWindow.data,
      qt_meta_data_BaseWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *BaseWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BaseWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BaseWindow.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int BaseWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void BaseWindow::advanceModelIndex()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
