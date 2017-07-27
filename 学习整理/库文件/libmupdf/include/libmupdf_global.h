#ifndef LIBMUPDF_GLOBAL_H
#define LIBMUPDF_GLOBAL_H

#include <QtCore/qglobal.h>

#ifdef LIBMUPDF_LIB
# define LIBMUPDF_EXPORT Q_DECL_EXPORT
#else
# define LIBMUPDF_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBMUPDF_GLOBAL_H
