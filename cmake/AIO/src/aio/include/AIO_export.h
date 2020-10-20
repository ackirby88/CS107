/* 
 * \file   AIO_export.h
 * \author akirby
 */

#ifndef AIO_EXPORT_H
#define AIO_EXPORT_H

#if defined(_WINDOWS)
#  if defined(AIO_EXPORTS)
#    define AIO_EXPORT __declspec(dllexport)
#  else
#    define AIO_EXPORT __declspec(dllimport)
#  endif
#else
#  define AIO_EXPORT
#endif
#endif /* AIO_EXPORT_H */