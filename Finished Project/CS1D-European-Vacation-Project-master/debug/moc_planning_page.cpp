/****************************************************************************
** Meta object code from reading C++ file 'planning_page.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../planning_page.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'planning_page.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Planning_Page_t {
    QByteArrayData data[17];
    char stringdata0[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Planning_Page_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Planning_Page_t qt_meta_stringdata_Planning_Page = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Planning_Page"
QT_MOC_LITERAL(1, 14, 33), // "on_ChoosePath_pushButton_rele..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 33), // "on_Save_Route_pushButton_rele..."
QT_MOC_LITERAL(4, 83, 15), // "FindClosestCity"
QT_MOC_LITERAL(5, 99, 21), // "std::vector<QString>&"
QT_MOC_LITERAL(6, 121, 21), // "CheckIfCityWasVisited"
QT_MOC_LITERAL(7, 143, 28), // "on_EndCityList_doubleClicked"
QT_MOC_LITERAL(8, 172, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 184, 5), // "index"
QT_MOC_LITERAL(10, 190, 29), // "on_London_PushButton_released"
QT_MOC_LITERAL(11, 220, 27), // "on_Paris_PushButton_clicked"
QT_MOC_LITERAL(12, 248, 35), // "on_From_ComboBox_currentTextC..."
QT_MOC_LITERAL(13, 284, 4), // "arg1"
QT_MOC_LITERAL(14, 289, 34), // "on_To_ComboBox_currentIndexCh..."
QT_MOC_LITERAL(15, 324, 32), // "on_ClearPath_PushButton_released"
QT_MOC_LITERAL(16, 357, 30) // "on_BuyFood_PushButton_released"

    },
    "Planning_Page\0on_ChoosePath_pushButton_released\0"
    "\0on_Save_Route_pushButton_released\0"
    "FindClosestCity\0std::vector<QString>&\0"
    "CheckIfCityWasVisited\0"
    "on_EndCityList_doubleClicked\0QModelIndex\0"
    "index\0on_London_PushButton_released\0"
    "on_Paris_PushButton_clicked\0"
    "on_From_ComboBox_currentTextChanged\0"
    "arg1\0on_To_ComboBox_currentIndexChanged\0"
    "on_ClearPath_PushButton_released\0"
    "on_BuyFood_PushButton_released"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Planning_Page[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    3,   71,    2, 0x08 /* Private */,
       6,    2,   78,    2, 0x08 /* Private */,
       7,    1,   83,    2, 0x08 /* Private */,
      10,    0,   86,    2, 0x08 /* Private */,
      11,    0,   87,    2, 0x08 /* Private */,
      12,    1,   88,    2, 0x08 /* Private */,
      14,    1,   91,    2, 0x08 /* Private */,
      15,    0,   94,    2, 0x08 /* Private */,
      16,    0,   95,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, 0x80000000 | 5, 0x80000000 | 5,    2,    2,    2,
    QMetaType::Bool, QMetaType::QString, 0x80000000 | 5,    2,    2,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Planning_Page::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Planning_Page *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ChoosePath_pushButton_released(); break;
        case 1: _t->on_Save_Route_pushButton_released(); break;
        case 2: _t->FindClosestCity((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< std::vector<QString>(*)>(_a[2])),(*reinterpret_cast< std::vector<QString>(*)>(_a[3]))); break;
        case 3: { bool _r = _t->CheckIfCityWasVisited((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< std::vector<QString>(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_EndCityList_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->on_London_PushButton_released(); break;
        case 6: _t->on_Paris_PushButton_clicked(); break;
        case 7: _t->on_From_ComboBox_currentTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->on_To_ComboBox_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->on_ClearPath_PushButton_released(); break;
        case 10: _t->on_BuyFood_PushButton_released(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Planning_Page::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_Planning_Page.data,
    qt_meta_data_Planning_Page,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Planning_Page::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Planning_Page::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Planning_Page.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Planning_Page::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
