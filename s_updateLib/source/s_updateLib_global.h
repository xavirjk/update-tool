#ifndef S_UPDATELIB_GLOBAL_H
#define S_UPDATELIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(S_UPDATELIB_LIBRARY)
#  define S_UPDATELIB_EXPORT Q_DECL_EXPORT
#else
#  define S_UPDATELIB_EXPORT Q_DECL_IMPORT
#endif

#endif // S_UPDATELIB_GLOBAL_H
