/****************************************************************************
** Meta object code from reading C++ file 'mainclass.h'
**
** Created: Wed Dec 29 20:38:02 2010
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainclass.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainclass.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainClass[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x0a,
      27,   10,   10,   10, 0x0a,
      46,   10,   10,   10, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_mainClass[] = {
    "mainClass\0\0buttonClicked()\0"
    "addButtonClicked()\0okButtonClicked()\0"
};

const QMetaObject mainClass::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainClass,
      qt_meta_data_mainClass, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainClass::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainClass::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainClass::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainClass))
        return static_cast<void*>(const_cast< mainClass*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainClass::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: buttonClicked(); break;
        case 1: addButtonClicked(); break;
        case 2: okButtonClicked(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
