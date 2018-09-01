/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[427];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 10),
QT_MOC_LITERAL(2, 22, 0),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 9),
QT_MOC_LITERAL(5, 43, 12),
QT_MOC_LITERAL(6, 56, 11),
QT_MOC_LITERAL(7, 68, 21),
QT_MOC_LITERAL(8, 90, 24),
QT_MOC_LITERAL(9, 115, 24),
QT_MOC_LITERAL(10, 140, 24),
QT_MOC_LITERAL(11, 165, 24),
QT_MOC_LITERAL(12, 190, 12),
QT_MOC_LITERAL(13, 203, 5),
QT_MOC_LITERAL(14, 209, 3),
QT_MOC_LITERAL(15, 213, 2),
QT_MOC_LITERAL(16, 216, 8),
QT_MOC_LITERAL(17, 225, 5),
QT_MOC_LITERAL(18, 231, 23),
QT_MOC_LITERAL(19, 255, 23),
QT_MOC_LITERAL(20, 279, 8),
QT_MOC_LITERAL(21, 288, 21),
QT_MOC_LITERAL(22, 310, 23),
QT_MOC_LITERAL(23, 334, 17),
QT_MOC_LITERAL(24, 352, 23),
QT_MOC_LITERAL(25, 376, 25),
QT_MOC_LITERAL(26, 402, 23)
    },
    "MainWindow\0updateTime\0\0print_sec\0"
    "text_edit\0itwasclicked\0push_button\0"
    "on_pushButton_clicked\0on_radioButton_1_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_2_clicked\0"
    "on_radioButton_4_clicked\0radio_button\0"
    "char*\0arr\0ch\0openfile\0qa_no\0"
    "on_pushButton_2_clicked\0on_pushButton_3_clicked\0"
    "someSlot\0store_answers_to_file\0"
    "print_attended_question\0attended_question\0"
    "on_pushButton_4_clicked\0"
    "read_response_from_server\0"
    "read_response_to_server\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  114,    2, 0x08,
       3,    0,  115,    2, 0x08,
       4,    0,  116,    2, 0x08,
       5,    0,  117,    2, 0x08,
       6,    0,  118,    2, 0x08,
       7,    0,  119,    2, 0x08,
       8,    0,  120,    2, 0x08,
       9,    0,  121,    2, 0x08,
      10,    0,  122,    2, 0x08,
      11,    0,  123,    2, 0x08,
      12,    2,  124,    2, 0x08,
      16,    2,  129,    2, 0x08,
      18,    0,  134,    2, 0x08,
      19,    0,  135,    2, 0x08,
      20,    0,  136,    2, 0x08,
      21,    0,  137,    2, 0x08,
      22,    1,  138,    2, 0x08,
      24,    0,  141,    2, 0x08,
      25,    0,  142,    2, 0x08,
      26,    0,  143,    2, 0x08,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 13, 0x80000000 | 13, 0x80000000 | 13,   14,   15,
    QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateTime(); break;
        case 1: _t->print_sec(); break;
        case 2: _t->text_edit(); break;
        case 3: _t->itwasclicked(); break;
        case 4: _t->push_button(); break;
        case 5: _t->on_pushButton_clicked(); break;
        case 6: _t->on_radioButton_1_clicked(); break;
        case 7: _t->on_radioButton_3_clicked(); break;
        case 8: _t->on_radioButton_2_clicked(); break;
        case 9: _t->on_radioButton_4_clicked(); break;
        case 10: { char* _r = _t->radio_button((*reinterpret_cast< char*(*)>(_a[1])),(*reinterpret_cast< char*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< char**>(_a[0]) = _r; }  break;
        case 11: { int _r = _t->openfile((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: _t->on_pushButton_2_clicked(); break;
        case 13: _t->on_pushButton_3_clicked(); break;
        case 14: _t->someSlot(); break;
        case 15: { int _r = _t->store_answers_to_file();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 16: _t->print_attended_question((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_pushButton_4_clicked(); break;
        case 18: { bool _r = _t->read_response_from_server();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 19: { bool _r = _t->read_response_to_server();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
struct qt_meta_stringdata_Client_t {
    QByteArrayData data[9];
    char stringdata[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Client_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Client_t qt_meta_stringdata_Client = {
    {
QT_MOC_LITERAL(0, 0, 6),
QT_MOC_LITERAL(1, 7, 12),
QT_MOC_LITERAL(2, 20, 0),
QT_MOC_LITERAL(3, 21, 17),
QT_MOC_LITERAL(4, 39, 13),
QT_MOC_LITERAL(5, 53, 4),
QT_MOC_LITERAL(6, 58, 9),
QT_MOC_LITERAL(7, 68, 4),
QT_MOC_LITERAL(8, 73, 12)
    },
    "Client\0dataReceived\0\0wait_for_response\0"
    "connectToHost\0host\0writeData\0data\0"
    "disconnected\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Client[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06,
       1,    1,   47,    2, 0x06,
       3,    1,   50,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       4,    1,   53,    2, 0x0a,
       6,    1,   56,    2, 0x0a,
       8,    0,   59,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, QMetaType::QByteArray,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Bool, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString,    5,
    QMetaType::Bool, QMetaType::QByteArray,    7,
    QMetaType::Void,

       0        // eod
};

void Client::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Client *_t = static_cast<Client *>(_o);
        switch (_id) {
        case 0: _t->dataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 1: _t->dataReceived((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: { bool _r = _t->wait_for_response((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->connectToHost((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { bool _r = _t->writeData((*reinterpret_cast< QByteArray(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: _t->disconnected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Client::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::dataReceived)) {
                *result = 0;
            }
        }
        {
            typedef void (Client::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::dataReceived)) {
                *result = 1;
            }
        }
        {
            typedef bool (Client::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Client::wait_for_response)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Client::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Client.data,
      qt_meta_data_Client,  qt_static_metacall, 0, 0}
};


const QMetaObject *Client::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Client::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Client.stringdata))
        return static_cast<void*>(const_cast< Client*>(this));
    return QObject::qt_metacast(_clname);
}

int Client::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void Client::dataReceived(QByteArray _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Client::dataReceived(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
bool Client::wait_for_response(int _t1)
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)), const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
