/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.2.1
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // /home/Saphir/Workspace-QtCreator/AutomatyKomorkowe/main.png
  0x0,0x0,0x0,0xf5,
  0x89,
  0x50,0x4e,0x47,0xd,0xa,0x1a,0xa,0x0,0x0,0x0,0xd,0x49,0x48,0x44,0x52,0x0,
  0x0,0x0,0x40,0x0,0x0,0x0,0x40,0x8,0x6,0x0,0x0,0x0,0xaa,0x69,0x71,0xde,
  0x0,0x0,0x0,0x1,0x73,0x52,0x47,0x42,0x0,0xae,0xce,0x1c,0xe9,0x0,0x0,0x0,
  0xaf,0x49,0x44,0x41,0x54,0x78,0xda,0xed,0xdb,0xb1,0x9,0xc4,0x30,0xc,0x40,0x51,
  0xe5,0xc8,0x5e,0xf6,0xe8,0xf2,0x64,0xc9,0x6,0xbe,0x14,0xc6,0xe4,0x4e,0x4f,0xb5,
  0xc0,0xf0,0xa,0xf1,0x1b,0x1f,0x99,0x79,0x45,0xe5,0xc9,0xcc,0xeb,0xdb,0xfc,0xf3,
  0xce,0x27,0x8a,0xf,0x0,0x0,0x0,0x0,0x0,0xa8,0x3c,0x47,0xf5,0x10,0x3a,0x23,
  0x22,0x5a,0x6b,0xd3,0xa5,0x31,0xc6,0xd6,0x9d,0xec,0x7d,0xba,0xd3,0x33,0x1f,0xed,
  0x3c,0x79,0xcb,0xd,0x0,0x0,0x0,0x0,0x0,0x0,0x42,0x48,0x8,0xbd,0x2a,0x84,
  0x56,0xc5,0x92,0x10,0x72,0x3,0x0,0x0,0x0,0x0,0x0,0x80,0x10,0xfa,0xb9,0x10,
  0x5a,0x15,0x39,0x42,0xc8,0xd,0x0,0x0,0x0,0x0,0x0,0x0,0x42,0x68,0x49,0x8,
  0xad,0x8a,0x93,0x9d,0x91,0x23,0x84,0xdc,0x0,0x0,0x0,0x0,0x0,0x0,0x20,0x84,
  0xb6,0x85,0xd0,0xdb,0x22,0x47,0x8,0xb9,0x1,0x0,0x0,0x0,0x0,0x0,0x40,0x8,
  0x4d,0xc7,0xaf,0x31,0x37,0x0,0x0,0x0,0x0,0x0,0x0,0x8,0xa1,0xaa,0x73,0x3,
  0xde,0x47,0x75,0xc5,0xc1,0x27,0x21,0x48,0x0,0x0,0x0,0x0,0x49,0x45,0x4e,0x44,
  0xae,0x42,0x60,0x82,
  
};

static const unsigned char qt_resource_name[] = {
  // windows
  0x0,0x7,
  0xe,0x4,0xb6,0x3,
  0x0,0x77,
  0x0,0x69,0x0,0x6e,0x0,0x64,0x0,0x6f,0x0,0x77,0x0,0x73,
    // main.png
  0x0,0x8,
  0x8,0x1,0x59,0x27,
  0x0,0x6d,
  0x0,0x61,0x0,0x69,0x0,0x6e,0x0,0x2e,0x0,0x70,0x0,0x6e,0x0,0x67,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/windows
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
  // :/windows/main.png
  0x0,0x0,0x0,0x14,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_Icons)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_Icons))

int QT_MANGLE_NAMESPACE(qCleanupResources_Icons)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_Icons))

