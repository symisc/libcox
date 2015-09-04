/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/*
 * Copyright (C) 2014, 2015 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SYMISC SYSTEMS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 * $SymiscID: libcox.c v1.7.3256 Win7 2015-08-21 23:05 stable <chm@symisc.net> $ 
 */
/* This file is an amalgamation of many separate C source files from Libcox version 1.7.
 * By combining all the individual C code files into this single large file, the entire code
 * can be compiled as a single translation unit. This allows many compilers to do optimization's
 * that would not be possible if the files were compiled separately. Performance improvements
 * are commonly seen when Libcox is compiled as a single translation unit.
 *
 * This file is all you need to compile Libcox. To use Libcox in other programs, you need
 * this file and the "libcox.h" header file that defines the programming interface to the 
 * Libcox engine.(If you do not have the "libcox.h" header file at hand, you will find
 * a copy embedded within the text of this file. Search for "Header file: <libcox.h>" to find
 * the start of the embedded libcox.h header file). Additional code files may be needed if
 * you want a wrapper to interface Libcox with your choice of programming language.
 * To get the official documentation, please visit http://libcox.net/
 */
 /*
  * Make the sure the following is defined in the amalgamation build
  */
 #ifndef LIBCOX_AMALGAMATION
 #define LIBCOX_AMALGAMATION
 #endif /* LIBCOX_AMALGAMATION */
/*
 * Embedded header file for Libcox: <libcox.h>
 */
/*
 * ----------------------------------------------------------
 * File: libcox.h
 * MD5: 1f01af5ae07349c5a7c9b6ab1f100a42
 * ----------------------------------------------------------
 */
/* This file was automatically generated.  Do not edit (Except for compile time directives)! */ 
#ifndef  _LIBCOX_H_
#define  _LIBCOX_H_
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/*
 * Copyright (C) 2014, 2015 Symisc Systems, S.U.A.R.L [M.I.A.G Mrad Chems Eddine <chm@symisc.net>].
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY SYMISC SYSTEMS ``AS IS'' AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR
 * NON-INFRINGEMENT, ARE DISCLAIMED.  IN NO EVENT SHALL SYMISC SYSTEMS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
 * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/* Make sure we can call this stuff from C++ */
#ifdef __cplusplus
extern "C" { 
#endif
 /* $SymiscID: libcox.h v1.7 Win7 2015-08-21 23:04 stable <chm@symisc.net> $ */
#include <stdarg.h> /* needed for the definition of va_list */
/*
 * Compile time engine version, signature, identification in the symisc source tree
 * and copyright notice.
 * Each macro have an equivalent C interface associated with it that provide the same
 * information but are associated with the library instead of the header file.
 * Refer to [libcox_lib_version()], [libcox_lib_signature()], [libcox_lib_ident()] and
 * [libcox_lib_copyright()] for more information.
 */
/*
 * The LIBCOX_VERSION C preprocessor macroevaluates to a string literal
 * that is the libcox version in the format "X.Y.Z" where X is the major
 * version number and Y is the minor version number and Z is the release
 * number.
 */
#define LIBCOX_VERSION "1.7"
/*
 * The LIBCOX_VERSION_NUMBER C preprocessor macro resolves to an integer
 * with the value (X*1000000 + Y*1000 + Z) where X, Y, and Z are the same
 * numbers used in [LIBCOX_VERSION].
 */
#define LIBCOX_VERSION_NUMBER 1007000
/*
 * The LIBCOX_SIG C preprocessor macro evaluates to a string
 * literal which is the public signature of the libcox engine.
 */
#define LIBCOX_SIG "libcox/1.7"
/*
 * libcox identification in the Symisc source tree:
 * Each particular check-in of a particular software released
 * by symisc systems have an unique identifier associated with it.
 * This macro hold the one associated with libcox.
 */
#define LIBCOX_IDENT "libcox:e71abcf3d4a71ac17e9adac1876232a13467dbc7"
/*
 * Copyright notice.
 * If you have any questions about the licensing situation, please
 * visit http://libcox.net/licensing.html
 * or contact Symisc Systems via:
 *   legal@symisc.net
 *   licensing@symisc.net
 *   contact@symisc.net
 */
#define LIBCOX_COPYRIGHT "Copyright (C) Symisc Systems, S.U.A.R.L [Mrad Chems Eddine <chm@symisc.net>] 2014, 2015 http://libcox.net/"
/* Forward declaration to public objects */
typedef struct libcox_io_methods libcox_io_methods;
typedef struct libcox_context libcox_context;
typedef struct libcox_value libcox_value;
typedef struct libcox_vfs libcox_vfs;
typedef struct libcox libcox;
/*
 * ------------------------------
 * Compile time directives
 * ------------------------------
 * For most purposes, libcox can be built just fine using the default compilation options.
 * However, if required, the compile-time options documented below can be used to omit libcox
 * features (resulting in a smaller compiled library size) or to change the default values
 * of some parameters.
 * Every effort has been made to ensure that the various combinations of compilation options
 * work harmoniously and produce a working library.
 *
 * LIBCOX_ENABLE_THREADS
 *  This option controls whether or not code is included in libcox to enable it to operate
 *  safely in a multithreaded environment. The default is not. All mutexing code is omitted
 *  and it is unsafe to use libcox in a multithreaded program. When compiled with the
 *  LIBCOX_ENABLE_THREADS directive enabled, libcox can be used in a multithreaded program
 *  and it is safe to share the same virtual machine and engine handle between two or more threads.
 *  The value of LIBCOX_ENABLE_THREADS can be determined at run-time using the libcox_lib_is_threadsafe()
 *  interface.
 *  When libcox has been compiled with threading support then the threading mode can be altered
 * at run-time using the libcox_lib_config() interface together with one of these verbs:
 *    LIBCOX_LIB_CONFIG_THREAD_LEVEL_SINGLE
 *    LIBCOX_LIB_CONFIG_THREAD_LEVEL_MULTI
 *  Platforms others than Windows and UNIX systems must install their own mutex subsystem via 
 *  libcox_lib_config() with a configuration verb set to LIBCOX_LIB_CONFIG_USER_MUTEX.
 *  Otherwise the library is not threadsafe.
 *  Note that you must link libcox with the POSIX threads library under UNIX systems (i.e: -lpthread).
 *
 */
/* Symisc public definitions */
#if !defined(SYMISC_STANDARD_DEFS)
#define SYMISC_STANDARD_DEFS
#if defined (_WIN32) || defined (WIN32) || defined(__MINGW32__) || defined (_MSC_VER) || defined (_WIN32_WCE)
/* Windows Systems */
#if !defined(__WINNT__)
#define __WINNT__
#endif 
/*
 * Determine if we are dealing with WindowsCE - which has a much
 * reduced API.
 */
#if defined(_WIN32_WCE)
#ifndef __WIN_CE__
#define __WIN_CE__
#endif /* __WIN_CE__ */
#endif /* _WIN32_WCE */
#else
/*
 * By default we will assume that we are compiling on a UNIX like (iOS and Android included) system.
 * Otherwise the OS_OTHER directive must be defined.
 */
#if !defined(OS_OTHER)
#if !defined(__UNIXES__)
#define __UNIXES__
#endif /* __UNIXES__ */
#else
#endif /* OS_OTHER */
#endif /* __WINNT__/__UNIXES__ */
#if defined(_MSC_VER) || defined(__BORLANDC__)
typedef signed __int64     sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned __int64   sxu64; /* 64 bits(8 bytes) unsigned int64 */
#else
typedef signed long long int   sxi64; /* 64 bits(8 bytes) signed int64 */
typedef unsigned long long int sxu64; /* 64 bits(8 bytes) unsigned int64 */
#endif /* _MSC_VER */
/* Signature of the consumer routine */
typedef int (*ProcConsumer)(const void *, unsigned int, void *);
/* Forward reference */
typedef struct SyMutexMethods SyMutexMethods;
typedef struct SyMemMethods SyMemMethods;
typedef struct SyString SyString;
typedef struct syiovec syiovec;
typedef struct SyMutex SyMutex;
typedef struct Sytm Sytm;
/* Scatter and gather array. */
struct syiovec
{
#if defined (__WINNT__)
	/* Same fields type and offset as WSABUF structure defined one winsock2 header */
	unsigned long nLen;
	char *pBase;
#else
	void *pBase;
	unsigned long nLen;
#endif
};
struct SyString
{
	const char *zString;  /* Raw string (may not be null terminated) */
	unsigned int nByte;   /* Raw string length */
};
/* Time structure. */
struct Sytm
{
  int tm_sec;     /* seconds (0 - 60) */
  int tm_min;     /* minutes (0 - 59) */
  int tm_hour;    /* hours (0 - 23) */
  int tm_mday;    /* day of month (1 - 31) */
  int tm_mon;     /* month of year (0 - 11) */
  int tm_year;    /* year + 1900 */
  int tm_wday;    /* day of week (Sunday = 0) */
  int tm_yday;    /* day of year (0 - 365) */
  int tm_isdst;   /* is summer time in effect? */
  char *tm_zone;  /* abbreviation of timezone name */
  long tm_gmtoff; /* offset from UTC in seconds */
};
/* Convert a tm structure (struct tm *) found in <time.h> to a Sytm structure */
#define STRUCT_TM_TO_SYTM(pTM, pSYTM) \
	(pSYTM)->tm_hour = (pTM)->tm_hour;\
	(pSYTM)->tm_min	 = (pTM)->tm_min;\
	(pSYTM)->tm_sec	 = (pTM)->tm_sec;\
	(pSYTM)->tm_mon	 = (pTM)->tm_mon;\
	(pSYTM)->tm_mday = (pTM)->tm_mday;\
	(pSYTM)->tm_year = (pTM)->tm_year + 1900;\
	(pSYTM)->tm_yday = (pTM)->tm_yday;\
	(pSYTM)->tm_wday = (pTM)->tm_wday;\
	(pSYTM)->tm_isdst = (pTM)->tm_isdst;\
	(pSYTM)->tm_gmtoff = 0;\
	(pSYTM)->tm_zone = 0;

/* Convert a SYSTEMTIME structure (LPSYSTEMTIME: Windows Systems only ) to a Sytm structure */
#define SYSTEMTIME_TO_SYTM(pSYSTIME, pSYTM) \
	 (pSYTM)->tm_hour = (pSYSTIME)->wHour;\
	 (pSYTM)->tm_min  = (pSYSTIME)->wMinute;\
	 (pSYTM)->tm_sec  = (pSYSTIME)->wSecond;\
	 (pSYTM)->tm_mon  = (pSYSTIME)->wMonth - 1;\
	 (pSYTM)->tm_mday = (pSYSTIME)->wDay;\
	 (pSYTM)->tm_year = (pSYSTIME)->wYear;\
	 (pSYTM)->tm_yday = 0;\
	 (pSYTM)->tm_wday = (pSYSTIME)->wDayOfWeek;\
	 (pSYTM)->tm_gmtoff = 0;\
	 (pSYTM)->tm_isdst = -1;\
	 (pSYTM)->tm_zone = 0;

/* Dynamic memory allocation methods. */
struct SyMemMethods 
{
	void * (*xAlloc)(unsigned int);          /* [Required:] Allocate a memory chunk */
	void * (*xRealloc)(void *, unsigned int); /* [Required:] Re-allocate a memory chunk */
	void   (*xFree)(void *);                 /* [Required:] Release a memory chunk */
	unsigned int  (*xChunkSize)(void *);     /* [Optional:] Return chunk size */
	int    (*xInit)(void *);                 /* [Optional:] Initialization callback */
	void   (*xRelease)(void *);              /* [Optional:] Release callback */
	void  *pUserData;                        /* [Optional:] First argument to xInit() and xRelease() */
};
/* Out of memory callback signature. */
typedef int (*ProcMemError)(void *);
/* Mutex methods. */
struct SyMutexMethods 
{
	int (*xGlobalInit)(void);		/* [Optional:] Global mutex initialization */
	void  (*xGlobalRelease)(void);	/* [Optional:] Global Release callback () */
	SyMutex * (*xNew)(int);	        /* [Required:] Request a new mutex */
	void  (*xRelease)(SyMutex *);	/* [Optional:] Release a mutex  */
	void  (*xEnter)(SyMutex *);	    /* [Required:] Enter mutex */
	int (*xTryEnter)(SyMutex *);    /* [Optional:] Try to enter a mutex */
	void  (*xLeave)(SyMutex *);	    /* [Required:] Leave a locked mutex */
};
#if defined (_MSC_VER) || defined (__MINGW32__) ||  defined (__GNUC__) && defined (__declspec)
#define SX_APIIMPORT	__declspec(dllimport)
#define SX_APIEXPORT	__declspec(dllexport)
#else
#define	SX_APIIMPORT
#define	SX_APIEXPORT
#endif
/* Standard return values from Symisc public interfaces */
#define SXRET_OK       0      /* Not an error */	
#define SXERR_MEM      (-1)   /* Out of memory */
#define SXERR_IO       (-2)   /* IO error */
#define SXERR_EMPTY    (-3)   /* Empty field */
#define SXERR_LOCKED   (-4)   /* Locked operation */
#define SXERR_ORANGE   (-5)   /* Out of range value */
#define SXERR_NOTFOUND (-6)   /* Item not found */
#define SXERR_LIMIT    (-7)   /* Limit reached */
#define SXERR_MORE     (-8)   /* Need more input */
#define SXERR_INVALID  (-9)   /* Invalid parameter */
#define SXERR_ABORT    (-10)  /* User callback request an operation abort */
#define SXERR_EXISTS   (-11)  /* Item exists */
#define SXERR_SYNTAX   (-12)  /* Syntax error */
#define SXERR_UNKNOWN  (-13)  /* Unknown error */
#define SXERR_BUSY     (-14)  /* Busy operation */
#define SXERR_OVERFLOW (-15)  /* Stack or buffer overflow */
#define SXERR_WILLBLOCK (-16) /* Operation will block */
#define SXERR_NOTIMPLEMENTED  (-17) /* Operation not implemented */
#define SXERR_EOF      (-18) /* End of input */
#define SXERR_PERM     (-19) /* Permission error */
#define SXERR_NOOP     (-20) /* No-op */	
#define SXERR_FORMAT   (-21) /* Invalid format */
#define SXERR_NEXT     (-22) /* Not an error */
#define SXERR_OS       (-23) /* System call return an error */
#define SXERR_CORRUPT  (-24) /* Corrupted pointer */
#define SXERR_CONTINUE (-25) /* Not an error: Operation in progress */
#define SXERR_NOMATCH  (-26) /* No match */
#define SXERR_RESET    (-27) /* Operation reset */
#define SXERR_DONE     (-28) /* Not an error */
#define SXERR_SHORT    (-29) /* Buffer too short */
#define SXERR_PATH     (-30) /* Path error */
#define SXERR_TIMEOUT  (-31) /* Timeout */
#define SXERR_BIG      (-32) /* Too big for processing */
#define SXERR_RETRY    (-33) /* Retry your call */
#define SXERR_IGNORE   (-63) /* Ignore */
#endif /* SYMISC_PUBLIC_DEFS */
/* 
 * Marker for exported interfaces. 
 */
#define LIBCOX_APIEXPORT SX_APIEXPORT
/* Standard libcox return values */
#define LIBCOX_OK      SXRET_OK      /* Successful result */
/* Beginning of error codes */
#define LIBCOX_NOMEM    SXERR_MEM     /* Out of memory */
#define LIBCOX_ABORT    SXERR_ABORT   /* Another thread have released this instance */
#define LIBCOX_IOERR    SXERR_IO      /* IO error */
#define LIBCOX_CORRUPT  SXERR_CORRUPT /* Corrupt pointer */
#define LIBCOX_LOCKED   SXERR_LOCKED  /* Forbidden Operation */ 
#define LIBCOX_BUSY	 SXERR_BUSY    /* The database file is locked */
#define LIBCOX_DONE	 SXERR_DONE    /* Operation done */
#define LIBCOX_PERM     SXERR_PERM    /* Permission error */
#define LIBCOX_NOTIMPLEMENTED SXERR_NOTIMPLEMENTED /* Method not implemented by the underlying Key/Value storage engine */
#define LIBCOX_NOTFOUND SXERR_NOTFOUND /* No such record */
#define LIBCOX_NOOP     SXERR_NOOP     /* No such method */
#define LIBCOX_INVALID  SXERR_INVALID  /* Invalid parameter */
#define LIBCOX_EOF      SXERR_EOF      /* End Of Input */
#define LIBCOX_UNKNOWN  SXERR_UNKNOWN  /* Unknown configuration option */
#define LIBCOX_LIMIT    SXERR_LIMIT    /* Database limit reached */
#define LIBCOX_EXISTS   SXERR_EXISTS   /* Record exists */
#define LIBCOX_EMPTY    SXERR_EMPTY    /* Empty record */
#define LIBCOX_FULL        (-73)       /* Full database (unused) */
#define LIBCOX_CANTOPEN    (-74)       /* Unable to open the database file */
#define LIBCOX_READ_ONLY   (-75)       /* Read only Key/Value storage engine */
#define LIBCOX_LOCKERR     (-76)       /* Locking protocol error */
/* end-of-error-codes */
/*
 * If compiling for a processor that lacks floating point
 * support, substitute integer for floating-point.
 */
#ifdef LIBCOX_OMIT_FLOATING_POINT
typedef sxi64 libcox_real;
#else
typedef double libcox_real;
#endif
typedef sxi64 libcox_int64;
/*
 * libcox Configuration Commands.
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure a libcox datastore handle.
 * These constants must be passed as the second argument to [libcox_config()].
 *
 * Each options require a variable number of arguments.
 * The [libcox_config()] interface will return LIBCOX_OK on success, any other
 * return value indicates failure.
 * For a full discussion on the configuration verbs and their expected 
 * parameters, please refer to this page:
 *      http://libcox.net/c_api/libcox_config.html
 */
#define LIBCOX_CONFIG_ERR_LOG             1  /* TWO ARGUMENTS: const char **pzBuf, int *pLen */
#define LIBCOX_CONFIG_OUTPUT_CONSUMER     2  /* TWO ARGUMENTS: int (*xConsumer)(libcox_value *pOut,void *pUserdata), void *pUserdata */
/*
 * Global Library Configuration Commands.
 *
 * The following set of constants are the available configuration verbs that can
 * be used by the host-application to configure the whole library.
 * These constants must be passed as the first argument to [libcox_lib_config()].
 *
 * Each options require a variable number of arguments.
 * The [libcox_lib_config()] interface will return LIBCOX_OK on success, any other return
 * value indicates failure.
 * Notes:
 * The default configuration is recommended for most applications and so the call to
 * [libcox_lib_config()] is usually not necessary. It is provided to support rare 
 * applications with unusual needs. 
 * The [libcox_lib_config()] interface is not threadsafe. The application must insure that
 * no other [libcox_*()] interfaces are invoked by other threads while [libcox_lib_config()]
 * is running. Furthermore, [libcox_lib_config()] may only be invoked prior to library
 * initialization using [libcox_lib_init()] or [libcox_init()] or after shutdown
 * by [libcox_lib_shutdown()]. If [libcox_lib_config()] is called after [libcox_lib_init()]
 * or [libcox_init()] and before [libcox_lib_shutdown()] then it will return LIBCOX_LOCKED.
 * For a full discussion on the configuration verbs and their expected parameters, please
 * refer to this page:
 *      http://libcox.net/c_api/libcox_lib.html
 */
#define LIBCOX_LIB_CONFIG_USER_MALLOC            1 /* ONE ARGUMENT: const SyMemMethods *pMemMethods */ 
#define LIBCOX_LIB_CONFIG_MEM_ERR_CALLBACK       2 /* TWO ARGUMENTS: int (*xMemError)(void *), void *pUserData */
#define LIBCOX_LIB_CONFIG_USER_MUTEX             3 /* ONE ARGUMENT: const SyMutexMethods *pMutexMethods */ 
#define LIBCOX_LIB_CONFIG_THREAD_LEVEL_SINGLE    4 /* NO ARGUMENTS */ 
#define LIBCOX_LIB_CONFIG_THREAD_LEVEL_MULTI     5 /* NO ARGUMENTS */ 
#define LIBCOX_LIB_CONFIG_VFS                    6 /* ONE ARGUMENT: const libcox_vfs *pVfs */
/*
 * CAPIREF: OS Interface: Open File Handle (RESERVED FOR FUTURE USE)
 *
 * An [libcox_file] object represents an open file in the [libcox_vfs] OS interface
 * layer.
 * Individual OS interface implementations will want to subclass this object by appending
 * additional fields for their own use. The pMethods entry is a pointer to an
 * [libcox_io_methods] object that defines methods for performing
 * I/O operations on the open file.
*/
typedef struct libcox_file libcox_file;
struct libcox_file {
  const libcox_io_methods *pMethods;  /* Methods for an open file. MUST BE FIRST */
};
/*
 * CAPIREF: OS Interface: File Methods Object (RESERVED FOR FUTURE USE)
 *
 * Every file opened by the [libcox_vfs] xOpen method populates an
 * [libcox_file] object (or, more commonly, a subclass of the
 * [libcox_file] object) with a pointer to an instance of this object.
 * This object defines the methods used to perform various operations
 * against the open file represented by the [libcox_file] object.
 *
 * If the xOpen method sets the libcox_file.pMethods element 
 * to a non-NULL pointer, then the libcox_io_methods.xClose method
 * may be invoked even if the xOpen reported that it failed.  The
 * only way to prevent a call to xClose following a failed xOpen
 * is for the xOpen to set the libcox_file.pMethods element to NULL.
 *
 * The flags argument to xSync may be one of [LIBCOX_SYNC_NORMAL] or
 * [LIBCOX_SYNC_FULL]. The first choice is the normal fsync().
 * The second choice is a Mac OS X style fullsync. The [LIBCOX_SYNC_DATAONLY]
 * flag may be ORed in to indicate that only the data of the file
 * and not its inode needs to be synced.
 *
 * The integer values to xLock() and xUnlock() are one of
 *
 * LIBCOX_LOCK_NONE
 * LIBCOX_LOCK_SHARED
 * LIBCOX_LOCK_RESERVED
 * LIBCOX_LOCK_PENDING
 * LIBCOX_LOCK_EXCLUSIVE
 * 
 * xLock() increases the lock. xUnlock() decreases the lock.
 * The xCheckReservedLock() method checks whether any database connection,
 * either in this process or in some other process, is holding a RESERVED,
 * PENDING, or EXCLUSIVE lock on the file. It returns true if such a lock exists
 * and false otherwise.
 * 
 * The xSectorSize() method returns the sector size of the device that underlies
 * the file. The sector size is the minimum write that can be performed without
 * disturbing other bytes in the file.
 */
struct libcox_io_methods {
  int iVersion;                 /* Structure version number (currently 1) */
  int (*xClose)(libcox_file*);
  int (*xRead)(libcox_file*, void*, libcox_int64 iAmt, libcox_int64 iOfst);
  int (*xWrite)(libcox_file*, const void*, libcox_int64 iAmt, libcox_int64 iOfst);
  int (*xTruncate)(libcox_file*, libcox_int64 size);
  int (*xSync)(libcox_file*, int flags);
  int (*xFileSize)(libcox_file*, libcox_int64 *pSize);
  int (*xLock)(libcox_file*, int);
  int (*xUnlock)(libcox_file*, int);
  int (*xCheckReservedLock)(libcox_file*, int *pResOut);
  int (*xSectorSize)(libcox_file*);
};
/*
 * CAPIREF: OS Interface Object
 *
 * An instance of the libcox_vfs object defines the interface between
 * the libcox core and the underlying operating system.  The "vfs"
 * in the name of the object stands for "Virtual File System".
 *
 * Only a single vfs can be registered within the libcox core.
 * Vfs registration is done using the [libcox_lib_config()] interface
 * with a configuration verb set to LIBCOX_LIB_CONFIG_VFS.
 * Note that Windows and UNIX (Linux, FreeBSD, Solaris, Mac OS X, etc.) users
 * does not have to worry about registering and installing a vfs since libcox
 * come with a built-in vfs for these platforms that implements most the methods
 * defined below.
 *
 * Clients running on exotic systems (ie: Other than Windows and UNIX systems)
 * must register their own vfs in order to be able to use the libcox library.
 *
 * The value of the iVersion field is initially 1 but may be larger in
 * future versions of libcox. 
 *
 * The szOsFile field is the size of the subclassed [libcox_file] structure
 * used by this VFS. mxPathname is the maximum length of a pathname in this VFS.
 * 
 * At least szOsFile bytes of memory are allocated by libcox to hold the [libcox_file]
 * structure passed as the third argument to xOpen. The xOpen method does not have to
 * allocate the structure; it should just fill it in. Note that the xOpen method must
 * set the libcox_file.pMethods to either a valid [libcox_io_methods] object or to NULL.
 * xOpen must do this even if the open fails. libcox expects that the libcox_file.pMethods
 * element will be valid after xOpen returns regardless of the success or failure of the
 * xOpen call.
 */
#define LIBCOX_VFS_VERSION 2600 /* 2.6 */
struct libcox_vfs {
	const char *zName;       /* Name of this virtual file system [i.e: Windows, UNIX, etc.] */
	int iVersion;            /* Structure version number (currently 2.6) */
	int szOsFile;            /* Size of subclassed libcox_file */
	int mxPathname;          /* Maximum file pathname length */
	/* Directory functions */
	int (*xChdir)(const char *);                     /* Change directory */
	int (*xChroot)(const char *);                    /* Change the root directory */
	int (*xGetcwd)(libcox_context *);                /* Get the current working directory */
	int (*xMkdir)(const char *, int, int);           /* Make directory */
	int (*xRmdir)(const char *);                     /* Remove directory */
	int (*xIsdir)(const char *);                     /* Tells whether the filename is a directory */
	int (*xRename)(const char *, const char *);       /* Renames a file or directory */
	int (*xRealpath)(const char *, libcox_context *);    /* Return canonicalized absolute pathname*/
	/* Dir handle */
	int  (*xOpenDir)(const char *, libcox_value *, void **);    /* Open directory handle */
	void (*xCloseDir)(void *pHandle);                           /* Close directory handle */
	int  (*xDirRead)(void *pHandle, libcox_value *);     /* Read the next entry from the directory handle */
	void (*xDirRewind)(void *pHandle);                   /* Rewind the cursor */
	/* Systems functions */
	int (*xSleep)(unsigned int);                     /* Delay execution in microseconds */
	int (*xUnlink)(const char *);                    /* Deletes a file */
	int (*xFileExists)(const char *);                /* Checks whether a file or directory exists */
	int (*xChmod)(const char *, int);                /* Changes file mode */
	int (*xChown)(const char *, const char *);       /* Changes file owner */
	int (*xChgrp)(const char *, const char *);       /* Changes file group */
	libcox_int64 (*xFreeSpace)(const char *);        /* Available space on filesystem or disk partition */
	libcox_int64 (*xTotalSpace)(const char *);       /* Total space on filesystem or disk partition */
	libcox_int64 (*xFileSize)(const char *);         /* Gets file size */
	libcox_int64 (*xFileAtime)(const char *);        /* Gets last access time of file */
	libcox_int64 (*xFileMtime)(const char *);        /* Gets file modification time */
	libcox_int64 (*xFileCtime)(const char *);        /* Gets inode change time of file */
	int (*xStat)(const char *, libcox_value *, libcox_value *);   /* Gives information about a file */
	int (*xlStat)(const char *, libcox_value *, libcox_value *);  /* Gives information about a file */
	int (*xIsfile)(const char *);                    /* Tells whether the filename is a regular file */
	int (*xIslink)(const char *);                    /* Tells whether the filename is a symbolic link */
	int (*xReadable)(const char *);                  /* Tells whether a file exists and is readable */
	int (*xWritable)(const char *);                  /* Tells whether the filename is writable */
	int (*xExecutable)(const char *);                /* Tells whether the filename is executable */
	int (*xFiletype)(const char *, libcox_context *);    /* Gets file type [i.e: fifo, dir, file..] */
	int (*xGetenv)(const char *, libcox_context *);      /* Gets the value of an environment variable */
	int (*xSetenv)(const char *, const char *);       /* Sets the value of an environment variable */
	int (*xTouch)(const char *, libcox_int64, libcox_int64); /* Sets access and modification time of file */
	int (*xMmap)(const char *, void **, libcox_int64 *); /* Read-only memory map of the whole file */
	void (*xUnmap)(void *, libcox_int64);                /* Unmap a memory view */
	int (*xLink)(const char *, const char *, int);       /* Create hard or symbolic link */
	int (*xUmask)(int);                                  /* Change the current umask */
	void (*xTempDir)(libcox_context *);                 /* Get path of the temporary directory */
	unsigned int (*xProcessId)(void);                /* Get running process ID */
	int (*xUid)(void);                               /* user ID of the process */
	int (*xGid)(void);                               /* group ID of the process */
	void (*xUsername)(libcox_context *);             /* Running username */
	int (*xSysError)(int,libcox_context *);          /* Last system error message */
};
/*
 * Flags for the xAccess VFS method (RESERVED FOR FUTURE USE)
 *
 * These integer constants can be used as the third parameter to
 * the xAccess method of an [libcox_vfs] object.  They determine
 * what kind of permissions the xAccess method is looking for.
 * With LIBCOX_ACCESS_EXISTS, the xAccess method
 * simply checks whether the file exists.
 * With LIBCOX_ACCESS_READWRITE, the xAccess method
 * checks whether the named directory is both readable and writable
 * (in other words, if files can be added, removed, and renamed within
 * the directory).
 * The LIBCOX_ACCESS_READWRITE constant is currently used only by the
 * [temp_store_directory pragma], though this could change in a future
 * release of libcox.
 * With LIBCOX_ACCESS_READ, the xAccess method
 * checks whether the file is readable.  The LIBCOX_ACCESS_READ constant is
 * currently unused, though it might be used in a future release of
 * libcox.
 */
#define LIBCOX_ACCESS_EXISTS    0
#define LIBCOX_ACCESS_READWRITE 1   
#define LIBCOX_ACCESS_READ      2 
/*
 * Call Context - Error Message Serverity Level.
 *
 * The following constans are the allowed severity level that can
 * passed as the second argument to the [libcox_context_throw_error()] or
 * [libcox_context_throw_error_format()] interfaces.
 * Refer to the official documentation for additional information.
 */
#define LIBCOX_CTX_ERR       1 /* Call context error such as unexpected number of arguments, invalid types and so on. */
#define LIBCOX_CTX_WARNING   2 /* Call context Warning */
#define LIBCOX_CTX_NOTICE    3 /* Call context Notice */
/* 
 * C-API-REF: Please refer to the official documentation for interfaces
 * purpose and expected parameters. 
 */
/* libcox Handle */
LIBCOX_APIEXPORT int libcox_init(libcox **ppHandle);
LIBCOX_APIEXPORT int libcox_config(libcox *pHandle,int iOp,...);
LIBCOX_APIEXPORT int libcox_release(libcox *pHandle);

/* Command Execution Interfaces */
LIBCOX_APIEXPORT int libcox_exec(libcox *pHandle,libcox_value **ppOut,const char *zCmd,int nLen);
LIBCOX_APIEXPORT int libcox_exec_fmt(libcox *pHandle,libcox_value **ppOut,const char *zFmt,...);
LIBCOX_APIEXPORT int libcox_exec_result_destroy(libcox *pHandle,libcox_value *pResult);

/* Foreign Command Registar */
LIBCOX_APIEXPORT int libcox_register_command(libcox *pHandle,const char *zName,int (*xCmd)(libcox_context *,int,libcox_value **),void *pUserdata);
LIBCOX_APIEXPORT int libcox_delete_command(libcox *pHandle,const char *zName);

/* Extracting libcox Commands Parameter/Return Values */
LIBCOX_APIEXPORT int libcox_value_to_int(libcox_value *pValue);
LIBCOX_APIEXPORT int libcox_value_to_bool(libcox_value *pValue);
LIBCOX_APIEXPORT libcox_int64 libcox_value_to_int64(libcox_value *pValue);
LIBCOX_APIEXPORT double libcox_value_to_double(libcox_value *pValue);
LIBCOX_APIEXPORT const char * libcox_value_to_string(libcox_value *pValue, int *pLen);

/* Object Values Query Interfaces */
LIBCOX_APIEXPORT int libcox_value_is_int(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_float(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_bool(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_string(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_null(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_numeric(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_scalar(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_is_array(libcox_value *pVal);

/* Setting The Return Value Of A libcox Command */
LIBCOX_APIEXPORT int libcox_result_int(libcox_context *pCtx, int iValue);
LIBCOX_APIEXPORT int libcox_result_int64(libcox_context *pCtx, libcox_int64 iValue);
LIBCOX_APIEXPORT int libcox_result_bool(libcox_context *pCtx, int iBool);
LIBCOX_APIEXPORT int libcox_result_double(libcox_context *pCtx, double Value);
LIBCOX_APIEXPORT int libcox_result_null(libcox_context *pCtx);
LIBCOX_APIEXPORT int libcox_result_string(libcox_context *pCtx, const char *zString, int nLen);
LIBCOX_APIEXPORT int libcox_result_string_format(libcox_context *pCtx, const char *zFormat, ...);
LIBCOX_APIEXPORT int libcox_result_value(libcox_context *pCtx, libcox_value *pValue);

/* Populating Objects Values */
LIBCOX_APIEXPORT int libcox_value_int(libcox_value *pVal, int iValue);
LIBCOX_APIEXPORT int libcox_value_int64(libcox_value *pVal, libcox_int64 iValue);
LIBCOX_APIEXPORT int libcox_value_bool(libcox_value *pVal, int iBool);
LIBCOX_APIEXPORT int libcox_value_null(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_double(libcox_value *pVal, double Value);
LIBCOX_APIEXPORT int libcox_value_string(libcox_value *pVal, const char *zString, int nLen);
LIBCOX_APIEXPORT int libcox_value_string_format(libcox_value *pVal, const char *zFormat, ...);
LIBCOX_APIEXPORT int libcox_value_reset_string_cursor(libcox_value *pVal);
LIBCOX_APIEXPORT int libcox_value_release(libcox_value *pVal);

/* Command Execution Context Interfaces */
LIBCOX_APIEXPORT int libcox_context_throw_error(libcox_context *pCtx, int iErr, const char *zErr);
LIBCOX_APIEXPORT int libcox_context_throw_error_format(libcox_context *pCtx, int iErr, const char *zFormat, ...);
LIBCOX_APIEXPORT void * libcox_context_user_data(libcox_context *pCtx);
LIBCOX_APIEXPORT int    libcox_context_push_aux_data(libcox_context *pCtx, void *pUserData);
LIBCOX_APIEXPORT void * libcox_context_peek_aux_data(libcox_context *pCtx);
LIBCOX_APIEXPORT void * libcox_context_pop_aux_data(libcox_context *pCtx);
LIBCOX_APIEXPORT const char * libcox_command_name(libcox_context *pCtx);

/* Working with libcox Arrays */
LIBCOX_APIEXPORT libcox_value * libcox_array_fetch(libcox_value *pArray,unsigned int index);
LIBCOX_APIEXPORT libcox_value * libcox_array_fetch_by_key(libcox_value *pArray, const char *zKey, int nByte);
LIBCOX_APIEXPORT int libcox_array_insert(libcox_value *pArray,libcox_value *pValue);
LIBCOX_APIEXPORT int libcox_array_insert_strkey_elem(libcox_value *pArray, const char *zKey, libcox_value *pValue);
LIBCOX_APIEXPORT unsigned int libcox_array_count(libcox_value *pArray);
LIBCOX_APIEXPORT int libcox_array_walk(libcox_value *pArray, int (*xWalk)(libcox_value *, void *), void *pUserData);
LIBCOX_APIEXPORT int libcox_array_reset(libcox_value *pArray);
LIBCOX_APIEXPORT libcox_value * libcox_array_next_elem(libcox_value *pArray);

/* On-demand Object Value Allocation */
LIBCOX_APIEXPORT libcox_value * libcox_context_new_scalar(libcox_context *pCtx);
LIBCOX_APIEXPORT libcox_value * libcox_context_new_array(libcox_context *pCtx);
LIBCOX_APIEXPORT void libcox_context_release_value(libcox_context *pCtx, libcox_value *pValue);

/* Global Library Management Interfaces */
LIBCOX_APIEXPORT int libcox_lib_init(void);
LIBCOX_APIEXPORT int libcox_lib_config(int nConfigOp, ...);
LIBCOX_APIEXPORT int libcox_lib_shutdown(void);
LIBCOX_APIEXPORT int libcox_lib_is_threadsafe(void);
LIBCOX_APIEXPORT const char * libcox_lib_version(void);
LIBCOX_APIEXPORT const char * libcox_lib_signature(void);
LIBCOX_APIEXPORT const char * libcox_lib_ident(void);
LIBCOX_APIEXPORT const char * libcox_lib_copyright(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _LIBCOX_H_ */
/*
 * ----------------------------------------------------------
 * File: libcoxInt.h
 * MD5: 05ea0a53ed1af9caa22127a8d877d249
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
 /* $SymiscID: libcoxInt.h v2.1 FreeBSD 2013-12-26 01:49 devel <chm@symisc.net> $ */
#ifndef __LIBCOXINT_H__
#define __LIBCOXINT_H__
/* Internal interface definitions for libcox. */
#ifdef LIBCOX_AMALGAMATION
#ifndef LIBCOX_PRIVATE
/* Marker for routines not intended for external use */
#define LIBCOX_PRIVATE static
#endif /* LIBCOX_PRIVATE */
#else
#define LIBCOX_PRIVATE
#include "libcox.h"
#endif 
#ifndef LIBCOX_PI
/* Value of PI */
#define LIBCOX_PI 3.1415926535898
#endif
/*
 * Constants for the largest and smallest possible 64-bit signed integers.
 * These macros are designed to work correctly on both 32-bit and 64-bit
 * compilers.
 */
#ifndef LARGEST_INT64
#define LARGEST_INT64  (0xffffffff|(((sxi64)0x7fffffff)<<32))
#endif
#ifndef SMALLEST_INT64
#define SMALLEST_INT64 (((sxi64)-1) - LARGEST_INT64)
#endif

/* Symisc Standard types */
#if !defined(SYMISC_STD_TYPES)
#define SYMISC_STD_TYPES
#ifdef __WINNT__
/* Disable nuisance warnings on Borland compilers */
#if defined(__BORLANDC__)
#pragma warn -rch /* unreachable code */
#pragma warn -ccc /* Condition is always true or false */
#pragma warn -aus /* Assigned value is never used */
#pragma warn -csu /* Comparing signed and unsigned */
#pragma warn -spa /* Suspicious pointer arithmetic */
#endif
#endif
typedef signed char        sxi8; /* signed char */
typedef unsigned char      sxu8; /* unsigned char */
typedef signed short int   sxi16; /* 16 bits(2 bytes) signed integer */
typedef unsigned short int sxu16; /* 16 bits(2 bytes) unsigned integer */
typedef int                sxi32; /* 32 bits(4 bytes) integer */
typedef unsigned int       sxu32; /* 32 bits(4 bytes) unsigned integer */
typedef long               sxptr;
typedef unsigned long      sxuptr;
typedef long               sxlong;
typedef unsigned long      sxulong;
typedef sxi32              sxofft;
typedef sxi64              sxofft64;
typedef long double	       sxlongreal;
typedef double             sxreal;
#define SXI8_HIGH       0x7F
#define SXU8_HIGH       0xFF
#define SXI16_HIGH      0x7FFF
#define SXU16_HIGH      0xFFFF
#define SXI32_HIGH      0x7FFFFFFF
#define SXU32_HIGH      0xFFFFFFFF
#define SXI64_HIGH      0x7FFFFFFFFFFFFFFF
#define SXU64_HIGH      0xFFFFFFFFFFFFFFFF 
#if !defined(TRUE)
#define TRUE 1
#endif
#if !defined(FALSE)
#define FALSE 0
#endif
/*
 * The following macros are used to cast pointers to integers and
 * integers to pointers.
 */
#if defined(__PTRDIFF_TYPE__)  
# define SX_INT_TO_PTR(X)  ((void*)(__PTRDIFF_TYPE__)(X))
# define SX_PTR_TO_INT(X)  ((int)(__PTRDIFF_TYPE__)(X))
#elif !defined(__GNUC__)    
# define SX_INT_TO_PTR(X)  ((void*)&((char*)0)[X])
# define SX_PTR_TO_INT(X)  ((int)(((char*)X)-(char*)0))
#else                       
# define SX_INT_TO_PTR(X)  ((void*)(X))
# define SX_PTR_TO_INT(X)  ((int)(X))
#endif
#define SXMIN(a, b)  ((a < b) ? (a) : (b))
#define SXMAX(a, b)  ((a < b) ? (b) : (a))
#endif /* SYMISC_STD_TYPES */
/* Symisc Run-time API private definitions */
#if !defined(SYMISC_PRIVATE_DEFS)
#define SYMISC_PRIVATE_DEFS

typedef sxi32 (*ProcRawStrCmp)(const SyString *, const SyString *);
#define SyStringData(RAW)	((RAW)->zString)
#define SyStringLength(RAW)	((RAW)->nByte)
#define SyStringInitFromBuf(RAW, ZBUF, NLEN){\
	(RAW)->zString 	= (const char *)ZBUF;\
	(RAW)->nByte	= (sxu32)(NLEN);\
}
#define SyStringUpdatePtr(RAW, NBYTES){\
	if( NBYTES > (RAW)->nByte ){\
		(RAW)->nByte = 0;\
	}else{\
		(RAW)->zString += NBYTES;\
		(RAW)->nByte -= NBYTES;\
	}\
}
#define SyStringDupPtr(RAW1, RAW2)\
	(RAW1)->zString = (RAW2)->zString;\
	(RAW1)->nByte = (RAW2)->nByte;

#define SyStringTrimLeadingChar(RAW, CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[0] == CHAR ){\
			(RAW)->zString++;\
			(RAW)->nByte--;\
	}
#define SyStringTrimTrailingChar(RAW, CHAR)\
	while((RAW)->nByte > 0 && (RAW)->zString[(RAW)->nByte - 1] == CHAR){\
		(RAW)->nByte--;\
	}
#define SyStringCmp(RAW1, RAW2, xCMP)\
	(((RAW1)->nByte == (RAW2)->nByte) ? xCMP((RAW1)->zString, (RAW2)->zString, (RAW2)->nByte) : (sxi32)((RAW1)->nByte - (RAW2)->nByte))

#define SyStringCmp2(RAW1, RAW2, xCMP)\
	(((RAW1)->nByte >= (RAW2)->nByte) ? xCMP((RAW1)->zString, (RAW2)->zString, (RAW2)->nByte) : (sxi32)((RAW2)->nByte - (RAW1)->nByte))

#define SyStringCharCmp(RAW, CHAR) \
	(((RAW)->nByte == sizeof(char)) ? ((RAW)->zString[0] == CHAR ? 0 : CHAR - (RAW)->zString[0]) : ((RAW)->zString[0] == CHAR ? 0 : (RAW)->nByte - sizeof(char)))

#define SX_ADDR(PTR)    ((sxptr)PTR)
#define SX_ARRAYSIZE(X) (sizeof(X)/sizeof(X[0]))
#define SXUNUSED(P)	(P = 0)
#define	SX_EMPTY(PTR)   (PTR == 0)
#define SX_EMPTY_STR(STR) (STR == 0 || STR[0] == 0 )
typedef struct SyMemBackend SyMemBackend;
typedef struct SyBlob SyBlob;
typedef struct SySet SySet;
/* Standard function signatures */
typedef sxi32 (*ProcCmp)(const void *, const void *, sxu32);
typedef sxi32 (*ProcPatternMatch)(const char *, sxu32, const char *, sxu32, sxu32 *);
typedef sxi32 (*ProcSearch)(const void *, sxu32, const void *, sxu32, ProcCmp, sxu32 *);
typedef sxu32 (*ProcHash)(const void *, sxu32);
typedef sxi32 (*ProcHashSum)(const void *, sxu32, unsigned char *, sxu32);
typedef sxi32 (*ProcSort)(void *, sxu32, sxu32, ProcCmp);
#define MACRO_LIST_PUSH(Head, Item)\
	Item->pNext = Head;\
	Head = Item; 
#define MACRO_LD_PUSH(Head, Item)\
	if( Head == 0 ){\
		Head = Item;\
	}else{\
		Item->pNext = Head;\
		Head->pPrev = Item;\
		Head = Item;\
	}
#define MACRO_LD_REMOVE(Head, Item)\
	if( Head == Item ){\
		Head = Head->pNext;\
	}\
	if( Item->pPrev ){ Item->pPrev->pNext = Item->pNext;}\
	if( Item->pNext ){ Item->pNext->pPrev = Item->pPrev;}
/*
 * A generic dynamic set.
 */
struct SySet
{
	SyMemBackend *pAllocator; /* Memory backend */
	void *pBase;              /* Base pointer */	
	sxu32 nUsed;              /* Total number of used slots  */
	sxu32 nSize;              /* Total number of available slots */
	sxu32 eSize;              /* Size of a single slot */
	sxu32 nCursor;	          /* Loop cursor */	
	void *pUserData;          /* User private data associated with this container */
};
#define SySetBasePtr(S)           ((S)->pBase)
#define SySetBasePtrJump(S, OFFT)  (&((char *)(S)->pBase)[OFFT*(S)->eSize])
#define SySetUsed(S)              ((S)->nUsed)
#define SySetSize(S)              ((S)->nSize)
#define SySetElemSize(S)          ((S)->eSize) 
#define SySetCursor(S)            ((S)->nCursor)
#define SySetGetAllocator(S)      ((S)->pAllocator)
#define SySetSetUserData(S, DATA)  ((S)->pUserData = DATA)
#define SySetGetUserData(S)       ((S)->pUserData)
/*
 * A variable length containers for generic data.
 */
struct SyBlob
{
	SyMemBackend *pAllocator; /* Memory backend */
	void   *pBlob;	          /* Base pointer */
	sxu32  nByte;	          /* Total number of used bytes */
	sxu32  mByte;	          /* Total number of available bytes */
	sxu32  nFlags;	          /* Blob internal flags, see below */
};
#define SXBLOB_LOCKED	0x01	/* Blob is locked [i.e: Cannot auto grow] */
#define SXBLOB_STATIC	0x02	/* Not allocated from heap   */
#define SXBLOB_RDONLY   0x04    /* Read-Only data */

#define SyBlobFreeSpace(BLOB)	 ((BLOB)->mByte - (BLOB)->nByte)
#define SyBlobLength(BLOB)	     ((BLOB)->nByte)
#define SyBlobData(BLOB)	     ((BLOB)->pBlob)
#define SyBlobCurData(BLOB)	     ((void*)(&((char*)(BLOB)->pBlob)[(BLOB)->nByte]))
#define SyBlobDataAt(BLOB, OFFT)	 ((void *)(&((char *)(BLOB)->pBlob)[OFFT]))
#define SyBlobGetAllocator(BLOB) ((BLOB)->pAllocator)

#define SXMEM_POOL_INCR			3
#define SXMEM_POOL_NBUCKETS		12
#define SXMEM_BACKEND_MAGIC	0xBAC3E67D
#define SXMEM_BACKEND_CORRUPT(BACKEND)	(BACKEND == 0 || BACKEND->nMagic != SXMEM_BACKEND_MAGIC)

#define SXMEM_BACKEND_RETRY	3
/* A memory backend subsystem is defined by an instance of the following structures */
typedef union SyMemHeader SyMemHeader;
typedef struct SyMemBlock SyMemBlock;
struct SyMemBlock
{
	SyMemBlock *pNext, *pPrev; /* Chain of allocated memory blocks */
#ifdef UNTRUST
	sxu32 nGuard;             /* magic number associated with each valid block, so we
							   * can detect misuse.
							   */
#endif
};
/*
 * Header associated with each valid memory pool block.
 */
union SyMemHeader
{
	SyMemHeader *pNext; /* Next chunk of size 1 << (nBucket + SXMEM_POOL_INCR) in the list */
	sxu32 nBucket;      /* Bucket index in aPool[] */
};
struct SyMemBackend
{
	const SyMutexMethods *pMutexMethods; /* Mutex methods */
	const SyMemMethods *pMethods;  /* Memory allocation methods */
	SyMemBlock *pBlocks;           /* List of valid memory blocks */
	sxu32 nBlock;                  /* Total number of memory blocks allocated so far */
	ProcMemError xMemError;        /* Out-of memory callback */
	void *pUserData;               /* First arg to xMemError() */
	SyMutex *pMutex;               /* Per instance mutex */
	sxu32 nMagic;                  /* Sanity check against misuse */
	SyMemHeader *apPool[SXMEM_POOL_NBUCKETS+SXMEM_POOL_INCR]; /* Pool of memory chunks */
};
/* Mutex types */
#define SXMUTEX_TYPE_FAST	1
#define SXMUTEX_TYPE_RECURSIVE	2
#define SXMUTEX_TYPE_STATIC_1	3
#define SXMUTEX_TYPE_STATIC_2	4
#define SXMUTEX_TYPE_STATIC_3	5
#define SXMUTEX_TYPE_STATIC_4	6
#define SXMUTEX_TYPE_STATIC_5	7
#define SXMUTEX_TYPE_STATIC_6	8

#define SyMutexGlobalInit(METHOD){\
	if( (METHOD)->xGlobalInit ){\
	(METHOD)->xGlobalInit();\
	}\
}
#define SyMutexGlobalRelease(METHOD){\
	if( (METHOD)->xGlobalRelease ){\
	(METHOD)->xGlobalRelease();\
	}\
}
#define SyMutexNew(METHOD, TYPE)			(METHOD)->xNew(TYPE)
#define SyMutexRelease(METHOD, MUTEX){\
	if( MUTEX && (METHOD)->xRelease ){\
		(METHOD)->xRelease(MUTEX);\
	}\
}
#define SyMutexEnter(METHOD, MUTEX){\
	if( MUTEX ){\
	(METHOD)->xEnter(MUTEX);\
	}\
}
#define SyMutexTryEnter(METHOD, MUTEX){\
	if( MUTEX && (METHOD)->xTryEnter ){\
	(METHOD)->xTryEnter(MUTEX);\
	}\
}
#define SyMutexLeave(METHOD, MUTEX){\
	if( MUTEX ){\
	(METHOD)->xLeave(MUTEX);\
	}\
}
/* Comparison, byte swap, byte copy macros */
#define SX_MACRO_FAST_CMP(X1, X2, SIZE, RC){\
	register unsigned char *r1 = (unsigned char *)X1;\
	register unsigned char *r2 = (unsigned char *)X2;\
	register sxu32 LEN = SIZE;\
	for(;;){\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	  if( !LEN ){ break; }if( r1[0] != r2[0] ){ break; } r1++; r2++; LEN--;\
	}\
	RC = !LEN ? 0 : r1[0] - r2[0];\
}
#define	SX_MACRO_FAST_MEMCPY(SRC, DST, SIZ){\
	register unsigned char *xSrc = (unsigned char *)SRC;\
	register unsigned char *xDst = (unsigned char *)DST;\
	register sxu32 xLen = SIZ;\
	for(;;){\
	    if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
		if( !xLen ){ break; }xDst[0] = xSrc[0]; xDst++; xSrc++; --xLen;\
	}\
}
#define SX_MACRO_BYTE_SWAP(X, Y, Z){\
	register unsigned char *s = (unsigned char *)X;\
	register unsigned char *d = (unsigned char *)Y;\
	sxu32	ZLong = Z;  \
	sxi32 c; \
	for(;;){\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	  if(!ZLong){ break; } c = s[0] ; s[0] = d[0]; d[0] = (unsigned char)c; s++; d++; --ZLong;\
	}\
}
#define SX_MSEC_PER_SEC	(1000)			/* Millisec per seconds */
#define SX_USEC_PER_SEC	(1000000)		/* Microsec per seconds */
#define SX_NSEC_PER_SEC	(1000000000)	/* Nanosec per seconds */
#endif /* SYMISC_PRIVATE_DEFS */
/* Symisc Run-time API auxiliary definitions */
#if !defined(SYMISC_PRIVATE_AUX_DEFS)
#define SYMISC_PRIVATE_AUX_DEFS

typedef struct SyHashEntry_Pr SyHashEntry_Pr;
typedef struct SyHashEntry SyHashEntry;
typedef struct SyHash SyHash;
/*
 * Each public hashtable entry is represented by an instance
 * of the following structure.
 */
struct SyHashEntry
{
	const void *pKey; /* Hash key */
	sxu32 nKeyLen;    /* Key length */
	void *pUserData;  /* User private data */
};
#define SyHashEntryGetUserData(ENTRY) ((ENTRY)->pUserData)
#define SyHashEntryGetKey(ENTRY)      ((ENTRY)->pKey)
/* Each active hashtable is identified by an instance of the following structure */
struct SyHash
{
	SyMemBackend *pAllocator;         /* Memory backend */
	ProcHash xHash;                   /* Hash function */
	ProcCmp xCmp;                     /* Comparison function */
	SyHashEntry_Pr *pList, *pCurrent;  /* Linked list of hash entries user for linear traversal */
	sxu32 nEntry;                     /* Total number of entries */
	SyHashEntry_Pr **apBucket;        /* Hash buckets */
	sxu32 nBucketSize;                /* Current bucket size */
};
#define SXHASH_BUCKET_SIZE 16 /* Initial bucket size: must be a power of two */
#define SXHASH_FILL_FACTOR 3
/* Hash access macro */
#define SyHashFunc(HASH)		((HASH)->xHash)
#define SyHashCmpFunc(HASH)		((HASH)->xCmp)
#define SyHashTotalEntry(HASH)	((HASH)->nEntry)
#define SyHashGetPool(HASH)		((HASH)->pAllocator)
/*
 * An instance of the following structure define a single context
 * for an Pseudo Random Number Generator.
 *
 * Nothing in this file or anywhere else in the library does any kind of
 * encryption.  The RC4 algorithm is being used as a PRNG (pseudo-random
 * number generator) not as an encryption device.
 * This implementation is taken from the SQLite3 source tree.
 */
typedef struct SyPRNGCtx SyPRNGCtx;
struct SyPRNGCtx
{
    sxu8 i, j;				/* State variables */
    unsigned char s[256];   /* State variables */
	sxu16 nMagic;			/* Sanity check */
 };
typedef sxi32 (*ProcRandomSeed)(void *, unsigned int, void *);
/* High resolution timer.*/
typedef struct sytime sytime;
struct sytime
{
	long tm_sec;	/* seconds */
	long tm_usec;	/* microseconds */
};
/* Forward declaration */
typedef struct SyStream SyStream;
typedef struct SyToken  SyToken;
typedef struct SyLex    SyLex;
/*
 * Tokenizer callback signature.
 */
typedef sxi32 (*ProcTokenizer)(SyStream *, SyToken *, void *, void *);
/*
 * Each token in the input is represented by an instance
 * of the following structure.
 */
struct SyToken
{
	SyString sData;  /* Token text and length */
	sxu32 nType;     /* Token type */
	sxu32 nLine;     /* Token line number */
	void *pUserData; /* User private data associated with this token */
};
/*
 * During tokenization, information about the state of the input
 * stream is held in an instance of the following structure.
 */
struct SyStream
{
	const unsigned char *zInput; /* Complete text of the input */
	const unsigned char *zText; /* Current input we are processing */	
	const unsigned char *zEnd; /* End of input marker */
	sxu32  nLine; /* Total number of processed lines */
	sxu32  nIgn; /* Total number of ignored tokens */
	SySet *pSet; /* Token containers */
};
/*
 * Each lexer is represented by an instance of the following structure.
 */
struct SyLex
{
	SyStream sStream;         /* Input stream */
	ProcTokenizer xTokenizer; /* Tokenizer callback */
	void * pUserData;         /* Third argument to xTokenizer() */
	SySet *pTokenSet;         /* Token set */
};
#define SyLexTotalToken(LEX)    SySetTotalEntry(&(LEX)->aTokenSet)
#define SyLexTotalLines(LEX)    ((LEX)->sStream.nLine)
#define SyLexTotalIgnored(LEX)  ((LEX)->sStream.nIgn)
#define XLEX_IN_LEN(STREAM)     (sxu32)(STREAM->zEnd - STREAM->zText)
#endif /* SYMISC_PRIVATE_AUX_DEFS */
/*
** Notes on UTF-8 (According to SQLite3 authors):
**
**   Byte-0    Byte-1    Byte-2    Byte-3    Value
**  0xxxxxxx                                 00000000 00000000 0xxxxxxx
**  110yyyyy  10xxxxxx                       00000000 00000yyy yyxxxxxx
**  1110zzzz  10yyyyyy  10xxxxxx             00000000 zzzzyyyy yyxxxxxx
**  11110uuu  10uuzzzz  10yyyyyy  10xxxxxx   000uuuuu zzzzyyyy yyxxxxxx
**
*/
/*
** Assuming zIn points to the first byte of a UTF-8 character, 
** advance zIn to point to the first byte of the next UTF-8 character.
*/
#define SX_JMP_UTF8(zIn, zEnd)\
	while(zIn < zEnd && (((unsigned char)zIn[0] & 0xc0) == 0x80) ){ zIn++; }
#define SX_WRITE_UTF8(zOut, c) {                       \
  if( c<0x00080 ){                                     \
    *zOut++ = (sxu8)(c&0xFF);                          \
  }else if( c<0x00800 ){                               \
    *zOut++ = 0xC0 + (sxu8)((c>>6)&0x1F);              \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else if( c<0x10000 ){                               \
    *zOut++ = 0xE0 + (sxu8)((c>>12)&0x0F);             \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }else{                                               \
    *zOut++ = 0xF0 + (sxu8)((c>>18) & 0x07);           \
    *zOut++ = 0x80 + (sxu8)((c>>12) & 0x3F);           \
    *zOut++ = 0x80 + (sxu8)((c>>6) & 0x3F);            \
    *zOut++ = 0x80 + (sxu8)(c & 0x3F);                 \
  }                                                    \
}
/* Rely on the standard ctype */
#include <ctype.h>
#define SyToUpper(c) toupper(c) 
#define SyToLower(c) tolower(c) 
#define SyisUpper(c) isupper(c)
#define SyisLower(c) islower(c)
#define SyisSpace(c) isspace(c)
#define SyisBlank(c) isspace(c)
#define SyisAlpha(c) isalpha(c)
#define SyisDigit(c) isdigit(c)
#define SyisHex(c)	 isxdigit(c)
#define SyisPrint(c) isprint(c)
#define SyisPunct(c) ispunct(c)
#define SyisSpec(c)	 iscntrl(c)
#define SyisCtrl(c)	 iscntrl(c)
#define SyisAscii(c) isascii(c)
#define SyisAlphaNum(c) isalnum(c)
#define SyisGraph(c)     isgraph(c)
#define SyDigToHex(c)    "0123456789ABCDEF"[c & 0x0F] 		
#define SyDigToInt(c)     ((c < 0xc0 && SyisDigit(c))? (c - '0') : 0 )
#define SyCharToUpper(c)  ((c < 0xc0 && SyisLower(c))? SyToUpper(c) : c)
#define SyCharToLower(c)  ((c < 0xc0 && SyisUpper(c))? SyToLower(c) : c)
/* Remove white space/NUL byte from a raw string */
#define SyStringLeftTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0 && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}
#define SyStringLeftTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0 && ((RAW)->zString[0] == 0 || SyisSpace((RAW)->zString[0]))){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}
#define SyStringRightTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}
#define SyStringRightTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && \
	(( RAW)->zString[(RAW)->nByte - 1] == 0 || SyisSpace((RAW)->zString[(RAW)->nByte - 1]))){\
		(RAW)->nByte--;\
	}

#define SyStringFullTrim(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0  && SyisSpace((RAW)->zString[0])){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && SyisSpace((RAW)->zString[(RAW)->nByte - 1])){\
		(RAW)->nByte--;\
	}
#define SyStringFullTrimSafe(RAW)\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[0] < 0xc0  && \
          ( (RAW)->zString[0] == 0 || SyisSpace((RAW)->zString[0]))){\
		(RAW)->nByte--;\
		(RAW)->zString++;\
	}\
	while((RAW)->nByte > 0 && (unsigned char)(RAW)->zString[(RAW)->nByte - 1] < 0xc0  && \
                   ( (RAW)->zString[(RAW)->nByte - 1] == 0 || SyisSpace((RAW)->zString[(RAW)->nByte - 1]))){\
		(RAW)->nByte--;\
	}

#ifndef LIBCOX_DISABLE_HASH_FUNC
/* MD5 context */
typedef struct MD5Context MD5Context;
struct MD5Context {
 sxu32 buf[4];
 sxu32 bits[2];
 unsigned char in[64];
};
/* SHA1 context */
typedef struct SHA1Context SHA1Context;
struct SHA1Context {
  unsigned int state[5];
  unsigned int count[2];
  unsigned char buffer[64];
};
#endif /* LIBCOX_DISABLE_HASH_FUNC */
/*
 * Memory Objects.
 * Internally, the libcox engine manipulates nearly all libcox values
 * [i.e: string, int, float, bool, null] as libcox_values structures.
 * Each libcox_values struct may cache multiple representations (string, integer etc.)
 * of the same value.
 */
struct libcox_value
{
	union{
		libcox_real rVal;      /* Real value */
		sxi64 iVal;       /* Integer value */
		void *pOther;     /* Other values (Hashmap etc.) */
	}x;
	sxi32 iFlags;       /* Control flags (see below) */
	SyBlob sBlob;       /* Blob values (Warning: Must be last field in this structure) */
};
/* Allowed value types.
 */
#define MEMOBJ_STRING    0x001  /* Memory value is a UTF-8/Binary stream */
#define MEMOBJ_INT       0x002  /* Memory value is an integer */
#define MEMOBJ_REAL      0x004  /* Memory value is a real number */
#define MEMOBJ_BOOL      0x008  /* Memory value is a boolean */
#define MEMOBJ_NULL      0x020  /* Memory value is NULL */
#define MEMOBJ_HASHMAP   0x040  /* Memory value is a hashmap  */
/* Mask of all known types */
#define MEMOBJ_ALL (MEMOBJ_STRING|MEMOBJ_INT|MEMOBJ_REAL|MEMOBJ_BOOL|MEMOBJ_NULL|MEMOBJ_HASHMAP) 
/*
 * The following macro clear the current libcox_value type and replace
 * it with the given one.
 */
#define MemObjSetType(OBJ, TYPE) ((OBJ)->iFlags = ((OBJ)->iFlags&~MEMOBJ_ALL)|TYPE)
#define MEMOBJ_SCALAR (MEMOBJ_STRING|MEMOBJ_INT|MEMOBJ_REAL|MEMOBJ_BOOL|MEMOBJ_NULL)
/* libcox cast method signature */
typedef sxi32 (*ProcMemObjCast)(libcox_value *);
/*
 * Auxiliary data associated with each foreign command is stored
 * in a stack of the following structure.
 * Note that automatic tracked chunks are also stored in an instance
 * of this structure.
 */
typedef struct libcox_aux_data libcox_aux_data;
struct libcox_aux_data
{
	void *pAuxData; /* Aux data */
};
/*
 * Each registered libcox command is represented by an instance of the following
 * structure.
 */
typedef int (*ProclibcoxCmd)(libcox_context *,int,libcox_value **);
typedef struct libcox_cmd libcox_cmd;
struct libcox_cmd
{
	SyString sName;       /* Command name */
	sxu32 nHash;          /* Hash of the command name */
	ProclibcoxCmd xCmd;    /* Command implementation */
	SySet aAux;           /* Stack of auxiliary data */
	void *pUserData;      /* Command private data */
	libcox_cmd *pNext,*pPrev; /* Pointer to other commands in the chaine */
	libcox_cmd *pNextCol,*pPrevCol; /* Collision chain */
};
/*
 * The 'context' argument for an installable commands. A pointer to an
 * instance of this structure is the first argument to the routines used
 * implement the libcox commands.
 */
struct libcox_context
{
	libcox *plibcox;       /* libcox handle */
	libcox_cmd *pCmd;     /* Executed libcox command */
	SyBlob sWorker;      /* Working buffer */
	libcox_value *pRet;   /* Return value is stored here. */
	SySet sVar;          /* Container of dynamically allocated libcox_values
						  * [i.e: Garbage collection purposes.]
						  */
};
/*
 * Command output consumer callback.
 */
typedef int (*ProcCmdConsumer)(libcox_value *,void *);
/*
 * Each command connection is an instance of the following structure.
 */
struct libcox
{
	SyMemBackend sMem;               /* Memory allocator subsystem */
	SyBlob sErr;                     /* Error log */
	libcox_cmd **apCmd;               /* Table of libcox command */
	sxu32 nSize;                     /* Table size */
	sxu32 nCmd;                      /* Total number of installed libcox commands */
	libcox_cmd *pList;                /* List of libcox command */
	SyPRNGCtx sRand;                 /* PRNG Context */
#if defined(LIBCOX_ENABLE_THREADS)
	const SyMutexMethods *pMethods;  /* Mutex methods */
	SyMutex *pMutex;                 /* Per-handle mutex */
#endif
	ProcCmdConsumer xResultConsumer; /* Result consumer callback */
	void *pUserData;                 /* Last argument to xResultConsumer() */
	sxi32 iFlags;                    /* Control flags (See below)  */
	libcox *pNext,*pPrev;             /* List of active handles */
	sxu32 nMagic;                    /* Sanity check against misuse */
};
/*
 * libcox Token
 * The following set of constants are the tokens recognized
 * by the lexer when processing input.
 * Important: Token values MUST BE A POWER OF TWO.
 */
#define LIBCOX_TK_INTEGER   0x0000001  /* Integer */
#define LIBCOX_TK_REAL      0x0000002  /* Real number */
#define LIBCOX_TK_NUM       (LIBCOX_TK_INTEGER|LIBCOX_TK_REAL) /* Numeric token, either integer or real */
#define LIBCOX_TK_STREAM    0x0000004 /* UTF-8/Binary stream */
#define LIBCOX_TK_SEMI      0x0000008 /* ';' semi-colon */
/* Forward declaration */
typedef struct libcox_hashmap_node libcox_hashmap_node;
typedef struct libcox_hashmap libcox_hashmap;
typedef struct libcox_builtin_func libcox_builtin_func;
/* 
 * Each active hashmap is represented by an instance of the following structure.
 */
struct libcox_hashmap
{
	libcox  *pStore;                  /* Store that own this instance */
	libcox_hashmap_node **apBucket;  /* Hash bucket */
	libcox_hashmap_node *pFirst;     /* First inserted entry */
	libcox_hashmap_node *pLast;      /* Last inserted entry */
	libcox_hashmap_node *pCur;       /* Current entry */
	sxu32 nSize;                  /* Bucket size */
	sxu32 nEntry;                 /* Total number of inserted entries */
	sxu32 (*xIntHash)(sxi64);     /* Hash function for int_keys */
	sxu32 (*xBlobHash)(const void *, sxu32); /* Hash function for blob_keys */
	sxi32 iFlags;                 /* Hashmap control flags */
	sxi64 iNextIdx;               /* Next available automatically assigned index */
	sxi32 iRef;                   /* Reference count */
};
/*
 * Each built-in foreign function (C function) is stored in an
 * instance of the following structure.
 * Please refer to the official documentation for more information
 * on how to create/install foreign functions.
 */
struct libcox_builtin_func
{
	const char *zName;        /* Function name [i.e: strlen(), rand(), array_merge(), etc.]*/
	ProclibcoxCmd xFunc;  /* C routine performing the computation */
};

/* cmd.c */
LIBCOX_PRIVATE int libcoxRegisterBuiltinCommands(libcox *plibcox);
/* obj.c */
LIBCOX_PRIVATE void libcoxMemObjInit(libcox *plibcox,libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjInitFromString(libcox *pStore, libcox_value *pObj, const SyString *pVal);
LIBCOX_PRIVATE sxi32 libcoxMemObjInitFromInt(libcox *pStore, libcox_value *pObj, sxi64 iVal);
LIBCOX_PRIVATE libcox_value * libcoxNewObjectValue(libcox *plibcox,SyToken *pToken);
LIBCOX_PRIVATE libcox_value * libcoxNewObjectArrayValue(libcox *plibcox);
LIBCOX_PRIVATE void libcoxObjectValueDestroy(libcox *plibcox,libcox_value *pValue);
LIBCOX_PRIVATE sxi32 libcoxMemObjRelease(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjTryInteger(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjIsNumeric(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjToInteger(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjToReal(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjToBool(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjToString(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjToNull(libcox_value *pObj);
LIBCOX_PRIVATE sxi32 libcoxMemObjStore(libcox_value *pSrc, libcox_value *pDest);
/* parse.c */
LIBCOX_PRIVATE int libcoxProcessInput(libcox *plibcox,libcox_value **ppOut,const char *zInput,sxu32 nByte);
/* api.c */
LIBCOX_PRIVATE int libcoxGenError(libcox *pDb,const char *zErr);
LIBCOX_PRIVATE int libcoxGenErrorFormat(libcox *pDb,const char *zFmt,...);
LIBCOX_PRIVATE int libcoxGenOutofMem(libcox *pDb);
LIBCOX_PRIVATE libcox_cmd * libcoxFetchCommand(libcox *plibcox,SyString *pName);
/* hashmap.c */
LIBCOX_PRIVATE sxu32 libcoxHashmapCount(libcox_hashmap *pMap);
LIBCOX_PRIVATE sxi32 libcoxHashmapWalk(
	libcox_hashmap *pMap, /* Target hashmap */
	int (*xWalk)(libcox_value *, void *), /* Walker callback */
	void *pUserData /* Last argument to xWalk() */
	);
LIBCOX_PRIVATE void libcoxHashmapResetLoopCursor(libcox_hashmap *pMap);
LIBCOX_PRIVATE libcox_value * libcoxHashmapGetNextEntry(libcox_hashmap *pMap);
LIBCOX_PRIVATE libcox_hashmap * libcoxNewHashmap(
	libcox *pStore,             /* Engine that trigger the hashmap creation */
	sxu32 (*xIntHash)(sxi64), /* Hash function for int keys.NULL otherwise*/
	sxu32 (*xBlobHash)(const void *, sxu32) /* Hash function for BLOB keys.NULL otherwise */
	);
LIBCOX_PRIVATE void libcoxHashmapRef(libcox_hashmap *pMap);
LIBCOX_PRIVATE void libcoxHashmapUnref(libcox_hashmap *pMap);
LIBCOX_PRIVATE libcox * libcoxHashmapGetEngine(libcox_hashmap *pMap);
LIBCOX_PRIVATE sxi32 libcoxHashmapLookup(
	libcox_hashmap *pMap,        /* Target hashmap */
	libcox_value *pKey,          /* Lookup key */
	libcox_value **ppOut /* OUT: Target node on success */
	);
LIBCOX_PRIVATE sxi32 libcoxHashmapInsert(
	libcox_hashmap *pMap, /* Target hashmap */
	libcox_value *pKey,   /* Lookup key */
	libcox_value *pVal    /* Node value.NULL otherwise */
	);
/* vfs.c [io_win.c, io_unix.c ] */
LIBCOX_PRIVATE const libcox_vfs * libcoxExportBuiltinVfs(void);
/* lib.c */
#ifdef LIBCOX_ENABLE_HASH_CMD
LIBCOX_PRIVATE sxi32 SyBinToHexConsumer(const void *pIn, sxu32 nLen, ProcConsumer xConsumer, void *pConsumerData);
LIBCOX_PRIVATE sxu32 SyCrc32(const void *pSrc, sxu32 nLen);
LIBCOX_PRIVATE void MD5Update(MD5Context *ctx, const unsigned char *buf, unsigned int len);
LIBCOX_PRIVATE void MD5Final(unsigned char digest[16], MD5Context *ctx);
LIBCOX_PRIVATE sxi32 MD5Init(MD5Context *pCtx);
LIBCOX_PRIVATE sxi32 SyMD5Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[16]);
LIBCOX_PRIVATE void SHA1Init(SHA1Context *context);
LIBCOX_PRIVATE void SHA1Update(SHA1Context *context, const unsigned char *data, unsigned int len);
LIBCOX_PRIVATE void SHA1Final(SHA1Context *context, unsigned char digest[20]);
LIBCOX_PRIVATE sxi32 SySha1Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[20]);
#endif /* LIBCOX_ENABLE_HASH_CMD */
LIBCOX_PRIVATE sxi32 SyRandomness(SyPRNGCtx *pCtx, void *pBuf, sxu32 nLen);
LIBCOX_PRIVATE sxi32 SyRandomnessInit(SyPRNGCtx *pCtx, ProcRandomSeed xSeed, void *pUserData);
LIBCOX_PRIVATE sxu32 SyBlobFormatAp(SyBlob *pBlob, const char *zFormat, va_list ap);
LIBCOX_PRIVATE sxu32 SyBlobFormat(SyBlob *pBlob, const char *zFormat, ...);
LIBCOX_PRIVATE sxi32 SyLexRelease(SyLex *pLex);
LIBCOX_PRIVATE sxi32 SyLexTokenizeInput(SyLex *pLex, const char *zInput, sxu32 nLen, void *pCtxData, ProcSort xSort, ProcCmp xCmp);
LIBCOX_PRIVATE sxi32 SyLexInit(SyLex *pLex, SySet *pSet, ProcTokenizer xTokenizer, void *pUserData);
LIBCOX_PRIVATE sxi32 SyBase64Decode(const char *zB64, sxu32 nLen, ProcConsumer xConsumer, void *pUserData);
LIBCOX_PRIVATE sxi32 SyBase64Encode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData);
LIBCOX_PRIVATE sxu32 SyBinHash(const void *pSrc, sxu32 nLen);
LIBCOX_PRIVATE sxi32 SyStrToReal(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
LIBCOX_PRIVATE sxi32 SyBinaryStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
LIBCOX_PRIVATE sxi32 SyOctalStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
LIBCOX_PRIVATE sxi32 SyHexStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
LIBCOX_PRIVATE sxi32 SyHexToint(sxi32 c);
LIBCOX_PRIVATE sxi32 SyStrToInt64(const char *zSrc, sxu32 nLen, void *pOutVal, const char **zRest);
LIBCOX_PRIVATE sxi32 SyStrIsNumeric(const char *zSrc, sxu32 nLen, sxu8 *pReal, const char **pzTail);
LIBCOX_PRIVATE void *SySetPop(SySet *pSet);
LIBCOX_PRIVATE void *SySetPeek(SySet *pSet);
LIBCOX_PRIVATE sxi32 SySetRelease(SySet *pSet);
LIBCOX_PRIVATE sxi32 SySetReset(SySet *pSet);
LIBCOX_PRIVATE sxi32 SySetPut(SySet *pSet, const void *pItem);
LIBCOX_PRIVATE sxi32 SySetInit(SySet *pSet, SyMemBackend *pAllocator, sxu32 ElemSize);
LIBCOX_PRIVATE sxi32 SyBlobRelease(SyBlob *pBlob);
LIBCOX_PRIVATE sxi32 SyBlobReset(SyBlob *pBlob);
LIBCOX_PRIVATE sxi32 SyBlobDup(SyBlob *pSrc, SyBlob *pDest);
LIBCOX_PRIVATE sxi32 SyBlobNullAppend(SyBlob *pBlob);
LIBCOX_PRIVATE sxi32 SyBlobAppend(SyBlob *pBlob, const void *pData, sxu32 nSize);
LIBCOX_PRIVATE sxi32 SyBlobInit(SyBlob *pBlob, SyMemBackend *pAllocator);
LIBCOX_PRIVATE void *SyMemBackendDup(SyMemBackend *pBackend, const void *pSrc, sxu32 nSize);
LIBCOX_PRIVATE sxi32 SyMemBackendRelease(SyMemBackend *pBackend);
LIBCOX_PRIVATE sxi32 SyMemBackendInitFromOthers(SyMemBackend *pBackend, const SyMemMethods *pMethods, ProcMemError xMemErr, void *pUserData);
LIBCOX_PRIVATE sxi32 SyMemBackendInit(SyMemBackend *pBackend, ProcMemError xMemErr, void *pUserData);
LIBCOX_PRIVATE sxi32 SyMemBackendInitFromParent(SyMemBackend *pBackend,const SyMemBackend *pParent);
#if 0
/* Not used in the current release of the LIBCOX engine */
LIBCOX_PRIVATE void *SyMemBackendPoolRealloc(SyMemBackend *pBackend, void *pOld, sxu32 nByte);
#endif
LIBCOX_PRIVATE sxi32 SyMemBackendPoolFree(SyMemBackend *pBackend, void *pChunk);
LIBCOX_PRIVATE void *SyMemBackendPoolAlloc(SyMemBackend *pBackend, sxu32 nByte);
LIBCOX_PRIVATE sxi32 SyMemBackendFree(SyMemBackend *pBackend, void *pChunk);
LIBCOX_PRIVATE void *SyMemBackendRealloc(SyMemBackend *pBackend, void *pOld, sxu32 nByte);
LIBCOX_PRIVATE void *SyMemBackendAlloc(SyMemBackend *pBackend, sxu32 nByte);
LIBCOX_PRIVATE sxu32 SyMemcpy(const void *pSrc, void *pDest, sxu32 nLen);
LIBCOX_PRIVATE sxi32 SyMemcmp(const void *pB1, const void *pB2, sxu32 nSize);
LIBCOX_PRIVATE void SyZero(void *pSrc, sxu32 nSize);
LIBCOX_PRIVATE sxi32 SyStrnicmp(const char *zLeft, const char *zRight, sxu32 SLen);
#if defined(__APPLE__)
LIBCOX_PRIVATE sxi32 SyStrncmp(const char *zLeft, const char *zRight, sxu32 nLen);
#endif
LIBCOX_PRIVATE sxu32 SyStrlen(const char *zSrc);
#if defined(LIBCOX_ENABLE_THREADS)
LIBCOX_PRIVATE const SyMutexMethods *SyMutexExportMethods(void);
LIBCOX_PRIVATE sxi32 SyMemBackendMakeThreadSafe(SyMemBackend *pBackend, const SyMutexMethods *pMethods);
LIBCOX_PRIVATE sxi32 SyMemBackendDisbaleMutexing(SyMemBackend *pBackend);
#endif
LIBCOX_PRIVATE const char * SyTimeGetDay(sxi32 iDay);
LIBCOX_PRIVATE const char * SyTimeGetMonth(sxi32 iMonth);
LIBCOX_PRIVATE sxi32 SyByteFind2(const char *zStr, sxu32 nLen, sxi32 c, sxu32 *pPos);
LIBCOX_PRIVATE sxi32 SyBlobSearch(const void *pBlob, sxu32 nLen, const void *pPattern, sxu32 pLen, sxu32 *pOfft);
LIBCOX_PRIVATE sxi32 SyUriEncode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData);
LIBCOX_PRIVATE sxi32 SyUriDecode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData, int bUTF8);
LIBCOX_PRIVATE sxi32 SyBinToHexConsumer(const void *pIn, sxu32 nLen, ProcConsumer xConsumer, void *pConsumerData);
LIBCOX_PRIVATE sxi32 SyStrncmp(const char *zLeft, const char *zRight, sxu32 nLen);
/* json.c */
LIBCOX_PRIVATE int libcoxJsonSerialize(libcox_value *pValue,SyBlob *pOut);

#endif /* _LIBCOXINT_H_ */
/*
 * ----------------------------------------------------------
 * File: vfs.c
 * MD5: 4f1c8ccbeb24cbfe98923ca9f9b949aa
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/* $SymiscID: vfs.c v1.3 FreeBSD 2013-12-29 04:15 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/*
 * Virtual File System (VFS) for libcox.
 */
/* NULL VFS [i.e: a no-op VFS]*/
static const libcox_vfs null_vfs = {
	"null_vfs", 
	LIBCOX_VFS_VERSION,
	0,
	0,
	0,    /* int (*xChdir)(const char *) */
	0,    /* int (*xChroot)(const char *); */
	0,    /* int (*xGetcwd)(libcox_context *) */
	0,    /* int (*xMkdir)(const char *, int, int) */
	0,    /* int (*xRmdir)(const char *) */ 
	0,    /* int (*xIsdir)(const char *) */
	0,    /* int (*xRename)(const char *, const char *) */
	0,    /*int (*xRealpath)(const char *, libcox_context *)*/
		  /* Directory */ 
	0,              
	0,   
	0, 
	0,
		/* Systems */
	0,  /* int (*xSleep)(unsigned int) */
	0,  /* int (*xUnlink)(const char *) */
	0,  /* int (*xFileExists)(const char *) */
	0,  /*int (*xChmod)(const char *, int)*/
	0,  /*int (*xChown)(const char *, const char *)*/
	0,  /*int (*xChgrp)(const char *, const char *)*/
	0,  /* libcox_int64 (*xFreeSpace)(const char *) */
	0,  /* libcox_int64 (*xTotalSpace)(const char *) */
	0,  /* libcox_int64 (*xFileSize)(const char *) */
	0,  /* libcox_int64 (*xFileAtime)(const char *) */
	0,  /* libcox_int64 (*xFileMtime)(const char *) */
	0,  /* libcox_int64 (*xFileCtime)(const char *) */
	0,  /* int (*xStat)(const char *, libcox_value *, libcox_value *) */
	0,  /* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
	0,  /* int (*xIsfile)(const char *) */
	0,  /* int (*xIslink)(const char *) */
	0,  /* int (*xReadable)(const char *) */
	0,  /* int (*xWritable)(const char *) */
	0,  /* int (*xExecutable)(const char *) */
	0,  /* int (*xFiletype)(const char *, libcox_context *) */
	0,  /* int (*xGetenv)(const char *, libcox_context *) */
	0,  /* int (*xSetenv)(const char *, const char *) */ 
	0,  /* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
	0,  /* int (*xMmap)(const char *, void **, libcox_int64 *) */
	0,  /* void (*xUnmap)(void *, libcox_int64);  */
	0,  /* int (*xLink)(const char *, const char *, int) */
	0,  /* int (*xUmask)(int) */
	0,  /* void (*xTempDir)(libcox_context *) */
	0,  /* unsigned int (*xProcessId)(void) */
	0,  /* int (*xUid)(void) */
	0,  /* int (*xGid)(void) */
	0,  /* void (*xUsername)(libcox_context *) */
	0  /* int (*Syserror)(const char *, libcox_context *) */
};

#ifdef __WINNT__
/*
 * Windows VFS implementation for the LIBCOX engine.
 * Authors:
 *    Symisc Systems, devel@symisc.net.
 *    Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Stable.
 */
/* What follows here is code that is specific to windows systems. */
#include <Windows.h>
/*
** Convert a UTF-8 string to microsoft unicode (UTF-16?).
**
** Space to hold the returned string is obtained from HeapAlloc().
** Taken from the sqlite3 source tree
** status: Public Domain
*/
static WCHAR *utf8ToUnicode(const char *zFilename){
  int nChar;
  WCHAR *zWideFilename;

  nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, 0, 0);
  zWideFilename = (WCHAR *)HeapAlloc(GetProcessHeap(), 0, nChar*sizeof(zWideFilename[0]));
  if( zWideFilename == 0 ){
 	return 0;
  } 
  nChar = MultiByteToWideChar(CP_UTF8, 0, zFilename, -1, zWideFilename, nChar);
  if( nChar==0 ){
    HeapFree(GetProcessHeap(), 0, zWideFilename);
    return 0;
  }
  return zWideFilename;
}
/*
** Convert a UTF-8 filename into whatever form the underlying
** operating system wants filenames in.Space to hold the result
** is obtained from HeapAlloc() and must be freed by the calling
** function.
** Taken from the sqlite3 source tree
** status: Public Domain
*/
static void *convertUtf8Filename(const char *zFilename){
  void *zConverted;
  zConverted = utf8ToUnicode(zFilename);
  return zConverted;
}
/*
** Convert microsoft unicode to UTF-8.  Space to hold the returned string is
** obtained from HeapAlloc().
** Taken from the sqlite3 source tree
** status: Public Domain
*/
static char *unicodeToUtf8(const WCHAR *zWideFilename){
  char *zFilename;
  int nByte;

  nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, 0, 0, 0, 0);
  zFilename = (char *)HeapAlloc(GetProcessHeap(), 0, nByte);
  if( zFilename == 0 ){
  	return 0;
  }
  nByte = WideCharToMultiByte(CP_UTF8, 0, zWideFilename, -1, zFilename, nByte, 0, 0);
  if( nByte == 0 ){
    HeapFree(GetProcessHeap(), 0, zFilename);
    return 0;
  }
  return zFilename;
}
/* int (*xchdir)(const char *) */
static int WinVfs_chdir(const char *zPath)
{
	void * pConverted;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	rc = SetCurrentDirectoryW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	return rc ? LIBCOX_OK : -1;
}
/* int (*xGetcwd)(libcox_context *) */
static int WinVfs_getcwd(libcox_context *pCtx)
{
	WCHAR zDir[2048];
	char *zConverted;
	DWORD rc;
	/* Get the current directory */
	rc = GetCurrentDirectoryW(sizeof(zDir), zDir);
	if( rc < 1 ){
		return -1;
	}
	zConverted = unicodeToUtf8(zDir);
	if( zConverted == 0 ){
		return -1;
	}
	libcox_result_string(pCtx, zConverted, -1/*Compute length automatically*/); /* Will make it's own copy */
	HeapFree(GetProcessHeap(), 0, zConverted);
	return LIBCOX_OK;
}
/* int (*xMkdir)(const char *, int, int) */
static int WinVfs_mkdir(const char *zPath, int mode, int recursive)
{
	void * pConverted;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	mode= 0; /* MSVC warning */
	recursive = 0;
	rc = CreateDirectoryW((LPCWSTR)pConverted, 0);
	HeapFree(GetProcessHeap(), 0, pConverted);
	return rc ? LIBCOX_OK : -1;
}
/* int (*xRmdir)(const char *) */
static int WinVfs_rmdir(const char *zPath)
{
	void * pConverted;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	rc = RemoveDirectoryW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	return rc ? LIBCOX_OK : -1;
}
/* int (*xIsdir)(const char *) */
static int WinVfs_isdir(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	return (dwAttr & FILE_ATTRIBUTE_DIRECTORY) ? LIBCOX_OK : -1;
}
/* int (*xRename)(const char *, const char *) */
static int WinVfs_Rename(const char *zOld, const char *zNew)
{
	void *pOld, *pNew;
	BOOL rc = 0;
	pOld = convertUtf8Filename(zOld);
	if( pOld == 0 ){
		return -1;
	}
	pNew = convertUtf8Filename(zNew);
	if( pNew  ){
		rc = MoveFileW((LPCWSTR)pOld, (LPCWSTR)pNew);
	}
	HeapFree(GetProcessHeap(), 0, pOld);
	if( pNew ){
		HeapFree(GetProcessHeap(), 0, pNew);
	}
	return rc ? LIBCOX_OK : - 1;
}
/* int (*xRealpath)(const char *, libcox_context *) */
static int WinVfs_Realpath(const char *zPath, libcox_context *pCtx)
{
	WCHAR zTemp[2048];
	void *pPath;
	char *zReal;
	DWORD n;
	pPath = convertUtf8Filename(zPath);
	if( pPath == 0 ){
		return -1;
	}
	n = GetFullPathNameW((LPCWSTR)pPath, 0, 0, 0);
	if( n > 0 ){
		if( n >= sizeof(zTemp) ){
			n = sizeof(zTemp) - 1;
		}
		GetFullPathNameW((LPCWSTR)pPath, n, zTemp, 0);
	}
	HeapFree(GetProcessHeap(), 0, pPath);
	if( !n ){
		return -1;
	}
	zReal = unicodeToUtf8(zTemp);
	if( zReal == 0 ){
		return -1;
	}
	libcox_result_string(pCtx, zReal, -1); /* Will make it's own copy */
	HeapFree(GetProcessHeap(), 0, zReal);
	return LIBCOX_OK;
}
/* int (*xSleep)(unsigned int) */
static int WinVfs_Sleep(unsigned int uSec)
{
	Sleep(uSec/1000/*uSec per Millisec */);
	return LIBCOX_OK;
}
/* int (*xUnlink)(const char *) */
static int WinVfs_unlink(const char *zPath)
{
	void * pConverted;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	rc = DeleteFileW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	return rc ? LIBCOX_OK : - 1;
}
/* libcox_int64 (*xFreeSpace)(const char *) */
static libcox_int64 WinVfs_DiskFreeSpace(const char *zPath)
{
#ifdef _WIN32_WCE
	/* GetDiskFreeSpace is not supported under WINCE */
	SXUNUSED(zPath);
	return 0;
#else
	DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
	void * pConverted;
	WCHAR *p;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return 0;
	}
	p = (WCHAR *)pConverted;
	for(;*p;p++){
		if( *p == '\\' || *p == '/'){
			*p = '\0';
			break;
		}
	}
	rc = GetDiskFreeSpaceW((LPCWSTR)pConverted, &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);
	if( !rc ){
		return 0;
	}
	return (libcox_int64)dwFreeClusters * dwSectPerClust * dwBytesPerSect;
#endif
}
/* libcox_int64 (*xTotalSpace)(const char *) */
static libcox_int64 WinVfs_DiskTotalSpace(const char *zPath)
{
#ifdef _WIN32_WCE
	/* GetDiskFreeSpace is not supported under WINCE */
	SXUNUSED(zPath);
	return 0;
#else
	DWORD dwSectPerClust, dwBytesPerSect, dwFreeClusters, dwTotalClusters;
	void * pConverted;
	WCHAR *p;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return 0;
	}
	p = (WCHAR *)pConverted;
	for(;*p;p++){
		if( *p == '\\' || *p == '/'){
			*p = '\0';
			break;
		}
	}
	rc = GetDiskFreeSpaceW((LPCWSTR)pConverted, &dwSectPerClust, &dwBytesPerSect, &dwFreeClusters, &dwTotalClusters);
	if( !rc ){
		return 0;
	}
	return (libcox_int64)dwTotalClusters * dwSectPerClust * dwBytesPerSect;
#endif
}
/* int (*xFileExists)(const char *) */
static int WinVfs_FileExists(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	return LIBCOX_OK;
}
/* Open a file in a read-only mode */
static HANDLE OpenReadOnly(LPCWSTR pPath)
{
	DWORD dwType = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
	DWORD dwShare = FILE_SHARE_READ | FILE_SHARE_WRITE;
	DWORD dwAccess = GENERIC_READ;
	DWORD dwCreate = OPEN_EXISTING;	
	HANDLE pHandle;
	pHandle = CreateFileW(pPath, dwAccess, dwShare, 0, dwCreate, dwType, 0);
	if( pHandle == INVALID_HANDLE_VALUE){
		return 0;
	}
	return pHandle;
}
static HANDLE OpenReadWrite(LPCWSTR pPath)
{
	DWORD dwType = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_RANDOM_ACCESS;
	DWORD dwShare = FILE_SHARE_READ | FILE_SHARE_WRITE;
	DWORD dwAccess = GENERIC_READ | GENERIC_WRITE;
	DWORD dwCreate = OPEN_EXISTING;	
	HANDLE pHandle;
	pHandle = CreateFileW(pPath, dwAccess, dwShare, 0, dwCreate, dwType, 0);
	if( pHandle == INVALID_HANDLE_VALUE){
		return 0;
	}
	return pHandle;
}
/* libcox_int64 (*xFileSize)(const char *) */
static libcox_int64 WinVfs_FileSize(const char *zPath)
{
	DWORD dwLow, dwHigh;
	void * pConverted;
	libcox_int64 nSize;
	HANDLE pHandle;
	
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	/* Open the file in read-only mode */
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( pHandle ){
		dwLow = GetFileSize(pHandle, &dwHigh);
		nSize = dwHigh;
		nSize <<= 32;
		nSize += dwLow;
		CloseHandle(pHandle);
	}else{
		nSize = -1;
	}
	return nSize;
}
#define TICKS_PER_SECOND 10000000
#define EPOCH_DIFFERENCE 11644473600LL
/* Convert Windows timestamp to UNIX timestamp */
static libcox_int64 convertWindowsTimeToUnixTime(LPFILETIME pTime)
{
    libcox_int64 input, temp;
	input = pTime->dwHighDateTime;
	input <<= 32;
	input += pTime->dwLowDateTime;
    temp = input / TICKS_PER_SECOND; /*convert from 100ns intervals to seconds*/
    temp = temp - EPOCH_DIFFERENCE;  /*subtract number of seconds between epochs*/
    return temp;
}
/* Convert UNIX timestamp to Windows timestamp */
static void convertUnixTimeToWindowsTime(libcox_int64 nUnixtime, LPFILETIME pOut)
{
  libcox_int64 result = EPOCH_DIFFERENCE;
  result += nUnixtime;
  result *= 10000000LL;
  pOut->dwHighDateTime = (DWORD)(nUnixtime>>32);
  pOut->dwLowDateTime = (DWORD)nUnixtime;
}
/* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
static int WinVfs_Touch(const char *zPath, libcox_int64 touch_time, libcox_int64 access_time)
{
	FILETIME sTouch, sAccess;
	void *pConverted;
	void *pHandle;
	BOOL rc = 0;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	pHandle = OpenReadWrite((LPCWSTR)pConverted);
	if( pHandle ){
		FILETIME *ptr1 = 0, *ptr2 = 0;
		
		if( touch_time > 0){
			convertUnixTimeToWindowsTime(touch_time, &sTouch);
			ptr1 = &sTouch;
		}
		if( access_time > 0 ){
			convertUnixTimeToWindowsTime(access_time, &sAccess);
			ptr2 = &sAccess;
		}
		rc = SetFileTime(pHandle, ptr1, ptr2, 0);
		/* Close the handle */
		CloseHandle(pHandle);
	}
	HeapFree(GetProcessHeap(), 0, pConverted);
	return rc ? LIBCOX_OK : -1;
}
/* libcox_int64 (*xFileAtime)(const char *) */
static libcox_int64 WinVfs_FileAtime(const char *zPath)
{
	BY_HANDLE_FILE_INFORMATION sInfo;
	void * pConverted;
	libcox_int64 atime;
	HANDLE pHandle;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	/* Open the file in read-only mode */
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	if( pHandle ){
		BOOL rc;
		rc = GetFileInformationByHandle(pHandle, &sInfo);
		if( rc ){
			atime = convertWindowsTimeToUnixTime(&sInfo.ftLastAccessTime);
		}else{
			atime = -1;
		}
		CloseHandle(pHandle);
	}else{
		atime = -1;
	}
	HeapFree(GetProcessHeap(), 0, pConverted);
	return atime;
}
/* libcox_int64 (*xFileMtime)(const char *) */
static libcox_int64 WinVfs_FileMtime(const char *zPath)
{
	BY_HANDLE_FILE_INFORMATION sInfo;
	void * pConverted;
	libcox_int64 mtime;
	HANDLE pHandle;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	/* Open the file in read-only mode */
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	if( pHandle ){
		BOOL rc;
		rc = GetFileInformationByHandle(pHandle, &sInfo);
		if( rc ){
			mtime = convertWindowsTimeToUnixTime(&sInfo.ftLastWriteTime);
		}else{
			mtime = -1;
		}
		CloseHandle(pHandle);
	}else{
		mtime = -1;
	}
	HeapFree(GetProcessHeap(), 0, pConverted);
	return mtime;
}
/* libcox_int64 (*xFileCtime)(const char *) */
static libcox_int64 WinVfs_FileCtime(const char *zPath)
{
	BY_HANDLE_FILE_INFORMATION sInfo;
	void * pConverted;
	libcox_int64 ctime;
	HANDLE pHandle;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	/* Open the file in read-only mode */
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	if( pHandle ){
		BOOL rc;
		rc = GetFileInformationByHandle(pHandle, &sInfo);
		if( rc ){
			ctime = convertWindowsTimeToUnixTime(&sInfo.ftCreationTime);
		}else{
			ctime = -1;
		}
		CloseHandle(pHandle);
	}else{
		ctime = -1;
	}
	HeapFree(GetProcessHeap(), 0, pConverted);
	return ctime;
}
/* int (*xStat)(const char *, libcox_value *, libcox_value *) */
/* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
static int WinVfs_Stat(const char *zPath, libcox_value *pArray, libcox_value *pWorker)
{
	BY_HANDLE_FILE_INFORMATION sInfo;
	void *pConverted;
	HANDLE pHandle;
	BOOL rc;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	/* Open the file in read-only mode */
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( pHandle == 0 ){
		return -1;
	}
	rc = GetFileInformationByHandle(pHandle, &sInfo);
	CloseHandle(pHandle);
	if( !rc ){
		return -1;
	}
	/* dev */
	libcox_value_int64(pWorker, (libcox_int64)sInfo.dwVolumeSerialNumber);
	libcox_array_insert_strkey_elem(pArray, "dev", pWorker); /* Will make it's own copy */
	/* ino */
	libcox_value_int64(pWorker, (libcox_int64)(((libcox_int64)sInfo.nFileIndexHigh << 32) | sInfo.nFileIndexLow));
	libcox_array_insert_strkey_elem(pArray, "ino", pWorker); /* Will make it's own copy */
	/* mode */
	libcox_value_int(pWorker, 0);
	libcox_array_insert_strkey_elem(pArray, "mode", pWorker);
	/* nlink */
	libcox_value_int(pWorker, (int)sInfo.nNumberOfLinks);
	libcox_array_insert_strkey_elem(pArray, "nlink", pWorker); /* Will make it's own copy */
	/* uid, gid, rdev */
	libcox_value_int(pWorker, 0);
	libcox_array_insert_strkey_elem(pArray, "uid", pWorker);
	libcox_array_insert_strkey_elem(pArray, "gid", pWorker);
	libcox_array_insert_strkey_elem(pArray, "rdev", pWorker);
	/* size */
	libcox_value_int64(pWorker, (libcox_int64)(((libcox_int64)sInfo.nFileSizeHigh << 32) | sInfo.nFileSizeLow));
	libcox_array_insert_strkey_elem(pArray, "size", pWorker); /* Will make it's own copy */
	/* atime */
	libcox_value_int64(pWorker, convertWindowsTimeToUnixTime(&sInfo.ftLastAccessTime));
	libcox_array_insert_strkey_elem(pArray, "atime", pWorker); /* Will make it's own copy */
	/* mtime */
	libcox_value_int64(pWorker, convertWindowsTimeToUnixTime(&sInfo.ftLastWriteTime));
	libcox_array_insert_strkey_elem(pArray, "mtime", pWorker); /* Will make it's own copy */
	/* ctime */
	libcox_value_int64(pWorker, convertWindowsTimeToUnixTime(&sInfo.ftCreationTime));
	libcox_array_insert_strkey_elem(pArray, "ctime", pWorker); /* Will make it's own copy */
	/* blksize, blocks */
	libcox_value_int(pWorker, 0);		
	libcox_array_insert_strkey_elem(pArray, "blksize", pWorker);
	libcox_array_insert_strkey_elem(pArray, "blocks", pWorker);
	return LIBCOX_OK;
}
/* int (*xIsfile)(const char *) */
static int WinVfs_isfile(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	return (dwAttr & (FILE_ATTRIBUTE_NORMAL|FILE_ATTRIBUTE_ARCHIVE)) ? LIBCOX_OK : -1;
}
/* int (*xIslink)(const char *) */
static int WinVfs_islink(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	return (dwAttr & FILE_ATTRIBUTE_REPARSE_POINT) ? LIBCOX_OK : -1;
}
/* int (*xWritable)(const char *) */
static int WinVfs_iswritable(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	if( (dwAttr & (FILE_ATTRIBUTE_ARCHIVE|FILE_ATTRIBUTE_NORMAL)) == 0 ){
		/* Not a regular file */
		return -1;
	}
	if( dwAttr & FILE_ATTRIBUTE_READONLY ){
		/* Read-only file */
		return -1;
	}
	/* File is writable */
	return LIBCOX_OK;
}
/* int (*xExecutable)(const char *) */
static int WinVfs_isexecutable(const char *zPath)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		return -1;
	}
	if( (dwAttr & FILE_ATTRIBUTE_NORMAL) == 0 ){
		/* Not a regular file */
		return -1;
	}
	/* FIXEME: GetBinaryType or another call to make sure this thing is executable  */

	/* File is executable */
	return LIBCOX_OK;
}
/* int (*xFiletype)(const char *, libcox_context *) */
static int WinVfs_Filetype(const char *zPath, libcox_context *pCtx)
{
	void * pConverted;
	DWORD dwAttr;
	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		/* Expand 'unknown' */
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
		return -1;
	}
	dwAttr = GetFileAttributesW((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( dwAttr == INVALID_FILE_ATTRIBUTES ){
		/* Expand 'unknown' */
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
		return -1;
	}
	if(dwAttr & (FILE_ATTRIBUTE_HIDDEN|FILE_ATTRIBUTE_NORMAL|FILE_ATTRIBUTE_ARCHIVE) ){
		libcox_result_string(pCtx, "file", sizeof("file")-1);
	}else if(dwAttr & FILE_ATTRIBUTE_DIRECTORY){
		libcox_result_string(pCtx, "dir", sizeof("dir")-1);
	}else if(dwAttr & FILE_ATTRIBUTE_REPARSE_POINT){
		libcox_result_string(pCtx, "link", sizeof("link")-1);
	}else if(dwAttr & (FILE_ATTRIBUTE_DEVICE)){
		libcox_result_string(pCtx, "block", sizeof("block")-1);
	}else{
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
	}
	return LIBCOX_OK;
}
/* int (*xGetenv)(const char *, libcox_context *) */
static int WinVfs_Getenv(const char *zVar, libcox_context *pCtx)
{
	char zValue[1024];
	DWORD n;
	/*
	 * According to MSDN
	 * If lpBuffer is not large enough to hold the data, the return 
	 * value is the buffer size, in characters, required to hold the 
	 * string and its terminating null character and the contents 
	 * of lpBuffer are undefined.
	 */
	n = sizeof(zValue);
	SyMemcpy("Undefined", zValue, sizeof("Undefined")-1);
	/* Extract the environment value */
	n = GetEnvironmentVariableA(zVar, zValue, sizeof(zValue));
	if( !n ){
		/* No such variable*/
		return -1;
	}
	libcox_result_string(pCtx, zValue, (int)n);
	return LIBCOX_OK;
}
/* int (*xSetenv)(const char *, const char *) */
static int WinVfs_Setenv(const char *zName, const char *zValue)
{
	BOOL rc;
	rc = SetEnvironmentVariableA(zName, zValue);
	return rc ? LIBCOX_OK : -1;
}
/* int (*xMmap)(const char *, void **, libcox_int64 *) */
static int WinVfs_Mmap(const char *zPath, void **ppMap, libcox_int64 *pSize)
{
	DWORD dwSizeLow, dwSizeHigh;
	HANDLE pHandle, pMapHandle;
	void *pConverted, *pView;

	pConverted = convertUtf8Filename(zPath);
	if( pConverted == 0 ){
		return -1;
	}
	pHandle = OpenReadOnly((LPCWSTR)pConverted);
	HeapFree(GetProcessHeap(), 0, pConverted);
	if( pHandle == 0 ){
		return -1;
	}
	/* Get the file size */
	dwSizeLow = GetFileSize(pHandle, &dwSizeHigh);
	/* Create the mapping */
	pMapHandle = CreateFileMappingW(pHandle, 0, PAGE_READONLY, dwSizeHigh, dwSizeLow, 0);
	if( pMapHandle == 0 ){
		CloseHandle(pHandle);
		return -1;
	}
	*pSize = ((libcox_int64)dwSizeHigh << 32) | dwSizeLow;
	/* Obtain the view */
	pView = MapViewOfFile(pMapHandle, FILE_MAP_READ, 0, 0, (SIZE_T)(*pSize));
	if( pView ){
		/* Let the upper layer point to the view */
		*ppMap = pView;
	}
	/* Close the handle
	 * According to MSDN it's OK the close the HANDLES.
	 */
	CloseHandle(pMapHandle);
	CloseHandle(pHandle);
	return pView ? LIBCOX_OK : -1;
}
/* void (*xUnmap)(void *, libcox_int64)  */
static void WinVfs_Unmap(void *pView, libcox_int64 nSize)
{
	nSize = 0; /* Compiler warning */
	UnmapViewOfFile(pView);
}
/* void (*xTempDir)(libcox_context *) */
static void WinVfs_TempDir(libcox_context *pCtx)
{
	CHAR zTemp[1024];
	DWORD n;
	n = GetTempPathA(sizeof(zTemp), zTemp);
	if( n < 1 ){
		/* Assume the default windows temp directory */
		libcox_result_string(pCtx, "C:\\Windows\\Temp", -1/*Compute length automatically*/);
	}else{
		libcox_result_string(pCtx, zTemp, (int)n);
	}
}
/* unsigned int (*xProcessId)(void) */
static unsigned int WinVfs_ProcessId(void)
{
	DWORD nID = 0;
#ifndef __MINGW32__
	nID = GetProcessId(GetCurrentProcess());
#endif /* __MINGW32__ */
	return (unsigned int)nID;
}
/* void (*xUsername)(libcox_context *) */
static void WinVfs_Username(libcox_context *pCtx)
{
	WCHAR zUser[1024];
	DWORD nByte;
	BOOL rc;
	nByte = sizeof(zUser);
	rc = GetUserNameW(zUser, &nByte);
	if( !rc ){
		/* Set a dummy name */
		libcox_result_string(pCtx, "Unknown", sizeof("Unknown")-1);
	}else{
		char *zName;
		zName = unicodeToUtf8(zUser);
		if( zName == 0 ){
			libcox_result_string(pCtx, "Unknown", sizeof("Unknown")-1);
		}else{
			libcox_result_string(pCtx, zName, -1/*Compute length automatically*/); /* Will make it's own copy */
			HeapFree(GetProcessHeap(), 0, zName);
		}
	}

}
/* An instance of the following structure is used to record state information 
 * while iterating throw directory entries.
 */
typedef struct WinDir_Info WinDir_Info;
struct WinDir_Info
{
	HANDLE pDirHandle;
	void *pPath;
	WIN32_FIND_DATAW sInfo;
	int rc;
};
/* int (*xOpenDir)(const char *, libcox_value *, void **) */
static int WinDir_Open(const char *zPath, libcox_value *pResource, void **ppHandle)
{
	WinDir_Info *pDirInfo;
	void *pConverted;
	char *zPrep;
	sxu32 n;
	/* Prepare the path */
	n = SyStrlen(zPath);
	zPrep = (char *)HeapAlloc(GetProcessHeap(), 0, n+sizeof("\\*")+4);
	if( zPrep == 0 ){
		return -1;
	}
	SyMemcpy((const void *)zPath, zPrep, n);
	zPrep[n]   = '\\';
	zPrep[n+1] =  '*';
	zPrep[n+2] = 0;
	pConverted = convertUtf8Filename(zPrep);
	HeapFree(GetProcessHeap(), 0, zPrep);
	if( pConverted == 0 ){
		return -1;
	}
	/* Allocate a new instance */
	pDirInfo = (WinDir_Info *)HeapAlloc(GetProcessHeap(), 0, sizeof(WinDir_Info));
	if( pDirInfo == 0 ){
		pResource = 0; /* Compiler warning */
		return -1;
	}
	pDirInfo->rc = SXRET_OK;
	pDirInfo->pDirHandle = FindFirstFileW((LPCWSTR)pConverted, &pDirInfo->sInfo);
	if( pDirInfo->pDirHandle == INVALID_HANDLE_VALUE ){
		/* Cannot open directory */
		HeapFree(GetProcessHeap(), 0, pConverted);
		HeapFree(GetProcessHeap(), 0, pDirInfo);
		return -1;
	}
	/* Save the path */
	pDirInfo->pPath = pConverted;
	/* Save our structure */
	*ppHandle = pDirInfo;
	return LIBCOX_OK;
}
/* void (*xCloseDir)(void *) */
static void WinDir_Close(void *pUserData)
{
	WinDir_Info *pDirInfo = (WinDir_Info *)pUserData;
	if( pDirInfo->pDirHandle != INVALID_HANDLE_VALUE ){
		FindClose(pDirInfo->pDirHandle);
	}
	HeapFree(GetProcessHeap(), 0, pDirInfo->pPath);
	HeapFree(GetProcessHeap(), 0, pDirInfo);
}
/* int (*xReadDir)(void *, libcox_value *) */
static int WinDir_Read(void *pUserData, libcox_value *pVal)
{
	WinDir_Info *pDirInfo = (WinDir_Info *)pUserData;
	LPWIN32_FIND_DATAW pData;
	char *zName;
	BOOL rc;
	sxu32 n;
	if( pDirInfo->rc != SXRET_OK ){
		/* No more entry to process */
		return -1;
	}
	pData = &pDirInfo->sInfo;
	for(;;){
		zName = unicodeToUtf8(pData->cFileName);
		if( zName == 0 ){
			/* Out of memory */
			return -1;
		}
		n = SyStrlen(zName);
		/* Ignore '.' && '..' */
		if( n > sizeof("..")-1 || zName[0] != '.' || ( n == sizeof("..")-1 && zName[1] != '.') ){
			break;
		}
		HeapFree(GetProcessHeap(), 0, zName);
		rc = FindNextFileW(pDirInfo->pDirHandle, &pDirInfo->sInfo);
		if( !rc ){
			return -1;
		}
	}
	/* Return the current file name */
	libcox_value_string(pVal, zName, -1);
	HeapFree(GetProcessHeap(), 0, zName);
	/* Point to the next entry */
	rc = FindNextFileW(pDirInfo->pDirHandle, &pDirInfo->sInfo);
	if( !rc ){
		pDirInfo->rc = SXERR_EOF;
	}
	return LIBCOX_OK;
}
/* void (*xRewindDir)(void *) */
static void WinDir_Rewind(void *pUserData)
{
	WinDir_Info *pDirInfo = (WinDir_Info *)pUserData;
	FindClose(pDirInfo->pDirHandle);
	pDirInfo->pDirHandle = FindFirstFileW((LPCWSTR)pDirInfo->pPath, &pDirInfo->sInfo);
	if( pDirInfo->pDirHandle == INVALID_HANDLE_VALUE ){
		pDirInfo->rc = SXERR_EOF;
	}else{
		pDirInfo->rc = SXRET_OK;
	}
}
#ifndef MAX_PATH
#define MAX_PATH 260
#endif /* MAX_PATH */
/* Export the windows vfs */
static const libcox_vfs sWinVfs = {
	"Windows_vfs", 
	LIBCOX_VFS_VERSION,
	0,
	MAX_PATH,
	WinVfs_chdir,    /* int (*xChdir)(const char *) */
	0,               /* int (*xChroot)(const char *); */
	WinVfs_getcwd,   /* int (*xGetcwd)(libcox_context *) */
	WinVfs_mkdir,    /* int (*xMkdir)(const char *, int, int) */
	WinVfs_rmdir,    /* int (*xRmdir)(const char *) */ 
	WinVfs_isdir,    /* int (*xIsdir)(const char *) */
	WinVfs_Rename,   /* int (*xRename)(const char *, const char *) */
	WinVfs_Realpath, /*int (*xRealpath)(const char *, libcox_context *)*/
	/* Directory */ 
	WinDir_Open,              
	WinDir_Close,   
	WinDir_Read, 
	WinDir_Rewind,
	/* Systems function */
	WinVfs_Sleep,  /* int (*xSleep)(unsigned int) */
	WinVfs_unlink, /* int (*xUnlink)(const char *) */
	WinVfs_FileExists, /* int (*xFileExists)(const char *) */
	0, /*int (*xChmod)(const char *, int)*/
	0, /*int (*xChown)(const char *, const char *)*/
	0, /*int (*xChgrp)(const char *, const char *)*/
	WinVfs_DiskFreeSpace, /* libcox_int64 (*xFreeSpace)(const char *) */
	WinVfs_DiskTotalSpace, /* libcox_int64 (*xTotalSpace)(const char *) */
	WinVfs_FileSize, /* libcox_int64 (*xFileSize)(const char *) */
	WinVfs_FileAtime, /* libcox_int64 (*xFileAtime)(const char *) */
	WinVfs_FileMtime, /* libcox_int64 (*xFileMtime)(const char *) */
	WinVfs_FileCtime, /* libcox_int64 (*xFileCtime)(const char *) */
	WinVfs_Stat, /* int (*xStat)(const char *, libcox_value *, libcox_value *) */
	WinVfs_Stat, /* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
	WinVfs_isfile,     /* int (*xIsfile)(const char *) */
	WinVfs_islink,     /* int (*xIslink)(const char *) */
	WinVfs_isfile,     /* int (*xReadable)(const char *) */
	WinVfs_iswritable, /* int (*xWritable)(const char *) */
	WinVfs_isexecutable, /* int (*xExecutable)(const char *) */
	WinVfs_Filetype,   /* int (*xFiletype)(const char *, libcox_context *) */
	WinVfs_Getenv,     /* int (*xGetenv)(const char *, libcox_context *) */
	WinVfs_Setenv,     /* int (*xSetenv)(const char *, const char *) */ 
	WinVfs_Touch,      /* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
	WinVfs_Mmap,       /* int (*xMmap)(const char *, void **, libcox_int64 *) */
	WinVfs_Unmap,      /* void (*xUnmap)(void *, libcox_int64);  */
	0,                 /* int (*xLink)(const char *, const char *, int) */
	0,                 /* int (*xUmask)(int) */
	WinVfs_TempDir,    /* void (*xTempDir)(libcox_context *) */
	WinVfs_ProcessId,  /* unsigned int (*xProcessId)(void) */
	0, /* int (*xUid)(void) */
	0, /* int (*xGid)(void) */
	WinVfs_Username,    /* void (*xUsername)(libcox_context *) */
	0 /* int (*xSysError)(const char *, libcox_context *) */
};

#elif defined(__UNIXES__)
/*
 * UNIX VFS implementation for the LIBCOX engine.
 * Authors:
 *    Symisc Systems, devel@symisc.net.
 *    Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Stable.
 */
#include <sys/types.h>
#include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/file.h>
#include <sys/statvfs.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <utime.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef PATH_MAX
#define PATH_MAX 4096
#endif /* PATH_MAX */

/* int (*xchdir)(const char *) */
static int UnixVfs_chdir(const char *zPath)
{
  int rc;
  rc = chdir(zPath);
  return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xGetcwd)(libcox_context *) */
static int UnixVfs_getcwd(libcox_context *pCtx)
{
	char zBuf[4096];
	char *zDir;
	/* Get the current directory */
	zDir = getcwd(zBuf, sizeof(zBuf));
	if( zDir == 0 ){
	  return -1;
    }
	libcox_result_string(pCtx, zDir, -1/*Compute length automatically*/);
	return LIBCOX_OK;
}
/* int (*xMkdir)(const char *, int, int) */
static int UnixVfs_mkdir(const char *zPath, int mode, int recursive)
{
	int rc;
        rc = mkdir(zPath, mode);
	recursive = 0; /* cc warning */
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xRmdir)(const char *) */
static int UnixVfs_rmdir(const char *zPath)
{
	int rc;
	rc = rmdir(zPath);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xIsdir)(const char *) */
static int UnixVfs_isdir(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){
	 return -1;
	}
	rc = S_ISDIR(st.st_mode);
	return rc ? LIBCOX_OK : -1 ;
}
/* int (*xRename)(const char *, const char *) */
static int UnixVfs_Rename(const char *zOld, const char *zNew)
{
	int rc;
	rc = rename(zOld, zNew);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xRealpath)(const char *, libcox_context *) */
static int UnixVfs_Realpath(const char *zPath, libcox_context *pCtx)
{
#ifndef LIBCOX_UNIX_OLD_LIBC
	char *zReal;
	zReal = realpath(zPath, 0);
	if( zReal == 0 ){
	  return -1;
	}
	libcox_result_string(pCtx, zReal, -1/*Compute length automatically*/);
        /* Release the allocated buffer */
	free(zReal);
	return LIBCOX_OK;
#else
    zPath = 0; /* cc warning */
    pCtx = 0;
    return -1;
#endif
}
/* int (*xSleep)(unsigned int) */
static int UnixVfs_Sleep(unsigned int uSec)
{
	usleep(uSec);
	return LIBCOX_OK;
}
/* int (*xUnlink)(const char *) */
static int UnixVfs_unlink(const char *zPath)
{
	int rc;
	rc = unlink(zPath);
	return rc == 0 ? LIBCOX_OK : -1 ;
}
/* int (*xFileExists)(const char *) */
static int UnixVfs_FileExists(const char *zPath)
{
	int rc;
	rc = access(zPath, F_OK);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* libcox_int64 (*xFileSize)(const char *) */
static libcox_int64 UnixVfs_FileSize(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	return (libcox_int64)st.st_size;
}
/* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
static int UnixVfs_Touch(const char *zPath, libcox_int64 touch_time, libcox_int64 access_time)
{
	struct utimbuf ut;
	int rc;
	ut.actime  = (time_t)access_time;
	ut.modtime = (time_t)touch_time;
	rc = utime(zPath, &ut);
	if( rc != 0 ){
	 return -1;
	}
	return LIBCOX_OK;
}
/* libcox_int64 (*xFileAtime)(const char *) */
static libcox_int64 UnixVfs_FileAtime(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	return (libcox_int64)st.st_atime;
}
/* libcox_int64 (*xFileMtime)(const char *) */
static libcox_int64 UnixVfs_FileMtime(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	return (libcox_int64)st.st_mtime;
}
/* libcox_int64 (*xFileCtime)(const char *) */
static libcox_int64 UnixVfs_FileCtime(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	return (libcox_int64)st.st_ctime;
}
/* int (*xStat)(const char *, libcox_value *, libcox_value *) */
static int UnixVfs_Stat(const char *zPath, libcox_value *pArray, libcox_value *pWorker)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	/* dev */
	libcox_value_int64(pWorker, (libcox_int64)st.st_dev);
	libcox_array_insert_strkey_elem(pArray, "dev", pWorker); /* Will make it's own copy */
	/* ino */
	libcox_value_int64(pWorker, (libcox_int64)st.st_ino);
	libcox_array_insert_strkey_elem(pArray, "ino", pWorker); /* Will make it's own copy */
	/* mode */
	libcox_value_int(pWorker, (int)st.st_mode);
	libcox_array_insert_strkey_elem(pArray, "mode", pWorker);
	/* nlink */
	libcox_value_int(pWorker, (int)st.st_nlink);
	libcox_array_insert_strkey_elem(pArray, "nlink", pWorker); /* Will make it's own copy */
	/* uid, gid, rdev */
	libcox_value_int(pWorker, (int)st.st_uid);
	libcox_array_insert_strkey_elem(pArray, "uid", pWorker);
	libcox_value_int(pWorker, (int)st.st_gid);
	libcox_array_insert_strkey_elem(pArray, "gid", pWorker);
	libcox_value_int(pWorker, (int)st.st_rdev);
	libcox_array_insert_strkey_elem(pArray, "rdev", pWorker);
	/* size */
	libcox_value_int64(pWorker, (libcox_int64)st.st_size);
	libcox_array_insert_strkey_elem(pArray, "size", pWorker); /* Will make it's own copy */
	/* atime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_atime);
	libcox_array_insert_strkey_elem(pArray, "atime", pWorker); /* Will make it's own copy */
	/* mtime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_mtime);
	libcox_array_insert_strkey_elem(pArray, "mtime", pWorker); /* Will make it's own copy */
	/* ctime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_ctime);
	libcox_array_insert_strkey_elem(pArray, "ctime", pWorker); /* Will make it's own copy */
	/* blksize, blocks */
	libcox_value_int(pWorker, (int)st.st_blksize);		
	libcox_array_insert_strkey_elem(pArray, "blksize", pWorker);
	libcox_value_int(pWorker, (int)st.st_blocks);
	libcox_array_insert_strkey_elem(pArray, "blocks", pWorker);
	return LIBCOX_OK;
}
/* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
static int UnixVfs_lStat(const char *zPath, libcox_value *pArray, libcox_value *pWorker)
{
	struct stat st;
	int rc;
	rc = lstat(zPath, &st);
	if( rc != 0 ){ 
	 return -1;
	}
	/* dev */
	libcox_value_int64(pWorker, (libcox_int64)st.st_dev);
	libcox_array_insert_strkey_elem(pArray, "dev", pWorker); /* Will make it's own copy */
	/* ino */
	libcox_value_int64(pWorker, (libcox_int64)st.st_ino);
	libcox_array_insert_strkey_elem(pArray, "ino", pWorker); /* Will make it's own copy */
	/* mode */
	libcox_value_int(pWorker, (int)st.st_mode);
	libcox_array_insert_strkey_elem(pArray, "mode", pWorker);
	/* nlink */
	libcox_value_int(pWorker, (int)st.st_nlink);
	libcox_array_insert_strkey_elem(pArray, "nlink", pWorker); /* Will make it's own copy */
	/* uid, gid, rdev */
	libcox_value_int(pWorker, (int)st.st_uid);
	libcox_array_insert_strkey_elem(pArray, "uid", pWorker);
	libcox_value_int(pWorker, (int)st.st_gid);
	libcox_array_insert_strkey_elem(pArray, "gid", pWorker);
	libcox_value_int(pWorker, (int)st.st_rdev);
	libcox_array_insert_strkey_elem(pArray, "rdev", pWorker);
	/* size */
	libcox_value_int64(pWorker, (libcox_int64)st.st_size);
	libcox_array_insert_strkey_elem(pArray, "size", pWorker); /* Will make it's own copy */
	/* atime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_atime);
	libcox_array_insert_strkey_elem(pArray, "atime", pWorker); /* Will make it's own copy */
	/* mtime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_mtime);
	libcox_array_insert_strkey_elem(pArray, "mtime", pWorker); /* Will make it's own copy */
	/* ctime */
	libcox_value_int64(pWorker, (libcox_int64)st.st_ctime);
	libcox_array_insert_strkey_elem(pArray, "ctime", pWorker); /* Will make it's own copy */
	/* blksize, blocks */
	libcox_value_int(pWorker, (int)st.st_blksize);		
	libcox_array_insert_strkey_elem(pArray, "blksize", pWorker);
	libcox_value_int(pWorker, (int)st.st_blocks);
	libcox_array_insert_strkey_elem(pArray, "blocks", pWorker);
	return LIBCOX_OK;
}
/* int (*xChmod)(const char *, int) */
static int UnixVfs_Chmod(const char *zPath, int mode)
{
    int rc;
    rc = chmod(zPath, (mode_t)mode);
    return rc == 0 ? LIBCOX_OK : - 1;
}
/* libcox_int64 (*xFreeSpace)(const char *) */
static libcox_int64 UnixVfs_DiskFreeSpace(const char *zPath)
{
	struct statvfs fiData;
	if((statvfs(zPath,&fiData)) < 0 ) {
		return 0;
	}
	return (libcox_int64)(fiData.f_bfree * fiData.f_bsize);
}
/* libcox_int64 (*xTotalSpace)(const char *) */
static libcox_int64 UnixVfs_DiskTotalSpace(const char *zPath)
{
	struct statvfs fiData;
	if((statvfs(zPath,&fiData)) < 0 ) {
		return 0;
	}
	return (libcox_int64)(fiData.f_blocks * fiData.f_bsize);
}
/* int (*xChown)(const char *, const char *) */
static int UnixVfs_Chown(const char *zPath, const char *zUser)
{
#ifndef LIBCOX_UNIX_STATIC_BUILD
  struct passwd *pwd;
  uid_t uid;
  int rc;
  pwd = getpwnam(zUser);   /* Try getting UID for username */
  if (pwd == 0) {
    return -1;
  }
  uid = pwd->pw_uid;
  rc = chown(zPath, uid, -1);
  return rc == 0 ? LIBCOX_OK : -1;
#else
	SXUNUSED(zPath);
	SXUNUSED(zUser);
	return -1;
#endif /* LIBCOX_UNIX_STATIC_BUILD */
}
/* int (*xChgrp)(const char *, const char *) */
static int UnixVfs_Chgrp(const char *zPath, const char *zGroup)
{
#ifndef LIBCOX_UNIX_STATIC_BUILD
  struct group *group;
  gid_t gid;
  int rc;
  group = getgrnam(zGroup);
  if (group == 0) {
    return -1;
  }
  gid = group->gr_gid;
  rc = chown(zPath, -1, gid);
  return rc == 0 ? LIBCOX_OK : -1;
#else
	SXUNUSED(zPath);
	SXUNUSED(zGroup);
	return -1;
#endif /* LIBCOX_UNIX_STATIC_BUILD */
}
/* int (*xIsfile)(const char *) */
static int UnixVfs_isfile(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){
	 return -1;
	}
	rc = S_ISREG(st.st_mode);
	return rc ? LIBCOX_OK : -1 ;
}
/* int (*xIslink)(const char *) */
static int UnixVfs_islink(const char *zPath)
{
	struct stat st;
	int rc;
	rc = stat(zPath, &st);
	if( rc != 0 ){
	 return -1;
	}
	rc = S_ISLNK(st.st_mode);
	return rc ? LIBCOX_OK : -1 ;
}
/* int (*xReadable)(const char *) */
static int UnixVfs_isreadable(const char *zPath)
{
	int rc;
	rc = access(zPath, R_OK);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xWritable)(const char *) */
static int UnixVfs_iswritable(const char *zPath)
{
	int rc;
	rc = access(zPath, W_OK);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xExecutable)(const char *) */
static int UnixVfs_isexecutable(const char *zPath)
{
	int rc;
	rc = access(zPath, X_OK);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xFiletype)(const char *, libcox_context *) */
static int UnixVfs_Filetype(const char *zPath, libcox_context *pCtx)
{
	struct stat st;
	int rc;
    rc = stat(zPath, &st);
	if( rc != 0 ){
	  /* Expand 'unknown' */
	  libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
	  return -1;
	}
	if(S_ISREG(st.st_mode) ){
		libcox_result_string(pCtx, "file", sizeof("file")-1);
	}else if(S_ISDIR(st.st_mode)){
		libcox_result_string(pCtx, "dir", sizeof("dir")-1);
	}else if(S_ISLNK(st.st_mode)){
		libcox_result_string(pCtx, "link", sizeof("link")-1);
	}else if(S_ISBLK(st.st_mode)){
		libcox_result_string(pCtx, "block", sizeof("block")-1);
    }else if(S_ISSOCK(st.st_mode)){
		libcox_result_string(pCtx, "socket", sizeof("socket")-1);
	}else if(S_ISFIFO(st.st_mode)){
       libcox_result_string(pCtx, "fifo", sizeof("fifo")-1);
	}else{
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
	}
	return LIBCOX_OK;
}
/* int (*xGetenv)(const char *, libcox_context *) */
static int UnixVfs_Getenv(const char *zVar, libcox_context *pCtx)
{
	char *zEnv;
	zEnv = getenv(zVar);
	if( zEnv == 0 ){
	  return -1;
	}
	libcox_result_string(pCtx, zEnv, -1/*Compute length automatically*/);
	return LIBCOX_OK;
}
/* int (*xSetenv)(const char *, const char *) */
static int UnixVfs_Setenv(const char *zName, const char *zValue)
{
   int rc;
   rc = setenv(zName, zValue, 1);
   return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xMmap)(const char *, void **, libcox_int64 *) */
static int UnixVfs_Mmap(const char *zPath, void **ppMap, libcox_int64 *pSize)
{
	struct stat st;
	void *pMap;
	int fd;
	int rc;
	/* Open the file in a read-only mode */
	fd = open(zPath, O_RDONLY);
	if( fd < 0 ){
		return -1;
	}
	/* stat the handle */
	fstat(fd, &st);
	/* Obtain a memory view of the whole file */
	pMap = mmap(0, st.st_size, PROT_READ, MAP_PRIVATE|MAP_FILE, fd, 0);
	rc = LIBCOX_OK;
	if( pMap == MAP_FAILED ){
		rc = -1;
	}else{
		/* Point to the memory view */
		*ppMap = pMap;
		*pSize = (libcox_int64)st.st_size;
	}
	close(fd);
	return rc;
}
/* void (*xUnmap)(void *, libcox_int64)  */
static void UnixVfs_Unmap(void *pView, libcox_int64 nSize)
{
	munmap(pView, (size_t)nSize);
}
/* void (*xTempDir)(libcox_context *) */
static void UnixVfs_TempDir(libcox_context *pCtx)
{
	static const char *azDirs[] = {
     "/var/tmp", 
     "/usr/tmp", 
	 "/usr/local/tmp"
  };
  unsigned int i;
  struct stat buf;
  const char *zDir;
  zDir = getenv("TMPDIR");
  if( zDir && zDir[0] != 0 && !access(zDir, 07) ){
	  libcox_result_string(pCtx, zDir, -1);
	  return;
  }
  for(i=0; i<sizeof(azDirs)/sizeof(azDirs[0]); i++){
	zDir=azDirs[i];
    if( zDir==0 ) continue;
    if( stat(zDir, &buf) ) continue;
    if( !S_ISDIR(buf.st_mode) ) continue;
    if( access(zDir, 07) ) continue;
    /* Got one */
	libcox_result_string(pCtx, zDir, -1);
	return;
  }
  /* Default temp dir */
  libcox_result_string(pCtx, "/tmp", (int)sizeof("/tmp")-1);
}
/* unsigned int (*xProcessId)(void) */
static unsigned int UnixVfs_ProcessId(void)
{
	return (unsigned int)getpid();
}
/* int (*xUid)(void) */
static int UnixVfs_uid(void)
{
	return (int)getuid();
}
/* int (*xGid)(void) */
static int UnixVfs_gid(void)
{
	return (int)getgid();
}
/* int (*xUmask)(int) */
static int UnixVfs_Umask(int new_mask)
{
	int old_mask;
	old_mask = umask(new_mask);
	return old_mask;
}
/* void (*xUsername)(libcox_context *) */
static void UnixVfs_Username(libcox_context *pCtx)
{
#ifndef LIBCOX_UNIX_STATIC_BUILD
  struct passwd *pwd;
  uid_t uid;
  uid = getuid();
  pwd = getpwuid(uid);   /* Try getting UID for username */
  if (pwd == 0) {
    return;
  }
  /* Return the username */
  libcox_result_string(pCtx, pwd->pw_name, -1);
#else
  libcox_result_string(pCtx, "Unknown", -1);
#endif /* LIBCOX_UNIX_STATIC_BUILD */
  return;
}
/* int (*xLink)(const char *, const char *, int) */
static int UnixVfs_link(const char *zSrc, const char *zTarget, int is_sym)
{
	int rc;
	if( is_sym ){
		/* Symbolic link */
		rc = symlink(zSrc, zTarget);
	}else{
		/* Hard link */
		rc = link(zSrc, zTarget);
	}
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xChroot)(const char *) */
static int UnixVfs_chroot(const char *zRootDir)
{
	int rc;
	rc = chroot(zRootDir);
	return rc == 0 ? LIBCOX_OK : -1;
}
/* int (*xOpenDir)(const char *, libcox_value *, void **) */
static int UnixDir_Open(const char *zPath, libcox_value *pResource, void **ppHandle)
{
	DIR *pDir;
	/* Open the target directory */
	pDir = opendir(zPath);
	if( pDir == 0 ){
		pResource = 0; /* Compiler warning */
		return -1;
	}
	/* Save our structure */
	*ppHandle = pDir;
	return LIBCOX_OK;
}
/* void (*xCloseDir)(void *) */
static void UnixDir_Close(void *pUserData)
{
	closedir((DIR *)pUserData);
}
/* (*xReadDir)(void *, libcox_value *) */
static int UnixDir_Read(void *pUserData, libcox_value *pVal)
{
	DIR *pDir = (DIR *)pUserData;
	struct dirent *pEntry;
	char *zName = 0; /* cc warning */
	sxu32 n = 0;
	for(;;){
		pEntry = readdir(pDir);
		if( pEntry == 0 ){
			/* No more entries to process */
			return -1;
		}
		zName = pEntry->d_name; 
		n = SyStrlen(zName);
		/* Ignore '.' && '..' */
		if( n > sizeof("..")-1 || zName[0] != '.' || ( n == sizeof("..")-1 && zName[1] != '.') ){
			break;
		}
		/* Next entry */
	}
	/* Return the current file name */
	libcox_value_string(pVal, zName, (int)n);
	return LIBCOX_OK;
}
/* void (*xRewindDir)(void *) */
static void UnixDir_Rewind(void *pUserData)
{
	rewinddir((DIR *)pUserData);
}
/* Export the UNIX vfs */
static const libcox_vfs sUnixVfs = {
	"Unix_vfs", 
	LIBCOX_VFS_VERSION,
	0,
	PATH_MAX,
	UnixVfs_chdir,    /* int (*xChdir)(const char *) */
	UnixVfs_chroot,   /* int (*xChroot)(const char *); */
	UnixVfs_getcwd,   /* int (*xGetcwd)(libcox_context *) */
	UnixVfs_mkdir,    /* int (*xMkdir)(const char *, int, int) */
	UnixVfs_rmdir,    /* int (*xRmdir)(const char *) */ 
	UnixVfs_isdir,    /* int (*xIsdir)(const char *) */
	UnixVfs_Rename,   /* int (*xRename)(const char *, const char *) */
	UnixVfs_Realpath, /*int (*xRealpath)(const char *, libcox_context *)*/
		/* Directory */ 
	UnixDir_Open,              
	UnixDir_Close,   
	UnixDir_Read, 
	UnixDir_Rewind,
		/* Systems */
	UnixVfs_Sleep,    /* int (*xSleep)(unsigned int) */
	UnixVfs_unlink,   /* int (*xUnlink)(const char *) */
	UnixVfs_FileExists, /* int (*xFileExists)(const char *) */
	UnixVfs_Chmod, /*int (*xChmod)(const char *, int)*/
	UnixVfs_Chown, /*int (*xChown)(const char *, const char *)*/
	UnixVfs_Chgrp, /*int (*xChgrp)(const char *, const char *)*/
	UnixVfs_DiskFreeSpace,             /* libcox_int64 (*xFreeSpace)(const char *) */
	UnixVfs_DiskTotalSpace,             /* libcox_int64 (*xTotalSpace)(const char *) */
	UnixVfs_FileSize, /* libcox_int64 (*xFileSize)(const char *) */
	UnixVfs_FileAtime, /* libcox_int64 (*xFileAtime)(const char *) */
	UnixVfs_FileMtime, /* libcox_int64 (*xFileMtime)(const char *) */
	UnixVfs_FileCtime, /* libcox_int64 (*xFileCtime)(const char *) */
	UnixVfs_Stat,  /* int (*xStat)(const char *, libcox_value *, libcox_value *) */
	UnixVfs_lStat, /* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
	UnixVfs_isfile,     /* int (*xIsfile)(const char *) */
	UnixVfs_islink,     /* int (*xIslink)(const char *) */
	UnixVfs_isreadable, /* int (*xReadable)(const char *) */
	UnixVfs_iswritable, /* int (*xWritable)(const char *) */
	UnixVfs_isexecutable, /* int (*xExecutable)(const char *) */
	UnixVfs_Filetype,   /* int (*xFiletype)(const char *, libcox_context *) */
	UnixVfs_Getenv,     /* int (*xGetenv)(const char *, libcox_context *) */
	UnixVfs_Setenv,     /* int (*xSetenv)(const char *, const char *) */ 
	UnixVfs_Touch,      /* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
	UnixVfs_Mmap,       /* int (*xMmap)(const char *, void **, libcox_int64 *) */
	UnixVfs_Unmap,      /* void (*xUnmap)(void *, libcox_int64);  */
	UnixVfs_link,       /* int (*xLink)(const char *, const char *, int) */
	UnixVfs_Umask,      /* int (*xUmask)(int) */
	UnixVfs_TempDir,    /* void (*xTempDir)(libcox_context *) */
	UnixVfs_ProcessId,  /* unsigned int (*xProcessId)(void) */
	UnixVfs_uid, /* int (*xUid)(void) */
	UnixVfs_gid, /* int (*xGid)(void) */
	UnixVfs_Username,    /* void (*xUsername)(libcox_context *) */
	0 /* int (*Syserror)(const char *, libcox_context *) */
};
#endif /* __WINNT__/__UNIXES__ */
/*
 * Export the builtin vfs.
 * Return a pointer to the builtin vfs if available.
 * Otherwise return the null_vfs [i.e: a no-op vfs] instead.
 * Note:
 *  The built-in vfs is always available for Windows/UNIX systems.
 * Note:
 *  If the engine is compiled with the LIBCOX_DISABLE_DISK_IO/LIBCOX_DISABLE_BUILTIN_FUNC
 *  directives defined then this function return the null_vfs instead.
 */
LIBCOX_PRIVATE const libcox_vfs * libcoxExportBuiltinVfs(void)
{
#ifndef LIBCOX_DISABLE_BUILTIN_FUNC
#ifdef LIBCOX_DISABLE_DISK_IO
	return &null_vfs;
#else
#ifdef __WINNT__
	return &sWinVfs;
#elif defined(__UNIXES__)
	return &sUnixVfs;
#else
	return &null_vfs;
#endif /* __WINNT__/__UNIXES__ */
#endif /*LIBCOX_DISABLE_DISK_IO*/
#else
	return &null_vfs;
#endif /* LIBCOX_DISABLE_BUILTIN_FUNC */
}

/*
 * ----------------------------------------------------------
 * File: parse.c
 * MD5: 97aa540191ba2235a7e49fff2e942fd0
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/* $SymiscID: parse.c v1.3 Win7 2013-07-08 05:42 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/* libcox command Lexer & parser */
/*
 * Tokenize a raw input.
 * Get a single low-level token from the input file. Update the stream pointer so that
 * it points to the first character beyond the extracted token.
 */
static sxi32 libcoxTokenizeInput(SyStream *pStream,SyToken *pToken,void *pUserData,void *pCtxData)
{
	const unsigned char *zIn;
	SyString *pStr;
	sxi32 c;
	/* Ignore leading white spaces */
	while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisSpace(pStream->zText[0]) ){
		/* Advance the stream cursor */
		if( pStream->zText[0] == '\n' ){
			/* Update line counter */
			pStream->nLine++;
		}
		pStream->zText++;
	}
	if( pStream->zText >= pStream->zEnd ){
		/* End of input reached */
		return SXERR_EOF;
	}
	/* Record token starting position and line */
	pToken->nLine = pStream->nLine;
	pToken->pUserData = 0;
	pStr = &pToken->sData;
	SyStringInitFromBuf(pStr, pStream->zText, 0);
	if( pStream->zText[0] == ';' ){
		pStream->zText++;
		/* A stream of semi-colons */
		while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && pStream->zText[0] == ';' ){
			pStream->zText++;
		}
		/* Mark the token */
		pToken->nType = LIBCOX_TK_SEMI;
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
	}else if( SyisDigit(pStream->zText[0]) ){
		pStream->zText++;
		/* Decimal digit stream */
		while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
			pStream->zText++;
		}
		/* Mark the token as integer until we encounter a real number */
		pToken->nType = LIBCOX_TK_INTEGER;
		if( pStream->zText < pStream->zEnd ){
			c = pStream->zText[0];
			if( c == '.' ){
				/* Real number */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
					pStream->zText++;
				}
				if( pStream->zText < pStream->zEnd ){
					c = pStream->zText[0];
					if( c=='e' || c=='E' ){
						pStream->zText++;
						if( pStream->zText < pStream->zEnd ){
							c = pStream->zText[0];
							if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  &&
								pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
									pStream->zText++;
							}
							while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
								pStream->zText++;
							}
						}
					}
				}
				pToken->nType = LIBCOX_TK_REAL;
			}else if( c=='e' || c=='E' ){
				SXUNUSED(pUserData); /* Prevent compiler warning */
				SXUNUSED(pCtxData);
				pStream->zText++;
				if( pStream->zText < pStream->zEnd ){
					c = pStream->zText[0];
					if( (c =='+' || c=='-') && &pStream->zText[1] < pStream->zEnd  &&
						pStream->zText[1] < 0xc0 && SyisDigit(pStream->zText[1]) ){
							pStream->zText++;
					}
					while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisDigit(pStream->zText[0]) ){
						pStream->zText++;
					}
				}
				pToken->nType = LIBCOX_TK_REAL;
			}else if( c == 'x' || c == 'X' ){
				/* Hex digit stream */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && pStream->zText[0] < 0xc0 && SyisHex(pStream->zText[0]) ){
					pStream->zText++;
				}
			}else if(c  == 'b' || c == 'B' ){
				/* Binary digit stream */
				pStream->zText++;
				while( pStream->zText < pStream->zEnd && (pStream->zText[0] == '0' || pStream->zText[0] == '1') ){
					pStream->zText++;
				}
			}
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
	}else if( pStream->zText[0] == '"' || pStream->zText[0] == '\'' ){
		/* Quoted string */
		c = pStream->zText[0];
		pStream->zText++;
		pStr->zString++;
		while( pStream->zText < pStream->zEnd ){
			if( pStream->zText[0] == c  ){
				if( pStream->zText[-1] != '\\' ){
					break;
				}
			}
			if( pStream->zText[0] == '\n' ){
				pStream->nLine++;
			}
			pStream->zText++;
		}
		/* Record token length and type */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
		pToken->nType = LIBCOX_TK_STREAM;
		/* Jump the trailing quote */
		pStream->zText++;
	}else{
		/* The following code fragment is taken verbatim from the xPP source tree.
		 * xPP is a modern embeddable macro processor with advanced features useful for
		 * application seeking for a production quality, ready to use macro processor.
		 * xPP is a widely used library developed and maintened by Symisc Systems.
		 * You can reach the xPP home page by following this link:
		 * http://symisc.net/
		 */
		/* Isolate UTF-8 or alphanumeric stream */
		if( pStream->zText[0] < 0xc0 ){
			pStream->zText++;
		}
		for(;;){
			zIn = pStream->zText;
			if( zIn[0] >= 0xc0 ){
				zIn++;
				/* UTF-8 stream */
				while( zIn < pStream->zEnd && ((zIn[0] & 0xc0) == 0x80) ){
					zIn++;
				}
			}
			/* Delimit the stream */
			while( zIn < pStream->zEnd && zIn[0] < 0xc0 && zIn[0] != ';' && !SyisSpace(zIn[0]) ){
				zIn++;
			}
			if( zIn == pStream->zText ){
				/* End of the stream */
				break;
			}
			/* Synchronize pointers */
			pStream->zText = zIn;
		}
		/* Record token length */
		pStr->nByte = (sxu32)((const char *)pStream->zText-pStr->zString);
		/* A simple identifier */
		pToken->nType = LIBCOX_TK_STREAM;
	}
	/* Tell the upper-layer to save the extracted token for later processing */
	return SXRET_OK;
}
/*
 * Tokenize a raw input. 
 */
static sxi32 libcoxTokenize(const char *zInput,sxu32 nLen,SySet *pOut)
{
	SyLex sLexer;
	sxi32 rc;
	/* Initialize the lexer */
	rc = SyLexInit(&sLexer, &(*pOut),libcoxTokenizeInput,0);
	if( rc != SXRET_OK ){
		return rc;
	}
	/* Tokenize input */
	rc = SyLexTokenizeInput(&sLexer, zInput, nLen, 0, 0, 0);
	/* Release the lexer */
	SyLexRelease(&sLexer);
	/* Tokenization result */
	return rc;
}
/*
 * libcox parser state is recorded in an instance of the following structure.
 */
typedef struct libcox_gen_state libcox_gen_state;
struct libcox_gen_state
{
	SyToken *pIn;  /* Token stream */
	SyToken *pEnd; /* End of the token stream */
	libcox *plibcox;    /* libcox handle  */
	libcox_value *pRes; /* Command execution result */
};
static int libcoxInitContext(libcox_context *pCtx,libcox *plibcox,libcox_cmd *pCmd,libcox_value *pResult)
{
	pCtx->plibcox = plibcox;
	pCtx->pCmd = pCmd;
	SyBlobInit(&pCtx->sWorker,&plibcox->sMem);
	SySetInit(&pCtx->sVar, &plibcox->sMem, sizeof(libcox_value *));
	pCtx->pRet = pResult;
	return LIBCOX_OK;
}
static void libcoxReleaseContext(libcox_context *pCtx)
{
	sxu32 n;
	if( SySetUsed(&pCtx->sVar) > 0 ){
		/* Context alloacated values */
		libcox_value **apObj = (libcox_value **)SySetBasePtr(&pCtx->sVar);
		for( n = 0 ; n < SySetUsed(&pCtx->sVar) ; ++n ){
			if( apObj[n] == 0 ){
				/* Already released */
				continue;
			}
			libcoxMemObjRelease(apObj[n]);
			SyMemBackendPoolFree(&pCtx->plibcox->sMem, apObj[n]);
		}
		SySetRelease(&pCtx->sVar);
	}
	SyBlobRelease(&pCtx->sWorker);
}
static void libcoxObjContainerDestroy(SySet *aValues,libcox *plibcox)
{
	libcox_value **apValues = (libcox_value **)SySetBasePtr(aValues);
	sxu32 n;
	for( n = 0 ; n < SySetUsed(aValues) ; ++n ){
		libcox_value *pValue = apValues[n];
		/* Destroy the object */
		libcoxObjectValueDestroy(plibcox,pValue);
	}
	SySetRelease(aValues);
}
static int libcoxExec(libcox_gen_state *pGen)
{
	libcox_value *pValue;
	libcox_context sCtx;
	libcox_cmd *pCmd;
	libcox *pStore;
	SySet sValue;
	int rc;
	/* Get the target command */
	if( !(pGen->pIn->nType & LIBCOX_TK_STREAM) ){
		libcoxGenError(pGen->plibcox,"Invalid libcox command");
		return SXERR_INVALID;
	}
	pStore = pGen->plibcox;
	/* Extract it */
	pCmd = libcoxFetchCommand(pStore,&pGen->pIn->sData);
	if( pCmd == 0 ){
		libcoxGenErrorFormat(pStore,"Unknown libcox command: '%z'",&pGen->pIn->sData);
		return SXERR_UNKNOWN;
	}
	pGen->pIn++;
	/* Collect command arguments */
	SySetInit(&sValue,&pStore->sMem,sizeof(libcox_value *));
	while( pGen->pIn < pGen->pEnd && (pGen->pIn->nType != LIBCOX_TK_SEMI /*';'*/) ){
		pValue = libcoxNewObjectValue(pStore,pGen->pIn);
		if( pValue ){
			SySetPut(&sValue,(const void *)&pValue);
		}
		/* Point to the next token */
		pGen->pIn++;
	}
	/* Init the call context */
	libcoxInitContext(&sCtx,pStore,pCmd,pGen->pRes);
	/* Invoke the command */
	rc = pCmd->xCmd(&sCtx,(int)SySetUsed(&sValue),(libcox_value **)SySetBasePtr(&sValue));
	if( rc == LIBCOX_ABORT ){
		libcoxGenErrorFormat(pGen->plibcox,"libcox command '%z' request an operation abort",&pCmd->sName);
	}else{
		rc = LIBCOX_OK;
	}
	/* Invoke any output consumer callback */
	if( pStore->xResultConsumer && rc == LIBCOX_OK ){
		rc = pStore->xResultConsumer(sCtx.pRet,pStore->pUserData);
		if( rc != LIBCOX_ABORT ){
			rc = LIBCOX_OK;
		}
	}
	/* Cleanup */
	libcoxReleaseContext(&sCtx);
	libcoxObjContainerDestroy(&sValue,pGen->plibcox);
	return rc;
}
LIBCOX_PRIVATE int libcoxProcessInput(libcox *plibcox,libcox_value **ppOut,const char *zInput,sxu32 nByte)
{
	SySet sToken;
	int rc;
	/* Prepare the tokenizer */
	SySetInit(&sToken,&plibcox->sMem,sizeof(SyToken));
	/* Tokenize the input */
	rc = libcoxTokenize(zInput,nByte,&sToken);
	if( rc != LIBCOX_OK ){
		goto fail;
	}
	rc = LIBCOX_OK;
	if( SySetUsed(&sToken) > 0 ){
		libcox_gen_state sGen;
		libcox_value *pResult;
		/* Init the parser state */
		pResult = libcoxNewObjectValue(plibcox,0);
		if( pResult == 0 ){
			libcoxGenOutofMem(plibcox);
			rc = LIBCOX_NOMEM;
			goto fail;
		}
		sGen.pIn = (SyToken *)SySetBasePtr(&sToken);
		sGen.pEnd = &sGen.pIn[SySetUsed(&sToken)];
		sGen.plibcox = plibcox;
		sGen.pRes = pResult;
		/* Process the pipelined commands */
		for(;;){
			while( sGen.pIn < sGen.pEnd && sGen.pIn->nType == LIBCOX_TK_SEMI ){
				/* Discard leading and trailing semi-colons */
				sGen.pIn++;
			}
			if( sGen.pIn >= sGen.pEnd ){
				/* End of the libcox input */
				break;
			}
			/* Execute the command if available */
			rc = libcoxExec(&sGen);
			if( rc != LIBCOX_OK ){
				break;
			}
		}
		/* Execution result */
		if( rc == LIBCOX_OK && ppOut ){
			*ppOut = pResult;
		}else{
			/* Release the memory object */
			libcoxObjectValueDestroy(plibcox,pResult);
		}
	}
	/* Fall through */
fail:
	/* Cleanup */
	SySetRelease(&sToken);
	return rc;
}
/*
 * ----------------------------------------------------------
 * File: obj.c
 * MD5: 0ec7db9680d2c6cf2bef01a031b171b5
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/* $SymiscID: obj.c v1.6 Linux 2013-07-10 03:52 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/* This file manage low-level stuff related to indexed memory objects [i.e: libcox_value] */
/*
 * Notes on memory objects [i.e: libcox_value].
 * Internally, the LIBCOX engine manipulates nearly all LIBCOX values
 * [i.e: string, int, float, resource, object, bool, null..] as libcox_values structures.
 * Each libcox_values struct may cache multiple representations (string, 
 * integer etc.) of the same value.
 */
/*
 * Convert a 64-bit IEEE double into a 64-bit signed integer.
 * If the double is too large, return 0x8000000000000000.
 *
 * Most systems appear to do this simply by assigning ariables and without
 * the extra range tests.
 * But there are reports that windows throws an expection if the floating 
 * point value is out of range.
 */
static sxi64 MemObjRealToInt(libcox_value *pObj)
{
#ifdef LIBCOX_OMIT_FLOATING_POINT
	/* Real and 64bit integer are the same when floating point arithmetic
	 * is omitted from the build.
	 */
	return pObj->x.rVal;
#else
 /*
  ** Many compilers we encounter do not define constants for the
  ** minimum and maximum 64-bit integers, or they define them
  ** inconsistently.  And many do not understand the "LL" notation.
  ** So we define our own static constants here using nothing
  ** larger than a 32-bit integer constant.
  */
  static const sxi64 maxInt = LARGEST_INT64;
  static const sxi64 minInt = SMALLEST_INT64;
  libcox_real r = pObj->x.rVal;
  if( r<(libcox_real)minInt ){
    return minInt;
  }else if( r>(libcox_real)maxInt ){
    /* minInt is correct here - not maxInt.  It turns out that assigning
    ** a very large positive number to an integer results in a very large
    ** negative integer.  This makes no sense, but it is what x86 hardware
    ** does so for compatibility we will do the same in software. */
    return minInt;
  }else{
    return (sxi64)r;
  }
#endif
}
/*
 * Convert a raw token value typically a stream of digit [i.e: hex, octal, binary or decimal] 
 * to a 64-bit integer.
 */
LIBCOX_PRIVATE sxi64 libcoxTokenValueToInt64(SyString *pVal)
{
	sxi64 iVal = 0;
	if( pVal->nByte <= 0 ){
		return 0;
	}
	if( pVal->zString[0] == '0' ){
		sxi32 c;
		if( pVal->nByte == sizeof(char) ){
			return 0;
		}
		c = pVal->zString[1];
		if( c  == 'x' || c == 'X' ){
			/* Hex digit stream */
			SyHexStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		}else if( c == 'b' || c == 'B' ){
			/* Binary digit stream */
			SyBinaryStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		}else{
			/* Octal digit stream */
			SyOctalStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
		}
	}else{
		/* Decimal digit stream */
		SyStrToInt64(pVal->zString, pVal->nByte, (void *)&iVal, 0);
	}
	return iVal;
}
/*
 * Return some kind of 64-bit integer value which is the best we can
 * do at representing the value that pObj describes as a string
 * representation.
 */
static sxi64 MemObjStringToInt(libcox_value *pObj)
{
	SyString sVal;
	SyStringInitFromBuf(&sVal, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
	return libcoxTokenValueToInt64(&sVal);	
}
/*
 * Return some kind of integer value which is the best we can
 * do at representing the value that pObj describes as an integer.
 * If pObj is an integer, then the value is exact. If pObj is
 * a floating-point then  the value returned is the integer part.
 * If pObj is a string, then we make an attempt to convert it into
 * a integer and return that. 
 * If pObj represents a NULL value, return 0.
 */
static sxi64 MemObjIntValue(libcox_value *pObj)
{
	sxi32 iFlags;
	iFlags = pObj->iFlags;
	if (iFlags & MEMOBJ_REAL ){
		return MemObjRealToInt(&(*pObj));
	}else if( iFlags & (MEMOBJ_INT|MEMOBJ_BOOL) ){
		return pObj->x.iVal;
	}else if (iFlags & MEMOBJ_STRING) {
		return MemObjStringToInt(&(*pObj));
	}else if( iFlags & MEMOBJ_NULL ){
		return 0;
	}else if( iFlags & MEMOBJ_HASHMAP ){
		libcox_hashmap *pMap = (libcox_hashmap *)pObj->x.pOther;
		sxu32 n = libcoxHashmapCount(pMap);
		libcoxHashmapUnref(pMap);
		/* Return total number of entries in the hashmap */
		return n; 
	}
	/* CANT HAPPEN */
	return 0;
}
/*
 * Return some kind of real value which is the best we can
 * do at representing the value that pObj describes as a real.
 * If pObj is a real, then the value is exact.If pObj is an
 * integer then the integer  is promoted to real and that value
 * is returned.
 * If pObj is a string, then we make an attempt to convert it
 * into a real and return that. 
 * If pObj represents a NULL value, return 0.0
 */
static libcox_real MemObjRealValue(libcox_value *pObj)
{
	sxi32 iFlags;
	iFlags = pObj->iFlags;
	if( iFlags & MEMOBJ_REAL ){
		return pObj->x.rVal;
	}else if (iFlags & (MEMOBJ_INT|MEMOBJ_BOOL) ){
		return (libcox_real)pObj->x.iVal;
	}else if (iFlags & MEMOBJ_STRING){
		SyString sString;
#ifdef LIBCOX_OMIT_FLOATING_POINT
		libcox_real rVal = 0;
#else
		libcox_real rVal = 0.0;
#endif
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if( SyBlobLength(&pObj->sBlob) > 0 ){
			/* Convert as much as we can */
#ifdef LIBCOX_OMIT_FLOATING_POINT
			rVal = MemObjStringToInt(&(*pObj));
#else
			SyStrToReal(sString.zString, sString.nByte, (void *)&rVal, 0);
#endif
		}
		return rVal;
	}else if( iFlags & MEMOBJ_NULL ){
#ifdef LIBCOX_OMIT_FLOATING_POINT
		return 0;
#else
		return 0.0;
#endif
	}else if( iFlags & MEMOBJ_HASHMAP ){
		/* Return the total number of entries in the hashmap */
		libcox_hashmap *pMap = (libcox_hashmap *)pObj->x.pOther;
		libcox_real n = (libcox_real)libcoxHashmapCount(pMap);
		libcoxHashmapUnref(pMap);
		return n;
	}
	/* NOT REACHED  */
	return 0;
}
/* 
 * Return the string representation of a given libcox_value.
 * This function never fail and always return SXRET_OK.
 */
static sxi32 MemObjStringValue(SyBlob *pOut,libcox_value *pObj)
{
	if( pObj->iFlags & MEMOBJ_REAL ){
		SyBlobFormat(&(*pOut), "%.15g", pObj->x.rVal);
	}else if( pObj->iFlags & MEMOBJ_INT ){
		SyBlobFormat(&(*pOut), "%qd", pObj->x.iVal);
		/* %qd (BSD quad) is equivalent to %lld in the libc printf */
	}else if( pObj->iFlags & MEMOBJ_BOOL ){
		if( pObj->x.iVal ){
			SyBlobAppend(&(*pOut),"true", sizeof("true")-1);
		}else{
			SyBlobAppend(&(*pOut),"false", sizeof("false")-1);
		}
	}else if( pObj->iFlags & MEMOBJ_HASHMAP ){
		/* Serialize JSON object or array */
		libcoxJsonSerialize(pObj,pOut);
		libcoxHashmapUnref((libcox_hashmap *)pObj->x.pOther);
	}
	return SXRET_OK;
}
/*
 * Return some kind of boolean value which is the best we can do
 * at representing the value that pObj describes as a boolean.
 * When converting to boolean, the following values are considered FALSE:
 * NULL
 * the boolean FALSE itself.
 * the integer 0 (zero).
 * the real 0.0 (zero).
 * the empty string, a stream of zero [i.e: "0", "00", "000", ...] and the string
 * "false".
 * an array with zero elements. 
 */
static sxi32 MemObjBooleanValue(libcox_value *pObj)
{
	sxi32 iFlags;	
	iFlags = pObj->iFlags;
	if (iFlags & MEMOBJ_REAL ){
#ifdef LIBCOX_OMIT_FLOATING_POINT
		return pObj->x.rVal ? 1 : 0;
#else
		return pObj->x.rVal != 0.0 ? 1 : 0;
#endif
	}else if( iFlags & MEMOBJ_INT ){
		return pObj->x.iVal ? 1 : 0;
	}else if (iFlags & MEMOBJ_STRING) {
		SyString sString;
		SyStringInitFromBuf(&sString, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if( sString.nByte == 0 ){
			/* Empty string */
			return 0;
		}else if( (sString.nByte == sizeof("true") - 1 && SyStrnicmp(sString.zString, "true", sizeof("true")-1) == 0) ||
			(sString.nByte == sizeof("on") - 1 && SyStrnicmp(sString.zString, "on", sizeof("on")-1) == 0) ||
			(sString.nByte == sizeof("yes") - 1 && SyStrnicmp(sString.zString, "yes", sizeof("yes")-1) == 0) ){
				return 1;
		}else if( sString.nByte == sizeof("false") - 1 && SyStrnicmp(sString.zString, "false", sizeof("false")-1) == 0 ){
			return 0;
		}else{
			const char *zIn, *zEnd;
			zIn = sString.zString;
			zEnd = &zIn[sString.nByte];
			while( zIn < zEnd && zIn[0] == '0' ){
				zIn++;
			}
			return zIn >= zEnd ? 0 : 1;
		}
	}else if( iFlags & MEMOBJ_NULL ){
		return 0;
	}else if( iFlags & MEMOBJ_HASHMAP ){
		libcox_hashmap *pMap = (libcox_hashmap *)pObj->x.pOther;
		sxu32 n = libcoxHashmapCount(pMap);
		libcoxHashmapUnref(pMap);
		return n > 0 ? TRUE : FALSE;
	}
	/* NOT REACHED */
	return 0;
}
/*
 * If the libcox_value is of type real, try to make it an integer also.
 */
static sxi32 MemObjTryIntger(libcox_value *pObj)
{
	sxi64 iVal = MemObjRealToInt(&(*pObj));
  /* Only mark the value as an integer if
  **
  **    (1) the round-trip conversion real->int->real is a no-op, and
  **    (2) The integer is neither the largest nor the smallest
  **        possible integer
  **
  ** The second and third terms in the following conditional enforces
  ** the second condition under the assumption that addition overflow causes
  ** values to wrap around.  On x86 hardware, the third term is always
  ** true and could be omitted.  But we leave it in because other
  ** architectures might behave differently.
  */
	if( pObj->x.rVal ==(libcox_real)iVal && iVal>SMALLEST_INT64 && iVal<LARGEST_INT64 ){
		pObj->x.iVal = iVal; 
		pObj->iFlags = MEMOBJ_INT;
	}
	return SXRET_OK;
}
/*
 * Check whether the libcox_value is numeric [i.e: int/float/bool] or looks
 * like a numeric number [i.e: if the libcox_value is of type string.].
 * Return TRUE if numeric.FALSE otherwise.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjIsNumeric(libcox_value *pObj)
{
	if( pObj->iFlags & ( MEMOBJ_BOOL|MEMOBJ_INT|MEMOBJ_REAL) ){
		return TRUE;
	}else if( pObj->iFlags & (MEMOBJ_NULL|MEMOBJ_HASHMAP) ){
		return FALSE;
	}else if( pObj->iFlags & MEMOBJ_STRING ){
		SyString sStr;
		sxi32 rc;
		SyStringInitFromBuf(&sStr, SyBlobData(&pObj->sBlob), SyBlobLength(&pObj->sBlob));
		if( sStr.nByte <= 0 ){
			/* Empty string */
			return FALSE;
		}
		/* Check if the string representation looks like a numeric number */
		rc = SyStrIsNumeric(sStr.zString, sStr.nByte, 0, 0);
		return rc == SXRET_OK ? TRUE : FALSE;
	}
	/* NOT REACHED */
	return FALSE;
}
/*
 * Convert a libcox_value to type integer.Invalidate any prior representations.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjToInteger(libcox_value *pObj)
{
	if( (pObj->iFlags & MEMOBJ_INT) == 0 ){
		/* Preform the conversion */
		pObj->x.iVal = MemObjIntValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_INT);
	}
	return SXRET_OK;
}
/*
 * Try a get an integer representation of the given libcox_value.
 * If the libcox_value is not of type real, this function is a no-op.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjTryInteger(libcox_value *pObj)
{
	if( pObj->iFlags & MEMOBJ_REAL ){
		/* Work only with reals */
		MemObjTryIntger(&(*pObj));
	}
	return SXRET_OK;
}
/*
 * Convert a libcox_value to type real (Try to get an integer representation also).
 * Invalidate any prior representations
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjToReal(libcox_value *pObj)
{
	if((pObj->iFlags & MEMOBJ_REAL) == 0 ){
		/* Preform the conversion */
		pObj->x.rVal = MemObjRealValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_REAL);
	}
	return SXRET_OK;
}
/*
 * Convert a libcox_value to type boolean.Invalidate any prior representations.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjToBool(libcox_value *pObj)
{
	if( (pObj->iFlags & MEMOBJ_BOOL) == 0 ){
		/* Preform the conversion */
		pObj->x.iVal = MemObjBooleanValue(&(*pObj));
		/* Invalidate any prior representations */
		SyBlobRelease(&pObj->sBlob);
		MemObjSetType(pObj, MEMOBJ_BOOL);
	}
	return SXRET_OK;
}
/*
 * Convert a libcox_value to type string. Prior representations are NOT invalidated.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjToString(libcox_value *pObj)
{
	sxi32 rc = SXRET_OK;
	if( (pObj->iFlags & MEMOBJ_STRING) == 0 ){
		/* Perform the conversion */
		SyBlobReset(&pObj->sBlob); /* Reset the internal buffer */
		rc = MemObjStringValue(&pObj->sBlob, &(*pObj));
		MemObjSetType(pObj, MEMOBJ_STRING);
	}
	return rc;
}
/*
 * Nullify a libcox_value.In other words invalidate any prior
 * representation.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjToNull(libcox_value *pObj)
{
	return libcoxMemObjRelease(pObj);
}
/*
 * Invalidate any prior representation of a given libcox_value.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjRelease(libcox_value *pObj)
{
	if( (pObj->iFlags & MEMOBJ_NULL) == 0 ){
		if( pObj->iFlags & MEMOBJ_HASHMAP ){
			libcoxHashmapUnref((libcox_hashmap *)pObj->x.pOther);
		}
		/* Release the internal buffer */
		SyBlobRelease(&pObj->sBlob);
		/* Invalidate any prior representation */
		pObj->iFlags = MEMOBJ_NULL;
	}
	return SXRET_OK;
}
/*
 * Duplicate the contents of a libcox_value.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjStore(libcox_value *pSrc,libcox_value *pDest)
{
	libcox_hashmap *pMap = 0;
	sxi32 rc;
	if( pSrc->iFlags & MEMOBJ_HASHMAP ){
		/* Increment reference count */
		libcoxHashmapRef((libcox_hashmap *)pSrc->x.pOther);
	}
	if( pDest->iFlags & MEMOBJ_HASHMAP ){
		pMap = (libcox_hashmap *)pDest->x.pOther;
	}
	SyMemcpy((const void *)&(*pSrc), &(*pDest), sizeof(libcox_value)-sizeof(SyBlob));
	rc = SXRET_OK;
	if( SyBlobLength(&pSrc->sBlob) > 0 ){
		SyBlobReset(&pDest->sBlob);
		rc = SyBlobDup(&pSrc->sBlob, &pDest->sBlob);
	}else{
		if( SyBlobLength(&pDest->sBlob) > 0 ){
			SyBlobRelease(&pDest->sBlob);
		}
	}
	if( pMap ){
		libcoxHashmapUnref(pMap);
	}
	return rc;
}
LIBCOX_PRIVATE void libcoxMemObjInit(libcox *plibcox,libcox_value *pObj)
{
	/* Zero the structure */
	SyZero(pObj,sizeof(libcox_value));
	/* Init */
	SyBlobInit(&pObj->sBlob,&plibcox->sMem);
	/* Set the NULL type */
	pObj->iFlags = MEMOBJ_NULL;
}
/*
 * Initialize a libcox_value to the integer type.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjInitFromInt(libcox *pStore, libcox_value *pObj, sxi64 iVal)
{
	/* Zero the structure */
	SyZero(pObj, sizeof(libcox_value));
	/* Initialize fields */
	SyBlobInit(&pObj->sBlob, &pStore->sMem);
	/* Set the desired type */
	pObj->x.iVal = iVal;
	pObj->iFlags = MEMOBJ_INT;
	return SXRET_OK;
}
/*
 * Initialize a libcox_value to the string type.
 */
LIBCOX_PRIVATE sxi32 libcoxMemObjInitFromString(libcox *pStore, libcox_value *pObj, const SyString *pVal)
{
	/* Zero the structure */
	SyZero(pObj, sizeof(libcox_value));
	/* Initialize fields */
	SyBlobInit(&pObj->sBlob, &pStore->sMem);
	if( pVal && pVal->nByte > 0){
		/* Append contents */
		SyBlobAppend(&pObj->sBlob, (const void *)pVal->zString, pVal->nByte);
	}
	/* Set the desired type */
	pObj->iFlags = MEMOBJ_STRING;
	return SXRET_OK;
}
LIBCOX_PRIVATE libcox_value * libcoxNewObjectValue(libcox *plibcox,SyToken *pToken)
{
	libcox_value *pObj;
	/* Allocate a new instance */
	pObj = (libcox_value *)SyMemBackendPoolAlloc(&plibcox->sMem,sizeof(libcox_value));
	if( pObj == 0 ){
		return 0;
	}
	if( pToken ){
		SyString *pValue = &pToken->sData;
		/* Switch to the appropriate type */
		libcoxMemObjInitFromString(plibcox,pObj,pValue);
		if( pToken->nType & LIBCOX_TK_INTEGER ){
			libcoxMemObjToInteger(pObj);
		}else if( pToken->nType & LIBCOX_TK_REAL ){
			libcoxMemObjToReal(pObj);
		}
	}else{
		/* Default to nil */
		libcoxMemObjInit(plibcox,pObj);
	}
	return pObj;
}
LIBCOX_PRIVATE libcox_value * libcoxNewObjectArrayValue(libcox *plibcox)
{
	libcox_hashmap *pMap;
	libcox_value *pObj;
	/* Allocate a new instance */
	pObj = (libcox_value *)SyMemBackendPoolAlloc(&plibcox->sMem,sizeof(libcox_value));
	if( pObj == 0 ){
		return 0;
	}
	libcoxMemObjInit(plibcox,pObj);
	/* Allocate a new hashmap instance */
	pMap = libcoxNewHashmap(plibcox,0,0); 
	if( pMap == 0 ){
		/* Discard */
		SyMemBackendPoolFree(&plibcox->sMem,pObj);
		return 0;
	}
	/* Set the array type */
	MemObjSetType(pObj, MEMOBJ_HASHMAP);
	pObj->x.pOther = pMap;
	return pObj;
}
LIBCOX_PRIVATE void libcoxObjectValueDestroy(libcox *plibcox,libcox_value *pValue)
{
	/* Invalidate any prior representation */
	libcoxMemObjRelease(pValue);
	/* Discard */
	SyMemBackendPoolFree(&plibcox->sMem,pValue);
}
/*
 * ----------------------------------------------------------
 * File: lib.c
 * MD5: a696cc06da99abbcab06354122ae38d5
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
 /* $SymiscID: lib.c v5.1 Win7 2012-08-08 04:19 stable <chm@symisc.net> $ */
/*
 * Symisc Run-Time API: A modern thread safe replacement of the standard libc
 * Copyright (C) Symisc Systems 2007-2012, http://www.symisc.net/
 *
 * The Symisc Run-Time API is an independent project developed by symisc systems
 * internally as a secure replacement of the standard libc.
 * The library is re-entrant, thread-safe and platform independent.
 */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
#if defined(__WINNT__)
#include <Windows.h>
#else
#include <stdlib.h>
#endif
#if defined(LIBCOX_ENABLE_THREADS)
/* SyRunTimeApi: sxmutex.c */
#if defined(__WINNT__)
struct SyMutex
{
	CRITICAL_SECTION sMutex;
	sxu32 nType; /* Mutex type, one of SXMUTEX_TYPE_* */
};
/* Preallocated static mutex */
static SyMutex aStaticMutexes[] = {
		{{0}, SXMUTEX_TYPE_STATIC_1}, 
		{{0}, SXMUTEX_TYPE_STATIC_2}, 
		{{0}, SXMUTEX_TYPE_STATIC_3}, 
		{{0}, SXMUTEX_TYPE_STATIC_4}, 
		{{0}, SXMUTEX_TYPE_STATIC_5}, 
		{{0}, SXMUTEX_TYPE_STATIC_6}
};
static BOOL winMutexInit = FALSE;
static LONG winMutexLock = 0;

static sxi32 WinMutexGlobaInit(void)
{
	LONG rc;
	rc = InterlockedCompareExchange(&winMutexLock, 1, 0);
	if ( rc == 0 ){
		sxu32 n;
		for( n = 0 ; n  < SX_ARRAYSIZE(aStaticMutexes) ; ++n ){
			InitializeCriticalSection(&aStaticMutexes[n].sMutex);
		}
		winMutexInit = TRUE;
	}else{
		/* Someone else is doing this for us */
		while( winMutexInit == FALSE ){
			Sleep(1);
		}
	}
	return SXRET_OK;
}
static void WinMutexGlobalRelease(void)
{
	LONG rc;
	rc = InterlockedCompareExchange(&winMutexLock, 0, 1);
	if( rc == 1 ){
		/* The first to decrement to zero does the actual global release */
		if( winMutexInit == TRUE ){
			sxu32 n;
			for( n = 0 ; n < SX_ARRAYSIZE(aStaticMutexes) ; ++n ){
				DeleteCriticalSection(&aStaticMutexes[n].sMutex);
			}
			winMutexInit = FALSE;
		}
	}
}
static SyMutex * WinMutexNew(int nType)
{
	SyMutex *pMutex = 0;
	if( nType == SXMUTEX_TYPE_FAST || nType == SXMUTEX_TYPE_RECURSIVE ){
		/* Allocate a new mutex */
		pMutex = (SyMutex *)HeapAlloc(GetProcessHeap(), 0, sizeof(SyMutex));
		if( pMutex == 0 ){
			return 0;
		}
		InitializeCriticalSection(&pMutex->sMutex);
	}else{
		/* Use a pre-allocated static mutex */
		if( nType > SXMUTEX_TYPE_STATIC_6 ){
			nType = SXMUTEX_TYPE_STATIC_6;
		}
		pMutex = &aStaticMutexes[nType - 3];
	}
	pMutex->nType = nType;
	return pMutex;
}
static void WinMutexRelease(SyMutex *pMutex)
{
	if( pMutex->nType == SXMUTEX_TYPE_FAST || pMutex->nType == SXMUTEX_TYPE_RECURSIVE ){
		DeleteCriticalSection(&pMutex->sMutex);
		HeapFree(GetProcessHeap(), 0, pMutex);
	}
}
static void WinMutexEnter(SyMutex *pMutex)
{
	EnterCriticalSection(&pMutex->sMutex);
}
static sxi32 WinMutexTryEnter(SyMutex *pMutex)
{
#ifdef _WIN32_WINNT
	BOOL rc;
	/* Only WindowsNT platforms */
	rc = TryEnterCriticalSection(&pMutex->sMutex);
	if( rc ){
		return SXRET_OK;
	}else{
		return SXERR_BUSY;
	}
#else
	return SXERR_NOTIMPLEMENTED;
#endif
}
static void WinMutexLeave(SyMutex *pMutex)
{
	LeaveCriticalSection(&pMutex->sMutex);
}
/* Export Windows mutex interfaces */
static const SyMutexMethods sWinMutexMethods = {
	WinMutexGlobaInit,  /* xGlobalInit() */
	WinMutexGlobalRelease, /* xGlobalRelease() */
	WinMutexNew,     /* xNew() */
	WinMutexRelease, /* xRelease() */
	WinMutexEnter,   /* xEnter() */
	WinMutexTryEnter, /* xTryEnter() */
	WinMutexLeave     /* xLeave() */
};
LIBCOX_PRIVATE const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sWinMutexMethods;
}
#elif defined(__UNIXES__)
#include <pthread.h>
struct SyMutex
{
	pthread_mutex_t sMutex;
	sxu32 nType;
};
static SyMutex * UnixMutexNew(int nType)
{
	static SyMutex aStaticMutexes[] = {
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_1}, 
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_2}, 
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_3}, 
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_4}, 
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_5}, 
		{PTHREAD_MUTEX_INITIALIZER, SXMUTEX_TYPE_STATIC_6}
	};
	SyMutex *pMutex;
	
	if( nType == SXMUTEX_TYPE_FAST || nType == SXMUTEX_TYPE_RECURSIVE ){
		pthread_mutexattr_t sRecursiveAttr;
  		/* Allocate a new mutex */
  		pMutex = (SyMutex *)malloc(sizeof(SyMutex));
  		if( pMutex == 0 ){
  			return 0;
  		}
  		if( nType == SXMUTEX_TYPE_RECURSIVE ){
  			pthread_mutexattr_init(&sRecursiveAttr);
  			pthread_mutexattr_settype(&sRecursiveAttr, PTHREAD_MUTEX_RECURSIVE);
  		}
  		pthread_mutex_init(&pMutex->sMutex, nType == SXMUTEX_TYPE_RECURSIVE ? &sRecursiveAttr : 0 );
		if(	nType == SXMUTEX_TYPE_RECURSIVE ){
   			pthread_mutexattr_destroy(&sRecursiveAttr);
		}
	}else{
		/* Use a pre-allocated static mutex */
		if( nType > SXMUTEX_TYPE_STATIC_6 ){
			nType = SXMUTEX_TYPE_STATIC_6;
		}
		pMutex = &aStaticMutexes[nType - 3];
	}
  pMutex->nType = nType;
  
  return pMutex;
}
static void UnixMutexRelease(SyMutex *pMutex)
{
	if( pMutex->nType == SXMUTEX_TYPE_FAST || pMutex->nType == SXMUTEX_TYPE_RECURSIVE ){
		pthread_mutex_destroy(&pMutex->sMutex);
		free(pMutex);
	}
}
static void UnixMutexEnter(SyMutex *pMutex)
{
	pthread_mutex_lock(&pMutex->sMutex);
}
static void UnixMutexLeave(SyMutex *pMutex)
{
	pthread_mutex_unlock(&pMutex->sMutex);
}
/* Export pthread mutex interfaces */
static const SyMutexMethods sPthreadMutexMethods = {
	0, /* xGlobalInit() */
	0, /* xGlobalRelease() */
	UnixMutexNew,      /* xNew() */
	UnixMutexRelease,  /* xRelease() */
	UnixMutexEnter,    /* xEnter() */
	0,                 /* xTryEnter() */
	UnixMutexLeave     /* xLeave() */
};
LIBCOX_PRIVATE const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sPthreadMutexMethods;
}
#else
/* Host application must register their own mutex subsystem if the target
 * platform is not an UNIX-like or windows systems.
 */
struct SyMutex
{
	sxu32 nType;
};
static SyMutex * DummyMutexNew(int nType)
{
	static SyMutex sMutex;
	SXUNUSED(nType);
	return &sMutex;
}
static void DummyMutexRelease(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
static void DummyMutexEnter(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
static void DummyMutexLeave(SyMutex *pMutex)
{
	SXUNUSED(pMutex);
}
/* Export the dummy mutex interfaces */
static const SyMutexMethods sDummyMutexMethods = {
	0, /* xGlobalInit() */
	0, /* xGlobalRelease() */
	DummyMutexNew,      /* xNew() */
	DummyMutexRelease,  /* xRelease() */
	DummyMutexEnter,    /* xEnter() */
	0,                  /* xTryEnter() */
	DummyMutexLeave     /* xLeave() */
};
LIBCOX_PRIVATE const SyMutexMethods * SyMutexExportMethods(void)
{
	return &sDummyMutexMethods;
}
#endif /* __WINNT__ */
#endif /* LIBCOX_ENABLE_THREADS */
static void * SyOSHeapAlloc(sxu32 nByte)
{
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapAlloc(GetProcessHeap(), 0, nByte);
#else
	pNew = malloc((size_t)nByte);
#endif
	return pNew;
}
static void * SyOSHeapRealloc(void *pOld, sxu32 nByte)
{
	void *pNew;
#if defined(__WINNT__)
	pNew = HeapReAlloc(GetProcessHeap(), 0, pOld, nByte);
#else
	pNew = realloc(pOld, (size_t)nByte);
#endif
	return pNew;	
}
static void SyOSHeapFree(void *pPtr)
{
#if defined(__WINNT__)
	HeapFree(GetProcessHeap(), 0, pPtr);
#else
	free(pPtr);
#endif
}
/* SyRunTimeApi:sxstr.c */
LIBCOX_PRIVATE sxu32 SyStrlen(const char *zSrc)
{
	register const char *zIn = zSrc;
#if defined(UNTRUST)
	if( zIn == 0 ){
		return 0;
	}
#endif
	for(;;){
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;
		if( !zIn[0] ){ break; } zIn++;	
	}
	return (sxu32)(zIn - zSrc);
}
#if defined(__APPLE__)
LIBCOX_PRIVATE sxi32 SyStrncmp(const char *zLeft, const char *zRight, sxu32 nLen)
{
	const unsigned char *zP = (const unsigned char *)zLeft;
	const unsigned char *zQ = (const unsigned char *)zRight;

	if( SX_EMPTY_STR(zP) || SX_EMPTY_STR(zQ)  ){
			return SX_EMPTY_STR(zP) ? (SX_EMPTY_STR(zQ) ? 0 : -1) :1;
	}
	if( nLen <= 0 ){
		return 0;
	}
	for(;;){
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
	}
	return (sxi32)(zP[0] - zQ[0]);
}	
#endif
LIBCOX_PRIVATE sxi32 SyStrnicmp(const char *zLeft, const char *zRight, sxu32 SLen)
{
  	register unsigned char *p = (unsigned char *)zLeft;
	register unsigned char *q = (unsigned char *)zRight;
	
	if( SX_EMPTY_STR(p) || SX_EMPTY_STR(q) ){
		return SX_EMPTY_STR(p)? SX_EMPTY_STR(q) ? 0 : -1 :1;
	}
	for(;;){
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		if( !SLen ){ return 0; }if( !*p || !*q || SyCharToLower(*p) != SyCharToLower(*q) ){ break; }p++;q++;--SLen;
		
	}
	return (sxi32)(SyCharToLower(p[0]) - SyCharToLower(q[0]));
}
/* SyRunTimeApi:sxmem.c */
LIBCOX_PRIVATE void SyZero(void *pSrc, sxu32 nSize)
{
	register unsigned char *zSrc = (unsigned char *)pSrc;
	unsigned char *zEnd;
#if defined(UNTRUST)
	if( zSrc == 0 || nSize <= 0 ){
		return ;
	}
#endif
	zEnd = &zSrc[nSize];
	for(;;){
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
		if( zSrc >= zEnd ){break;} zSrc[0] = 0; zSrc++;
	}
}
LIBCOX_PRIVATE sxi32 SyMemcmp(const void *pB1, const void *pB2, sxu32 nSize)
{
	sxi32 rc;
	if( nSize <= 0 ){
		return 0;
	}
	if( pB1 == 0 || pB2 == 0 ){
		return pB1 != 0 ? 1 : (pB2 == 0 ? 0 : -1);
	}
	SX_MACRO_FAST_CMP(pB1, pB2, nSize, rc);
	return rc;
}
LIBCOX_PRIVATE sxu32 SyMemcpy(const void *pSrc, void *pDest, sxu32 nLen)
{
	if( pSrc == 0 || pDest == 0 ){
		return 0;
	}
	if( pSrc == (const void *)pDest ){
		return nLen;
	}
	SX_MACRO_FAST_MEMCPY(pSrc, pDest, nLen);
	return nLen;
}
static void * MemOSAlloc(sxu32 nBytes)
{
	sxu32 *pChunk;
	pChunk = (sxu32 *)SyOSHeapAlloc(nBytes + sizeof(sxu32));
	if( pChunk == 0 ){
		return 0;
	}
	pChunk[0] = nBytes;
	return (void *)&pChunk[1];
}
static void * MemOSRealloc(void *pOld, sxu32 nBytes)
{
	sxu32 *pOldChunk;
	sxu32 *pChunk;
	pOldChunk = (sxu32 *)(((char *)pOld)-sizeof(sxu32));
	if( pOldChunk[0] >= nBytes ){
		return pOld;
	}
	pChunk = (sxu32 *)SyOSHeapRealloc(pOldChunk, nBytes + sizeof(sxu32));
	if( pChunk == 0 ){
		return 0;
	}
	pChunk[0] = nBytes;
	return (void *)&pChunk[1];
}
static void MemOSFree(void *pBlock)
{
	void *pChunk;
	pChunk = (void *)(((char *)pBlock)-sizeof(sxu32));
	SyOSHeapFree(pChunk);
}
static sxu32 MemOSChunkSize(void *pBlock)
{
	sxu32 *pChunk;
	pChunk = (sxu32 *)(((char *)pBlock)-sizeof(sxu32));
	return pChunk[0];
}
/* Export OS allocation methods */
static const SyMemMethods sOSAllocMethods = {
	MemOSAlloc, 
	MemOSRealloc, 
	MemOSFree, 
	MemOSChunkSize, 
	0, 
	0, 
	0
};
static void * MemBackendAlloc(SyMemBackend *pBackend, sxu32 nByte)
{
	SyMemBlock *pBlock;
	sxi32 nRetry = 0;

	/* Append an extra block so we can tracks allocated chunks and avoid memory
	 * leaks.
	 */
	nByte += sizeof(SyMemBlock);
	for(;;){
		pBlock = (SyMemBlock *)pBackend->pMethods->xAlloc(nByte);
		if( pBlock != 0 || pBackend->xMemError == 0 || nRetry > SXMEM_BACKEND_RETRY 
			|| SXERR_RETRY != pBackend->xMemError(pBackend->pUserData) ){
				break;
		}
		nRetry++;
	}
	if( pBlock  == 0 ){
		return 0;
	}
	pBlock->pNext = pBlock->pPrev = 0;
	/* Link to the list of already tracked blocks */
	MACRO_LD_PUSH(pBackend->pBlocks, pBlock);
#if defined(UNTRUST)
	pBlock->nGuard = SXMEM_BACKEND_MAGIC;
#endif
	pBackend->nBlock++;
	return (void *)&pBlock[1];
}
LIBCOX_PRIVATE void * SyMemBackendAlloc(SyMemBackend *pBackend, sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	pChunk = MemBackendAlloc(&(*pBackend), nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return pChunk;
}
static void * MemBackendRealloc(SyMemBackend *pBackend, void * pOld, sxu32 nByte)
{
	SyMemBlock *pBlock, *pNew, *pPrev, *pNext;
	sxu32 nRetry = 0;

	if( pOld == 0 ){
		return MemBackendAlloc(&(*pBackend), nByte);
	}
	pBlock = (SyMemBlock *)(((char *)pOld) - sizeof(SyMemBlock));
#if defined(UNTRUST)
	if( pBlock->nGuard != SXMEM_BACKEND_MAGIC ){
		return 0;
	}
#endif
	nByte += sizeof(SyMemBlock);
	pPrev = pBlock->pPrev;
	pNext = pBlock->pNext;
	for(;;){
		pNew = (SyMemBlock *)pBackend->pMethods->xRealloc(pBlock, nByte);
		if( pNew != 0 || pBackend->xMemError == 0 || nRetry > SXMEM_BACKEND_RETRY ||
			SXERR_RETRY != pBackend->xMemError(pBackend->pUserData) ){
				break;
		}
		nRetry++;
	}
	if( pNew == 0 ){
		return 0;
	}
	if( pNew != pBlock ){
		if( pPrev == 0 ){
			pBackend->pBlocks = pNew;
		}else{
			pPrev->pNext = pNew;
		}
		if( pNext ){
			pNext->pPrev = pNew;
		}
#if defined(UNTRUST)
		pNew->nGuard = SXMEM_BACKEND_MAGIC;
#endif
	}
	return (void *)&pNew[1];
}
LIBCOX_PRIVATE void * SyMemBackendRealloc(SyMemBackend *pBackend, void * pOld, sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend)  ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	pChunk = MemBackendRealloc(&(*pBackend), pOld, nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return pChunk;
}
static sxi32 MemBackendFree(SyMemBackend *pBackend, void * pChunk)
{
	SyMemBlock *pBlock;
	pBlock = (SyMemBlock *)(((char *)pChunk) - sizeof(SyMemBlock));
#if defined(UNTRUST)
	if( pBlock->nGuard != SXMEM_BACKEND_MAGIC ){
		return SXERR_CORRUPT;
	}
#endif
	/* Unlink from the list of active blocks */
	if( pBackend->nBlock > 0 ){
		/* Release the block */
#if defined(UNTRUST)
		/* Mark as stale block */
		pBlock->nGuard = 0x635B;
#endif
		MACRO_LD_REMOVE(pBackend->pBlocks, pBlock);
		pBackend->nBlock--;
		pBackend->pMethods->xFree(pBlock);
	}
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendFree(SyMemBackend *pBackend, void * pChunk)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return SXERR_CORRUPT;
	}
#endif
	if( pChunk == 0 ){
		return SXRET_OK;
	}
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	rc = MemBackendFree(&(*pBackend), pChunk);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return rc;
}
#if defined(LIBCOX_ENABLE_THREADS)
LIBCOX_PRIVATE sxi32 SyMemBackendMakeThreadSafe(SyMemBackend *pBackend, const SyMutexMethods *pMethods)
{
	SyMutex *pMutex;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) || pMethods == 0 || pMethods->xNew == 0){
		return SXERR_CORRUPT;
	}
#endif
	pMutex = pMethods->xNew(SXMUTEX_TYPE_FAST);
	if( pMutex == 0 ){
		return SXERR_OS;
	}
	/* Attach the mutex to the memory backend */
	pBackend->pMutex = pMutex;
	pBackend->pMutexMethods = pMethods;
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendDisbaleMutexing(SyMemBackend *pBackend)
{
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return SXERR_CORRUPT;
	}
#endif
	if( pBackend->pMutex == 0 ){
		/* There is no mutex subsystem at all */
		return SXRET_OK;
	}
	SyMutexRelease(pBackend->pMutexMethods, pBackend->pMutex);
	pBackend->pMutexMethods = 0;
	pBackend->pMutex = 0; 
	return SXRET_OK;
}
#endif
/*
 * Memory pool allocator
 */
#define SXMEM_POOL_MAGIC		0xDEAD
#define SXMEM_POOL_MAXALLOC		(1<<(SXMEM_POOL_NBUCKETS+SXMEM_POOL_INCR)) 
#define SXMEM_POOL_MINALLOC		(1<<(SXMEM_POOL_INCR))
static sxi32 MemPoolBucketAlloc(SyMemBackend *pBackend, sxu32 nBucket)
{
	char *zBucket, *zBucketEnd;
	SyMemHeader *pHeader;
	sxu32 nBucketSize;
	
	/* Allocate one big block first */
	zBucket = (char *)MemBackendAlloc(&(*pBackend), SXMEM_POOL_MAXALLOC);
	if( zBucket == 0 ){
		return SXERR_MEM;
	}
	zBucketEnd = &zBucket[SXMEM_POOL_MAXALLOC];
	/* Divide the big block into mini bucket pool */
	nBucketSize = 1 << (nBucket + SXMEM_POOL_INCR);
	pBackend->apPool[nBucket] = pHeader = (SyMemHeader *)zBucket;
	for(;;){
		if( &zBucket[nBucketSize] >= zBucketEnd ){
			break;
		}
		pHeader->pNext = (SyMemHeader *)&zBucket[nBucketSize];
		/* Advance the cursor to the next available chunk */
		pHeader = pHeader->pNext;
		zBucket += nBucketSize;	
	}
	pHeader->pNext = 0;
	
	return SXRET_OK;
}
static void * MemBackendPoolAlloc(SyMemBackend *pBackend, sxu32 nByte)
{
	SyMemHeader *pBucket, *pNext;
	sxu32 nBucketSize;
	sxu32 nBucket;

	if( nByte + sizeof(SyMemHeader) >= SXMEM_POOL_MAXALLOC ){
		/* Allocate a big chunk directly */
		pBucket = (SyMemHeader *)MemBackendAlloc(&(*pBackend), nByte+sizeof(SyMemHeader));
		if( pBucket == 0 ){
			return 0;
		}
		/* Record as big block */
		pBucket->nBucket = (sxu32)(SXMEM_POOL_MAGIC << 16) | SXU16_HIGH;
		return (void *)(pBucket+1);
	}
	/* Locate the appropriate bucket */
	nBucket = 0;
	nBucketSize = SXMEM_POOL_MINALLOC;
	while( nByte + sizeof(SyMemHeader) > nBucketSize  ){
		nBucketSize <<= 1;
		nBucket++;
	}
	pBucket = pBackend->apPool[nBucket];
	if( pBucket == 0 ){
		sxi32 rc;
		rc = MemPoolBucketAlloc(&(*pBackend), nBucket);
		if( rc != SXRET_OK ){
			return 0;
		}
		pBucket = pBackend->apPool[nBucket];
	}
	/* Remove from the free list */
	pNext = pBucket->pNext;
	pBackend->apPool[nBucket] = pNext;
	/* Record bucket&magic number */
	pBucket->nBucket = (SXMEM_POOL_MAGIC << 16) | nBucket;
	return (void *)&pBucket[1];
}
LIBCOX_PRIVATE void * SyMemBackendPoolAlloc(SyMemBackend *pBackend, sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	pChunk = MemBackendPoolAlloc(&(*pBackend), nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return pChunk;
}
static sxi32 MemBackendPoolFree(SyMemBackend *pBackend, void * pChunk)
{
	SyMemHeader *pHeader;
	sxu32 nBucket;
	/* Get the corresponding bucket */
	pHeader = (SyMemHeader *)(((char *)pChunk) - sizeof(SyMemHeader));
	/* Sanity check to avoid misuse */
	if( (pHeader->nBucket >> 16) != SXMEM_POOL_MAGIC ){
		return SXERR_CORRUPT;
	}
	nBucket = pHeader->nBucket & 0xFFFF;
	if( nBucket == SXU16_HIGH ){
		/* Free the big block */
		MemBackendFree(&(*pBackend), pHeader);
	}else{
		/* Return to the free list */
		pHeader->pNext = pBackend->apPool[nBucket & 0x0f];
		pBackend->apPool[nBucket & 0x0f] = pHeader;
	}
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendPoolFree(SyMemBackend *pBackend, void * pChunk)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) || pChunk == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	rc = MemBackendPoolFree(&(*pBackend), pChunk);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return rc;
}
#if 0
static void * MemBackendPoolRealloc(SyMemBackend *pBackend, void * pOld, sxu32 nByte)
{
	sxu32 nBucket, nBucketSize;
	SyMemHeader *pHeader;
	void * pNew;

	if( pOld == 0 ){
		/* Allocate a new pool */
		pNew = MemBackendPoolAlloc(&(*pBackend), nByte);
		return pNew;
	}
	/* Get the corresponding bucket */
	pHeader = (SyMemHeader *)(((char *)pOld) - sizeof(SyMemHeader));
	/* Sanity check to avoid misuse */
	if( (pHeader->nBucket >> 16) != SXMEM_POOL_MAGIC ){
		return 0;
	}
	nBucket = pHeader->nBucket & 0xFFFF;
	if( nBucket == SXU16_HIGH ){
		/* Big block */
		return MemBackendRealloc(&(*pBackend), pHeader, nByte);
	}
	nBucketSize = 1 << (nBucket + SXMEM_POOL_INCR);
	if( nBucketSize >= nByte + sizeof(SyMemHeader) ){
		/* The old bucket can honor the requested size */
		return pOld;
	}
	/* Allocate a new pool */
	pNew = MemBackendPoolAlloc(&(*pBackend), nByte);
	if( pNew == 0 ){
		return 0;
	}
	/* Copy the old data into the new block */
	SyMemcpy(pOld, pNew, nBucketSize);
	/* Free the stale block */
	MemBackendPoolFree(&(*pBackend), pOld);
	return pNew;
}
LIBCOX_PRIVATE void * SyMemBackendPoolRealloc(SyMemBackend *pBackend, void * pOld, sxu32 nByte)
{
	void *pChunk;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return 0;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	pChunk = MemBackendPoolRealloc(&(*pBackend), pOld, nByte);
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return pChunk;
}
#endif
LIBCOX_PRIVATE sxi32 SyMemBackendInit(SyMemBackend *pBackend, ProcMemError xMemErr, void * pUserData)
{
#if defined(UNTRUST)
	if( pBackend == 0 ){
		return SXERR_EMPTY;
	}
#endif
	/* Zero the allocator first */
	SyZero(&(*pBackend), sizeof(SyMemBackend));
	pBackend->xMemError = xMemErr;
	pBackend->pUserData = pUserData;
	/* Switch to the OS memory allocator */
	pBackend->pMethods = &sOSAllocMethods;
	if( pBackend->pMethods->xInit ){
		/* Initialize the backend  */
		if( SXRET_OK != pBackend->pMethods->xInit(pBackend->pMethods->pUserData) ){
			return SXERR_ABORT;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendInitFromOthers(SyMemBackend *pBackend, const SyMemMethods *pMethods, ProcMemError xMemErr, void * pUserData)
{
#if defined(UNTRUST)
	if( pBackend == 0 || pMethods == 0){
		return SXERR_EMPTY;
	}
#endif
	if( pMethods->xAlloc == 0 || pMethods->xRealloc == 0 || pMethods->xFree == 0 || pMethods->xChunkSize == 0 ){
		/* mandatory methods are missing */
		return SXERR_INVALID;
	}
	/* Zero the allocator first */
	SyZero(&(*pBackend), sizeof(SyMemBackend));
	pBackend->xMemError = xMemErr;
	pBackend->pUserData = pUserData;
	/* Switch to the host application memory allocator */
	pBackend->pMethods = pMethods;
	if( pBackend->pMethods->xInit ){
		/* Initialize the backend  */
		if( SXRET_OK != pBackend->pMethods->xInit(pBackend->pMethods->pUserData) ){
			return SXERR_ABORT;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendInitFromParent(SyMemBackend *pBackend,const SyMemBackend *pParent)
{
	sxu8 bInheritMutex;
#if defined(UNTRUST)
	if( pBackend == 0 || SXMEM_BACKEND_CORRUPT(pParent) ){
		return SXERR_CORRUPT;
	}
#endif
	/* Zero the allocator first */
	SyZero(&(*pBackend), sizeof(SyMemBackend));
	pBackend->pMethods  = pParent->pMethods;
	pBackend->xMemError = pParent->xMemError;
	pBackend->pUserData = pParent->pUserData;
	bInheritMutex = pParent->pMutexMethods ? TRUE : FALSE;
	if( bInheritMutex ){
		pBackend->pMutexMethods = pParent->pMutexMethods;
		/* Create a private mutex */
		pBackend->pMutex = pBackend->pMutexMethods->xNew(SXMUTEX_TYPE_FAST);
		if( pBackend->pMutex ==  0){
			return SXERR_OS;
		}
	}
#if defined(UNTRUST)
	pBackend->nMagic = SXMEM_BACKEND_MAGIC;
#endif
	return SXRET_OK;
}
static sxi32 MemBackendRelease(SyMemBackend *pBackend)
{
	SyMemBlock *pBlock, *pNext;

	pBlock = pBackend->pBlocks;
	for(;;){
		if( pBackend->nBlock == 0 ){
			break;
		}
		pNext  = pBlock->pNext;
		pBackend->pMethods->xFree(pBlock);
		pBlock = pNext;
		pBackend->nBlock--;
		/* LOOP ONE */
		if( pBackend->nBlock == 0 ){
			break;
		}
		pNext  = pBlock->pNext;
		pBackend->pMethods->xFree(pBlock);
		pBlock = pNext;
		pBackend->nBlock--;
		/* LOOP TWO */
		if( pBackend->nBlock == 0 ){
			break;
		}
		pNext  = pBlock->pNext;
		pBackend->pMethods->xFree(pBlock);
		pBlock = pNext;
		pBackend->nBlock--;
		/* LOOP THREE */
		if( pBackend->nBlock == 0 ){
			break;
		}
		pNext  = pBlock->pNext;
		pBackend->pMethods->xFree(pBlock);
		pBlock = pNext;
		pBackend->nBlock--;
		/* LOOP FOUR */
	}
	if( pBackend->pMethods->xRelease ){
		pBackend->pMethods->xRelease(pBackend->pMethods->pUserData);
	}
	pBackend->pMethods = 0;
	pBackend->pBlocks  = 0;
#if defined(UNTRUST)
	pBackend->nMagic = 0x2626;
#endif
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMemBackendRelease(SyMemBackend *pBackend)
{
	sxi32 rc;
#if defined(UNTRUST)
	if( SXMEM_BACKEND_CORRUPT(pBackend) ){
		return SXERR_INVALID;
	}
#endif
	if( pBackend->pMutexMethods ){
		SyMutexEnter(pBackend->pMutexMethods, pBackend->pMutex);
	}
	rc = MemBackendRelease(&(*pBackend));
	if( pBackend->pMutexMethods ){
		SyMutexLeave(pBackend->pMutexMethods, pBackend->pMutex);
		SyMutexRelease(pBackend->pMutexMethods, pBackend->pMutex);
	}
	return rc;
}
LIBCOX_PRIVATE void * SyMemBackendDup(SyMemBackend *pBackend, const void *pSrc, sxu32 nSize)
{
	void *pNew;
#if defined(UNTRUST)
	if( pSrc == 0 || nSize <= 0 ){
		return 0;
	}
#endif
	pNew = SyMemBackendAlloc(&(*pBackend), nSize);
	if( pNew ){
		SyMemcpy(pSrc, pNew, nSize);
	}
	return pNew;
}
LIBCOX_PRIVATE sxi32 SyBlobInit(SyBlob *pBlob, SyMemBackend *pAllocator)
{
#if defined(UNTRUST)
	if( pBlob == 0  ){
		return SXERR_EMPTY;
	}
#endif
	pBlob->pBlob = 0;
	pBlob->mByte = pBlob->nByte	= 0;
	pBlob->pAllocator = &(*pAllocator);
	pBlob->nFlags = 0;
	return SXRET_OK;
}
#ifndef SXBLOB_MIN_GROWTH
#define SXBLOB_MIN_GROWTH 16
#endif
static sxi32 BlobPrepareGrow(SyBlob *pBlob, sxu32 *pByte)
{
	sxu32 nByte;
	void *pNew;
	nByte = *pByte;
	if( pBlob->nFlags & (SXBLOB_LOCKED|SXBLOB_STATIC) ){
		if ( SyBlobFreeSpace(pBlob) < nByte ){
			*pByte = SyBlobFreeSpace(pBlob);
			if( (*pByte) == 0 ){
				return SXERR_SHORT;
			}
		}
		return SXRET_OK;
	}
	if( pBlob->nFlags & SXBLOB_RDONLY ){
		/* Make a copy of the read-only item */
		if( pBlob->nByte > 0 ){
			pNew = SyMemBackendDup(pBlob->pAllocator, pBlob->pBlob, pBlob->nByte);
			if( pNew == 0 ){
				return SXERR_MEM;
			}
			pBlob->pBlob = pNew;
			pBlob->mByte = pBlob->nByte;
		}else{
			pBlob->pBlob = 0;
			pBlob->mByte = 0;
		}
		/* Remove the read-only flag */
		pBlob->nFlags &= ~SXBLOB_RDONLY;
	}
	if( SyBlobFreeSpace(pBlob) >= nByte ){
		return SXRET_OK;
	}
	if( pBlob->mByte > 0 ){
		nByte = nByte + pBlob->mByte * 2 + SXBLOB_MIN_GROWTH;
	}else if ( nByte < SXBLOB_MIN_GROWTH ){
		nByte = SXBLOB_MIN_GROWTH;
	}
	pNew = SyMemBackendRealloc(pBlob->pAllocator, pBlob->pBlob, nByte);
	if( pNew == 0 ){
		return SXERR_MEM;
	}
	pBlob->pBlob = pNew;
	pBlob->mByte = nByte;
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyBlobAppend(SyBlob *pBlob, const void *pData, sxu32 nSize)
{
	sxu8 *zBlob;
	sxi32 rc;
	if( nSize < 1 ){
		return SXRET_OK;
	}
	rc = BlobPrepareGrow(&(*pBlob), &nSize);
	if( SXRET_OK != rc ){
		return rc;
	}
	if( pData ){
		zBlob = (sxu8 *)pBlob->pBlob ;
		zBlob = &zBlob[pBlob->nByte];
		pBlob->nByte += nSize;
		SX_MACRO_FAST_MEMCPY(pData, zBlob, nSize);
	}
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyBlobNullAppend(SyBlob *pBlob)
{
	sxi32 rc;
	sxu32 n;
	n = pBlob->nByte;
	rc = SyBlobAppend(&(*pBlob), (const void *)"\0", sizeof(char));
	if (rc == SXRET_OK ){
		pBlob->nByte = n;
	}
	return rc;
}
LIBCOX_PRIVATE sxi32 SyBlobDup(SyBlob *pSrc, SyBlob *pDest)
{
	sxi32 rc = SXRET_OK;
	if( pSrc->nByte > 0 ){
		rc = SyBlobAppend(&(*pDest), pSrc->pBlob, pSrc->nByte);
	}
	return rc;
}
LIBCOX_PRIVATE sxi32 SyBlobReset(SyBlob *pBlob)
{
	pBlob->nByte = 0;
	if( pBlob->nFlags & SXBLOB_RDONLY ){
		/* Read-only (Not malloced chunk) */
		pBlob->pBlob = 0;
		pBlob->mByte = 0;
		pBlob->nFlags &= ~SXBLOB_RDONLY;
	}
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyBlobRelease(SyBlob *pBlob)
{
	if( (pBlob->nFlags & (SXBLOB_STATIC|SXBLOB_RDONLY)) == 0 && pBlob->mByte > 0 ){
		SyMemBackendFree(pBlob->pAllocator, pBlob->pBlob);
	}
	pBlob->pBlob = 0;
	pBlob->nByte = pBlob->mByte = 0;
	pBlob->nFlags = 0;
	return SXRET_OK;
}
/* SyRunTimeApi:sxds.c */
LIBCOX_PRIVATE sxi32 SySetInit(SySet *pSet, SyMemBackend *pAllocator, sxu32 ElemSize)
{
	pSet->nSize = 0 ;
	pSet->nUsed = 0;
	pSet->nCursor = 0;
	pSet->eSize = ElemSize;
	pSet->pAllocator = pAllocator;
	pSet->pBase =  0;
	pSet->pUserData = 0;
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SySetPut(SySet *pSet, const void *pItem)
{
	unsigned char *zbase;
	if( pSet->nUsed >= pSet->nSize ){
		void *pNew;
		if( pSet->pAllocator == 0 ){
			return  SXERR_LOCKED;
		}
		if( pSet->nSize <= 0 ){
			pSet->nSize = 4;
		}
		pNew = SyMemBackendRealloc(pSet->pAllocator, pSet->pBase, pSet->eSize * pSet->nSize * 2);
		if( pNew == 0 ){
			return SXERR_MEM;
		}
		pSet->pBase = pNew;
		pSet->nSize <<= 1;
	}
	zbase = (unsigned char *)pSet->pBase;
	SX_MACRO_FAST_MEMCPY(pItem, &zbase[pSet->nUsed * pSet->eSize], pSet->eSize);
	pSet->nUsed++;	
	return SXRET_OK;
} 
LIBCOX_PRIVATE sxi32 SySetReset(SySet *pSet)
{
	pSet->nUsed   = 0;
	pSet->nCursor = 0;
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SySetRelease(SySet *pSet)
{
	sxi32 rc = SXRET_OK;
	if( pSet->pAllocator && pSet->pBase ){
		rc = SyMemBackendFree(pSet->pAllocator, pSet->pBase);
	}
	pSet->pBase = 0;
	pSet->nUsed = 0;
	pSet->nCursor = 0;
	return rc;
}
LIBCOX_PRIVATE void * SySetPeek(SySet *pSet)
{
	const char *zBase;
	if( pSet->nUsed <= 0 ){
		return 0;
	}
	zBase = (const char *)pSet->pBase;
	return (void *)&zBase[(pSet->nUsed - 1) * pSet->eSize]; 
}
LIBCOX_PRIVATE void * SySetPop(SySet *pSet)
{
	const char *zBase;
	void *pData;
	if( pSet->nUsed <= 0 ){
		return 0;
	}
	zBase = (const char *)pSet->pBase;
	pSet->nUsed--;
	pData =  (void *)&zBase[pSet->nUsed * pSet->eSize]; 
	return pData;
}
/* SyRunTimeApi:sxutils.c */
LIBCOX_PRIVATE sxi32 SyStrIsNumeric(const char *zSrc, sxu32 nLen, sxu8 *pReal, const char  **pzTail)
{
	const char *zCur, *zEnd;
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc) ){
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	/* Jump leading white spaces */
	while( zSrc < zEnd && (unsigned char)zSrc[0] < 0xc0  && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && (zSrc[0] == '+' || zSrc[0] == '-') ){
		zSrc++;
	}
	zCur = zSrc;
	if( pReal ){
		*pReal = FALSE;
	}
	for(;;){
		if( zSrc >= zEnd || (unsigned char)zSrc[0] >= 0xc0 || !SyisDigit(zSrc[0]) ){ break; } zSrc++;
		if( zSrc >= zEnd || (unsigned char)zSrc[0] >= 0xc0 || !SyisDigit(zSrc[0]) ){ break; } zSrc++;
		if( zSrc >= zEnd || (unsigned char)zSrc[0] >= 0xc0 || !SyisDigit(zSrc[0]) ){ break; } zSrc++;
		if( zSrc >= zEnd || (unsigned char)zSrc[0] >= 0xc0 || !SyisDigit(zSrc[0]) ){ break; } zSrc++;
	};
	if( zSrc < zEnd && zSrc > zCur ){
		int c = zSrc[0];
		if( c == '.' ){
			zSrc++;
			if( pReal ){
				*pReal = TRUE;
			}
			if( pzTail ){
				while( zSrc < zEnd && (unsigned char)zSrc[0] < 0xc0 && SyisDigit(zSrc[0]) ){
					zSrc++;
				}
				if( zSrc < zEnd && (zSrc[0] == 'e' || zSrc[0] == 'E') ){
					zSrc++;
					if( zSrc < zEnd && (zSrc[0] == '+' || zSrc[0] == '-') ){
						zSrc++;
					}
					while( zSrc < zEnd && (unsigned char)zSrc[0] < 0xc0 && SyisDigit(zSrc[0]) ){
						zSrc++;
					}
				}
			}
		}else if( c == 'e' || c == 'E' ){
			zSrc++;
			if( pReal ){
				*pReal = TRUE;
			}
			if( pzTail ){
				if( zSrc < zEnd && (zSrc[0] == '+' || zSrc[0] == '-') ){
					zSrc++;
				}
				while( zSrc < zEnd && (unsigned char)zSrc[0] < 0xc0 && SyisDigit(zSrc[0]) ){
					zSrc++;
				}
			}
		}
	}
	if( pzTail ){
		/* Point to the non numeric part */
		*pzTail = zSrc;
	}
	return zSrc > zCur ? SXRET_OK /* String prefix is numeric */ : SXERR_INVALID /* Not a digit stream */;
}
#define SXINT32_MIN_STR		"2147483648"
#define SXINT32_MAX_STR		"2147483647"
#define SXINT64_MIN_STR		"9223372036854775808"
#define SXINT64_MAX_STR		"9223372036854775807"
LIBCOX_PRIVATE sxi32 SyStrToInt64(const char *zSrc, sxu32 nLen, void * pOutVal, const char **zRest)
{
	int isNeg = FALSE;
	const char *zEnd;
	sxi64 nVal;
	sxi16 i;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++;
	}
	i = 19;
	if( (sxu32)(zEnd-zSrc) >= 19 ){
		i = SyMemcmp(zSrc, isNeg ? SXINT64_MIN_STR : SXINT64_MAX_STR, 19) <= 0 ? 19 : 18 ;
	}
	nVal = 0;
	for(;;){
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
		if(zSrc >= zEnd || !i || !SyisDigit(zSrc[0])){ break; } nVal = nVal * 10 + ( zSrc[0] - '0' ) ; --i ; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = (char *)zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi64 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
LIBCOX_PRIVATE sxi32 SyHexToint(sxi32 c)
{
	switch(c){
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	case 'A': case 'a': return 10;
	case 'B': case 'b': return 11;
	case 'C': case 'c': return 12;
	case 'D': case 'd': return 13;
	case 'E': case 'e': return 14;
	case 'F': case 'f': return 15;
	}
	return -1; 	
}
LIBCOX_PRIVATE sxi32 SyHexStrToInt64(const char *zSrc, sxu32 nLen, void * pOutVal, const char **zRest)
{
	const char *zIn, *zEnd;
	int isNeg = FALSE;
	sxi64 nVal = 0;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( *zSrc == '-' || *zSrc == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	if( zSrc < &zEnd[-2] && zSrc[0] == '0' && (zSrc[1] == 'x' || zSrc[1] == 'X') ){
		/* Bypass hex prefix */
		zSrc += sizeof(char) * 2;
	}	
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++;
	}
	zIn = zSrc;
	for(;;){
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) || (int)(zSrc-zIn) > 15) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) || (int)(zSrc-zIn) > 15) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) || (int)(zSrc-zIn) > 15) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
		if(zSrc >= zEnd || !SyisHex(zSrc[0]) || (int)(zSrc-zIn) > 15) break; nVal = nVal * 16 + SyHexToint(zSrc[0]);  zSrc++ ;
	}
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}	
	if( zRest ){
		*zRest = zSrc;
	}
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi64 *)pOutVal = nVal;
	}
	return zSrc >= zEnd ? SXRET_OK : SXERR_SYNTAX;
}
LIBCOX_PRIVATE sxi32 SyOctalStrToInt64(const char *zSrc, sxu32 nLen, void * pOutVal, const char **zRest)
{
	const char *zIn, *zEnd;
	int isNeg = FALSE;
	sxi64 nVal = 0;
	int c;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++; 
	}
	zIn = zSrc;
	for(;;){
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 || (int)(zSrc-zIn) > 20){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 || (int)(zSrc-zIn) > 20){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 || (int)(zSrc-zIn) > 20){ break;} nVal = nVal * 8 +  c; zSrc++;
		if(zSrc >= zEnd || !SyisDigit(zSrc[0])){ break; } if( (c=zSrc[0]-'0') > 7 || (int)(zSrc-zIn) > 20){ break;} nVal = nVal * 8 +  c; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi64 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
LIBCOX_PRIVATE sxi32 SyBinaryStrToInt64(const char *zSrc, sxu32 nLen, void * pOutVal, const char **zRest)
{
	const char *zIn, *zEnd;
	int isNeg = FALSE;
	sxi64 nVal = 0;
	int c;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) ){
		if( pOutVal ){
			*(sxi32 *)pOutVal = 0;
		}
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	while(zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+' ) ){
		isNeg = (zSrc[0] == '-') ? TRUE :FALSE;
		zSrc++;
	}
	if( zSrc < &zEnd[-2] && zSrc[0] == '0' && (zSrc[1] == 'b' || zSrc[1] == 'B') ){
		/* Bypass binary prefix */
		zSrc += sizeof(char) * 2;
	}
	/* Skip leading zero */
	while(zSrc < zEnd && zSrc[0] == '0' ){
		zSrc++; 
	}
	zIn = zSrc;
	for(;;){
		if(zSrc >= zEnd || (zSrc[0] != '1' && zSrc[0] != '0') || (int)(zSrc-zIn) > 62){ break; } c = zSrc[0] - '0'; nVal = (nVal << 1) + c; zSrc++;
		if(zSrc >= zEnd || (zSrc[0] != '1' && zSrc[0] != '0') || (int)(zSrc-zIn) > 62){ break; } c = zSrc[0] - '0'; nVal = (nVal << 1) + c; zSrc++;
		if(zSrc >= zEnd || (zSrc[0] != '1' && zSrc[0] != '0') || (int)(zSrc-zIn) > 62){ break; } c = zSrc[0] - '0'; nVal = (nVal << 1) + c; zSrc++;
		if(zSrc >= zEnd || (zSrc[0] != '1' && zSrc[0] != '0') || (int)(zSrc-zIn) > 62){ break; } c = zSrc[0] - '0'; nVal = (nVal << 1) + c; zSrc++;
	}
	/* Skip trailing spaces */
	while(zSrc < zEnd && SyisSpace(zSrc[0])){
		zSrc++;
	}
	if( zRest ){
		*zRest = zSrc;
	}	
	if( pOutVal ){
		if( isNeg == TRUE && nVal != 0 ){
			nVal = -nVal;
		}
		*(sxi64 *)pOutVal = nVal;
	}
	return (zSrc >= zEnd) ? SXRET_OK : SXERR_SYNTAX;
}
LIBCOX_PRIVATE sxi32 SyStrToReal(const char *zSrc, sxu32 nLen, void * pOutVal, const char **zRest)
{
#define SXDBL_DIG        15
#define SXDBL_MAX_EXP    308
#define SXDBL_MIN_EXP_PLUS	307
	static const sxreal aTab[] = {
	10, 
	1.0e2, 
	1.0e4, 
	1.0e8, 
	1.0e16, 
	1.0e32, 
	1.0e64, 
	1.0e128, 
	1.0e256
	};
	sxu8 neg = FALSE;
	sxreal Val = 0.0;
	const char *zEnd;
	sxi32 Lim, exp;
	sxreal *p = 0;
#ifdef UNTRUST
	if( SX_EMPTY_STR(zSrc)  ){
		if( pOutVal ){
			*(sxreal *)pOutVal = 0.0;
		}
		return SXERR_EMPTY;
	}
#endif
	zEnd = &zSrc[nLen];
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++; 
	}
	if( zSrc < zEnd && (zSrc[0] == '-' || zSrc[0] == '+' ) ){
		neg =  zSrc[0] == '-' ? TRUE : FALSE ;
		zSrc++;
	}
	Lim = SXDBL_DIG ;
	for(;;){
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
		if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; zSrc++ ; --Lim;
	}
	if( zSrc < zEnd && ( zSrc[0] == '.' || zSrc[0] == ',' ) ){
		sxreal dec = 1.0;
		zSrc++;
		for(;;){
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
			if(zSrc >= zEnd||!Lim||!SyisDigit(zSrc[0])) break ; Val = Val * 10.0 + (zSrc[0] - '0') ; dec *= 10.0; zSrc++ ;--Lim;
		}
		Val /= dec;
	}
	if( neg == TRUE && Val != 0.0 ) {
		Val = -Val ; 
	}
	if( Lim <= 0 ){
		/* jump overflow digit */
		while( zSrc < zEnd ){
			if( zSrc[0] == 'e' || zSrc[0] == 'E' ){
				break;  
			}
			zSrc++;
		}
	}
	neg = FALSE;
	if( zSrc < zEnd && ( zSrc[0] == 'e' || zSrc[0] == 'E' ) ){
		zSrc++;
		if( zSrc < zEnd && ( zSrc[0] == '-' || zSrc[0] == '+') ){
			neg = zSrc[0] == '-' ? TRUE : FALSE ;
			zSrc++;
		}
		exp = 0;
		while( zSrc < zEnd && SyisDigit(zSrc[0]) && exp < SXDBL_MAX_EXP ){
			exp = exp * 10 + (zSrc[0] - '0');
			zSrc++;
		}
		if( neg  ){
			if( exp > SXDBL_MIN_EXP_PLUS ) exp = SXDBL_MIN_EXP_PLUS ;
		}else if ( exp > SXDBL_MAX_EXP ){
			exp = SXDBL_MAX_EXP; 
		}		
		for( p = (sxreal *)aTab ; exp ; exp >>= 1 , p++ ){
			if( exp & 01 ){
				if( neg ){
					Val /= *p ;
				}else{
					Val *= *p;
				}
			}
		}
	}
	while( zSrc < zEnd && SyisSpace(zSrc[0]) ){
		zSrc++;
	}
	if( zRest ){
		*zRest = zSrc; 
	}
	if( pOutVal ){
		*(sxreal *)pOutVal = Val;
	}
	return zSrc >= zEnd ? SXRET_OK : SXERR_SYNTAX;
}
/* SyRunTimeApi:sxlib.c  */
LIBCOX_PRIVATE sxu32 SyBinHash(const void *pSrc, sxu32 nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	sxu32 nH = 5381;
	zEnd = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
	}	
	return nH;
}
LIBCOX_PRIVATE sxi32 SyBase64Encode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData)
{
	static const unsigned char zBase64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char z64[4];
	sxu32 i;
	sxi32 rc;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0){
		return SXERR_EMPTY;
	}
#endif
	for(i = 0; i + 2 < nLen; i += 3){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1] = zBase64[( ((zIn[i] & 0x03) << 4)   | (zIn[i+1] >> 4)) & 0x3F]; 
		z64[2] = zBase64[( ((zIn[i+1] & 0x0F) << 2) | (zIn[i + 2] >> 6) ) & 0x3F];
		z64[3] = zBase64[ zIn[i + 2] & 0x3F];
		
		rc = xConsumer((const void *)z64, sizeof(z64), pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}

	}	
	if ( i+1 < nLen ){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1] = zBase64[( ((zIn[i] & 0x03) << 4)   | (zIn[i+1] >> 4)) & 0x3F]; 
		z64[2] = zBase64[(zIn[i+1] & 0x0F) << 2 ];
		z64[3] = '=';
		
		rc = xConsumer((const void *)z64, sizeof(z64), pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}

	}else if( i < nLen ){
		z64[0] = zBase64[(zIn[i] >> 2) & 0x3F];
		z64[1]   = zBase64[(zIn[i] & 0x03) << 4];
		z64[2] = '=';
		z64[3] = '=';
		
		rc = xConsumer((const void *)z64, sizeof(z64), pUserData);
		if( rc != SXRET_OK ){return SXERR_ABORT;}
	}

	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyBase64Decode(const char *zB64, sxu32 nLen, ProcConsumer xConsumer, void *pUserData)
{
	static const sxu32 aBase64Trans[] = {
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 62, 0, 0, 0, 63, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 
	5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 0, 0, 0, 0, 0, 0, 26, 27, 
	28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 0, 0, 
	0, 0, 0
	};
	sxu32 n, w, x, y, z;
	sxi32 rc;
	unsigned char zOut[10];
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zB64) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	while(nLen > 0 && zB64[nLen - 1] == '=' ){
		nLen--;
	}
	for( n = 0 ; n+3<nLen ; n += 4){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];
		y = aBase64Trans[zB64[n+2] & 0x7F];
		z = aBase64Trans[zB64[n+3] & 0x7F];
		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);
		zOut[1] = ((x<<4) & 0xF0) | ((y>>2) & 0x0F);
		zOut[2] = ((y<<6) & 0xC0) | (z & 0x3F);

		rc = xConsumer((const void *)zOut, sizeof(unsigned char)*3, pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}
	if( n+2 < nLen ){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];
		y = aBase64Trans[zB64[n+2] & 0x7F];

		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);
		zOut[1] = ((x<<4) & 0xF0) | ((y>>2) & 0x0F);

		rc = xConsumer((const void *)zOut, sizeof(unsigned char)*2, pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}else if( n+1 < nLen ){
		w = aBase64Trans[zB64[n] & 0x7F];
		x = aBase64Trans[zB64[n+1] & 0x7F];

		zOut[0] = ((w<<2) & 0xFC) | ((x>>4) & 0x03);

		rc = xConsumer((const void *)zOut, sizeof(unsigned char)*1, pUserData);
		if( rc != SXRET_OK ){ return SXERR_ABORT;}
	}
	return SXRET_OK;
}

#define INVALID_LEXER(LEX)	(  LEX == 0  || LEX->xTokenizer == 0 )
LIBCOX_PRIVATE sxi32 SyLexInit(SyLex *pLex, SySet *pSet, ProcTokenizer xTokenizer, void *pUserData)
{
	SyStream *pStream;
#if defined (UNTRUST)
	if ( pLex == 0 || xTokenizer == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	pLex->pTokenSet = 0;
	/* Initialize lexer fields */
	if( pSet ){
		if ( SySetElemSize(pSet) != sizeof(SyToken) ){
			return SXERR_INVALID;
		}
		pLex->pTokenSet = pSet;
	}
	pStream = &pLex->sStream;
	pLex->xTokenizer = xTokenizer;
	pLex->pUserData = pUserData;
	
	pStream->nLine = 1;
	pStream->nIgn  = 0;
	pStream->zText = pStream->zEnd = 0;
	pStream->pSet  = pSet;
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyLexTokenizeInput(SyLex *pLex, const char *zInput, sxu32 nLen, void *pCtxData, ProcSort xSort, ProcCmp xCmp)
{
	const unsigned char *zCur;
	SyStream *pStream;
	SyToken sToken;
	sxi32 rc;
#if defined (UNTRUST)
	if ( INVALID_LEXER(pLex) || zInput == 0 ){
		return SXERR_CORRUPT;
	}
#endif
	pStream = &pLex->sStream;
	/* Point to the head of the input */
	pStream->zText = pStream->zInput = (const unsigned char *)zInput;
	/* Point to the end of the input */
	pStream->zEnd = &pStream->zInput[nLen];
	for(;;){
		if( pStream->zText >= pStream->zEnd ){
			/* End of the input reached */
			break;
		}
		zCur = pStream->zText;
		/* Call the tokenizer callback */
		rc = pLex->xTokenizer(pStream, &sToken, pLex->pUserData, pCtxData);
		if( rc != SXRET_OK && rc != SXERR_CONTINUE ){
			/* Tokenizer callback request an operation abort */
			if( rc == SXERR_ABORT ){
				return SXERR_ABORT;
			}
			break;
		}
		if( rc == SXERR_CONTINUE ){
			/* Request to ignore this token */
			pStream->nIgn++;
		}else if( pLex->pTokenSet  ){
			/* Put the token in the set */
			rc = SySetPut(pLex->pTokenSet, (const void *)&sToken);
			if( rc != SXRET_OK ){
				break;
			}
		}
		if( zCur >= pStream->zText ){
			/* Automatic advance of the stream cursor */
			pStream->zText = &zCur[1];
		}
	}
	if( xSort &&  pLex->pTokenSet ){
		SyToken *aToken = (SyToken *)SySetBasePtr(pLex->pTokenSet);
		/* Sort the extrated tokens */
		if( xCmp == 0 ){
			/* Use a default comparison function */
			xCmp = SyMemcmp;
		}
		xSort(aToken, SySetUsed(pLex->pTokenSet), sizeof(SyToken), xCmp);
	}
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyLexRelease(SyLex *pLex)
{
	sxi32 rc = SXRET_OK;
#if defined (UNTRUST)
	if ( INVALID_LEXER(pLex) ){
		return SXERR_CORRUPT;
	}
#else
	SXUNUSED(pLex); /* Prevent compiler warning */
#endif
	return rc;
}
static const char *zEngDay[] = { 
	"Sunday", "Monday", "Tuesday", "Wednesday", 
	"Thursday", "Friday", "Saturday"
};
static const char *zEngMonth[] = {
	"January", "February", "March", "April", 
	"May", "June", "July", "August", 
	"September", "October", "November", "December"
};
static const char * GetDay(sxi32 i)
{
	return zEngDay[ i % 7 ];
}
static const char * GetMonth(sxi32 i)
{
	return zEngMonth[ i % 12 ];
}
LIBCOX_PRIVATE const char * SyTimeGetDay(sxi32 iDay)
{
	return GetDay(iDay);
}
LIBCOX_PRIVATE const char * SyTimeGetMonth(sxi32 iMonth)
{
	return GetMonth(iMonth);
}
LIBCOX_PRIVATE sxi32 SyByteFind2(const char *zStr, sxu32 nLen, sxi32 c, sxu32 *pPos)
{
	const char *zIn = zStr;
	const char *zEnd;
	
	zEnd = &zIn[nLen - 1];
	for( ;; ){
		if( zEnd < zIn ){ break; } if( zEnd[0] == c ){ if( pPos ){ *pPos =  (sxu32)(zEnd - zIn);} return SXRET_OK; } zEnd--;
		if( zEnd < zIn ){ break; } if( zEnd[0] == c ){ if( pPos ){ *pPos =  (sxu32)(zEnd - zIn);} return SXRET_OK; } zEnd--;
		if( zEnd < zIn ){ break; } if( zEnd[0] == c ){ if( pPos ){ *pPos =  (sxu32)(zEnd - zIn);} return SXRET_OK; } zEnd--;
		if( zEnd < zIn ){ break; } if( zEnd[0] == c ){ if( pPos ){ *pPos =  (sxu32)(zEnd - zIn);} return SXRET_OK; } zEnd--;
	}
	return SXERR_NOTFOUND; 
}
LIBCOX_PRIVATE sxi32 SyBlobSearch(const void *pBlob, sxu32 nLen, const void *pPattern, sxu32 pLen, sxu32 *pOfft)
{
	const char *zIn = (const char *)pBlob;
	const char *zEnd;
	sxi32 rc;
	if( pLen > nLen ){
		return SXERR_NOTFOUND;
	}
	zEnd = &zIn[nLen-pLen];
	for(;;){
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn, pPattern, pLen, rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn, pPattern, pLen, rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn, pPattern, pLen, rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
		if( zIn > zEnd ){break;} SX_MACRO_FAST_CMP(zIn, pPattern, pLen, rc); if( rc == 0 ){ if( pOfft ){ *pOfft = (sxu32)(zIn - (const char *)pBlob);} return SXRET_OK; } zIn++;
	}
	return SXERR_NOTFOUND;
}
LIBCOX_PRIVATE sxi32 SyBinToHexConsumer(const void *pIn, sxu32 nLen, ProcConsumer xConsumer, void *pConsumerData)
{
	static const unsigned char zHexTab[] = "0123456789abcdef";
	const unsigned char *zIn, *zEnd;
	unsigned char zOut[3];
	sxi32 rc;
#if defined(UNTRUST)
	if( pIn == 0 || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	zIn   = (const unsigned char *)pIn;
	zEnd  = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd  ){
			break;
		}
		zOut[0] = zHexTab[zIn[0] >> 4];  zOut[1] = zHexTab[zIn[0] & 0x0F];
		rc = xConsumer((const void *)zOut, sizeof(char)*2, pConsumerData);
		if( rc != SXRET_OK ){
			return rc;
		}
		zIn++; 
	}
	return SXRET_OK;
}
#define SAFE_HTTP(C)	(SyisAlphaNum(c) || c == '_' || c == '-' || c == '$' || c == '.' )
LIBCOX_PRIVATE sxi32 SyUriEncode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData)
{
	unsigned char *zIn = (unsigned char *)zSrc;
	unsigned char zHex[3] = { '%', 0, 0 };
	unsigned char zOut[2];
	unsigned char *zCur, *zEnd;
	sxi32 c;
	sxi32 rc = SXRET_OK;
	zEnd = &zIn[nLen]; zCur = zIn;
	for(;;){
		if( zCur >= zEnd ){
			if( zCur != zIn ){
				rc = xConsumer(zIn, (sxu32)(zCur-zIn), pUserData);
			}
			break;
		}
		c = zCur[0];
		if( SAFE_HTTP(c) ){
			zCur++; continue;
		}
		if( zCur != zIn && SXRET_OK != (rc = xConsumer(zIn, (sxu32)(zCur-zIn), pUserData))){
			break;
		}		
		if( c == ' ' ){
			zOut[0] = '+';
			rc = xConsumer((const void *)zOut, sizeof(unsigned char), pUserData);
		}else{
			zHex[1]	= "0123456789ABCDEF"[(c >> 4) & 0x0F];
			zHex[2] = "0123456789ABCDEF"[c & 0x0F];
			rc = xConsumer(zHex, sizeof(zHex), pUserData);
		}
		if( SXRET_OK != rc ){
			break;
		}				
		zIn = &zCur[1]; zCur = zIn ;
	}
	return rc == SXRET_OK ? SXRET_OK : SXERR_ABORT;
}
LIBCOX_PRIVATE sxi32 SyStrncmp(const char *zLeft, const char *zRight, sxu32 nLen)
{
	const unsigned char *zP = (const unsigned char *)zLeft;
	const unsigned char *zQ = (const unsigned char *)zRight;

	if( SX_EMPTY_STR(zP) || SX_EMPTY_STR(zQ)  ){
			return SX_EMPTY_STR(zP) ? (SX_EMPTY_STR(zQ) ? 0 : -1) :1;
	}
	if( nLen <= 0 ){
		return 0;
	}
	for(;;){
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
		if( nLen <= 0 ){ return 0; } if( zP[0] == 0 || zQ[0] == 0 || zP[0] != zQ[0] ){ break; } zP++; zQ++; nLen--;
	}
	return (sxi32)(zP[0] - zQ[0]);
}	
static sxi32 SyAsciiToHex(sxi32 c)
{
	if( c >= 'a' && c <= 'f' ){
		c += 10 - 'a';
		return c;
	}
	if( c >= '0' && c <= '9' ){
		c -= '0';
		return c;
	}
	if( c >= 'A' && c <= 'F') {
		c += 10 - 'A';
		return c;
	}		
	return 0; 
}
LIBCOX_PRIVATE sxi32 SyUriDecode(const char *zSrc, sxu32 nLen, ProcConsumer xConsumer, void *pUserData, int bUTF8)
{
	static const sxu8 Utf8Trans[] = {
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
		0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
		0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
		0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
		0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
		0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x00, 0x00
	};
	const char *zIn = zSrc;
	const char *zEnd;
	const char *zCur;
	sxu8 *zOutPtr;
	sxu8 zOut[10];
	sxi32 c, d;
	sxi32 rc;
#if defined(UNTRUST)
	if( SX_EMPTY_STR(zSrc) || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	rc = SXRET_OK;
	zEnd = &zSrc[nLen];
	zCur = zIn;
	for(;;){
		while(zCur < zEnd && zCur[0] != '%' && zCur[0] != '+' ){
			zCur++;
		}
		if( zCur != zIn ){
			/* Consume input */
			rc = xConsumer(zIn, (unsigned int)(zCur-zIn), pUserData);
			if( rc != SXRET_OK ){
				/* User consumer routine request an operation abort */
				break;
			}
		}
		if( zCur >= zEnd ){
			rc = SXRET_OK;
			break;
		}
		/* Decode unsafe HTTP characters */
		zOutPtr = zOut;
		if( zCur[0] == '+' ){
			*zOutPtr++ = ' ';
			zCur++;
		}else{
			if( &zCur[2] >= zEnd ){
				rc = SXERR_OVERFLOW;
				break;
			}
			c = (SyAsciiToHex(zCur[1]) <<4) | SyAsciiToHex(zCur[2]);
			zCur += 3;
			if( c < 0x000C0 ){
				*zOutPtr++ = (sxu8)c;
			}else{
				c = Utf8Trans[c-0xC0];
				while( zCur[0] == '%' ){
					d = (SyAsciiToHex(zCur[1]) <<4) | SyAsciiToHex(zCur[2]);
					if( (d&0xC0) != 0x80 ){
						break;
					}
					c = (c<<6) + (0x3f & d);
					zCur += 3;
				}
				if( bUTF8 == FALSE ){
					*zOutPtr++ = (sxu8)c;
				}else{
					SX_WRITE_UTF8(zOutPtr, c);
				}
			}
			
		}
		/* Consume the decoded characters */
		rc = xConsumer((const void *)zOut, (unsigned int)(zOutPtr-zOut), pUserData);
		if( rc != SXRET_OK ){
			break;
		}
		/* Synchronize pointers */
		zIn = zCur;
	}
	return rc;
}
/* SyRunTimeApi: sxfmt.c */
#define SXFMT_BUFSIZ 1024 /* Conversion buffer size */
/*
** Conversion types fall into various categories as defined by the
** following enumeration.
*/
#define SXFMT_RADIX       1 /* Integer types.%d, %x, %o, and so forth */
#define SXFMT_FLOAT       2 /* Floating point.%f */
#define SXFMT_EXP         3 /* Exponentional notation.%e and %E */
#define SXFMT_GENERIC     4 /* Floating or exponential, depending on exponent.%g */
#define SXFMT_SIZE        5 /* Total number of characters processed so far.%n */
#define SXFMT_STRING      6 /* Strings.%s */
#define SXFMT_PERCENT     7 /* Percent symbol.%% */
#define SXFMT_CHARX       8 /* Characters.%c */
#define SXFMT_ERROR       9 /* Used to indicate no such conversion type */
/* Extension by Symisc Systems */
#define SXFMT_RAWSTR     13 /* %z Pointer to raw string (SyString *) */
#define SXFMT_UNUSED     15 
/*
** Allowed values for SyFmtInfo.flags
*/
#define SXFLAG_SIGNED	0x01
#define SXFLAG_UNSIGNED 0x02
/* Allowed values for SyFmtConsumer.nType */
#define SXFMT_CONS_PROC		1	/* Consumer is a procedure */
#define SXFMT_CONS_STR		2	/* Consumer is a managed string */
#define SXFMT_CONS_FILE		5	/* Consumer is an open File */
#define SXFMT_CONS_BLOB		6	/* Consumer is a BLOB */
/*
** Each builtin conversion character (ex: the 'd' in "%d") is described
** by an instance of the following structure
*/
typedef struct SyFmtInfo SyFmtInfo;
struct SyFmtInfo
{
  char fmttype;  /* The format field code letter [i.e: 'd', 's', 'x'] */
  sxu8 base;     /* The base for radix conversion */
  int flags;    /* One or more of SXFLAG_ constants below */
  sxu8 type;     /* Conversion paradigm */
  char *charset; /* The character set for conversion */
  char *prefix;  /* Prefix on non-zero values in alt format */
};
typedef struct SyFmtConsumer SyFmtConsumer;
struct SyFmtConsumer
{
	sxu32 nLen; /* Total output length */
	sxi32 nType; /* Type of the consumer see below */
	sxi32 rc;	/* Consumer return value;Abort processing if rc != SXRET_OK */
 union{
	struct{	
	ProcConsumer xUserConsumer;
	void *pUserData;
	}sFunc;  
	SyBlob *pBlob;
 }uConsumer;	
}; 
#ifndef SX_OMIT_FLOATINGPOINT
static int getdigit(sxlongreal *val, int *cnt)
{
  sxlongreal d;
  int digit;

  if( (*cnt)++ >= 16 ){
	  return '0';
  }
  digit = (int)*val;
  d = digit;
   *val = (*val - d)*10.0;
  return digit + '0' ;
}
#endif /* SX_OMIT_FLOATINGPOINT */
/*
 * The following routine was taken from the SQLITE2 source tree and was
 * extended by Symisc Systems to fit its need.
 * Status: Public Domain
 */
static sxi32 InternFormat(ProcConsumer xConsumer, void *pUserData, const char *zFormat, va_list ap)
{
	/*
	 * The following table is searched linearly, so it is good to put the most frequently
	 * used conversion types first.
	 */
static const SyFmtInfo aFmt[] = {
  {  'd', 10, SXFLAG_SIGNED, SXFMT_RADIX, "0123456789", 0    }, 
  {  's',  0, 0, SXFMT_STRING,     0,                  0    }, 
  {  'c',  0, 0, SXFMT_CHARX,      0,                  0    }, 
  {  'x', 16, 0, SXFMT_RADIX,      "0123456789abcdef", "x0" }, 
  {  'X', 16, 0, SXFMT_RADIX,      "0123456789ABCDEF", "X0" }, 
         /* -- Extensions by Symisc Systems -- */
  {  'z',  0, 0, SXFMT_RAWSTR,     0,                   0   }, /* Pointer to a raw string (SyString *) */
  {  'B',  2, 0, SXFMT_RADIX,      "01",                "b0"}, 
         /* -- End of Extensions -- */
  {  'o',  8, 0, SXFMT_RADIX,      "01234567",         "0"  }, 
  {  'u', 10, 0, SXFMT_RADIX,      "0123456789",       0    }, 
#ifndef SX_OMIT_FLOATINGPOINT
  {  'f',  0, SXFLAG_SIGNED, SXFMT_FLOAT,       0,     0    }, 
  {  'e',  0, SXFLAG_SIGNED, SXFMT_EXP,        "e",    0    }, 
  {  'E',  0, SXFLAG_SIGNED, SXFMT_EXP,        "E",    0    }, 
  {  'g',  0, SXFLAG_SIGNED, SXFMT_GENERIC,    "e",    0    }, 
  {  'G',  0, SXFLAG_SIGNED, SXFMT_GENERIC,    "E",    0    }, 
#endif
  {  'i', 10, SXFLAG_SIGNED, SXFMT_RADIX, "0123456789", 0    }, 
  {  'n',  0, 0, SXFMT_SIZE,       0,                  0    }, 
  {  '%',  0, 0, SXFMT_PERCENT,    0,                  0    }, 
  {  'p', 10, 0, SXFMT_RADIX,      "0123456789",       0    }
};
  int c;                     /* Next character in the format string */
  char *bufpt;               /* Pointer to the conversion buffer */
  int precision;             /* Precision of the current field */
  int length;                /* Length of the field */
  int idx;                   /* A general purpose loop counter */
  int width;                 /* Width of the current field */
  sxu8 flag_leftjustify;   /* True if "-" flag is present */
  sxu8 flag_plussign;      /* True if "+" flag is present */
  sxu8 flag_blanksign;     /* True if " " flag is present */
  sxu8 flag_alternateform; /* True if "#" flag is present */
  sxu8 flag_zeropad;       /* True if field width constant starts with zero */
  sxu8 flag_long;          /* True if "l" flag is present */
  sxi64 longvalue;         /* Value for integer types */
  const SyFmtInfo *infop;  /* Pointer to the appropriate info structure */
  char buf[SXFMT_BUFSIZ];  /* Conversion buffer */
  char prefix;             /* Prefix character."+" or "-" or " " or '\0'.*/
  sxu8 errorflag = 0;      /* True if an error is encountered */
  sxu8 xtype;              /* Conversion paradigm */
  char *zExtra;    
  static char spaces[] = "                                                  ";
#define etSPACESIZE ((int)sizeof(spaces)-1)
#ifndef SX_OMIT_FLOATINGPOINT
  sxlongreal realvalue;    /* Value for real types */
  int  exp;                /* exponent of real numbers */
  double rounder;          /* Used for rounding floating point values */
  sxu8 flag_dp;            /* True if decimal point should be shown */
  sxu8 flag_rtz;           /* True if trailing zeros should be removed */
  sxu8 flag_exp;           /* True to force display of the exponent */
  int nsd;                 /* Number of significant digits returned */
#endif
  int rc;

  length = 0;
  bufpt = 0;
  for(; (c=(*zFormat))!=0; ++zFormat){
    if( c!='%' ){
      unsigned int amt;
      bufpt = (char *)zFormat;
      amt = 1;
      while( (c=(*++zFormat))!='%' && c!=0 ) amt++;
	  rc = xConsumer((const void *)bufpt, amt, pUserData);
	  if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
	  }
      if( c==0 ){
		  return errorflag > 0 ? SXERR_FORMAT : SXRET_OK;
	  }
    }
    if( (c=(*++zFormat))==0 ){
      errorflag = 1;
	  rc = xConsumer("%", sizeof("%")-1, pUserData);
	  if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
	  }
      return errorflag > 0 ? SXERR_FORMAT : SXRET_OK;
    }
    /* Find out what flags are present */
    flag_leftjustify = flag_plussign = flag_blanksign = 
     flag_alternateform = flag_zeropad = 0;
    do{
      switch( c ){
        case '-':   flag_leftjustify = 1;     c = 0;   break;
        case '+':   flag_plussign = 1;        c = 0;   break;
        case ' ':   flag_blanksign = 1;       c = 0;   break;
        case '#':   flag_alternateform = 1;   c = 0;   break;
        case '0':   flag_zeropad = 1;         c = 0;   break;
        default:                                       break;
      }
    }while( c==0 && (c=(*++zFormat))!=0 );
    /* Get the field width */
    width = 0;
    if( c=='*' ){
      width = va_arg(ap, int);
      if( width<0 ){
        flag_leftjustify = 1;
        width = -width;
      }
      c = *++zFormat;
    }else{
      while( c>='0' && c<='9' ){
        width = width*10 + c - '0';
        c = *++zFormat;
      }
    }
    if( width > SXFMT_BUFSIZ-10 ){
      width = SXFMT_BUFSIZ-10;
    }
    /* Get the precision */
	precision = -1;
    if( c=='.' ){
      precision = 0;
      c = *++zFormat;
      if( c=='*' ){
        precision = va_arg(ap, int);
        if( precision<0 ) precision = -precision;
        c = *++zFormat;
      }else{
        while( c>='0' && c<='9' ){
          precision = precision*10 + c - '0';
          c = *++zFormat;
        }
      }
    }
    /* Get the conversion type modifier */
	flag_long = 0;
    if( c=='l' || c == 'q' /* BSD quad (expect a 64-bit integer) */ ){
      flag_long = (c == 'q') ? 2 : 1;
      c = *++zFormat;
	  if( c == 'l' ){
		  /* Standard printf emulation 'lld' (expect a 64bit integer) */
		  flag_long = 2;
	  }
    }
    /* Fetch the info entry for the field */
    infop = 0;
    xtype = SXFMT_ERROR;
	for(idx=0; idx< (int)SX_ARRAYSIZE(aFmt); idx++){
      if( c==aFmt[idx].fmttype ){
        infop = &aFmt[idx];
		xtype = infop->type;
        break;
      }
    }
    zExtra = 0;

    /*
    ** At this point, variables are initialized as follows:
    **
    **   flag_alternateform          TRUE if a '#' is present.
    **   flag_plussign               TRUE if a '+' is present.
    **   flag_leftjustify            TRUE if a '-' is present or if the
    **                               field width was negative.
    **   flag_zeropad                TRUE if the width began with 0.
    **   flag_long                   TRUE if the letter 'l' (ell) or 'q'(BSD quad) prefixed
    **                               the conversion character.
    **   flag_blanksign              TRUE if a ' ' is present.
    **   width                       The specified field width.This is
    **                               always non-negative.Zero is the default.
    **   precision                   The specified precision.The default
    **                               is -1.
    **   xtype                       The object of the conversion.
    **   infop                       Pointer to the appropriate info struct.
    */
    switch( xtype ){
      case SXFMT_RADIX:
        if( flag_long > 0 ){
			if( flag_long > 1 ){
				/* BSD quad: expect a 64-bit integer */
				longvalue = va_arg(ap, sxi64);
			}else{
				longvalue = va_arg(ap, sxlong);
			}
		}else{
			if( infop->flags & SXFLAG_SIGNED ){
				longvalue = va_arg(ap, sxi32);
			}else{
				longvalue = va_arg(ap, sxu32);
			}
		}
		/* Limit the precision to prevent overflowing buf[] during conversion */
      if( precision>SXFMT_BUFSIZ-40 ) precision = SXFMT_BUFSIZ-40;
#if 1
        /* For the format %#x, the value zero is printed "0" not "0x0".
        ** I think this is stupid.*/
        if( longvalue==0 ) flag_alternateform = 0;
#else
        /* More sensible: turn off the prefix for octal (to prevent "00"), 
        ** but leave the prefix for hex.*/
        if( longvalue==0 && infop->base==8 ) flag_alternateform = 0;
#endif
        if( infop->flags & SXFLAG_SIGNED ){
          if( longvalue<0 ){ 
            longvalue = -longvalue;
			/* Ticket 1433-003 */
			if( longvalue < 0 ){
				/* Overflow */
				longvalue= 0x7FFFFFFFFFFFFFFF;
			}
            prefix = '-';
          }else if( flag_plussign )  prefix = '+';
          else if( flag_blanksign )  prefix = ' ';
          else                       prefix = 0;
        }else{
			if( longvalue<0 ){
				longvalue = -longvalue;
				/* Ticket 1433-003 */
				if( longvalue < 0 ){
					/* Overflow */
					longvalue= 0x7FFFFFFFFFFFFFFF;
				}
			}
			prefix = 0;
		}
        if( flag_zeropad && precision<width-(prefix!=0) ){
          precision = width-(prefix!=0);
        }
        bufpt = &buf[SXFMT_BUFSIZ-1];
        {
          register char *cset;      /* Use registers for speed */
          register int base;
          cset = infop->charset;
          base = infop->base;
          do{                                           /* Convert to ascii */
            *(--bufpt) = cset[longvalue%base];
            longvalue = longvalue/base;
          }while( longvalue>0 );
        }
        length = &buf[SXFMT_BUFSIZ-1]-bufpt;
        for(idx=precision-length; idx>0; idx--){
          *(--bufpt) = '0';                             /* Zero pad */
        }
        if( prefix ) *(--bufpt) = prefix;               /* Add sign */
        if( flag_alternateform && infop->prefix ){      /* Add "0" or "0x" */
          char *pre, x;
          pre = infop->prefix;
          if( *bufpt!=pre[0] ){
            for(pre=infop->prefix; (x=(*pre))!=0; pre++) *(--bufpt) = x;
          }
        }
        length = &buf[SXFMT_BUFSIZ-1]-bufpt;
        break;
      case SXFMT_FLOAT:
      case SXFMT_EXP:
      case SXFMT_GENERIC:
#ifndef SX_OMIT_FLOATINGPOINT
		realvalue = va_arg(ap, double);
        if( precision<0 ) precision = 6;         /* Set default precision */
        if( precision>SXFMT_BUFSIZ-40) precision = SXFMT_BUFSIZ-40;
        if( realvalue<0.0 ){
          realvalue = -realvalue;
          prefix = '-';
        }else{
          if( flag_plussign )          prefix = '+';
          else if( flag_blanksign )    prefix = ' ';
          else                         prefix = 0;
        }
        if( infop->type==SXFMT_GENERIC && precision>0 ) precision--;
        rounder = 0.0;
#if 0
        /* Rounding works like BSD when the constant 0.4999 is used.Wierd! */
        for(idx=precision, rounder=0.4999; idx>0; idx--, rounder*=0.1);
#else
        /* It makes more sense to use 0.5 */
        for(idx=precision, rounder=0.5; idx>0; idx--, rounder*=0.1);
#endif
        if( infop->type==SXFMT_FLOAT ) realvalue += rounder;
        /* Normalize realvalue to within 10.0 > realvalue >= 1.0 */
        exp = 0;
        if( realvalue>0.0 ){
          while( realvalue>=1e8 && exp<=350 ){ realvalue *= 1e-8; exp+=8; }
          while( realvalue>=10.0 && exp<=350 ){ realvalue *= 0.1; exp++; }
          while( realvalue<1e-8 && exp>=-350 ){ realvalue *= 1e8; exp-=8; }
          while( realvalue<1.0 && exp>=-350 ){ realvalue *= 10.0; exp--; }
          if( exp>350 || exp<-350 ){
            bufpt = "NaN";
            length = 3;
            break;
          }
        }
        bufpt = buf;
        /*
        ** If the field type is etGENERIC, then convert to either etEXP
        ** or etFLOAT, as appropriate.
        */
        flag_exp = xtype==SXFMT_EXP;
        if( xtype!=SXFMT_FLOAT ){
          realvalue += rounder;
          if( realvalue>=10.0 ){ realvalue *= 0.1; exp++; }
        }
        if( xtype==SXFMT_GENERIC ){
          flag_rtz = !flag_alternateform;
          if( exp<-4 || exp>precision ){
            xtype = SXFMT_EXP;
          }else{
            precision = precision - exp;
            xtype = SXFMT_FLOAT;
          }
        }else{
          flag_rtz = 0;
        }
        /*
        ** The "exp+precision" test causes output to be of type etEXP if
        ** the precision is too large to fit in buf[].
        */
        nsd = 0;
        if( xtype==SXFMT_FLOAT && exp+precision<SXFMT_BUFSIZ-30 ){
          flag_dp = (precision>0 || flag_alternateform);
          if( prefix ) *(bufpt++) = prefix;         /* Sign */
          if( exp<0 )  *(bufpt++) = '0';            /* Digits before "." */
          else for(; exp>=0; exp--) *(bufpt++) = (char)getdigit(&realvalue, &nsd);
          if( flag_dp ) *(bufpt++) = '.';           /* The decimal point */
          for(exp++; exp<0 && precision>0; precision--, exp++){
            *(bufpt++) = '0';
          }
          while( (precision--)>0 ) *(bufpt++) = (char)getdigit(&realvalue, &nsd);
          *(bufpt--) = 0;                           /* Null terminate */
          if( flag_rtz && flag_dp ){     /* Remove trailing zeros and "." */
            while( bufpt>=buf && *bufpt=='0' ) *(bufpt--) = 0;
            if( bufpt>=buf && *bufpt=='.' ) *(bufpt--) = 0;
          }
          bufpt++;                            /* point to next free slot */
        }else{    /* etEXP or etGENERIC */
          flag_dp = (precision>0 || flag_alternateform);
          if( prefix ) *(bufpt++) = prefix;   /* Sign */
          *(bufpt++) = (char)getdigit(&realvalue, &nsd);  /* First digit */
          if( flag_dp ) *(bufpt++) = '.';     /* Decimal point */
          while( (precision--)>0 ) *(bufpt++) = (char)getdigit(&realvalue, &nsd);
          bufpt--;                            /* point to last digit */
          if( flag_rtz && flag_dp ){          /* Remove tail zeros */
            while( bufpt>=buf && *bufpt=='0' ) *(bufpt--) = 0;
            if( bufpt>=buf && *bufpt=='.' ) *(bufpt--) = 0;
          }
          bufpt++;                            /* point to next free slot */
          if( exp || flag_exp ){
            *(bufpt++) = infop->charset[0];
            if( exp<0 ){ *(bufpt++) = '-'; exp = -exp; } /* sign of exp */
            else       { *(bufpt++) = '+'; }
            if( exp>=100 ){
              *(bufpt++) = (char)((exp/100)+'0');                /* 100's digit */
              exp %= 100;
            }
            *(bufpt++) = (char)(exp/10+'0');                     /* 10's digit */
            *(bufpt++) = (char)(exp%10+'0');                     /* 1's digit */
          }
        }
        /* The converted number is in buf[] and zero terminated.Output it.
        ** Note that the number is in the usual order, not reversed as with
        ** integer conversions.*/
        length = bufpt-buf;
        bufpt = buf;

        /* Special case:  Add leading zeros if the flag_zeropad flag is
        ** set and we are not left justified */
        if( flag_zeropad && !flag_leftjustify && length < width){
          int i;
          int nPad = width - length;
          for(i=width; i>=nPad; i--){
            bufpt[i] = bufpt[i-nPad];
          }
          i = prefix!=0;
          while( nPad-- ) bufpt[i++] = '0';
          length = width;
        }
#else
         bufpt = " ";
		 length = (int)sizeof(" ") - 1;
#endif /* SX_OMIT_FLOATINGPOINT */
        break;
      case SXFMT_SIZE:{
		 int *pSize = va_arg(ap, int *);
		 *pSize = ((SyFmtConsumer *)pUserData)->nLen;
		 length = width = 0;
					  }
        break;
      case SXFMT_PERCENT:
        buf[0] = '%';
        bufpt = buf;
        length = 1;
        break;
      case SXFMT_CHARX:
        c = va_arg(ap, int);
		buf[0] = (char)c;
		/* Limit the precision to prevent overflowing buf[] during conversion */
		if( precision>SXFMT_BUFSIZ-40 ) precision = SXFMT_BUFSIZ-40;
        if( precision>=0 ){
          for(idx=1; idx<precision; idx++) buf[idx] = (char)c;
          length = precision;
        }else{
          length =1;
        }
        bufpt = buf;
        break;
      case SXFMT_STRING:
        bufpt = va_arg(ap, char*);
        if( bufpt==0 ){
          bufpt = " ";
		  length = (int)sizeof(" ")-1;
		  break;
        }
		length = precision;
		if( precision < 0 ){
			/* Symisc extension */
			length = (int)SyStrlen(bufpt);
		}
        if( precision>=0 && precision<length ) length = precision;
        break;
	case SXFMT_RAWSTR:{
		/* Symisc extension */
		SyString *pStr = va_arg(ap, SyString *);
		if( pStr == 0 || pStr->zString == 0 ){
			 bufpt = " ";
		     length = (int)sizeof(char);
		     break;
		}
		bufpt = (char *)pStr->zString;
		length = (int)pStr->nByte;
		break;
					  }
      case SXFMT_ERROR:
        buf[0] = '?';
        bufpt = buf;
		length = (int)sizeof(char);
        if( c==0 ) zFormat--;
        break;
    }/* End switch over the format type */
    /*
    ** The text of the conversion is pointed to by "bufpt" and is
    ** "length" characters long.The field width is "width".Do
    ** the output.
    */
    if( !flag_leftjustify ){
      register int nspace;
      nspace = width-length;
      if( nspace>0 ){
        while( nspace>=etSPACESIZE ){
			rc = xConsumer(spaces, etSPACESIZE, pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
			nspace -= etSPACESIZE;
        }
        if( nspace>0 ){
			rc = xConsumer(spaces, (unsigned int)nspace, pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
		}
      }
    }
    if( length>0 ){
		rc = xConsumer(bufpt, (unsigned int)length, pUserData);
		if( rc != SXRET_OK ){
		  return SXERR_ABORT; /* Consumer routine request an operation abort */
		}
    }
    if( flag_leftjustify ){
      register int nspace;
      nspace = width-length;
      if( nspace>0 ){
        while( nspace>=etSPACESIZE ){
			rc = xConsumer(spaces, etSPACESIZE, pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
			nspace -= etSPACESIZE;
        }
        if( nspace>0 ){
			rc = xConsumer(spaces, (unsigned int)nspace, pUserData);
			if( rc != SXRET_OK ){
				return SXERR_ABORT; /* Consumer routine request an operation abort */
			}
		}
      }
    }
  }/* End for loop over the format string */
  return errorflag ? SXERR_FORMAT : SXRET_OK;
} 
static sxi32 FormatConsumer(const void *pSrc, unsigned int nLen, void *pData)
{
	SyFmtConsumer *pConsumer = (SyFmtConsumer *)pData;
	sxi32 rc = SXERR_ABORT;
	switch(pConsumer->nType){
	case SXFMT_CONS_PROC:
			/* User callback */
			rc = pConsumer->uConsumer.sFunc.xUserConsumer(pSrc, nLen, pConsumer->uConsumer.sFunc.pUserData);
			break;
	case SXFMT_CONS_BLOB:
			/* Blob consumer */
			rc = SyBlobAppend(pConsumer->uConsumer.pBlob, pSrc, (sxu32)nLen);
			break;
		default: 
			/* Unknown consumer */
			break;
	}
	/* Update total number of bytes consumed so far */
	pConsumer->nLen += nLen;
	pConsumer->rc = rc;
	return rc;	
}
static sxi32 FormatMount(sxi32 nType, void *pConsumer, ProcConsumer xUserCons, void *pUserData, sxu32 *pOutLen, const char *zFormat, va_list ap)
{
	SyFmtConsumer sCons;
	sCons.nType = nType;
	sCons.rc = SXRET_OK;
	sCons.nLen = 0;
	if( pOutLen ){
		*pOutLen = 0;
	}
	switch(nType){
	case SXFMT_CONS_PROC:
#if defined(UNTRUST)
			if( xUserCons == 0 ){
				return SXERR_EMPTY;
			}
#endif
			sCons.uConsumer.sFunc.xUserConsumer = xUserCons;
			sCons.uConsumer.sFunc.pUserData	    = pUserData;
		break;
		case SXFMT_CONS_BLOB:
			sCons.uConsumer.pBlob = (SyBlob *)pConsumer;
			break;
		default: 
			return SXERR_UNKNOWN;
	}
	InternFormat(FormatConsumer, &sCons, zFormat, ap); 
	if( pOutLen ){
		*pOutLen = sCons.nLen;
	}
	return sCons.rc;
}
LIBCOX_PRIVATE sxu32 SyBlobFormat(SyBlob *pBlob, const char *zFormat, ...)
{
	va_list ap;
	sxu32 n;
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif			
	va_start(ap, zFormat);
	FormatMount(SXFMT_CONS_BLOB, &(*pBlob), 0, 0, &n, zFormat, ap);
	va_end(ap);
	return n;
}
LIBCOX_PRIVATE sxu32 SyBlobFormatAp(SyBlob *pBlob, const char *zFormat, va_list ap)
{
	sxu32 n = 0; /* cc warning */
#if defined(UNTRUST)	
	if( SX_EMPTY_STR(zFormat) ){
		return 0;
	}
#endif	
	FormatMount(SXFMT_CONS_BLOB, &(*pBlob), 0, 0, &n, zFormat, ap);
	return n;
}
/*
 * Psuedo Random Number Generator (PRNG)
 * @authors: SQLite authors <http://www.sqlite.org/>
 * @status: Public Domain
 * NOTE:
 *  Nothing in this file or anywhere else in the library does any kind of
 *  encryption.The RC4 algorithm is being used as a PRNG (pseudo-random
 *  number generator) not as an encryption device.
 */
#define SXPRNG_MAGIC	0x13C4
#ifdef __UNIXES__
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#endif
static sxi32 SyOSUtilRandomSeed(void *pBuf, sxu32 nLen, void *pUnused)
{
	char *zBuf = (char *)pBuf;
#ifdef __WINNT__
	DWORD nProcessID; /* Yes, keep it uninitialized when compiling using the MinGW32 builds tools */
#elif defined(__UNIXES__)
	pid_t pid;
	int fd;
#else
	char zGarbage[128]; /* Yes, keep this buffer uninitialized */
#endif
	SXUNUSED(pUnused);
#ifdef __WINNT__
#ifndef __MINGW32__
	nProcessID = GetProcessId(GetCurrentProcess());
#endif
	SyMemcpy((const void *)&nProcessID, zBuf, SXMIN(nLen, sizeof(DWORD)));
	if( (sxu32)(&zBuf[nLen] - &zBuf[sizeof(DWORD)]) >= sizeof(SYSTEMTIME)  ){
		GetSystemTime((LPSYSTEMTIME)&zBuf[sizeof(DWORD)]);
	}
#elif defined(__UNIXES__)
	fd = open("/dev/urandom", O_RDONLY);
	if (fd >= 0 ){
		if( read(fd, zBuf, nLen) > 0 ){
			return SXRET_OK;
		}
		/* FALL THRU */
	}
	pid = getpid();
	SyMemcpy((const void *)&pid, zBuf, SXMIN(nLen, sizeof(pid_t)));
	if( &zBuf[nLen] - &zBuf[sizeof(pid_t)] >= (int)sizeof(struct timeval)  ){
		gettimeofday((struct timeval *)&zBuf[sizeof(pid_t)], 0);
	}
#else
	/* Fill with uninitialized data */
	SyMemcpy(zGarbage, zBuf, SXMIN(nLen, sizeof(zGarbage)));
#endif
	return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyRandomnessInit(SyPRNGCtx *pCtx, ProcRandomSeed xSeed, void * pUserData)
{
	char zSeed[256];
	sxu8 t;
	sxi32 rc;
	sxu32 i;
	if( pCtx->nMagic == SXPRNG_MAGIC ){
		return SXRET_OK; /* Already initialized */
	}
 /* Initialize the state of the random number generator once, 
  ** the first time this routine is called.The seed value does
  ** not need to contain a lot of randomness since we are not
  ** trying to do secure encryption or anything like that...
  */	
	if( xSeed == 0 ){
		xSeed = SyOSUtilRandomSeed;
	}
	rc = xSeed(zSeed, sizeof(zSeed), pUserData);
	if( rc != SXRET_OK ){
		return rc;
	}
	pCtx->i = pCtx->j = 0;
	for(i=0; i < SX_ARRAYSIZE(pCtx->s) ; i++){
		pCtx->s[i] = (unsigned char)i;
    }
    for(i=0; i < sizeof(zSeed) ; i++){
      pCtx->j += pCtx->s[i] + zSeed[i];
      t = pCtx->s[pCtx->j];
      pCtx->s[pCtx->j] = pCtx->s[i];
      pCtx->s[i] = t;
    }
	pCtx->nMagic = SXPRNG_MAGIC;
	
	return SXRET_OK;
}
/*
 * Get a single 8-bit random value using the RC4 PRNG.
 */
static sxu8 randomByte(SyPRNGCtx *pCtx)
{
  sxu8 t;
  
  /* Generate and return single random byte */
  pCtx->i++;
  t = pCtx->s[pCtx->i];
  pCtx->j += t;
  pCtx->s[pCtx->i] = pCtx->s[pCtx->j];
  pCtx->s[pCtx->j] = t;
  t += pCtx->s[pCtx->i];
  return pCtx->s[t];
}
LIBCOX_PRIVATE sxi32 SyRandomness(SyPRNGCtx *pCtx, void *pBuf, sxu32 nLen)
{
	unsigned char *zBuf = (unsigned char *)pBuf;
	unsigned char *zEnd = &zBuf[nLen];
#if defined(UNTRUST)
	if( pCtx == 0 || pBuf == 0 || nLen <= 0 ){
		return SXERR_EMPTY;
	}
#endif
	if(pCtx->nMagic != SXPRNG_MAGIC ){
		return SXERR_CORRUPT;
	}
	for(;;){
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
		if( zBuf >= zEnd ){break;}	zBuf[0] = randomByte(pCtx);	zBuf++;	
	}
	return SXRET_OK;  
}
#ifdef LIBCOX_ENABLE_HASH_CMD
/* SyRunTimeApi: sxhash.c */
/*
 * This code implements the MD5 message-digest algorithm.
 * The algorithm is due to Ron Rivest.This code was
 * written by Colin Plumb in 1993, no copyright is claimed.
 * This code is in the public domain; do with it what you wish.
 *
 * Equivalent code is available from RSA Data Security, Inc.
 * This code has been tested against that, and is equivalent, 
 * except that you don't need to include two pages of legalese
 * with every copy.
 *
 * To compute the message digest of a chunk of bytes, declare an
 * MD5Context structure, pass it to MD5Init, call MD5Update as
 * needed on buffers full of bytes, and then call MD5Final, which
 * will fill a supplied 16-byte array with the digest.
 */
#define SX_MD5_BINSZ	16
#define SX_MD5_HEXSZ	32
/*
 * Note: this code is harmless on little-endian machines.
 */
static void byteReverse (unsigned char *buf, unsigned longs)
{
	sxu32 t;
        do {
                t = (sxu32)((unsigned)buf[3]<<8 | buf[2]) << 16 |
                            ((unsigned)buf[1]<<8 | buf[0]);
                *(sxu32*)buf = t;
                buf += 4;
        } while (--longs);
}
/* The four core functions - F1 is optimized somewhat */

/* #define F1(x, y, z) (x & y | ~x & z) */
#ifdef F1
#undef F1
#endif
#ifdef F2
#undef F2
#endif
#ifdef F3
#undef F3
#endif
#ifdef F4
#undef F4
#endif

#define F1(x, y, z) (z ^ (x & (y ^ z)))
#define F2(x, y, z) F1(z, x, y)
#define F3(x, y, z) (x ^ y ^ z)
#define F4(x, y, z) (y ^ (x | ~z))

/* This is the central step in the MD5 algorithm.*/
#define SX_MD5STEP(f, w, x, y, z, data, s) \
        ( w += f(x, y, z) + data,  w = w<<s | w>>(32-s),  w += x )

/*
 * The core of the MD5 algorithm, this alters an existing MD5 hash to
 * reflect the addition of 16 longwords of new data.MD5Update blocks
 * the data and converts bytes into longwords for this routine.
 */
static void MD5Transform(sxu32 buf[4], const sxu32 in[16])
{
	register sxu32 a, b, c, d;

        a = buf[0];
        b = buf[1];
        c = buf[2];
        d = buf[3];

        SX_MD5STEP(F1, a, b, c, d, in[ 0]+0xd76aa478,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 1]+0xe8c7b756, 12);
        SX_MD5STEP(F1, c, d, a, b, in[ 2]+0x242070db, 17);
        SX_MD5STEP(F1, b, c, d, a, in[ 3]+0xc1bdceee, 22);
        SX_MD5STEP(F1, a, b, c, d, in[ 4]+0xf57c0faf,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 5]+0x4787c62a, 12);
        SX_MD5STEP(F1, c, d, a, b, in[ 6]+0xa8304613, 17);
        SX_MD5STEP(F1, b, c, d, a, in[ 7]+0xfd469501, 22);
        SX_MD5STEP(F1, a, b, c, d, in[ 8]+0x698098d8,  7);
        SX_MD5STEP(F1, d, a, b, c, in[ 9]+0x8b44f7af, 12);
        SX_MD5STEP(F1, c, d, a, b, in[10]+0xffff5bb1, 17);
        SX_MD5STEP(F1, b, c, d, a, in[11]+0x895cd7be, 22);
        SX_MD5STEP(F1, a, b, c, d, in[12]+0x6b901122,  7);
        SX_MD5STEP(F1, d, a, b, c, in[13]+0xfd987193, 12);
        SX_MD5STEP(F1, c, d, a, b, in[14]+0xa679438e, 17);
        SX_MD5STEP(F1, b, c, d, a, in[15]+0x49b40821, 22);

        SX_MD5STEP(F2, a, b, c, d, in[ 1]+0xf61e2562,  5);
        SX_MD5STEP(F2, d, a, b, c, in[ 6]+0xc040b340,  9);
        SX_MD5STEP(F2, c, d, a, b, in[11]+0x265e5a51, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 0]+0xe9b6c7aa, 20);
        SX_MD5STEP(F2, a, b, c, d, in[ 5]+0xd62f105d,  5);
        SX_MD5STEP(F2, d, a, b, c, in[10]+0x02441453,  9);
        SX_MD5STEP(F2, c, d, a, b, in[15]+0xd8a1e681, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 4]+0xe7d3fbc8, 20);
        SX_MD5STEP(F2, a, b, c, d, in[ 9]+0x21e1cde6,  5);
        SX_MD5STEP(F2, d, a, b, c, in[14]+0xc33707d6,  9);
        SX_MD5STEP(F2, c, d, a, b, in[ 3]+0xf4d50d87, 14);
        SX_MD5STEP(F2, b, c, d, a, in[ 8]+0x455a14ed, 20);
        SX_MD5STEP(F2, a, b, c, d, in[13]+0xa9e3e905,  5);
        SX_MD5STEP(F2, d, a, b, c, in[ 2]+0xfcefa3f8,  9);
        SX_MD5STEP(F2, c, d, a, b, in[ 7]+0x676f02d9, 14);
        SX_MD5STEP(F2, b, c, d, a, in[12]+0x8d2a4c8a, 20);

        SX_MD5STEP(F3, a, b, c, d, in[ 5]+0xfffa3942,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 8]+0x8771f681, 11);
        SX_MD5STEP(F3, c, d, a, b, in[11]+0x6d9d6122, 16);
        SX_MD5STEP(F3, b, c, d, a, in[14]+0xfde5380c, 23);
        SX_MD5STEP(F3, a, b, c, d, in[ 1]+0xa4beea44,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 4]+0x4bdecfa9, 11);
        SX_MD5STEP(F3, c, d, a, b, in[ 7]+0xf6bb4b60, 16);
        SX_MD5STEP(F3, b, c, d, a, in[10]+0xbebfbc70, 23);
        SX_MD5STEP(F3, a, b, c, d, in[13]+0x289b7ec6,  4);
        SX_MD5STEP(F3, d, a, b, c, in[ 0]+0xeaa127fa, 11);
        SX_MD5STEP(F3, c, d, a, b, in[ 3]+0xd4ef3085, 16);
        SX_MD5STEP(F3, b, c, d, a, in[ 6]+0x04881d05, 23);
        SX_MD5STEP(F3, a, b, c, d, in[ 9]+0xd9d4d039,  4);
        SX_MD5STEP(F3, d, a, b, c, in[12]+0xe6db99e5, 11);
        SX_MD5STEP(F3, c, d, a, b, in[15]+0x1fa27cf8, 16);
        SX_MD5STEP(F3, b, c, d, a, in[ 2]+0xc4ac5665, 23);

        SX_MD5STEP(F4, a, b, c, d, in[ 0]+0xf4292244,  6);
        SX_MD5STEP(F4, d, a, b, c, in[ 7]+0x432aff97, 10);
        SX_MD5STEP(F4, c, d, a, b, in[14]+0xab9423a7, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 5]+0xfc93a039, 21);
        SX_MD5STEP(F4, a, b, c, d, in[12]+0x655b59c3,  6);
        SX_MD5STEP(F4, d, a, b, c, in[ 3]+0x8f0ccc92, 10);
        SX_MD5STEP(F4, c, d, a, b, in[10]+0xffeff47d, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 1]+0x85845dd1, 21);
        SX_MD5STEP(F4, a, b, c, d, in[ 8]+0x6fa87e4f,  6);
        SX_MD5STEP(F4, d, a, b, c, in[15]+0xfe2ce6e0, 10);
        SX_MD5STEP(F4, c, d, a, b, in[ 6]+0xa3014314, 15);
        SX_MD5STEP(F4, b, c, d, a, in[13]+0x4e0811a1, 21);
        SX_MD5STEP(F4, a, b, c, d, in[ 4]+0xf7537e82,  6);
        SX_MD5STEP(F4, d, a, b, c, in[11]+0xbd3af235, 10);
        SX_MD5STEP(F4, c, d, a, b, in[ 2]+0x2ad7d2bb, 15);
        SX_MD5STEP(F4, b, c, d, a, in[ 9]+0xeb86d391, 21);

        buf[0] += a;
        buf[1] += b;
        buf[2] += c;
        buf[3] += d;
}
/*
 * Update context to reflect the concatenation of another buffer full
 * of bytes.
 */
LIBCOX_PRIVATE void MD5Update(MD5Context *ctx, const unsigned char *buf, unsigned int len)
{
	sxu32 t;

        /* Update bitcount */
        t = ctx->bits[0];
        if ((ctx->bits[0] = t + ((sxu32)len << 3)) < t)
                ctx->bits[1]++; /* Carry from low to high */
        ctx->bits[1] += len >> 29;
        t = (t >> 3) & 0x3f;    /* Bytes already in shsInfo->data */
        /* Handle any leading odd-sized chunks */
        if ( t ) {
                unsigned char *p = (unsigned char *)ctx->in + t;

                t = 64-t;
                if (len < t) {
                        SyMemcpy(buf, p, len);
                        return;
                }
                SyMemcpy(buf, p, t);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);
                buf += t;
                len -= t;
        }
        /* Process data in 64-byte chunks */
        while (len >= 64) {
                SyMemcpy(buf, ctx->in, 64);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);
                buf += 64;
                len -= 64;
        }
        /* Handle any remaining bytes of data.*/
        SyMemcpy(buf, ctx->in, len);
}
/*
 * Final wrapup - pad to 64-byte boundary with the bit pattern 
 * 1 0* (64-bit count of bits processed, MSB-first)
 */
LIBCOX_PRIVATE void MD5Final(unsigned char digest[16], MD5Context *ctx){
        unsigned count;
        unsigned char *p;

        /* Compute number of bytes mod 64 */
        count = (ctx->bits[0] >> 3) & 0x3F;

        /* Set the first char of padding to 0x80.This is safe since there is
           always at least one byte free */
        p = ctx->in + count;
        *p++ = 0x80;

        /* Bytes of padding needed to make 64 bytes */
        count = 64 - 1 - count;

        /* Pad out to 56 mod 64 */
        if (count < 8) {
                /* Two lots of padding:  Pad the first block to 64 bytes */
               SyZero(p, count);
                byteReverse(ctx->in, 16);
                MD5Transform(ctx->buf, (sxu32*)ctx->in);

                /* Now fill the next block with 56 bytes */
                SyZero(ctx->in, 56);
        } else {
                /* Pad block to 56 bytes */
                SyZero(p, count-8);
        }
        byteReverse(ctx->in, 14);

        /* Append length in bits and transform */
        ((sxu32*)ctx->in)[ 14 ] = ctx->bits[0];
        ((sxu32*)ctx->in)[ 15 ] = ctx->bits[1];

        MD5Transform(ctx->buf, (sxu32*)ctx->in);
        byteReverse((unsigned char *)ctx->buf, 4);
        SyMemcpy(ctx->buf, digest, 0x10);
        SyZero(ctx, sizeof(ctx));    /* In case it's sensitive */
}
#undef F1
#undef F2
#undef F3
#undef F4
LIBCOX_PRIVATE sxi32 MD5Init(MD5Context *pCtx)
{	
	pCtx->buf[0] = 0x67452301;
    pCtx->buf[1] = 0xefcdab89;
    pCtx->buf[2] = 0x98badcfe;
    pCtx->buf[3] = 0x10325476;
    pCtx->bits[0] = 0;
    pCtx->bits[1] = 0;
   
   return SXRET_OK;
}
LIBCOX_PRIVATE sxi32 SyMD5Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[16])
{
	MD5Context sCtx;
	MD5Init(&sCtx);
	MD5Update(&sCtx, (const unsigned char *)pIn, nLen);
	MD5Final(zDigest, &sCtx);	
	return SXRET_OK;
}
/*
 * SHA-1 in C
 * By Steve Reid <steve@edmweb.com>
 * Status: Public Domain
 */
/*
 * blk0() and blk() perform the initial expand.
 * I got the idea of expanding during the round function from SSLeay
 *
 * blk0le() for little-endian and blk0be() for big-endian.
 */
#if __GNUC__ && (defined(__i386__) || defined(__x86_64__))
/*
 * GCC by itself only generates left rotates.  Use right rotates if
 * possible to be kinder to dinky implementations with iterative rotate
 * instructions.
 */
#define SHA_ROT(op, x, k) \
        ({ unsigned int y; asm(op " %1, %0" : "=r" (y) : "I" (k), "0" (x)); y; })
#define rol(x, k) SHA_ROT("roll", x, k)
#define ror(x, k) SHA_ROT("rorl", x, k)

#else
/* Generic C equivalent */
#define SHA_ROT(x, l, r) ((x) << (l) | (x) >> (r))
#define rol(x, k) SHA_ROT(x, k, 32-(k))
#define ror(x, k) SHA_ROT(x, 32-(k), k)
#endif

#define blk0le(i) (block[i] = (ror(block[i], 8)&0xFF00FF00) \
    |(rol(block[i], 8)&0x00FF00FF))
#define blk0be(i) block[i]
#define blk(i) (block[i&15] = rol(block[(i+13)&15]^block[(i+8)&15] \
    ^block[(i+2)&15]^block[i&15], 1))

/*
 * (R0+R1), R2, R3, R4 are the different operations (rounds) used in SHA1
 *
 * Rl0() for little-endian and Rb0() for big-endian.  Endianness is 
 * determined at run-time.
 */
#define Rl0(v, w, x, y, z, i) \
    z+=((w&(x^y))^y)+blk0le(i)+0x5A827999+rol(v, 5);w=ror(w, 2);
#define Rb0(v, w, x, y, z, i) \
    z+=((w&(x^y))^y)+blk0be(i)+0x5A827999+rol(v, 5);w=ror(w, 2);
#define R1(v, w, x, y, z, i) \
    z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v, 5);w=ror(w, 2);
#define R2(v, w, x, y, z, i) \
    z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v, 5);w=ror(w, 2);
#define R3(v, w, x, y, z, i) \
    z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v, 5);w=ror(w, 2);
#define R4(v, w, x, y, z, i) \
    z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v, 5);w=ror(w, 2);

/*
 * Hash a single 512-bit block. This is the core of the algorithm.
 */
#define a qq[0]
#define b qq[1]
#define c qq[2]
#define d qq[3]
#define e qq[4]

static void SHA1Transform(unsigned int state[5], const unsigned char buffer[64])
{
  unsigned int qq[5]; /* a, b, c, d, e; */
  static int one = 1;
  unsigned int block[16];
  SyMemcpy(buffer, (void *)block, 64);
  SyMemcpy(state, qq, 5*sizeof(unsigned int));

  /* Copy context->state[] to working vars */
  /*
  a = state[0];
  b = state[1];
  c = state[2];
  d = state[3];
  e = state[4];
  */

  /* 4 rounds of 20 operations each. Loop unrolled. */
  if( 1 == *(unsigned char*)&one ){
    Rl0(a, b, c, d, e, 0); Rl0(e, a, b, c, d, 1); Rl0(d, e, a, b, c, 2); Rl0(c, d, e, a, b, 3);
    Rl0(b, c, d, e, a, 4); Rl0(a, b, c, d, e, 5); Rl0(e, a, b, c, d, 6); Rl0(d, e, a, b, c, 7);
    Rl0(c, d, e, a, b, 8); Rl0(b, c, d, e, a, 9); Rl0(a, b, c, d, e, 10); Rl0(e, a, b, c, d, 11);
    Rl0(d, e, a, b, c, 12); Rl0(c, d, e, a, b, 13); Rl0(b, c, d, e, a, 14); Rl0(a, b, c, d, e, 15);
  }else{
    Rb0(a, b, c, d, e, 0); Rb0(e, a, b, c, d, 1); Rb0(d, e, a, b, c, 2); Rb0(c, d, e, a, b, 3);
    Rb0(b, c, d, e, a, 4); Rb0(a, b, c, d, e, 5); Rb0(e, a, b, c, d, 6); Rb0(d, e, a, b, c, 7);
    Rb0(c, d, e, a, b, 8); Rb0(b, c, d, e, a, 9); Rb0(a, b, c, d, e, 10); Rb0(e, a, b, c, d, 11);
    Rb0(d, e, a, b, c, 12); Rb0(c, d, e, a, b, 13); Rb0(b, c, d, e, a, 14); Rb0(a, b, c, d, e, 15);
  }
  R1(e, a, b, c, d, 16); R1(d, e, a, b, c, 17); R1(c, d, e, a, b, 18); R1(b, c, d, e, a, 19);
  R2(a, b, c, d, e, 20); R2(e, a, b, c, d, 21); R2(d, e, a, b, c, 22); R2(c, d, e, a, b, 23);
  R2(b, c, d, e, a, 24); R2(a, b, c, d, e, 25); R2(e, a, b, c, d, 26); R2(d, e, a, b, c, 27);
  R2(c, d, e, a, b, 28); R2(b, c, d, e, a, 29); R2(a, b, c, d, e, 30); R2(e, a, b, c, d, 31);
  R2(d, e, a, b, c, 32); R2(c, d, e, a, b, 33); R2(b, c, d, e, a, 34); R2(a, b, c, d, e, 35);
  R2(e, a, b, c, d, 36); R2(d, e, a, b, c, 37); R2(c, d, e, a, b, 38); R2(b, c, d, e, a, 39);
  R3(a, b, c, d, e, 40); R3(e, a, b, c, d, 41); R3(d, e, a, b, c, 42); R3(c, d, e, a, b, 43);
  R3(b, c, d, e, a, 44); R3(a, b, c, d, e, 45); R3(e, a, b, c, d, 46); R3(d, e, a, b, c, 47);
  R3(c, d, e, a, b, 48); R3(b, c, d, e, a, 49); R3(a, b, c, d, e, 50); R3(e, a, b, c, d, 51);
  R3(d, e, a, b, c, 52); R3(c, d, e, a, b, 53); R3(b, c, d, e, a, 54); R3(a, b, c, d, e, 55);
  R3(e, a, b, c, d, 56); R3(d, e, a, b, c, 57); R3(c, d, e, a, b, 58); R3(b, c, d, e, a, 59);
  R4(a, b, c, d, e, 60); R4(e, a, b, c, d, 61); R4(d, e, a, b, c, 62); R4(c, d, e, a, b, 63);
  R4(b, c, d, e, a, 64); R4(a, b, c, d, e, 65); R4(e, a, b, c, d, 66); R4(d, e, a, b, c, 67);
  R4(c, d, e, a, b, 68); R4(b, c, d, e, a, 69); R4(a, b, c, d, e, 70); R4(e, a, b, c, d, 71);
  R4(d, e, a, b, c, 72); R4(c, d, e, a, b, 73); R4(b, c, d, e, a, 74); R4(a, b, c, d, e, 75);
  R4(e, a, b, c, d, 76); R4(d, e, a, b, c, 77); R4(c, d, e, a, b, 78); R4(b, c, d, e, a, 79);

  /* Add the working vars back into context.state[] */
  state[0] += a;
  state[1] += b;
  state[2] += c;
  state[3] += d;
  state[4] += e;
}
#undef a
#undef b
#undef c
#undef d
#undef e
/*
 * SHA1Init - Initialize new context
 */
LIBCOX_PRIVATE void SHA1Init(SHA1Context *context){
    /* SHA1 initialization constants */
    context->state[0] = 0x67452301;
    context->state[1] = 0xEFCDAB89;
    context->state[2] = 0x98BADCFE;
    context->state[3] = 0x10325476;
    context->state[4] = 0xC3D2E1F0;
    context->count[0] = context->count[1] = 0;
}
/*
 * Run your data through this.
 */
LIBCOX_PRIVATE void SHA1Update(SHA1Context *context, const unsigned char *data, unsigned int len){
    unsigned int i, j;

    j = context->count[0];
    if ((context->count[0] += len << 3) < j)
	context->count[1] += (len>>29)+1;
    j = (j >> 3) & 63;
    if ((j + len) > 63) {
		(void)SyMemcpy(data, &context->buffer[j],  (i = 64-j));
	SHA1Transform(context->state, context->buffer);
	for ( ; i + 63 < len; i += 64)
	    SHA1Transform(context->state, &data[i]);
	j = 0;
    } else {
	i = 0;
    }
	(void)SyMemcpy(&data[i], &context->buffer[j], len - i);
}
/*
 * Add padding and return the message digest.
 */
LIBCOX_PRIVATE void SHA1Final(SHA1Context *context, unsigned char digest[20]){
    unsigned int i;
    unsigned char finalcount[8];

    for (i = 0; i < 8; i++) {
	finalcount[i] = (unsigned char)((context->count[(i >= 4 ? 0 : 1)]
	 >> ((3-(i & 3)) * 8) ) & 255);	 /* Endian independent */
    }
    SHA1Update(context, (const unsigned char *)"\200", 1);
    while ((context->count[0] & 504) != 448)
	SHA1Update(context, (const unsigned char *)"\0", 1);
    SHA1Update(context, finalcount, 8);  /* Should cause a SHA1Transform() */

    if (digest) {
	for (i = 0; i < 20; i++)
	    digest[i] = (unsigned char)
		((context->state[i>>2] >> ((3-(i & 3)) * 8) ) & 255);
    }
}
#undef Rl0
#undef Rb0
#undef R1
#undef R2
#undef R3
#undef R4

LIBCOX_PRIVATE sxi32 SySha1Compute(const void *pIn, sxu32 nLen, unsigned char zDigest[20])
{
	SHA1Context sCtx;
	SHA1Init(&sCtx);
	SHA1Update(&sCtx, (const unsigned char *)pIn, nLen);
	SHA1Final(&sCtx, zDigest);
	return SXRET_OK;
}
static const sxu32 crc32_table[] = {
	0x00000000, 0x77073096, 0xee0e612c, 0x990951ba, 
	0x076dc419, 0x706af48f, 0xe963a535, 0x9e6495a3, 
	0x0edb8832, 0x79dcb8a4, 0xe0d5e91e, 0x97d2d988, 
	0x09b64c2b, 0x7eb17cbd, 0xe7b82d07, 0x90bf1d91, 
	0x1db71064, 0x6ab020f2, 0xf3b97148, 0x84be41de, 
	0x1adad47d, 0x6ddde4eb, 0xf4d4b551, 0x83d385c7, 
	0x136c9856, 0x646ba8c0, 0xfd62f97a, 0x8a65c9ec, 
	0x14015c4f, 0x63066cd9, 0xfa0f3d63, 0x8d080df5, 
	0x3b6e20c8, 0x4c69105e, 0xd56041e4, 0xa2677172, 
	0x3c03e4d1, 0x4b04d447, 0xd20d85fd, 0xa50ab56b, 
	0x35b5a8fa, 0x42b2986c, 0xdbbbc9d6, 0xacbcf940, 
	0x32d86ce3, 0x45df5c75, 0xdcd60dcf, 0xabd13d59, 
	0x26d930ac, 0x51de003a, 0xc8d75180, 0xbfd06116, 
	0x21b4f4b5, 0x56b3c423, 0xcfba9599, 0xb8bda50f, 
	0x2802b89e, 0x5f058808, 0xc60cd9b2, 0xb10be924, 
	0x2f6f7c87, 0x58684c11, 0xc1611dab, 0xb6662d3d, 
	0x76dc4190, 0x01db7106, 0x98d220bc, 0xefd5102a, 
	0x71b18589, 0x06b6b51f, 0x9fbfe4a5, 0xe8b8d433, 
	0x7807c9a2, 0x0f00f934, 0x9609a88e, 0xe10e9818, 
	0x7f6a0dbb, 0x086d3d2d, 0x91646c97, 0xe6635c01, 
	0x6b6b51f4, 0x1c6c6162, 0x856530d8, 0xf262004e, 
	0x6c0695ed, 0x1b01a57b, 0x8208f4c1, 0xf50fc457, 
	0x65b0d9c6, 0x12b7e950, 0x8bbeb8ea, 0xfcb9887c, 
	0x62dd1ddf, 0x15da2d49, 0x8cd37cf3, 0xfbd44c65, 
	0x4db26158, 0x3ab551ce, 0xa3bc0074, 0xd4bb30e2, 
	0x4adfa541, 0x3dd895d7, 0xa4d1c46d, 0xd3d6f4fb, 
	0x4369e96a, 0x346ed9fc, 0xad678846, 0xda60b8d0, 
	0x44042d73, 0x33031de5, 0xaa0a4c5f, 0xdd0d7cc9, 
	0x5005713c, 0x270241aa, 0xbe0b1010, 0xc90c2086, 
	0x5768b525, 0x206f85b3, 0xb966d409, 0xce61e49f, 
	0x5edef90e, 0x29d9c998, 0xb0d09822, 0xc7d7a8b4, 
	0x59b33d17, 0x2eb40d81, 0xb7bd5c3b, 0xc0ba6cad, 
	0xedb88320, 0x9abfb3b6, 0x03b6e20c, 0x74b1d29a, 
	0xead54739, 0x9dd277af, 0x04db2615, 0x73dc1683, 
	0xe3630b12, 0x94643b84, 0x0d6d6a3e, 0x7a6a5aa8, 
	0xe40ecf0b, 0x9309ff9d, 0x0a00ae27, 0x7d079eb1, 
	0xf00f9344, 0x8708a3d2, 0x1e01f268, 0x6906c2fe, 
	0xf762575d, 0x806567cb, 0x196c3671, 0x6e6b06e7, 
	0xfed41b76, 0x89d32be0, 0x10da7a5a, 0x67dd4acc, 
	0xf9b9df6f, 0x8ebeeff9, 0x17b7be43, 0x60b08ed5, 
	0xd6d6a3e8, 0xa1d1937e, 0x38d8c2c4, 0x4fdff252, 
	0xd1bb67f1, 0xa6bc5767, 0x3fb506dd, 0x48b2364b, 
	0xd80d2bda, 0xaf0a1b4c, 0x36034af6, 0x41047a60, 
	0xdf60efc3, 0xa867df55, 0x316e8eef, 0x4669be79, 
	0xcb61b38c, 0xbc66831a, 0x256fd2a0, 0x5268e236, 
	0xcc0c7795, 0xbb0b4703, 0x220216b9, 0x5505262f, 
	0xc5ba3bbe, 0xb2bd0b28, 0x2bb45a92, 0x5cb36a04, 
	0xc2d7ffa7, 0xb5d0cf31, 0x2cd99e8b, 0x5bdeae1d, 
	0x9b64c2b0, 0xec63f226, 0x756aa39c, 0x026d930a, 
	0x9c0906a9, 0xeb0e363f, 0x72076785, 0x05005713, 
	0x95bf4a82, 0xe2b87a14, 0x7bb12bae, 0x0cb61b38, 
	0x92d28e9b, 0xe5d5be0d, 0x7cdcefb7, 0x0bdbdf21, 
	0x86d3d2d4, 0xf1d4e242, 0x68ddb3f8, 0x1fda836e, 
	0x81be16cd, 0xf6b9265b, 0x6fb077e1, 0x18b74777, 
	0x88085ae6, 0xff0f6a70, 0x66063bca, 0x11010b5c, 
	0x8f659eff, 0xf862ae69, 0x616bffd3, 0x166ccf45, 
	0xa00ae278, 0xd70dd2ee, 0x4e048354, 0x3903b3c2, 
	0xa7672661, 0xd06016f7, 0x4969474d, 0x3e6e77db, 
	0xaed16a4a, 0xd9d65adc, 0x40df0b66, 0x37d83bf0, 
	0xa9bcae53, 0xdebb9ec5, 0x47b2cf7f, 0x30b5ffe9, 
	0xbdbdf21c, 0xcabac28a, 0x53b39330, 0x24b4a3a6, 
	0xbad03605, 0xcdd70693, 0x54de5729, 0x23d967bf, 
	0xb3667a2e, 0xc4614ab8, 0x5d681b02, 0x2a6f2b94, 
	0xb40bbe37, 0xc30c8ea1, 0x5a05df1b, 0x2d02ef8d, 
};
#define CRC32C(c, d) (c = ( crc32_table[(c ^ (d)) & 0xFF] ^ (c>>8) ) )
static sxu32 SyCrc32Update(sxu32 crc32, const void *pSrc, sxu32 nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	if( zIn == 0 ){
		return crc32;
	}
	zEnd = &zIn[nLen];
	for(;;){
		if(zIn >= zEnd ){ break; } CRC32C(crc32, zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32, zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32, zIn[0]); zIn++;
		if(zIn >= zEnd ){ break; } CRC32C(crc32, zIn[0]); zIn++;
	}
		
	return crc32;
}
LIBCOX_PRIVATE sxu32 SyCrc32(const void *pSrc, sxu32 nLen)
{
	return SyCrc32Update(SXU32_HIGH, pSrc, nLen);
}
LIBCOX_PRIVATE sxi32 SyBinToHexConsumer(const void *pIn, sxu32 nLen, ProcConsumer xConsumer, void *pConsumerData)
{
	static const unsigned char zHexTab[] = "0123456789abcdef";
	const unsigned char *zIn, *zEnd;
	unsigned char zOut[3];
	sxi32 rc;
#if defined(UNTRUST)
	if( pIn == 0 || xConsumer == 0 ){
		return SXERR_EMPTY;
	}
#endif
	zIn   = (const unsigned char *)pIn;
	zEnd  = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd  ){
			break;
		}
		zOut[0] = zHexTab[zIn[0] >> 4];  zOut[1] = zHexTab[zIn[0] & 0x0F];
		rc = xConsumer((const void *)zOut, sizeof(char)*2, pConsumerData);
		if( rc != SXRET_OK ){
			return rc;
		}
		zIn++; 
	}
	return SXRET_OK;
}
#endif /* LIBCOX_ENABLE_HASH_CMD */
/*
 * ----------------------------------------------------------
 * File: json.c
 * MD5: d548e49744ee4c1f239d2b6fcfff9eb9
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
 /* $SymiscID: json.c v1.0 FreeBSD 2012-12-16 00:28 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/* This file deals with JSON serialization, decoding and stuff like that. */
/*
 * Section: 
 *  JSON encoding/decoding routines.
 * Authors:
 *  Symisc Systems, devel@symisc.net.
 *  Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Devel.
 */
/* Forward reference */
static int VmJsonArrayEncode(libcox_value *pValue, void *pUserData);
/* 
 * JSON encoder state is stored in an instance 
 * of the following structure.
 */
typedef struct json_private_data json_private_data;
struct json_private_data
{
	SyBlob *pOut;      /* Output consumer buffer */
	int isFirst;       /* True if first encoded entry */
	int iFlags;        /* JSON encoding flags */
	int nRecCount;     /* Recursion count */
};
/*
 * Returns the JSON representation of a value.In other word perform a JSON encoding operation.
 * According to wikipedia
 * JSON's basic types are:
 *   Number (double precision floating-point format in JavaScript, generally depends on implementation)
 *   String (double-quoted Unicode, with backslash escaping)
 *   Boolean (true or false)
 *   Array (an ordered sequence of values, comma-separated and enclosed in square brackets; the values
 *    do not need to be of the same type)
 *   Object (an unordered collection of key:value pairs with the ':' character separating the key 
 *     and the value, comma-separated and enclosed in curly braces; the keys must be strings and should
 *     be distinct from each other)
 *   null (empty)
 * Non-significant white space may be added freely around the "structural characters"
 * (i.e. the brackets "[{]}", colon ":" and comma ",").
 */
static sxi32 VmJsonEncode(
	libcox_value *pIn,          /* Encode this value */
	json_private_data *pData /* Context data */
	){
		SyBlob *pOut = pData->pOut;
		int nByte;
		if( libcox_value_is_null(pIn) ){
			/* null */
			SyBlobAppend(pOut, "null", sizeof("null")-1);
		}else if( libcox_value_is_bool(pIn) ){
			int iBool = libcox_value_to_bool(pIn);
			sxu32 iLen;
			/* true/false */
			iLen = iBool ? sizeof("true") : sizeof("false");
			SyBlobAppend(pOut, iBool ? "true" : "false", iLen-1);
		}else if(  libcox_value_is_numeric(pIn) && !libcox_value_is_string(pIn) ){
			const char *zNum;
			/* Get a string representation of the number */
			zNum = libcox_value_to_string(pIn, &nByte);
			SyBlobAppend(pOut,zNum,nByte);
		}else if( libcox_value_is_string(pIn) ){
				const char *zIn, *zEnd;
				int c;
				/* Encode the string */
				zIn = libcox_value_to_string(pIn, &nByte);
				zEnd = &zIn[nByte];
				/* Append the double quote */
				SyBlobAppend(pOut,"\"", sizeof(char));
				for(;;){
					if( zIn >= zEnd ){
						/* No more input to process */
						break;
					}
					c = zIn[0];
					/* Advance the stream cursor */
					zIn++;
					if( c == '"' || c == '\\' ){
						/* Unescape the character */
						SyBlobAppend(pOut,"\\", sizeof(char));
					}
					/* Append character verbatim */
					SyBlobAppend(pOut,(const char *)&c,sizeof(char));
				}
				/* Append the double quote */
				SyBlobAppend(pOut,"\"",sizeof(char));
		}else if( libcox_value_is_array(pIn) ){
			/* Encode the array/object */
			pData->isFirst = 1;
			/* Append the square bracket or curly braces */
			SyBlobAppend(pOut,"[",sizeof(char));
			/* Iterate over array entries */
			libcox_array_walk(pIn, VmJsonArrayEncode, pData);
			/* Append the closing square bracket or curly braces */
			SyBlobAppend(pOut,"]",sizeof(char));
		}else{
			/* Can't happen */
			SyBlobAppend(pOut,"null",sizeof("null")-1);
		}
		/* All done */
		return LIBCOX_OK;
}
/*
 * The following walker callback is invoked each time we need
 * to encode an array to JSON.
 */
static int VmJsonArrayEncode(libcox_value *pValue, void *pUserData)
{
	json_private_data *pJson = (json_private_data *)pUserData;
	if( pJson->nRecCount > 31 ){
		/* Recursion limit reached, return immediately */
		return LIBCOX_OK;
	}
	if( !pJson->isFirst ){
		/* Append the colon first */
		SyBlobAppend(pJson->pOut,",",(int)sizeof(char));
	}
	/* Encode the value */
	pJson->nRecCount++;
	VmJsonEncode(pValue, pJson);
	pJson->nRecCount--;
	pJson->isFirst = 0;
	return LIBCOX_OK;
}
#if 0
/*
 * The following walker callback is invoked each time we need to encode
 * a object instance [i.e: Object in the LIBCOX jargon] to JSON.
 */
static int VmJsonObjectEncode(libcox_value *pKey,libcox_value *pValue,void *pUserData)
{
	json_private_data *pJson = (json_private_data *)pUserData;
	const char *zKey;
	int nByte;
	if( pJson->nRecCount > 31 ){
		/* Recursion limit reached, return immediately */
		return LIBCOX_OK;
	}
	if( !pJson->isFirst ){
		/* Append the colon first */
		SyBlobAppend(pJson->pOut,",",sizeof(char));
	}
	/* Extract a string representation of the key */
	zKey = libcox_value_to_string(pKey, &nByte);
	/* Append the key and the double colon */
	if( nByte > 0 ){
		SyBlobAppend(pJson->pOut,"\"",sizeof(char));
		SyBlobAppend(pJson->pOut,zKey,(sxu32)nByte);
		SyBlobAppend(pJson->pOut,"\"",sizeof(char));
	}else{
		/* Can't happen */
		SyBlobAppend(pJson->pOut,"null",sizeof("null")-1);
	}
	SyBlobAppend(pJson->pOut,":",sizeof(char));
	/* Encode the value */
	pJson->nRecCount++;
	VmJsonEncode(pValue, pJson);
	pJson->nRecCount--;
	pJson->isFirst = 0;
	return LIBCOX_OK;
}
#endif
/*
 *  Returns a string containing the JSON representation of value. 
 *  In other words, perform the serialization of the given JSON object.
 */
LIBCOX_PRIVATE int libcoxJsonSerialize(libcox_value *pValue,SyBlob *pOut)
{
	json_private_data sJson;
	/* Prepare the JSON data */
	sJson.nRecCount = 0;
	sJson.pOut = pOut;
	sJson.isFirst = 1;
	sJson.iFlags = 0;
	/* Perform the encoding operation */
	VmJsonEncode(pValue, &sJson);
	/* All done */
	return LIBCOX_OK;
}
/*
 * ----------------------------------------------------------
 * File: hashmap.c
 * MD5: d33b0c309bde395066689220e329e300
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/* $SymiscID: hashmap.c v1.2 FreeBSD 2013-07-20 06:09 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/*
 * Each hashmap entry [i.e: array(4, 5, 6)] is recorded in an instance
 * of the following structure.
 */
struct libcox_hashmap_node
{
	libcox_hashmap *pMap;     /* Hashmap that own this instance */
	sxi32 iType;           /* Node type */
	union{
		sxi64 iKey;        /* Int key */
		SyBlob sKey;       /* Blob key */
	}xKey;
	sxi32 iFlags;          /* Control flags */
	sxu32 nHash;           /* Key hash value */
	libcox_value sValue;    /* Node value */
	libcox_hashmap_node *pNext, *pPrev;               /* Link to other entries [i.e: linear traversal] */
	libcox_hashmap_node *pNextCollide, *pPrevCollide; /* Collision chain */
};
/* Allowed node types */
#define HASHMAP_INT_NODE   1  /* Node with an int [i.e: 64-bit integer] key */
#define HASHMAP_BLOB_NODE  2  /* Node with a string/BLOB key */
/*
 * Default hash function for int [i.e; 64-bit integer] keys.
 */
static sxu32 IntHash(sxi64 iKey)
{
	return (sxu32)(iKey ^ (iKey << 8) ^ (iKey >> 8));
}
/*
 * Default hash function for string/BLOB keys.
 */
static sxu32 BinHash(const void *pSrc, sxu32 nLen)
{
	register unsigned char *zIn = (unsigned char *)pSrc;
	unsigned char *zEnd;
	sxu32 nH = 5381;
	zEnd = &zIn[nLen];
	for(;;){
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
		if( zIn >= zEnd ){ break; } nH = nH * 33 + zIn[0] ; zIn++;
	}	
	return nH;
}
/*
 * Return the total number of entries in a given hashmap.
 */
LIBCOX_PRIVATE sxu32 libcoxHashmapCount(libcox_hashmap *pMap)
{
	return pMap->nEntry;
}
/*
 * Allocate a new hashmap node with a 64-bit integer key.
 * If something goes wrong [i.e: out of memory], this function return NULL.
 * Otherwise a fresh [libcox_hashmap_node] instance is returned.
 */
static libcox_hashmap_node * HashmapNewIntNode(libcox_hashmap *pMap, sxi64 iKey, sxu32 nHash,libcox_value *pValue)
{
	libcox_hashmap_node *pNode;
	/* Allocate a new node */
	pNode = (libcox_hashmap_node *)SyMemBackendPoolAlloc(&pMap->pStore->sMem, sizeof(libcox_hashmap_node));
	if( pNode == 0 ){
		return 0;
	}
	/* Zero the stucture */
	SyZero(pNode, sizeof(libcox_hashmap_node));
	/* Fill in the structure */
	pNode->pMap  = &(*pMap);
	pNode->iType = HASHMAP_INT_NODE;
	pNode->nHash = nHash;
	pNode->xKey.iKey = iKey;
	/* Duplicate the value */
	libcoxMemObjInit(pMap->pStore,&pNode->sValue);
	if( pValue ){
		libcoxMemObjStore(pValue,&pNode->sValue);
	}
	return pNode;
}
/*
 * Allocate a new hashmap node with a BLOB key.
 * If something goes wrong [i.e: out of memory], this function return NULL.
 * Otherwise a fresh [libcox_hashmap_node] instance is returned.
 */
static libcox_hashmap_node * HashmapNewBlobNode(libcox_hashmap *pMap, const void *pKey, sxu32 nKeyLen, sxu32 nHash,libcox_value *pValue)
{
	libcox_hashmap_node *pNode;
	/* Allocate a new node */
	pNode = (libcox_hashmap_node *)SyMemBackendPoolAlloc(&pMap->pStore->sMem, sizeof(libcox_hashmap_node));
	if( pNode == 0 ){
		return 0;
	}
	/* Zero the stucture */
	SyZero(pNode, sizeof(libcox_hashmap_node));
	/* Fill in the structure */
	pNode->pMap  = &(*pMap);
	pNode->iType = HASHMAP_BLOB_NODE;
	pNode->nHash = nHash;
	SyBlobInit(&pNode->xKey.sKey, &pMap->pStore->sMem);
	SyBlobAppend(&pNode->xKey.sKey, pKey, nKeyLen);
	/* Duplicate the value */
	libcoxMemObjInit(pMap->pStore,&pNode->sValue);
	if( pValue ){
		libcoxMemObjStore(pValue,&pNode->sValue);
	}
	return pNode;
}
/*
 * link a hashmap node to the given bucket index (last argument to this function).
 */
static void HashmapNodeLink(libcox_hashmap *pMap, libcox_hashmap_node *pNode, sxu32 nBucketIdx)
{
	/* Link */
	if( pMap->apBucket[nBucketIdx] != 0 ){
		pNode->pNextCollide = pMap->apBucket[nBucketIdx];
		pMap->apBucket[nBucketIdx]->pPrevCollide = pNode;
	}
	pMap->apBucket[nBucketIdx] = pNode;
	/* Link to the map list */
	if( pMap->pFirst == 0 ){
		pMap->pFirst = pMap->pLast = pNode;
		/* Point to the first inserted node */
		pMap->pCur = pNode;
	}else{
		MACRO_LD_PUSH(pMap->pLast, pNode);
	}
	++pMap->nEntry;
}
#define HASHMAP_FILL_FACTOR 3
/*
 * Grow the hash-table and rehash all entries.
 */
static sxi32 HashmapGrowBucket(libcox_hashmap *pMap)
{
	if( pMap->nEntry >= pMap->nSize * HASHMAP_FILL_FACTOR ){
		libcox_hashmap_node **apOld = pMap->apBucket;
		libcox_hashmap_node *pEntry, **apNew;
		sxu32 nNew = pMap->nSize << 1;
		sxu32 nBucket;
		sxu32 n;
		if( nNew < 1 ){
			nNew = 16;
		}
		/* Allocate a new bucket */
		apNew = (libcox_hashmap_node **)SyMemBackendAlloc(&pMap->pStore->sMem, nNew * sizeof(libcox_hashmap_node *));
		if( apNew == 0 ){
			if( pMap->nSize < 1 ){
				return SXERR_MEM; /* Fatal */
			}
			/* Not so fatal here, simply a performance hit */
			return SXRET_OK;
		}
		/* Zero the table */
		SyZero((void *)apNew, nNew * sizeof(libcox_hashmap_node *));
		/* Reflect the change */
		pMap->apBucket = apNew;
		pMap->nSize = nNew;
		if( apOld == 0 ){
			/* First allocated table [i.e: no entry], return immediately */
			return SXRET_OK;
		}
		/* Rehash old entries */
		pEntry = pMap->pFirst;
		n = 0;
		for( ;; ){
			if( n >= pMap->nEntry ){
				break;
			}
			/* Clear the old collision link */
			pEntry->pNextCollide = pEntry->pPrevCollide = 0;
			/* Link to the new bucket */
			nBucket = pEntry->nHash & (nNew - 1);
			if( pMap->apBucket[nBucket] != 0 ){
				pEntry->pNextCollide = pMap->apBucket[nBucket];
				pMap->apBucket[nBucket]->pPrevCollide = pEntry;
			}
			pMap->apBucket[nBucket] = pEntry;
			/* Point to the next entry */
			pEntry = pEntry->pPrev; /* Reverse link */
			n++;
		}
		/* Free the old table */
		SyMemBackendFree(&pMap->pStore->sMem, (void *)apOld);
	}
	return SXRET_OK;
}
/*
 * Insert a 64-bit integer key and it's associated value (if any) in the given
 * hashmap.
 */
static sxi32 HashmapInsertIntKey(libcox_hashmap *pMap,sxi64 iKey,libcox_value *pValue)
{
	libcox_hashmap_node *pNode;
	sxu32 nHash;
	sxi32 rc;
	
	/* Hash the key */
	nHash = pMap->xIntHash(iKey);
	/* Allocate a new int node */
	pNode = HashmapNewIntNode(&(*pMap), iKey, nHash, pValue);
	if( pNode == 0 ){
		return SXERR_MEM;
	}
	/* Make sure the bucket is big enough to hold the new entry */
	rc = HashmapGrowBucket(&(*pMap));
	if( rc != SXRET_OK ){
		SyMemBackendPoolFree(&pMap->pStore->sMem, pNode);
		return rc;
	}
	/* Perform the insertion */
	HashmapNodeLink(&(*pMap), pNode, nHash & (pMap->nSize - 1));
	/* All done */
	return SXRET_OK;
}
/*
 * Insert a BLOB key and it's associated value (if any) in the given
 * hashmap.
 */
static sxi32 HashmapInsertBlobKey(libcox_hashmap *pMap,const void *pKey,sxu32 nKeyLen,libcox_value *pValue)
{
	libcox_hashmap_node *pNode;
	sxu32 nHash;
	sxi32 rc;
	
	/* Hash the key */
	nHash = pMap->xBlobHash(pKey, nKeyLen);
	/* Allocate a new blob node */
	pNode = HashmapNewBlobNode(&(*pMap), pKey, nKeyLen, nHash,pValue);
	if( pNode == 0 ){
		return SXERR_MEM;
	}
	/* Make sure the bucket is big enough to hold the new entry */
	rc = HashmapGrowBucket(&(*pMap));
	if( rc != SXRET_OK ){
		SyMemBackendPoolFree(&pMap->pStore->sMem, pNode);
		return rc;
	}
	/* Perform the insertion */
	HashmapNodeLink(&(*pMap), pNode, nHash & (pMap->nSize - 1));
	/* All done */
	return SXRET_OK;
}
/*
 * Check if a given 64-bit integer key exists in the given hashmap.
 * Write a pointer to the target node on success. Otherwise
 * SXERR_NOTFOUND is returned on failure.
 */
static sxi32 HashmapLookupIntKey(
	libcox_hashmap *pMap,         /* Target hashmap */
	sxi64 iKey,                /* lookup key */
	libcox_hashmap_node **ppNode  /* OUT: target node on success */
	)
{
	libcox_hashmap_node *pNode;
	sxu32 nHash;
	if( pMap->nEntry < 1 ){
		/* Don't bother hashing, there is no entry anyway */
		return SXERR_NOTFOUND;
	}
	/* Hash the key first */
	nHash = pMap->xIntHash(iKey);
	/* Point to the appropriate bucket */
	pNode = pMap->apBucket[nHash & (pMap->nSize - 1)];
	/* Perform the lookup */
	for(;;){
		if( pNode == 0 ){
			break;
		}
		if( pNode->iType == HASHMAP_INT_NODE
			&& pNode->nHash == nHash
			&& pNode->xKey.iKey == iKey ){
				/* Node found */
				if( ppNode ){
					*ppNode = pNode;
				}
				return SXRET_OK;
		}
		/* Follow the collision link */
		pNode = pNode->pNextCollide;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Check if a given BLOB key exists in the given hashmap.
 * Write a pointer to the target node on success. Otherwise
 * SXERR_NOTFOUND is returned on failure.
 */
static sxi32 HashmapLookupBlobKey(
	libcox_hashmap *pMap,          /* Target hashmap */
	const void *pKey,           /* Lookup key */
	sxu32 nKeyLen,              /* Key length in bytes */
	libcox_hashmap_node **ppNode   /* OUT: target node on success */
	)
{
	libcox_hashmap_node *pNode;
	sxu32 nHash;
	if( pMap->nEntry < 1 ){
		/* Don't bother hashing, there is no entry anyway */
		return SXERR_NOTFOUND;
	}
	/* Hash the key first */
	nHash = pMap->xBlobHash(pKey, nKeyLen);
	/* Point to the appropriate bucket */
	pNode = pMap->apBucket[nHash & (pMap->nSize - 1)];
	/* Perform the lookup */
	for(;;){
		if( pNode == 0 ){
			break;
		}
		if( pNode->iType == HASHMAP_BLOB_NODE 
			&& pNode->nHash == nHash
			&& SyBlobLength(&pNode->xKey.sKey) == nKeyLen 
			&& SyMemcmp(SyBlobData(&pNode->xKey.sKey), pKey, nKeyLen) == 0 ){
				/* Node found */
				if( ppNode ){
					*ppNode = pNode;
				}
				return SXRET_OK;
		}
		/* Follow the collision link */
		pNode = pNode->pNextCollide;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Check if a given key exists in the given hashmap.
 * Write a pointer to the target node on success.
 * Otherwise SXERR_NOTFOUND is returned on failure.
 */
static sxi32 HashmapLookup(
	libcox_hashmap *pMap,          /* Target hashmap */
	libcox_value *pKey,            /* Lookup key */
	libcox_hashmap_node **ppNode   /* OUT: target node on success */
	)
{
	libcox_hashmap_node *pNode = 0; /* cc -O6 warning */
	sxi32 rc;
	if( pKey->iFlags & (MEMOBJ_STRING|MEMOBJ_HASHMAP) ){
		if( (pKey->iFlags & MEMOBJ_STRING) == 0 ){
			/* Force a string cast */
			libcoxMemObjToString(&(*pKey));
		}
		if( SyBlobLength(&pKey->sBlob) > 0 ){
			/* Perform a blob lookup */
			rc = HashmapLookupBlobKey(&(*pMap), SyBlobData(&pKey->sBlob), SyBlobLength(&pKey->sBlob), &pNode);
			goto result;
		}
	}
	/* Perform an int lookup */
	if((pKey->iFlags & MEMOBJ_INT) == 0 ){
		/* Force an integer cast */
		libcoxMemObjToInteger(pKey);
	}
	/* Perform an int lookup */
	rc = HashmapLookupIntKey(&(*pMap), pKey->x.iVal, &pNode);
result:
	if( rc == SXRET_OK ){
		/* Node found */
		if( ppNode ){
			*ppNode = pNode;
		}
		return SXRET_OK;
	}
	/* No such entry */
	return SXERR_NOTFOUND;
}
/*
 * Check if the given BLOB key looks like a decimal number. 
 * Retrurn TRUE on success.FALSE otherwise.
 */
static int HashmapIsIntKey(SyBlob *pKey)
{
	const char *zIn  = (const char *)SyBlobData(pKey);
	const char *zEnd = &zIn[SyBlobLength(pKey)];
	if( (int)(zEnd-zIn) > 1 && zIn[0] == '0' ){
		/* Octal not decimal number */
		return FALSE;
	}
	if( (zIn[0] == '-' || zIn[0] == '+') && &zIn[1] < zEnd ){
		zIn++;
	}
	for(;;){
		if( zIn >= zEnd ){
			return TRUE;
		}
		if( (unsigned char)zIn[0] >= 0xc0 /* UTF-8 stream */  || !SyisDigit(zIn[0]) ){
			break;
		}
		zIn++;
	}
	/* Key does not look like a decimal number */
	return FALSE;
}
/*
 * Insert a given key and it's associated value (if any) in the given
 * hashmap.
 * If a node with the given key already exists in the database
 * then this function overwrite the old value.
 */
static sxi32 HashmapInsert(
	libcox_hashmap *pMap, /* Target hashmap */
	libcox_value *pKey,   /* Lookup key  */
	libcox_value *pVal    /* Node value */
	)
{
	libcox_hashmap_node *pNode = 0;
	sxi32 rc = SXRET_OK;
	
	if( pKey && (pKey->iFlags & (MEMOBJ_STRING|MEMOBJ_HASHMAP)) ){
		if( (pKey->iFlags & MEMOBJ_STRING) == 0 ){
			/* Force a string cast */
			libcoxMemObjToString(&(*pKey));
		}
		if( SyBlobLength(&pKey->sBlob) < 1 || HashmapIsIntKey(&pKey->sBlob) ){
			if(SyBlobLength(&pKey->sBlob) < 1){
				/* Automatic index assign */
				pKey = 0;
			}
			goto IntKey;
		}
		if( SXRET_OK == HashmapLookupBlobKey(&(*pMap), SyBlobData(&pKey->sBlob), 
			SyBlobLength(&pKey->sBlob), &pNode) ){
				/* Overwrite the old value */
				if( pVal ){
					libcoxMemObjStore(pVal,&pNode->sValue);
				}else{
					/* Nullify the entry */
					libcoxMemObjToNull(&pNode->sValue);
				}
				return SXRET_OK;
		}
		/* Perform a blob-key insertion */
		rc = HashmapInsertBlobKey(&(*pMap),SyBlobData(&pKey->sBlob),SyBlobLength(&pKey->sBlob),&(*pVal));
		return rc;
	}
IntKey:
	if( pKey ){
		if((pKey->iFlags & MEMOBJ_INT) == 0 ){
			/* Force an integer cast */
			libcoxMemObjToInteger(pKey);
		}
		if( SXRET_OK == HashmapLookupIntKey(&(*pMap), pKey->x.iVal, &pNode) ){
			/* Overwrite the old value */
			if( pVal ){
				libcoxMemObjStore(pVal,&pNode->sValue);
			}else{
				/* Nullify the entry */
				libcoxMemObjToNull(&pNode->sValue);
			}
			return SXRET_OK;
		}
		/* Perform a 64-bit-int-key insertion */
		rc = HashmapInsertIntKey(&(*pMap), pKey->x.iVal, &(*pVal));
		if( rc == SXRET_OK ){
			if( pKey->x.iVal >= pMap->iNextIdx ){
				/* Increment the automatic index */ 
				pMap->iNextIdx = pKey->x.iVal + 1;
				/* Make sure the automatic index is not reserved */
				while( SXRET_OK == HashmapLookupIntKey(&(*pMap), pMap->iNextIdx, 0) ){
					pMap->iNextIdx++;
				}
			}
		}
	}else{
		/* Assign an automatic index */
		rc = HashmapInsertIntKey(&(*pMap),pMap->iNextIdx,&(*pVal));
		if( rc == SXRET_OK ){
			++pMap->iNextIdx;
		}
	}
	/* Insertion result */
	return rc;
}
/*
 * Allocate a new hashmap.
 * Return a pointer to the freshly allocated hashmap on success.NULL otherwise.
 */
LIBCOX_PRIVATE libcox_hashmap * libcoxNewHashmap(
	libcox *pStore,             /* Engine that trigger the hashmap creation */
	sxu32 (*xIntHash)(sxi64), /* Hash function for int keys.NULL otherwise*/
	sxu32 (*xBlobHash)(const void *, sxu32) /* Hash function for BLOB keys.NULL otherwise */
	)
{
	libcox_hashmap *pMap;
	/* Allocate a new instance */
	pMap = (libcox_hashmap *)SyMemBackendPoolAlloc(&pStore->sMem, sizeof(libcox_hashmap));
	if( pMap == 0 ){
		return 0;
	}
	/* Zero the structure */
	SyZero(pMap, sizeof(libcox_hashmap));
	/* Fill in the structure */
	pMap->pStore = &(*pStore);
	pMap->iRef = 1;
	/* pMap->iFlags = 0; */
	/* Default hash functions */
	pMap->xIntHash  = xIntHash ? xIntHash : IntHash;
	pMap->xBlobHash = xBlobHash ? xBlobHash : BinHash;
	return pMap;
}
/*
 * Increment the reference count of a given hashmap.
 */
LIBCOX_PRIVATE void libcoxHashmapRef(libcox_hashmap *pMap)
{
	pMap->iRef++;
}
/*
 * Release a hashmap.
 */
static sxi32 libcoxHashmapRelease(libcox_hashmap *pMap)
{
	libcox_hashmap_node *pEntry, *pNext;
	libcox *pStore = pMap->pStore;
	sxu32 n;
	/* Start the release process */
	n = 0;
	pEntry = pMap->pFirst;
	for(;;){
		if( n >= pMap->nEntry ){
			break;
		}
		pNext = pEntry->pPrev; /* Reverse link */
		/* Release the libcox_value */
		libcoxMemObjRelease(&pEntry->sValue);
		/* Release the node */
		if( pEntry->iType == HASHMAP_BLOB_NODE ){
			SyBlobRelease(&pEntry->xKey.sKey);
		}
		SyMemBackendPoolFree(&pStore->sMem, pEntry);
		/* Point to the next entry */
		pEntry = pNext;
		n++;
	}
	if( pMap->nEntry > 0 ){
		/* Release the hash bucket */
		SyMemBackendFree(&pStore->sMem, pMap->apBucket);
	}
	/* Free the whole instance */
	SyMemBackendPoolFree(&pStore->sMem, pMap);
	return SXRET_OK;
}
/*
 * Decrement the reference count of a given hashmap.
 * If the count reaches zero which mean no more variables
 * are pointing to this hashmap, then release the whole instance.
 */
LIBCOX_PRIVATE void libcoxHashmapUnref(libcox_hashmap *pMap)
{
	pMap->iRef--;
	if( pMap->iRef < 1 ){
		libcoxHashmapRelease(pMap);
	}
}
LIBCOX_PRIVATE libcox * libcoxHashmapGetEngine(libcox_hashmap *pMap)
{
	return pMap->pStore;
}
/*
 * Check if a given key exists in the given hashmap.
 * Write a pointer to the target node on success.
 * Otherwise SXERR_NOTFOUND is returned on failure.
 */
LIBCOX_PRIVATE sxi32 libcoxHashmapLookup(
	libcox_hashmap *pMap,        /* Target hashmap */
	libcox_value *pKey,          /* Lookup key */
	libcox_value **ppOut /* OUT: Target node on success */
	)
{
	libcox_hashmap_node *pNode;
	sxi32 rc;
	if( pMap->nEntry < 1 ){
		/* TICKET 1433-25: Don't bother hashing, the hashmap is empty anyway.
		 */
		return SXERR_NOTFOUND;
	}
	rc = HashmapLookup(&(*pMap), &(*pKey),&pNode);
	if( rc != SXRET_OK ){
		return rc;
	}
	if( ppOut ){
		/* Point to the node value */
		*ppOut = &pNode->sValue;
	}
	return LIBCOX_OK;
}
/*
 * Insert a given key and it's associated value (if any) in the given
 * hashmap.
 * If a node with the given key already exists in the database
 * then this function overwrite the old value.
 */
LIBCOX_PRIVATE sxi32 libcoxHashmapInsert(
	libcox_hashmap *pMap, /* Target hashmap */
	libcox_value *pKey,   /* Lookup key */
	libcox_value *pVal    /* Node value.NULL otherwise */
	)
{
	sxi32 rc;
	rc = HashmapInsert(&(*pMap), &(*pKey), &(*pVal));
	return rc;
}
/*
 * Iterate throw hashmap entries and invoke the given callback [i.e: xWalk()] for each 
 * retrieved entry.
 * If the callback wishes to abort processing [i.e: it's invocation] it must return
 * a value different from LIBCOX_OK.
 * Refer to [libcox_array_walk()] for more information.
 */
LIBCOX_PRIVATE sxi32 libcoxHashmapWalk(
	libcox_hashmap *pMap, /* Target hashmap */
	int (*xWalk)(libcox_value *, void *), /* Walker callback */
	void *pUserData /* Last argument to xWalk() */
	)
{
	libcox_hashmap_node *pEntry;
	sxi32 rc;
	sxu32 n;
	/* Initialize walker parameter */
	rc = SXRET_OK;
	n = pMap->nEntry;
	pEntry = pMap->pFirst;
	/* Start the iteration process */
	for(;;){
		if( n < 1 ){
			break;
		}
		/* Invoke the user callback */
		rc = xWalk(&pEntry->sValue,pUserData);
		if( rc != LIBCOX_OK ){
			/* Callback request an operation abort */
			return SXERR_ABORT;
		}
		/* Point to the next entry */
		pEntry = pEntry->pPrev; /* Reverse link */
		n--;
	}
	/* All done */
	return SXRET_OK;
}
/*
 * Reset the node cursor of a given hashmap.
 */
LIBCOX_PRIVATE void libcoxHashmapResetLoopCursor(libcox_hashmap *pMap)
{
	/* Reset the loop cursor */
	pMap->pCur = pMap->pFirst;
}
/*
 * Return a pointer to the node currently pointed by the node cursor.
 * If the cursor reaches the end of the list, then this function
 * return NULL.
 * Note that the node cursor is automatically advanced by this function.
 */
LIBCOX_PRIVATE libcox_value * libcoxHashmapGetNextEntry(libcox_hashmap *pMap)
{
	libcox_hashmap_node *pCur = pMap->pCur;
	if( pCur == 0 ){
		/* End of the list, return null */
		return 0;
	}
	/* Advance the node cursor */
	pMap->pCur = pCur->pPrev; /* Reverse link */
	/* Entry value */
	return &pCur->sValue;
}
/*
 * ----------------------------------------------------------
 * File: cmd.c
 * MD5: ef56d6802fb634aaee25f77ab0d674c0
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
/* $SymiscID: cmd.c v1.3 Win7 2013-12-28 04:25 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/*
 * Built-in libcox commands.
 */

/*
 * CMD: chdir. Refer to the official documentation for additional informations.
 */
static int libcoxCmdChdir(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zDir;
	int rc;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xChdir == 0 ){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zDir = nArg > 0 ? libcox_value_to_string(apArg[0],0) : "./";
	/* Perfrom the requested operation */
	rc = pVfs->xChdir(zDir);
	/* API Result */
	libcox_result_bool(pCtx,rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: getcwd. Refer to the official documentation for additional informations.
 */
static int libcoxCmdPwd(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	/* Check if the VFS implement the underlying method */
	if( pVfs->xGetcwd == 0 ){
		SXUNUSED(nArg); 
		SXUNUSED(apArg);
		/* Return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	pVfs->xGetcwd(pCtx);
	return LIBCOX_OK;
}
/*
 * CMD: echo. Refer to the official documentation for additional informations.
 */
static int libcoxCmdEcho(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const char *zMsg;
	int nLen;
	/* Check if the VFS implement the underlying method */
	if( nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zMsg = libcox_value_to_string(apArg[0],&nLen);
	/* Output */
	if( nLen > 0 ){
		libcox_result_string(pCtx,zMsg,nLen);

	}
	return LIBCOX_OK;
}
/*
 * CMD: RMDIR. Refer to the official documentation for additional informations.
 */
static int libcoxCmdRmDir(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zDir;
	int rc;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xRmdir == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zDir = libcox_value_to_string(apArg[0],0);
	/* Perfrom the requested operation */
	rc = pVfs->xRmdir(zDir);
	/* API Result */
	libcox_result_bool(pCtx,rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: GETENV. Refer to the official documentation for additional informations.
 */
static int libcoxCmdEnv(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zEnv;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xGetenv == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zEnv = libcox_value_to_string(apArg[0],0);
	/* Perfrom the requested operation */
	pVfs->xGetenv(zEnv,pCtx);
	return LIBCOX_OK;
}
/*
 * CMD: SETENV. Refer to the official documentation for additional informations.
 */
static int libcoxCmdSetEnv(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zEnv,*zValue;
	int rc;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xSetenv == 0 || nArg < 2){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zEnv = libcox_value_to_string(apArg[0],0);
	zValue = libcox_value_to_string(apArg[1],0);
	/* Perfrom the requested operation */
	rc = pVfs->xSetenv(zEnv,zValue);
	libcox_result_bool(pCtx,rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: RENAME. Refer to the official documentation for additional informations.
 */
static int libcoxCmdRename(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zOld,*zNew;
	int rc;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xRename == 0 || nArg < 2){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	zOld = libcox_value_to_string(apArg[0],0);
	zNew = libcox_value_to_string(apArg[1],0);
	/* Perfrom the requested operation */
	rc = pVfs->xRename(zOld,zNew);
	libcox_result_bool(pCtx,rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: REALPATH. Refer to the official documentation for additional informations.
 */
static int libcoxCmdRealPath(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath = "./";
	/* Check if the VFS implement the underlying method */
	if( pVfs->xRealpath == 0 ){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	if( nArg > 0 ){
		zPath = libcox_value_to_string(apArg[0],0);
	}
	/* Perfrom the requested operation */
	pVfs->xRealpath(zPath,pCtx);
	return LIBCOX_OK;
}
/*
 * CMD: RANDOM. Refer to the official documentation for additional informations.
 */
static int libcoxCmdRandomNum(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	sxu32 nRand = 0; /* stupid cc warning */
	SyRandomness(&pCtx->plibcox->sRand,(void *)&nRand,sizeof(sxu32));
	if( nArg > 1 ){
		sxu32 iMin, iMax;
		iMin = (sxu32)libcox_value_to_int(apArg[0]);
		iMax = (sxu32)libcox_value_to_int(apArg[1]);
		if( iMin < iMax ){
			sxu32 iDiv = iMax+1-iMin;
			if( iDiv > 0 ){
				nRand = (nRand % iDiv)+iMin;
			}
		}else if(iMax > 0 ){
			nRand %= iMax;
		}
	}
	libcox_result_int64(pCtx,(libcox_int64)nRand);
	return LIBCOX_OK;
}
/*
 * CMD: GETPID. Refer to the official documentation for additional informations.
 */
static int libcoxCmdPid(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	sxu32 nPid;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xProcessId == 0 ){
		SXUNUSED(nArg); 
		SXUNUSED(apArg);
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	nPid = pVfs->xProcessId();
	libcox_result_int(pCtx,nPid);
	return LIBCOX_OK;
}
/*
 * CMD: USERNAME. Refer to the official documentation for additional informations.
 */
static int libcoxCmdUsername(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	/* Point to the underlying vfs */
	if( pVfs == 0 || pVfs->xUsername == 0 ){
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		/* IO command not implemented */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS", 
			libcox_command_name(pCtx)
			);		
		/* Set a dummy username */
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	pVfs->xUsername(pCtx);
	return LIBCOX_OK;
}
/*
 * CMD: GETUID. Refer to the official documentation for additional informations.
 */
static int libcoxCmdUid(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int uid;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xUid == 0 ){
		/* Return false */
		SXUNUSED(nArg); 
		SXUNUSED(apArg);
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	uid = pVfs->xUid();
	libcox_result_int(pCtx,uid);
	return LIBCOX_OK;
}
/*
 * CMD: GETGID. Refer to the official documentation for additional informations.
 */
static int libcoxCmdGid(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int gid;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xGid == 0 ){
		SXUNUSED(nArg); 
		SXUNUSED(apArg);
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	gid = pVfs->xGid();
	libcox_result_int(pCtx,gid);
	return LIBCOX_OK;
}
/*
 * CMD: ISDIR. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisDir(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xIsdir == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xIsdir(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: ISLNK. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisLink(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xIslink == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xIslink(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: ISFILE. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisFile(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xIsfile == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xIsfile(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: ISRD. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisReadable(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xReadable == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xReadable(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: ISWR. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisWritable(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xWritable == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xWritable(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: ISEXEC. Refer to the official documentation for additional informations.
 */
static int libcoxCmdisExecutable(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int res;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xExecutable == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	res = pVfs->xExecutable(zPath);
	libcox_result_bool(pCtx,res == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: FILESIZE. Refer to the official documentation for additional informations.
 */
static int libcoxCmdFileSize(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	libcox_int64 iSz;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xFileSize == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	iSz = pVfs->xFileSize(zPath);
	libcox_result_int64(pCtx,iSz);
	return LIBCOX_OK;
}
/*
 * CMD: FILECTIME. Refer to the official documentation for additional informations.
 */
static int libcoxCmdFileCtime(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	libcox_int64 iSz;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xFileCtime == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	iSz = pVfs->xFileCtime(zPath);
	libcox_result_int64(pCtx,iSz);
	return LIBCOX_OK;
}
/*
 * CMD: FILEATIME. Refer to the official documentation for additional informations.
 */
static int libcoxCmdFileAtime(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	libcox_int64 iSz;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xFileAtime == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	iSz = pVfs->xFileAtime(zPath);
	libcox_result_int64(pCtx,iSz);
	return LIBCOX_OK;
}
/*
 * CMD: FILEMTIME. Refer to the official documentation for additional informations.
 */
static int libcoxCmdFileMtime(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	libcox_int64 iSz;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xFileMtime == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	iSz = pVfs->xFileMtime(zPath);
	libcox_result_int64(pCtx,iSz);
	return LIBCOX_OK;
}
/*
 * CMD: FILEEXISTS. Refer to the official documentation for additional informations.
 */
static int libcoxCmdFileExists(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int exists;
	/* Check if the VFS implement the underlying method */
	if( pVfs->xFileExists == 0 || nArg < 1){
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	zPath = libcox_value_to_string(apArg[0],0);
	exists = pVfs->xFileExists(zPath);
	libcox_result_bool(pCtx,exists);
	return LIBCOX_OK;
}
/*
 * CMD: TMPDIR. Refer to the official documentation for additional informations.
 */
static int libcoxCmdTmpDir(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	/* Check if the VFS implement the underlying method */
	if( pVfs->xTempDir == 0){
		SXUNUSED(nArg); 
		SXUNUSED(apArg);
		/* Return false */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	/* Perfrom the requested operation */
	pVfs->xTempDir(pCtx);
	return LIBCOX_OK;
}
/*
 * int sleep(int $seconds)
 *  Delays the program execution for the given number of seconds.
 * Parameters
 *  $seconds
 *   Halt time in seconds.
 * Return
 *  True on success or FALSE on failure.
 */
static int libcoxCmdSleep(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc, nSleep;
	if( nArg < 1 || !libcox_value_is_int(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xSleep == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Amount to sleep */
	nSleep = libcox_value_to_int(apArg[0]);
	if( nSleep < 0 ){
		/* Invalid value, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation (Microseconds) */
	rc = pVfs->xSleep((unsigned int)(nSleep * SX_USEC_PER_SEC));
	if( rc != LIBCOX_OK ){
		/* Return FALSE */
		libcox_result_bool(pCtx, 0);
	}else{
		/* Return true */
		libcox_result_bool(pCtx, 1);
	}
	return LIBCOX_OK;
}
/*
 * void usleep(int $micro_seconds)
 *  Delays program execution for the given number of micro seconds.
 * Parameters
 *  $micro_seconds
 *   Halt time in micro seconds. A micro second is one millionth of a second.
 * Return
 *  True on success or FALSE on failure.
 */
static int libcoxCmdUsleep(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int nSleep;
	if( nArg < 1 || !libcox_value_is_int(apArg[0]) ){
		/* Missing/Invalid argument, return immediately */
		return LIBCOX_OK;
	}

	if( pVfs == 0 || pVfs->xSleep == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS", 
			libcox_command_name(pCtx)
			);
		return LIBCOX_OK;
	}
	/* Amount to sleep */
	nSleep = libcox_value_to_int(apArg[0]);
	if( nSleep < 0 ){
		/* Return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation (Microseconds) */
	pVfs->xSleep((unsigned int)nSleep);
	/* Return true */
		libcox_result_bool(pCtx, 1);
	return LIBCOX_OK;
}
/*
 * bool unlink (string $filename)
 *  Delete a file.
 * Parameters
 *  $filename
 *   Path to the file.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdUnlink(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	
	int rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xUnlink == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Perform the requested operation */
	rc = pVfs->xUnlink(zPath);
	/* IO return value */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * bool chmod(string $filename, int $mode)
 *  Attempts to change the mode of the specified file to that given in mode.
 * Parameters
 *  $filename
 *   Path to the file.
 * $mode
 *   Mode (Must be an integer)
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdchmod(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath;
	int iMode;
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xChmod == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Extract the mode */
	iMode = libcox_value_to_int(apArg[1]);
	/* Perform the requested operation */
	rc = pVfs->xChmod(zPath, iMode);
	/* IO return value */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * bool chown(string $filename, string $user)
 *  Attempts to change the owner of the file filename to user user.
 * Parameters
 *  $filename
 *   Path to the file.
 * $user
 *   Username.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdchown(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zPath, *zUser;
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}

	if( pVfs == 0 || pVfs->xChown == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Extract the user */
	zUser = libcox_value_to_string(apArg[1], 0);
	/* Perform the requested operation */
	rc = pVfs->xChown(zPath, zUser);
	/* IO return value */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * bool chgrp(string $filename, string $group)
 *  Attempts to change the group of the file filename to group.
 * Parameters
 *  $filename
 *   Path to the file.
 * $group
 *   groupname.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdchgrp(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath, *zGroup;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xChgrp == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Extract the user */
	zGroup = libcox_value_to_string(apArg[1], 0);
	/* Perform the requested operation */
	rc = pVfs->xChgrp(zPath, zGroup);
	/* IO return value */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * CMD: CHROOT. Refer to the official documentation for additional informations.
 */
static int libcoxCmdChroot(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	const char *zPath;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return fasle */
		libcox_result_bool(pCtx,0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xChroot == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	zPath = libcox_value_to_string(apArg[0],0);
	/* Perform the requested operation */
	rc = pVfs->xChroot(zPath);
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * int64 disk_free_space(string $directory)
 *  Returns available space on filesystem or disk partition.
 * Parameters
 *  $directory
 *   A directory of the filesystem or disk partition.
 * Return
 *  Returns the number of available bytes as a 64-bit integer or FALSE on failure.
 */
static int libcoxCmd_disk_free_space(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath;
	libcox_int64 iSize;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xFreeSpace == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Perform the requested operation */
	iSize = pVfs->xFreeSpace(zPath);
	/* IO return value */
	libcox_result_int64(pCtx, iSize);
	return LIBCOX_OK;
}
/*
 * int64 disk_total_space(string $directory)
 *  Returns the total size of a filesystem or disk partition.
 * Parameters
 *  $directory
 *   A directory of the filesystem or disk partition.
 * Return
 *  Returns the number of available bytes as a 64-bit integer or FALSE on failure.
 */
static int libcoxCmd_disk_total_space(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath;
	libcox_int64 iSize;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xTotalSpace == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Perform the requested operation */
	iSize = pVfs->xTotalSpace(zPath);
	/* IO return value */
	libcox_result_int64(pCtx, iSize);
	return LIBCOX_OK;
}
/*
 * string filetype(string $filename)
 *  Gets file type.
 * Parameters
 *  $filename
 *   Path to the file.
 * Return
 *  The type of the file. Possible values are fifo, char, dir, block, link
 *  file, socket and unknown.
 */
static int libcoxCmdfiletype(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return 'unknown' */
		libcox_result_string(pCtx, "unknown", sizeof("unknown")-1);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xFiletype == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Set the empty string as the default return value */
	libcox_result_string(pCtx, "", 0);
	/* Perform the requested operation */
	pVfs->xFiletype(zPath, pCtx);
	return LIBCOX_OK;
}
/*
 * array stat(string $filename)
 *  Gives information about a file.
 * Parameters
 *  $filename
 *   Path to the file.
 * Return
 *  An associative array on success holding the following entries on success
 *  0   dev     device number
 * 1    ino     inode number (zero on windows)
 * 2    mode    inode protection mode
 * 3    nlink   number of links
 * 4    uid     userid of owner (zero on windows)
 * 5    gid     groupid of owner (zero on windows)
 * 6    rdev    device type, if inode device
 * 7    size    size in bytes
 * 8    atime   time of last access (Unix timestamp)
 * 9    mtime   time of last modification (Unix timestamp)
 * 10   ctime   time of last inode change (Unix timestamp)
 * 11   blksize blocksize of filesystem IO (zero on windows)
 * 12   blocks  number of 512-byte blocks allocated.
 * Note:
 *  FALSE is returned on failure.
 */
static int libcoxCmdStat(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	libcox_value *pArray, *pValue;
	const char *zPath;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xStat == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Create the array and the working value */
	pArray = libcox_context_new_array(pCtx);
	pValue = libcox_context_new_scalar(pCtx);
	if( pArray == 0 || pValue == 0 ){
		libcox_context_throw_error(pCtx, LIBCOX_CTX_ERR, "LIBCOX is running out of memory");
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the file path */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Perform the requested operation */
	rc = pVfs->xStat(zPath, pArray, pValue);
	if( rc != LIBCOX_OK ){
		/* IO error, return FALSE */
		libcox_result_bool(pCtx, 0);
	}else{
		/* Return the associative array */
		libcox_result_value(pCtx, pArray);
	}
	/* Don't worry about freeing memory here, everything will be released
	 * automatically as soon we return from this function. */
	return LIBCOX_OK;
}
/*
 * array lstat(string $filename)
 *  Gives information about a file or symbolic link.
 * Parameters
 *  $filename
 *   Path to the file.
 * Return
 *  An associative array on success holding the following entries on success
 *  0   dev     device number
 * 1    ino     inode number (zero on windows)
 * 2    mode    inode protection mode
 * 3    nlink   number of links
 * 4    uid     userid of owner (zero on windows)
 * 5    gid     groupid of owner (zero on windows)
 * 6    rdev    device type, if inode device
 * 7    size    size in bytes
 * 8    atime   time of last access (Unix timestamp)
 * 9    mtime   time of last modification (Unix timestamp)
 * 10   ctime   time of last inode change (Unix timestamp)
 * 11   blksize blocksize of filesystem IO (zero on windows)
 * 12   blocks  number of 512-byte blocks allocated.
 * Note:
 *  FALSE is returned on failure.
 */
static int libcoxCmdLstat(libcox_context *pCtx,int nArg,libcox_value **apArg)
{
	libcox_value *pArray, *pValue;
	const char *zPath;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xlStat == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Create the array and the working value */
	pArray = libcox_context_new_array(pCtx);
	pValue = libcox_context_new_scalar(pCtx);
	if( pArray == 0 || pValue == 0 ){
		libcox_context_throw_error(pCtx, LIBCOX_CTX_ERR, "LIBCOX is running out of memory");
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the file path */
	zPath = libcox_value_to_string(apArg[0], 0);
	/* Perform the requested operation */
	rc = pVfs->xlStat(zPath, pArray, pValue);
	if( rc != LIBCOX_OK ){
		/* IO error, return FALSE */
		libcox_result_bool(pCtx, 0);
	}else{
		/* Return the associative array */
		libcox_result_value(pCtx, pArray);
	}
	/* Don't worry about freeing memory here, everything will be released
	 * automatically as soon we return from this function. */
	return LIBCOX_OK;
}
/*
 * bool touch(string $filename[, int64 $time = time()[, int64 $atime]])
 *  Sets access and modification time of the given file.
 * Note: On windows
 *   If the file does not exists, it will not be created.
 * Parameters
 *  $filename
 *   The name of the file being touched.
 *  $time
 *   The touch time. If time is not supplied, the current system time is used.
 * $atime
 *   If present, the access time of the given filename is set to the value of atime.
 *   Otherwise, it is set to the value passed to the time parameter. If neither are 
 *   present, the current system time is used.
 * Return
 *  TRUE on success or FALSE on failure.
*/
static int libcoxCmdtouch(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	libcox_int64 nTime, nAccess;
	const char *zFile;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xTouch == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	nTime = nAccess = -1;
	zFile = libcox_value_to_string(apArg[0], 0);
	if( nArg > 1 ){
		nTime = libcox_value_to_int64(apArg[1]);
		if( nArg > 2 ){
			nAccess = libcox_value_to_int64(apArg[1]);
		}else{
			nAccess = nTime;
		}
	}
	rc = pVfs->xTouch(zFile, nTime, nAccess);
	/* IO result */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * Path processing functions that do not need access to the VFS layer
 * Authors:
 *    Symisc Systems, devel@symisc.net.
 *    Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Stable.
 */
/*
 * Given a string containing the path of a file or directory, this function 
 * return the parent directory's path.
 */
static const char * libcoxExtractDirName(const char *zPath, int nByte, int *pLen)
{
	const char *zEnd = &zPath[nByte - 1];
	int c, d;
	c = d = '/';
#ifdef __WINNT__
	d = '\\';
#endif
	while( zEnd > zPath && ( (int)zEnd[0] != c && (int)zEnd[0] != d ) ){
		zEnd--;
	}
	*pLen = (int)(zEnd-zPath);
#ifdef __WINNT__
	if( (*pLen) == (int)sizeof(char) && zPath[0] == '/' ){
		/* Normalize path on windows */
		return "\\";
	}
#endif
	if( zEnd == zPath && ( (int)zEnd[0] != c && (int)zEnd[0] != d) ){
		/* No separator, return "." as the current directory */
		*pLen = sizeof(char);
		return ".";
	}
	if( (*pLen) == 0 ){
		*pLen = sizeof(char);
#ifdef __WINNT__
		return "\\";
#else
		return "/";
#endif
	}
	return zPath;
}
/*
 * string dirname(string $path)
 *  Returns parent directory's path.
 * Parameters
 * $path
 *  Target path.
 *  On Windows, both slash (/) and backslash (\) are used as directory separator character.
 *  In other environments, it is the forward slash (/).
 * Return
 *  The path of the parent directory. If there are no slashes in path, a dot ('.') 
 *  is returned, indicating the current directory.
 */
static int libcoxCmddirname(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath, *zDir;
	int iLen, iDirlen;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid arguments, return the empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Point to the target path */
	zPath = libcox_value_to_string(apArg[0], &iLen);
	if( iLen < 1 ){
		/* Reuturn "." */
		libcox_result_string(pCtx, ".", sizeof(char));
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	zDir = libcoxExtractDirName(zPath, iLen, &iDirlen);
	/* Return directory name */
	libcox_result_string(pCtx, zDir, iDirlen);
	return LIBCOX_OK;
}
/*
 * string basename(string $path[, string $suffix ])
 *  Returns trailing name component of path.
 * Parameters
 * $path
 *  Target path.
 *  On Windows, both slash (/) and backslash (\) are used as directory separator character.
 *  In other environments, it is the forward slash (/).
 * $suffix
 *  If the name component ends in suffix this will also be cut off.
 * Return
 *  The base name of the given path. 
 */
static int libcoxCmdbasename(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath, *zBase, *zEnd;
	int c, d, iLen;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return the empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	c = d = '/';
#ifdef __WINNT__
	d = '\\';
#endif
	/* Point to the target path */
	zPath = libcox_value_to_string(apArg[0], &iLen);
	if( iLen < 1 ){
		/* Empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	zEnd = &zPath[iLen - 1];
	/* Ignore trailing '/' */
	while( zEnd > zPath && ( (int)zEnd[0] == c || (int)zEnd[0] == d ) ){
		zEnd--;
	}
	iLen = (int)(&zEnd[1]-zPath);
	while( zEnd > zPath && ( (int)zEnd[0] != c && (int)zEnd[0] != d ) ){
		zEnd--;
	}
	zBase = (zEnd > zPath) ? &zEnd[1] : zPath;
	zEnd = &zPath[iLen];
	if( nArg > 1 && libcox_value_is_string(apArg[1]) ){
		const char *zSuffix;
		int nSuffix;
		/* Strip suffix */
		zSuffix = libcox_value_to_string(apArg[1], &nSuffix);
		if( nSuffix > 0 && nSuffix < iLen && SyMemcmp(&zEnd[-nSuffix], zSuffix, nSuffix) == 0 ){
			zEnd -= nSuffix;
		}
	}
	/* Store the basename */
	libcox_result_string(pCtx, zBase, (int)(zEnd-zBase));
	return LIBCOX_OK;
}
/*
 * value pathinfo(string $path [, int $options = PATHINFO_DIRNAME | PATHINFO_BASENAME | PATHINFO_EXTENSION | PATHINFO_FILENAME ])
 *  Returns information about a file path.
 * Parameter
 *  $path
 *   The path to be parsed.
 *  $options
 *    If present, specifies a specific element to be returned; one of
 *      PATHINFO_DIRNAME, PATHINFO_BASENAME, PATHINFO_EXTENSION or PATHINFO_FILENAME.
 * Return
 *  If the options parameter is not passed, an associative array containing the following
 *  elements is returned: dirname, basename, extension (if any), and filename. 
 *  If options is present, returns a string containing the requested element. 
 */
typedef struct path_info path_info;
struct path_info
{
	SyString sDir; /* Directory [i.e: /var/www] */
	SyString sBasename; /* Basename [i.e httpd.conf] */
	SyString sExtension; /* File extension [i.e xml, pdf..] */
	SyString sFilename;  /* Filename */
};
/*
 * Extract path fields.
 */
static sxi32 ExtractPathInfo(const char *zPath, int nByte, path_info *pOut)
{
	const char *zPtr, *zEnd = &zPath[nByte - 1];
	SyString *pCur;
	int c, d;
	c = d = '/';
#ifdef __WINNT__
	d = '\\';
#endif
	/* Zero the structure */
	SyZero(pOut, sizeof(path_info));
	/* Handle special case */
	if( nByte == sizeof(char) && ( (int)zPath[0] == c || (int)zPath[0] == d ) ){
#ifdef __WINNT__
		SyStringInitFromBuf(&pOut->sDir, "\\", sizeof(char));
#else
		SyStringInitFromBuf(&pOut->sDir, "/", sizeof(char));
#endif
		return SXRET_OK;
	}
	/* Extract the basename */
	while( zEnd > zPath && ( (int)zEnd[0] != c && (int)zEnd[0] != d ) ){
		zEnd--;
	}
	zPtr = (zEnd > zPath) ? &zEnd[1] : zPath;
	zEnd = &zPath[nByte];
	/* dirname */
	pCur = &pOut->sDir;
	SyStringInitFromBuf(pCur, zPath, zPtr-zPath);
	if( pCur->nByte > 1 ){
		SyStringTrimTrailingChar(pCur, '/');
#ifdef __WINNT__
		SyStringTrimTrailingChar(pCur, '\\');
#endif
	}else if( (int)zPath[0] == c || (int)zPath[0] == d ){
#ifdef __WINNT__
		SyStringInitFromBuf(&pOut->sDir, "\\", sizeof(char));
#else
		SyStringInitFromBuf(&pOut->sDir, "/", sizeof(char));
#endif
	}
	/* basename/filename */
	pCur = &pOut->sBasename;
	SyStringInitFromBuf(pCur, zPtr, zEnd-zPtr);
	SyStringTrimLeadingChar(pCur, '/');
#ifdef __WINNT__
	SyStringTrimLeadingChar(pCur, '\\');
#endif
	SyStringDupPtr(&pOut->sFilename, pCur);
	if( pCur->nByte > 0 ){
		/* extension */
		zEnd--;
		while( zEnd > pCur->zString /*basename*/ && zEnd[0] != '.' ){
			zEnd--;
		}
		if( zEnd > pCur->zString ){
			zEnd++; /* Jump leading dot */
			SyStringInitFromBuf(&pOut->sExtension, zEnd, &zPath[nByte]-zEnd);
			/* Fix filename */
			pCur = &pOut->sFilename;
			if( pCur->nByte > SyStringLength(&pOut->sExtension) ){
				pCur->nByte -= 1 + SyStringLength(&pOut->sExtension);
			}
		}
	}
	return SXRET_OK;
}
/*
 * value pathinfo(string $path [, int $options = PATHINFO_DIRNAME | PATHINFO_BASENAME | PATHINFO_EXTENSION | PATHINFO_FILENAME ])
 *  See block comment above.
 */
static int libcoxCmdpathinfo(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zPath;
	path_info sInfo;
	SyString *pComp;
	int iLen;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return the empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Point to the target path */
	zPath = libcox_value_to_string(apArg[0], &iLen);
	if( iLen < 1 ){
		/* Empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Extract path info */
	ExtractPathInfo(zPath, iLen, &sInfo);
	if( nArg > 1 && libcox_value_is_int(apArg[1]) ){
		/* Return path component */
		int nComp = libcox_value_to_int(apArg[1]);
		switch(nComp){
		case 1: /* PATHINFO_DIRNAME */
			pComp = &sInfo.sDir;
			if( pComp->nByte > 0 ){
				libcox_result_string(pCtx, pComp->zString, (int)pComp->nByte);
			}else{
				/* Expand the empty string */
				libcox_result_string(pCtx, "", 0);
			}
			break;
		case 2: /*PATHINFO_BASENAME*/
			pComp = &sInfo.sBasename;
			if( pComp->nByte > 0 ){
				libcox_result_string(pCtx, pComp->zString, (int)pComp->nByte);
			}else{
				/* Expand the empty string */
				libcox_result_string(pCtx, "", 0);
			}
			break;
		case 3: /*PATHINFO_EXTENSION*/
			pComp = &sInfo.sExtension;
			if( pComp->nByte > 0 ){
				libcox_result_string(pCtx, pComp->zString, (int)pComp->nByte);
			}else{
				/* Expand the empty string */
				libcox_result_string(pCtx, "", 0);
			}
			break;
		case 4: /*PATHINFO_FILENAME*/
			pComp = &sInfo.sFilename;
			if( pComp->nByte > 0 ){
				libcox_result_string(pCtx, pComp->zString, (int)pComp->nByte);
			}else{
				/* Expand the empty string */
				libcox_result_string(pCtx, "", 0);
			}
			break;
		default:
			/* Expand the empty string */
			libcox_result_string(pCtx, "", 0);
			break;
		}
	}else{
		/* Return an associative array */
		libcox_value *pArray, *pValue;
		pArray = libcox_context_new_array(pCtx);
		pValue = libcox_context_new_scalar(pCtx);
		if( pArray == 0 || pValue == 0 ){
			/* Out of mem, return NULL */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* dirname */
		pComp = &sInfo.sDir;
		if( pComp->nByte > 0 ){
			libcox_value_string(pValue, pComp->zString, (int)pComp->nByte);
			/* Perform the insertion */
			libcox_array_insert_strkey_elem(pArray, "dirname", pValue); /* Will make it's own copy */
		}
		/* Reset the string cursor */
		libcox_value_reset_string_cursor(pValue);
		/* basername */
		pComp = &sInfo.sBasename;
		if( pComp->nByte > 0 ){
			libcox_value_string(pValue, pComp->zString, (int)pComp->nByte);
			/* Perform the insertion */
			libcox_array_insert_strkey_elem(pArray, "basename", pValue); /* Will make it's own copy */
		}
		/* Reset the string cursor */
		libcox_value_reset_string_cursor(pValue);
		/* extension */
		pComp = &sInfo.sExtension;
		if( pComp->nByte > 0 ){
			libcox_value_string(pValue, pComp->zString, (int)pComp->nByte);
			/* Perform the insertion */
			libcox_array_insert_strkey_elem(pArray, "extension", pValue); /* Will make it's own copy */
		}
		/* Reset the string cursor */
		libcox_value_reset_string_cursor(pValue);
		/* filename */
		pComp = &sInfo.sFilename;
		if( pComp->nByte > 0 ){
			libcox_value_string(pValue, pComp->zString, (int)pComp->nByte);
			/* Perform the insertion */
			libcox_array_insert_strkey_elem(pArray, "filename", pValue); /* Will make it's own copy */
		}
		/* Return the created array */
		libcox_result_value(pCtx, pArray);
		/* Don't worry about freeing memory, everything will be released
		 * automatically as soon we return from this foreign function.
		 */
	}
	return LIBCOX_OK;
}
/*
 * Globbing implementation extracted from the sqlite3 source tree.
 * Original author: D. Richard Hipp (http://www.sqlite.org)
 * Status: Public Domain
 */
typedef unsigned char u8;
/* An array to map all upper-case characters into their corresponding
** lower-case character. 
**
** SQLite only considers US-ASCII (or EBCDIC) characters.  We do not
** handle case conversions for the UTF character set since the tables
** involved are nearly as big or bigger than SQLite itself.
*/
static const unsigned char sqlite3UpperToLower[] = {
      0,  1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 
     18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 
     36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 
     54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 97, 98, 99, 100, 101, 102, 103, 
    104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 
    122, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 
    108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 
    126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 142, 143, 
    144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159, 160, 161, 
    162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179, 
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 
    198, 199, 200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 
    216, 217, 218, 219, 220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 
    234, 235, 236, 237, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 
    252, 253, 254, 255
};
#define GlogUpperToLower(A)     if( A<0x80 ){ A = sqlite3UpperToLower[A]; }
/*
** Assuming zIn points to the first byte of a UTF-8 character, 
** advance zIn to point to the first byte of the next UTF-8 character.
*/
#define SQLITE_SKIP_UTF8(zIn) {                        \
  if( (*(zIn++))>=0xc0 ){                              \
    while( (*zIn & 0xc0)==0x80 ){ zIn++; }             \
  }                                                    \
}
/*
** This lookup table is used to help decode the first byte of
** a multi-byte UTF8 character.
*/
static const unsigned char UtfTrans1[] = {
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
  0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 
  0x18, 0x19, 0x1a, 0x1b, 0x1c, 0x1d, 0x1e, 0x1f, 
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
  0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 
  0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 
  0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x00, 0x00, 
};
/*
** Translate a single UTF-8 character.  Return the unicode value.
**
** During translation, assume that the byte that zTerm points
** is a 0x00.
**
** Write a pointer to the next unread byte back into *pzNext.
**
** Notes On Invalid UTF-8:
**
**  *  This routine never allows a 7-bit character (0x00 through 0x7f) to
**     be encoded as a multi-byte character.  Any multi-byte character that
**     attempts to encode a value between 0x00 and 0x7f is rendered as 0xfffd.
**
**  *  This routine never allows a UTF16 surrogate value to be encoded.
**     If a multi-byte character attempts to encode a value between
**     0xd800 and 0xe000 then it is rendered as 0xfffd.
**
**  *  Bytes in the range of 0x80 through 0xbf which occur as the first
**     byte of a character are interpreted as single-byte characters
**     and rendered as themselves even though they are technically
**     invalid characters.
**
**  *  This routine accepts an infinite number of different UTF8 encodings
**     for unicode values 0x80 and greater.  It do not change over-length
**     encodings to 0xfffd as some systems recommend.
*/
#define READ_UTF8(zIn, zTerm, c)                           \
  c = *(zIn++);                                            \
  if( c>=0xc0 ){                                           \
    c = UtfTrans1[c-0xc0];                                 \
    while( zIn!=zTerm && (*zIn & 0xc0)==0x80 ){            \
      c = (c<<6) + (0x3f & *(zIn++));                      \
    }                                                      \
    if( c<0x80                                             \
        || (c&0xFFFFF800)==0xD800                          \
        || (c&0xFFFFFFFE)==0xFFFE ){  c = 0xFFFD; }        \
  }
LIBCOX_PRIVATE int libcoxUtf8Read(
  const unsigned char *z,         /* First byte of UTF-8 character */
  const unsigned char *zTerm,     /* Pretend this byte is 0x00 */
  const unsigned char **pzNext    /* Write first byte past UTF-8 char here */
){
  int c;
  READ_UTF8(z, zTerm, c);
  *pzNext = z;
  return c;
}
/*
** Compare two UTF-8 strings for equality where the first string can
** potentially be a "glob" expression.  Return true (1) if they
** are the same and false (0) if they are different.
**
** Globbing rules:
**
**      '*'       Matches any sequence of zero or more characters.
**
**      '?'       Matches exactly one character.
**
**     [...]      Matches one character from the enclosed list of
**                characters.
**
**     [^...]     Matches one character not in the enclosed list.
**
** With the [...] and [^...] matching, a ']' character can be included
** in the list by making it the first character after '[' or '^'.  A
** range of characters can be specified using '-'.  Example:
** "[a-z]" matches any single lower-case letter.  To match a '-', make
** it the last character in the list.
**
** This command is usually quick, but can be N**2 in the worst case.
**
** Hints: to match '*' or '?', put them in "[]".  Like this:
**
**         abc[*]xyz        Matches "abc*xyz" only
*/
static int patternCompare(
  const u8 *zPattern,              /* The glob pattern */
  const u8 *zString,               /* The string to compare against the glob */
  const int esc,                    /* The escape character */
  int noCase
){
  int c, c2;
  int invert;
  int seen;
  u8 matchOne = '?';
  u8 matchAll = '*';
  u8 matchSet = '[';
  int prevEscape = 0;     /* True if the previous character was 'escape' */

  if( !zPattern || !zString ) return 0;
  while( (c = libcoxUtf8Read(zPattern, 0, &zPattern))!=0 ){
    if( !prevEscape && c==matchAll ){
      while( (c= libcoxUtf8Read(zPattern, 0, &zPattern)) == matchAll
               || c == matchOne ){
        if( c==matchOne && libcoxUtf8Read(zString, 0, &zString)==0 ){
          return 0;
        }
      }
      if( c==0 ){
        return 1;
      }else if( c==esc ){
        c = libcoxUtf8Read(zPattern, 0, &zPattern);
        if( c==0 ){
          return 0;
        }
      }else if( c==matchSet ){
	  if( (esc==0) || (matchSet<0x80) ) return 0;
	  while( *zString && patternCompare(&zPattern[-1], zString, esc, noCase)==0 ){
          SQLITE_SKIP_UTF8(zString);
        }
        return *zString!=0;
      }
      while( (c2 = libcoxUtf8Read(zString, 0, &zString))!=0 ){
        if( noCase ){
          GlogUpperToLower(c2);
          GlogUpperToLower(c);
          while( c2 != 0 && c2 != c ){
            c2 = libcoxUtf8Read(zString, 0, &zString);
            GlogUpperToLower(c2);
          }
        }else{
          while( c2 != 0 && c2 != c ){
            c2 = libcoxUtf8Read(zString, 0, &zString);
          }
        }
        if( c2==0 ) return 0;
		if( patternCompare(zPattern, zString, esc, noCase) ) return 1;
      }
      return 0;
    }else if( !prevEscape && c==matchOne ){
      if( libcoxUtf8Read(zString, 0, &zString)==0 ){
        return 0;
      }
    }else if( c==matchSet ){
      int prior_c = 0;
      if( esc == 0 ) return 0;
      seen = 0;
      invert = 0;
      c = libcoxUtf8Read(zString, 0, &zString);
      if( c==0 ) return 0;
      c2 = libcoxUtf8Read(zPattern, 0, &zPattern);
      if( c2=='^' ){
        invert = 1;
        c2 = libcoxUtf8Read(zPattern, 0, &zPattern);
      }
      if( c2==']' ){
        if( c==']' ) seen = 1;
        c2 = libcoxUtf8Read(zPattern, 0, &zPattern);
      }
      while( c2 && c2!=']' ){
        if( c2=='-' && zPattern[0]!=']' && zPattern[0]!=0 && prior_c>0 ){
          c2 = libcoxUtf8Read(zPattern, 0, &zPattern);
          if( c>=prior_c && c<=c2 ) seen = 1;
          prior_c = 0;
        }else{
          if( c==c2 ){
            seen = 1;
          }
          prior_c = c2;
        }
        c2 = libcoxUtf8Read(zPattern, 0, &zPattern);
      }
      if( c2==0 || (seen ^ invert)==0 ){
        return 0;
      }
    }else if( esc==c && !prevEscape ){
      prevEscape = 1;
    }else{
      c2 = libcoxUtf8Read(zString, 0, &zString);
      if( noCase ){
        GlogUpperToLower(c);
        GlogUpperToLower(c2);
      }
      if( c!=c2 ){
        return 0;
      }
      prevEscape = 0;
    }
  }
  return *zString==0;
}
/*
 * Wrapper around patternCompare() defined above.
 * See block comment above for more information.
 */
static int Glob(const unsigned char *zPattern, const unsigned char *zString, int iEsc, int CaseCompare)
{
	int rc;
	if( iEsc < 0 ){
		iEsc = '\\';
	}
	rc = patternCompare(zPattern, zString, iEsc, CaseCompare);
	return rc;
}
/*
 * bool fnmatch(string $pattern, string $string[, int $flags = 0 ])
 *  Match filename against a pattern.
 * Parameters
 *  $pattern
 *   The shell wildcard pattern.
 * $string
 *  The tested string.
 * $flags
 *   A list of possible flags:
 *    FNM_NOESCAPE 	Disable backslash escaping.
 *    FNM_PATHNAME 	Slash in string only matches slash in the given pattern.
 *    FNM_PERIOD 	Leading period in string must be exactly matched by period in the given pattern.
 *    FNM_CASEFOLD 	Caseless match.
 * Return
 *  TRUE if there is a match, FALSE otherwise. 
 */
static int libcoxCmdfnmatch(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString, *zPattern;
	int iEsc = '\\';
	int noCase = 0;
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) || !libcox_value_is_string(apArg[1]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the pattern and the string */
	zPattern  = libcox_value_to_string(apArg[0], 0);
	zString = libcox_value_to_string(apArg[1], 0);
	/* Extract the flags if avaialble */
	if( nArg > 2 && libcox_value_is_int(apArg[2]) ){
		rc = libcox_value_to_int(apArg[2]);
		if( rc & 0x01 /*FNM_NOESCAPE*/){
			iEsc = 0;
		}
		if( rc & 0x08 /*FNM_CASEFOLD*/){
			noCase = 1;
		}
	}
	/* Go globbing */
	rc = Glob((const unsigned char *)zPattern, (const unsigned char *)zString, iEsc, noCase);
	/* Globbing result */
	libcox_result_bool(pCtx, rc);
	return LIBCOX_OK;
}
/*
 * bool strglob(string $pattern, string $string)
 *  Match string against a pattern.
 * Parameters
 *  $pattern
 *   The shell wildcard pattern.
 * $string
 *  The tested string.
 * Return
 *  TRUE if there is a match, FALSE otherwise. 
 */
static int libcoxCmdstrglob(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString, *zPattern;
	int iEsc = '\\';
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) || !libcox_value_is_string(apArg[1]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the pattern and the string */
	zPattern  = libcox_value_to_string(apArg[0], 0);
	zString = libcox_value_to_string(apArg[1], 0);
	/* Go globbing */
	rc = Glob((const unsigned char *)zPattern, (const unsigned char *)zString, iEsc, 0);
	/* Globbing result */
	libcox_result_bool(pCtx, rc);
	return LIBCOX_OK;
}
/*
 * bool link(string $target, string $link)
 *  Create a hard link.
 * Parameters
 *  $target
 *   Target of the link.
 *  $link
 *   The link name.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdlink(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zTarget, *zLink;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) || !libcox_value_is_string(apArg[1]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}

	if( pVfs == 0 || pVfs->xLink == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the given arguments */
	zTarget  = libcox_value_to_string(apArg[0], 0);
	zLink = libcox_value_to_string(apArg[1], 0);
	/* Perform the requested operation */
	rc = pVfs->xLink(zTarget, zLink, 0/*Not a symbolic link */);
	/* IO result */
	libcox_result_bool(pCtx, rc == LIBCOX_OK );
	return LIBCOX_OK;
}
/*
 * bool symlink(string $target, string $link)
 *  Creates a symbolic link.
 * Parameters
 *  $target
 *   Target of the link.
 *  $link
 *   The link name.
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdsymlink(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zTarget, *zLink;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int rc;
	if( nArg < 2 || !libcox_value_is_string(apArg[0]) || !libcox_value_is_string(apArg[1]) ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xLink == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the given arguments */
	zTarget  = libcox_value_to_string(apArg[0], 0);
	zLink = libcox_value_to_string(apArg[1], 0);
	/* Perform the requested operation */
	rc = pVfs->xLink(zTarget, zLink, 1/*A symbolic link */);
	/* IO result */
	libcox_result_bool(pCtx, rc == LIBCOX_OK );
	return LIBCOX_OK;
}
/*
 * int umask([ int $mask ])
 *  Changes the current umask.
 * Parameters
 *  $mask
 *   The new umask.
 * Return
 *  umask() without arguments simply returns the current umask.
 *  Otherwise the old umask is returned.
 */
static int libcoxCmdumask(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iOld, iNew;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	
	if( pVfs == 0 || pVfs->xUmask == 0 ){
		/* IO command not implemented, return -1 */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS", 
			libcox_command_name(pCtx)
			);
		libcox_result_int(pCtx, 0);
		return LIBCOX_OK;
	}
	iNew = 0;
	if( nArg > 0 ){
		iNew = libcox_value_to_int(apArg[0]);
	}
	/* Perform the requested operation */
	iOld = pVfs->xUmask(iNew);
	/* Old mask */
	libcox_result_int(pCtx, iOld);
	return LIBCOX_OK;
}
#ifdef __WINNT__
#include <Windows.h>
#elif defined(__UNIXES__)
#include <sys/utsname.h>
#endif
/*
 * string uname([ string $mode = "a" ])
 *  Returns information about the host operating system.
 * Parameters
 *  $mode
 *   mode is a single character that defines what information is returned:
 *    'a': This is the default. Contains all modes in the sequence "s n r v m".
 *    's': Operating system name. eg. FreeBSD.
 *    'n': Host name. eg. localhost.example.com.
 *    'r': Release name. eg. 5.1.2-RELEASE.
 *    'v': Version information. Varies a lot between operating systems.
 *    'm': Machine type. eg. i386.
 * Return
 *  OS description as a string.
 */
static int libcoxCmdUname(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
#if defined(__WINNT__)
	const char *zName = "Microsoft Windows";
	OSVERSIONINFOW sVer;
#elif defined(__UNIXES__)
	struct utsname sName;
#endif
	const char *zMode = "a";
	if( nArg > 0 && libcox_value_is_string(apArg[0]) ){
		/* Extract the desired mode */
		zMode = libcox_value_to_string(apArg[0], 0);
	}
#if defined(__WINNT__)
	sVer.dwOSVersionInfoSize = sizeof(sVer);
	if( TRUE != GetVersionExW(&sVer)){
		libcox_result_string(pCtx, zName, -1);
		return LIBCOX_OK;
	}
	if( sVer.dwPlatformId == VER_PLATFORM_WIN32_NT ){
		if( sVer.dwMajorVersion <= 4 ){
			zName = "Microsoft Windows NT";
		}else if( sVer.dwMajorVersion == 5 ){
			switch(sVer.dwMinorVersion){
				case 0:	zName = "Microsoft Windows 2000"; break;
				case 1: zName = "Microsoft Windows XP";   break;
				case 2: zName = "Microsoft Windows Server 2003"; break;
			}
		}else if( sVer.dwMajorVersion == 6){
				switch(sVer.dwMinorVersion){
					case 0: zName = "Microsoft Windows Vista"; break;
					case 1: zName = "Microsoft Windows 7"; break;
					case 2: zName = "Microsoft Windows 8"; break;
					case 3: zName = "Microsoft Windows 10"; break;
					default: break;
				}
		}
	}
	switch(zMode[0]){
	case 's':
		/* Operating system name */
		libcox_result_string(pCtx, zName, -1/* Compute length automatically*/);
		break;
	case 'n':
		/* Host name */
		libcox_result_string(pCtx, "localhost", (int)sizeof("localhost")-1);
		break;
	case 'r':
	case 'v':
		/* Version information. */
		libcox_result_string_format(pCtx, "%u.%u build %u", 
			sVer.dwMajorVersion, sVer.dwMinorVersion, sVer.dwBuildNumber
			);
		break;
	case 'm':
		/* Machine name */
		libcox_result_string(pCtx, "x86", (int)sizeof("x86")-1);
		break;
	default:
		libcox_result_string_format(pCtx, "%s localhost %u.%u build %u x86", 
			zName, 
			sVer.dwMajorVersion, sVer.dwMinorVersion, sVer.dwBuildNumber
			);
		break;
	}
#elif defined(__UNIXES__)
	if( uname(&sName) != 0 ){
		libcox_result_string(pCtx, "Unix", (int)sizeof("Unix")-1);
		return LIBCOX_OK;
	}
	switch(zMode[0]){
	case 's':
		/* Operating system name */
		libcox_result_string(pCtx, sName.sysname, -1/* Compute length automatically*/);
		break;
	case 'n':
		/* Host name */
		libcox_result_string(pCtx, sName.nodename, -1/* Compute length automatically*/);
		break;
	case 'r':
		/* Release information */
		libcox_result_string(pCtx, sName.release, -1/* Compute length automatically*/);
		break;
	case 'v':
		/* Version information. */
		libcox_result_string(pCtx, sName.version, -1/* Compute length automatically*/);
		break;
	case 'm':
		/* Machine name */
		libcox_result_string(pCtx, sName.machine, -1/* Compute length automatically*/);
		break;
	default:
		libcox_result_string_format(pCtx, 
			"%s %s %s %s %s", 
			sName.sysname, 
			sName.release, 
			sName.version, 
			sName.nodename, 
			sName.machine
			);
		break;
	}
#else
	libcox_result_string(pCtx, "Host Operating System/localhost", (int)sizeof("Host Operating System/localhost")-1);
#endif
	return LIBCOX_OK;
}
/*
 * float round ( float $val [, int $precision = 0 [, int $mode = PHP_ROUND_HALF_UP ]] )
 *  Exponential expression.
 * Parameter
 *  $val
 *   The value to round.
 * $precision
 *   The optional number of decimal digits to round to.
 * Return
 *  The rounded value.
 */
static int libcoxCmd_round(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int n = 0;
	double r; 
	if( nArg < 1 ){
		/* Missing argument, return 0 */
		libcox_result_int(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the precision if available */
	if( nArg > 1 ){
		n = libcox_value_to_int(apArg[1]);
		if( n>30 ){
			n = 30;
		}
		if( n<0 ){
			n = 0;
		}
	}
	r = libcox_value_to_double(apArg[0]);
	/* If Y==0 and X will fit in a 64-bit int, 
     * handle the rounding directly.Otherwise 
	 * 
     */
  if( n==0 && r>=0 && r<LARGEST_INT64-1 ){
    r = (double)((libcox_int64)(r+0.5));
  }else if( n==0 && r<0 && (-r)<LARGEST_INT64-1 ){
    r = -(double)((libcox_int64)((-r)+0.5));
  }
  /* Return thr rounded value */
  libcox_result_double(pCtx, r);
  return LIBCOX_OK;
}
/*
 * string dechex(int $number)
 *  Decimal to hexadecimal.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Hexadecimal string representation of number
 */
static int libcoxCmd_dechex(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iVal;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the given number */
	iVal = libcox_value_to_int(apArg[0]);
	/* Format */
	libcox_result_string_format(pCtx, "%x", iVal);
	return LIBCOX_OK;
}
/*
 * string decoct(int $number)
 *  Decimal to Octal.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Octal string representation of number
 */
static int libcoxCmd_decoct(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iVal;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the given number */
	iVal = libcox_value_to_int(apArg[0]);
	/* Format */
	libcox_result_string_format(pCtx, "%o", iVal);
	return LIBCOX_OK;
}
/*
 * string decbin(int $number)
 *  Decimal to binary.
 * Parameters
 *  $number
 *   Decimal value to convert
 * Return
 *  Binary string representation of number
 */
static int libcoxCmd_decbin(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iVal;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the given number */
	iVal = libcox_value_to_int(apArg[0]);
	/* Format */
	libcox_result_string_format(pCtx, "%B", iVal);
	return LIBCOX_OK;
}
/*
 * int64 hexdec(string $hex_string)
 *  Hexadecimal to decimal.
 * Parameters
 *  $hex_string
 *   The hexadecimal string to convert
 * Return
 *  The decimal representation of hex_string 
 */
static int libcoxCmd_hexdec(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString, *zEnd;
	libcox_int64 iVal;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return -1 */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	iVal = 0;
	if( libcox_value_is_string(apArg[0]) ){
		/* Extract the given string */
		zString = libcox_value_to_string(apArg[0], &nLen);
		/* Delimit the string */
		zEnd = &zString[nLen];
		/* Ignore non hex-stream */
		while( zString < zEnd ){
			if( (unsigned char)zString[0] >= 0xc0 ){
				/* UTF-8 stream */
				zString++;
				while( zString < zEnd && (((unsigned char)zString[0] & 0xc0) == 0x80) ){
					zString++;
				}
			}else{
				if( SyisHex(zString[0]) ){
					break;
				}
				/* Ignore */
				zString++;
			}
		}
		if( zString < zEnd ){
			/* Cast */
			SyHexStrToInt64(zString, (sxu32)(zEnd-zString), (void *)&iVal, 0);
		}
	}else{
		/* Extract as a 64-bit integer */
		iVal = libcox_value_to_int64(apArg[0]);
	}
	/* Return the number */
	libcox_result_int64(pCtx, iVal);
	return LIBCOX_OK;
}
/*
 * int64 bindec(string $bin_string)
 *  Binary to decimal.
 * Parameters
 *  $bin_string
 *   The binary string to convert
 * Return
 *  Returns the decimal equivalent of the binary number represented by the binary_string argument.  
 */
static int libcoxCmd_bindec(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	libcox_int64 iVal;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return -1 */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	iVal = 0;
	if( libcox_value_is_string(apArg[0]) ){
		/* Extract the given string */
		zString = libcox_value_to_string(apArg[0], &nLen);
		if( nLen > 0 ){
			/* Perform a binary cast */
			SyBinaryStrToInt64(zString, (sxu32)nLen, (void *)&iVal, 0);
		}
	}else{
		/* Extract as a 64-bit integer */
		iVal = libcox_value_to_int64(apArg[0]);
	}
	/* Return the number */
	libcox_result_int64(pCtx, iVal);
	return LIBCOX_OK;
}
/*
 * int64 octdec(string $oct_string)
 *  Octal to decimal.
 * Parameters
 *  $oct_string
 *   The octal string to convert
 * Return
 *  Returns the decimal equivalent of the octal number represented by the octal_string argument.  
 */
static int libcoxCmd_octdec(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	libcox_int64 iVal;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return -1 */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	iVal = 0;
	if( libcox_value_is_string(apArg[0]) ){
		/* Extract the given string */
		zString = libcox_value_to_string(apArg[0], &nLen);
		if( nLen > 0 ){
			/* Perform the cast */
			SyOctalStrToInt64(zString, (sxu32)nLen, (void *)&iVal, 0);
		}
	}else{
		/* Extract as a 64-bit integer */
		iVal = libcox_value_to_int64(apArg[0]);
	}
	/* Return the number */
	libcox_result_int64(pCtx, iVal);
	return LIBCOX_OK;
}
/*
 * string base_convert(string $number, int $frombase, int $tobase)
 *  Convert a number between arbitrary bases.
 * Parameters
 * $number
 *  The number to convert
 * $frombase
 *  The base number is in
 * $tobase
 *  The base to convert number to
 * Return
 *  Number converted to base tobase 
 */
static int libcoxCmd_base_convert(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int nLen, iFbase, iTobase;
	const char *zNum;
	libcox_int64 iNum;
	if( nArg < 3 ){
		/* Return the empty string*/
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Base numbers */
	iFbase  = libcox_value_to_int(apArg[1]);
	iTobase = libcox_value_to_int(apArg[2]);
	if( libcox_value_is_string(apArg[0]) ){
		/* Extract the target number */
		zNum = libcox_value_to_string(apArg[0], &nLen);
		if( nLen < 1 ){
			/* Return the empty string*/
			libcox_result_string(pCtx, "", 0);
			return LIBCOX_OK;
		}
		/* Base conversion */
		switch(iFbase){
		case 16:
			/* Hex */
			SyHexStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
			break;
		case 8:
			/* Octal */
			SyOctalStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
			break;
		case 2:
			/* Binary */
			SyBinaryStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
			break;
		default:
			/* Decimal */
			SyStrToInt64(zNum, (sxu32)nLen, (void *)&iNum, 0);
			break;
		}
	}else{
		iNum = libcox_value_to_int64(apArg[0]);
	}
	switch(iTobase){
	case 16:
		/* Hex */
		libcox_result_string_format(pCtx, "%qx", iNum); /* Quad hex */
		break;
	case 8:
		/* Octal */
		libcox_result_string_format(pCtx, "%qo", iNum); /* Quad octal */
		break;
	case 2:
		/* Binary */
		libcox_result_string_format(pCtx, "%qB", iNum); /* Quad binary */
		break;
	default:
		/* Decimal */
		libcox_result_string_format(pCtx, "%qd", iNum); /* Quad decimal */
		break;
	}
	return LIBCOX_OK;
}
/*
 * string substr(string $string, int $start[, int $length ])
 *  Return part of a string.
 * Parameters
 *  $string
 *   The input string. Must be one character or longer.
 * $start
 *   If start is non-negative, the returned string will start at the start'th position
 *   in string, counting from zero. For instance, in the string 'abcdef', the character
 *   at position 0 is 'a', the character at position 2 is 'c', and so forth.
 *   If start is negative, the returned string will start at the start'th character
 *   from the end of string.
 *   If string is less than or equal to start characters long, FALSE will be returned.
 * $length
 *   If length is given and is positive, the string returned will contain at most length
 *   characters beginning from start (depending on the length of string).
 *   If length is given and is negative, then that many characters will be omitted from
 *   the end of string (after the start position has been calculated when a start is negative).
 *   If start denotes the position of this truncation or beyond, false will be returned.
 *   If length is given and is 0, FALSE or NULL an empty string will be returned.
 *   If length is omitted, the substring starting from start until the end of the string
 *   will be returned. 
 * Return
 *  Returns the extracted part of string, or FALSE on failure or an empty string.
 */
static int libcoxCmd_substr(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zSource, *zOfft;
	int nOfft, nLen, nSrcLen;	
	if( nArg < 2 ){
		/* return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zSource = libcox_value_to_string(apArg[0], &nSrcLen);
	if( nSrcLen < 1 ){
		/* Empty string, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	nLen = nSrcLen; /* cc warning */
	/* Extract the offset */
	nOfft = libcox_value_to_int(apArg[1]);
	if( nOfft < 0 ){
		zOfft = &zSource[nSrcLen+nOfft]; 
		if( zOfft < zSource ){
			/* Invalid offset */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		nLen = (int)(&zSource[nSrcLen]-zOfft);
		nOfft = (int)(zOfft-zSource);
	}else if( nOfft >= nSrcLen ){
		/* Invalid offset */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}else{
		zOfft = &zSource[nOfft];
		nLen = nSrcLen - nOfft;
	}
	if( nArg > 2 ){
		/* Extract the length */
		nLen = libcox_value_to_int(apArg[2]);
		if( nLen == 0 ){
			/* Invalid length, return an empty string */
			libcox_result_string(pCtx, "", 0);
			return LIBCOX_OK;
		}else if( nLen < 0 ){
			nLen = nSrcLen + nLen - nOfft;
			if( nLen < 1 ){
				/* Invalid  length */
				nLen = nSrcLen - nOfft;
			}
		}
		if( nLen + nOfft > nSrcLen ){
			/* Invalid length */
			nLen = nSrcLen - nOfft;
		}
	}
	/* Return the substring */
	libcox_result_string(pCtx, zOfft, nLen);
	return LIBCOX_OK;
}
/*
 * int substr_compare(string $main_str, string $str , int $offset[, int $length[, bool $case_insensitivity = false ]])
 *  Binary safe comparison of two strings from an offset, up to length characters.
 * Parameters
 *  $main_str
 *  The main string being compared.
 *  $str
 *   The secondary string being compared.
 * $offset
 *  The start position for the comparison. If negative, it starts counting from
 *  the end of the string.
 * $length
 *  The length of the comparison. The default value is the largest of the length 
 *  of the str compared to the length of main_str less the offset.
 * $case_insensitivity
 *  If case_insensitivity is TRUE, comparison is case insensitive.
 * Return
 *  Returns < 0 if main_str from position offset is less than str, > 0 if it is greater than
 *  str, and 0 if they are equal. If offset is equal to or greater than the length of main_str
 *  or length is set and is less than 1, substr_compare() prints a warning and returns FALSE. 
 */
static int libcoxCmd_substr_compare(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zSource, *zOfft, *zSub;
	int nOfft, nLen, nSrcLen, nSublen;
	int iCase = 0;
	int rc;
	if( nArg < 3 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zSource = libcox_value_to_string(apArg[0], &nSrcLen);
	if( nSrcLen < 1 ){
		/* Empty string, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	nLen = nSrcLen; /* cc warning */
	/* Extract the substring */
	zSub = libcox_value_to_string(apArg[1], &nSublen);
	if( nSublen < 1 || nSublen > nSrcLen){
		/* Empty string, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the offset */
	nOfft = libcox_value_to_int(apArg[2]);
	if( nOfft < 0 ){
		zOfft = &zSource[nSrcLen+nOfft]; 
		if( zOfft < zSource ){
			/* Invalid offset */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		nLen = (int)(&zSource[nSrcLen]-zOfft);
		nOfft = (int)(zOfft-zSource);
	}else if( nOfft >= nSrcLen ){
		/* Invalid offset */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}else{
		zOfft = &zSource[nOfft];
		nLen = nSrcLen - nOfft;
	}
	if( nArg > 3 ){
		/* Extract the length */
		nLen = libcox_value_to_int(apArg[3]);
		if( nLen < 1 ){
			/* Invalid  length */
			libcox_result_int(pCtx, 1);
			return LIBCOX_OK;
		}else if( nLen + nOfft > nSrcLen ){
			/* Invalid length */
			nLen = nSrcLen - nOfft;
		}
		if( nArg > 4 ){
			/* Case-sensitive or not */
			iCase = libcox_value_to_bool(apArg[4]);
		}
	}
	/* Perform the comparison */
	if( iCase ){
		rc = SyStrnicmp(zOfft, zSub, (sxu32)nLen);
	}else{
		rc = SyStrncmp(zOfft, zSub, (sxu32)nLen);
	}
	/* Comparison result */
	libcox_result_int(pCtx, rc);
	return LIBCOX_OK;
}
/*
 * int substr_count(string $haystack, string $needle[, int $offset = 0 [, int $length ]])
 *  Count the number of substring occurrences.
 * Parameters
 * $haystack
 *   The string to search in
 * $needle
 *   The substring to search for
 * $offset
 *  The offset where to start counting
 * $length (NOT USED)
 *  The maximum length after the specified offset to search for the substring.
 *  It outputs a warning if the offset plus the length is greater than the haystack length.
 * Return
 *  Total number of substring occurrences.
 */
static int libcoxCmd_substr_count(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zText, *zPattern, *zEnd;
	int nTextlen, nPatlen;
	int iCount = 0;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments */
		libcox_result_int(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the haystack */
	zText = libcox_value_to_string(apArg[0], &nTextlen);
	/* Point to the neddle */
	zPattern = libcox_value_to_string(apArg[1], &nPatlen);
	if( nTextlen < 1 || nPatlen < 1 || nPatlen > nTextlen ){
		/* NOOP, return zero */
		libcox_result_int(pCtx, 0);
		return LIBCOX_OK;
	}
	if( nArg > 2 ){
		int nOfft;
		/* Extract the offset */
		nOfft = libcox_value_to_int(apArg[2]);
		if( nOfft < 0 || nOfft > nTextlen ){
			/* Invalid offset, return zero */
			libcox_result_int(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Point to the desired offset */
		zText = &zText[nOfft];
		/* Adjust length */
		nTextlen -= nOfft;
	}
	/* Point to the end of the string */
	zEnd = &zText[nTextlen];
	if( nArg > 3 ){
		int nLen;
		/* Extract the length */
		nLen = libcox_value_to_int(apArg[3]);
		if( nLen < 0 || nLen > nTextlen ){
			/* Invalid length, return 0 */
			libcox_result_int(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Adjust pointer */
		nTextlen = nLen;
		zEnd = &zText[nTextlen];
	}
	/* Perform the search */
	for(;;){
		rc = SyBlobSearch((const void *)zText, (sxu32)(zEnd-zText), (const void *)zPattern, nPatlen, &nOfft);
		if( rc != SXRET_OK ){
			/* Pattern not found, break immediately */
			break;
		}
		/* Increment counter and update the offset */
		iCount++;
		zText += nOfft + nPatlen;
		if( zText >= zEnd ){
			break;
		}
	}
	/* Pattern count */
	libcox_result_int(pCtx, iCount);
	return LIBCOX_OK;
}
/*
 * string chunk_split(string $body[, int $chunklen = 76 [, string $end = "\r\n" ]])
 *   Split a string into smaller chunks.
 * Parameters
 *  $body
 *   The string to be chunked.
 * $chunklen
 *   The chunk length.
 * $end
 *   The line ending sequence.
 * Return
 *  The chunked string or NULL on failure.
 */
static int libcoxCmd_chunk_split(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn, *zEnd, *zSep = "\r\n";
	int nSepLen, nChunkLen, nLen;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Nothing to split, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* initialize/Extract arguments */
	nSepLen = (int)sizeof("\r\n") - 1;
	nChunkLen = 76;
	zIn = libcox_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	if( nArg > 1 ){
		/* Chunk length */
		nChunkLen = libcox_value_to_int(apArg[1]);
		if( nChunkLen < 1 ){
			/* Switch back to the default length */
			nChunkLen = 76;
		}
		if( nArg > 2 ){
			/* Separator */
			zSep = libcox_value_to_string(apArg[2], &nSepLen);
			if( nSepLen < 1 ){
				/* Switch back to the default separator */
				zSep = "\r\n";
				nSepLen = (int)sizeof("\r\n") - 1;
			}
		}
	}
	/* Perform the requested operation */
	if( nChunkLen > nLen ){
		/* Nothing to split, return the string and the separator */
		libcox_result_string_format(pCtx, "%.*s%.*s", nLen, zIn, nSepLen, zSep);
		return LIBCOX_OK;
	}
	while( zIn < zEnd ){
		if( nChunkLen > (int)(zEnd-zIn) ){
			nChunkLen = (int)(zEnd - zIn);
		}
		/* Append the chunk and the separator */
		libcox_result_string_format(pCtx, "%.*s%.*s", nChunkLen, zIn, nSepLen, zSep);
		/* Point beyond the chunk */
		zIn += nChunkLen;
	}
	return LIBCOX_OK;
}
/*
 * string htmlspecialchars(string $string [, int $flags = ENT_COMPAT | ENT_HTML401])
 *  HTML escaping of special characters.
 *  The translations performed are:
 *   '&' (ampersand) ==> '&amp;'
 *   '"' (double quote) ==> '&quot;' when ENT_NOQUOTES is not set.
 *   "'" (single quote) ==> '&#039;' only when ENT_QUOTES is set.
 *   '<' (less than) ==> '&lt;'
 *   '>' (greater than) ==> '&gt;'
 * Parameters
 *  $string
 *   The string being converted.
 * $flags
 *   A bitmask of one or more of the following flags, which specify how to handle quotes.
 *   The default is ENT_COMPAT | ENT_IGNORE.
 *   ENT_COMPAT 	Will convert double-quotes and leave single-quotes alone.
 *   ENT_QUOTES 	Will convert both double and single quotes.
 *   ENT_NOQUOTES 	Will leave both double and single quotes unconverted.
 *   ENT_IGNORE 	Silently discard invalid code unit sequences instead of returning an empty string.
 * Return
 *  The escaped string or NULL on failure.
 */
static int libcoxCmd_htmlspecialchars(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zCur, *zIn, *zEnd;
	int iFlags = 0x01|0x40; /* ENT_COMPAT | ENT_HTML401 */
	int nLen, c;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid arguments, return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if( nArg > 1 ){
		iFlags = libcox_value_to_int(apArg[1]);
		if( iFlags < 0 ){
			iFlags = 0x01|0x40;
		}
	}
	/* Perform the requested operation */
	for(;;){
		if( zIn >= zEnd ){
			break;
		}
		zCur = zIn;
		while( zIn < zEnd && zIn[0] != '&' && zIn[0] != '\'' && zIn[0] != '"' && zIn[0] != '<' && zIn[0] != '>' ){
			zIn++;
		}
		if( zCur < zIn ){
			/* Append the raw string verbatim */
			libcox_result_string(pCtx, zCur, (int)(zIn-zCur));
		}
		if( zIn >= zEnd ){
			break;
		}
		c = zIn[0];
		if( c == '&' ){
			/* Expand '&amp;' */
			libcox_result_string(pCtx, "&amp;", (int)sizeof("&amp;")-1);
		}else if( c == '<' ){
			/* Expand '&lt;' */
			libcox_result_string(pCtx, "&lt;", (int)sizeof("&lt;")-1);
		}else if( c == '>' ){
			/* Expand '&gt;' */
			libcox_result_string(pCtx, "&gt;", (int)sizeof("&gt;")-1);
		}else if( c == '\'' ){
			if( iFlags & 0x02 /*ENT_QUOTES*/ ){
				/* Expand '&#039;' */
				libcox_result_string(pCtx, "&#039;", (int)sizeof("&#039;")-1);
			}else{
				/* Leave the single quote untouched */
				libcox_result_string(pCtx, "'", (int)sizeof(char));
			}
		}else if( c == '"' ){
			if( (iFlags & 0x04) == 0 /*ENT_NOQUOTES*/ ){
				/* Expand '&quot;' */
				libcox_result_string(pCtx, "&quot;", (int)sizeof("&quot;")-1);
			}else{
				/* Leave the double quote untouched */
				libcox_result_string(pCtx, "\"", (int)sizeof(char));
			}
		}
		/* Ignore the unsafe HTML character */
		zIn++;
	}
	return LIBCOX_OK;
}
/*
 * string htmlspecialchars_decode(string $string[, int $quote_style = ENT_COMPAT ])
 *  Unescape HTML entities.
 * Parameters
 *  $string
 *   The string to decode
 *  $quote_style
 *    The quote style. One of the following constants:
 *   ENT_COMPAT 	Will convert double-quotes and leave single-quotes alone (default)
 *   ENT_QUOTES 	Will convert both double and single quotes
 *   ENT_NOQUOTES 	Will leave both double and single quotes unconverted
 * Return
 *  The decoded string or NULL on failure.
 */
static int libcoxCmd_htmlspecialchars_decode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zCur, *zIn, *zEnd;
	int iFlags = 0x01; /* ENT_COMPAT */
	int nLen, nJump;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid arguments, return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	zEnd = &zIn[nLen];
	/* Extract the flags if available */
	if( nArg > 1 ){
		iFlags = libcox_value_to_int(apArg[1]);
		if( iFlags < 0 ){
			iFlags = 0x01;
		}
	}
	/* Perform the requested operation */
	for(;;){
		if( zIn >= zEnd ){
			break;
		}
		zCur = zIn;
		while( zIn < zEnd && zIn[0] != '&' ){
			zIn++;
		}
		if( zCur < zIn ){
			/* Append the raw string verbatim */
			libcox_result_string(pCtx, zCur, (int)(zIn-zCur));
		}
		nLen = (int)(zEnd-zIn);
		nJump = (int)sizeof(char);
		if( nLen >= (int)sizeof("&amp;")-1 && SyStrnicmp(zIn, "&amp;", sizeof("&amp;")-1) == 0 ){
			/* &amp; ==> '&' */
			libcox_result_string(pCtx, "&", (int)sizeof(char));
			nJump = (int)sizeof("&amp;")-1;
		}else if( nLen >= (int)sizeof("&lt;")-1 && SyStrnicmp(zIn, "&lt;", sizeof("&lt;")-1) == 0 ){
			/* &lt; ==> < */
			libcox_result_string(pCtx, "<", (int)sizeof(char));
			nJump = (int)sizeof("&lt;")-1; 
		}else if( nLen >= (int)sizeof("&gt;")-1 && SyStrnicmp(zIn, "&gt;", sizeof("&gt;")-1) == 0 ){
			/* &gt; ==> '>' */
			libcox_result_string(pCtx, ">", (int)sizeof(char));
			nJump = (int)sizeof("&gt;")-1; 
		}else if( nLen >= (int)sizeof("&quot;")-1 && SyStrnicmp(zIn, "&quot;", sizeof("&quot;")-1) == 0 ){
			/* &quot; ==> '"' */
			if( (iFlags & 0x04) == 0 /*ENT_NOQUOTES*/ ){
				libcox_result_string(pCtx, "\"", (int)sizeof(char));
			}else{
				/* Leave untouched */
				libcox_result_string(pCtx, "&quot;", (int)sizeof("&quot;")-1);
			}
			nJump = (int)sizeof("&quot;")-1;
		}else if( nLen >= (int)sizeof("&#039;")-1 && SyStrnicmp(zIn, "&#039;", sizeof("&#039;")-1) == 0 ){
			/* &#039; ==> ''' */
			if( iFlags & 0x02 /*ENT_QUOTES*/ ){
				/* Expand ''' */
				libcox_result_string(pCtx, "'", (int)sizeof(char));
			}else{
				/* Leave untouched */
				libcox_result_string(pCtx, "&#039;", (int)sizeof("&#039;")-1);
			}
			nJump = (int)sizeof("&#039;")-1;
		}else if( nLen >= (int)sizeof(char) ){
			/* expand '&' */
			libcox_result_string(pCtx, "&", (int)sizeof(char));
		}else{
			/* No more input to process */
			break;
		}
		zIn += nJump;
	}
	return LIBCOX_OK;
}
/*
 * int strlen($string)
 *  return the length of the given string.
 * Parameter
 *  string: The string being measured for length.
 * Return
 *  length of the given string.
 */
static int libcoxCmd_strlen(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iLen = 0;
	if( nArg > 0 ){
		libcox_value_to_string(apArg[0], &iLen);
	}
	/* String length */
	libcox_result_int(pCtx, iLen);
	return LIBCOX_OK;
}
/*
 * int strcmp(string $str1, string $str2)
 *  Perform a binary safe string comparison.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater 
 *  than str2, and 0 if they are equal.
 */
static int libcoxCmd_strcmp(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *z1, *z2;
	int n1, n2;
	int res;
	if( nArg < 2 ){
		res = nArg == 0 ? 0 : 1;
		libcox_result_int(pCtx, res);
		return LIBCOX_OK;
	}
	/* Perform the comparison */
	z1 = libcox_value_to_string(apArg[0], &n1);
	z2 = libcox_value_to_string(apArg[1], &n2);
	res = SyStrncmp(z1, z2, (sxu32)(SXMAX(n1, n2)));
	/* Comparison result */
	libcox_result_int(pCtx, res);
	return LIBCOX_OK;
}
/*
 * int strncmp(string $str1, string $str2, int n)
 *  Perform a binary safe string comparison of the first n characters.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater 
 *  than str2, and 0 if they are equal.
 */
static int libcoxCmd_strncmp(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *z1, *z2;
	int res;
	int n;
	if( nArg < 3 ){
		/* Perform a standard comparison */
		return libcoxCmd_strcmp(pCtx, nArg, apArg);
	}
	/* Desired comparison length */
	n  = libcox_value_to_int(apArg[2]);
	if( n < 0 ){
		/* Invalid length */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	/* Perform the comparison */
	z1 = libcox_value_to_string(apArg[0], 0);
	z2 = libcox_value_to_string(apArg[1], 0);
	res = SyStrncmp(z1, z2, (sxu32)n);
	/* Comparison result */
	libcox_result_int(pCtx, res);
	return LIBCOX_OK;
}
/*
 * int strcasecmp(string $str1, string $str2, int n)
 *  Perform a binary safe case-insensitive string comparison.
 * Parameter
 *  str1: The first string
 *  str2: The second string
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater 
 *  than str2, and 0 if they are equal.
 */
static int libcoxCmd_strcasecmp(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *z1, *z2;
	int n1, n2;
	int res;
	if( nArg < 2 ){
		res = nArg == 0 ? 0 : 1;
		libcox_result_int(pCtx, res);
		return LIBCOX_OK;
	}
	/* Perform the comparison */
	z1 = libcox_value_to_string(apArg[0], &n1);
	z2 = libcox_value_to_string(apArg[1], &n2);
	res = SyStrnicmp(z1, z2, (sxu32)(SXMAX(n1, n2)));
	/* Comparison result */
	libcox_result_int(pCtx, res);
	return LIBCOX_OK;
}
/*
 * int strncasecmp(string $str1, string $str2, int n)
 *  Perform a binary safe case-insensitive string comparison of the first n characters.
 * Parameter
 *  $str1: The first string
 *  $str2: The second string
 *  $len:  The length of strings to be used in the comparison.
 * Return
 *  Returns < 0 if str1 is less than str2; > 0 if str1 is greater 
 *  than str2, and 0 if they are equal.
 */
static int libcoxCmd_strncasecmp(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *z1, *z2;
	int res;
	int n;
	if( nArg < 3 ){
		/* Perform a standard comparison */
		return libcoxCmd_strcasecmp(pCtx, nArg, apArg);
	}
	/* Desired comparison length */
	n  = libcox_value_to_int(apArg[2]);
	if( n < 0 ){
		/* Invalid length */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	/* Perform the comparison */
	z1 = libcox_value_to_string(apArg[0], 0);
	z2 = libcox_value_to_string(apArg[1], 0);
	res = SyStrnicmp(z1, z2, (sxu32)n);
	/* Comparison result */
	libcox_result_int(pCtx, res);
	return LIBCOX_OK;
}
/*
 * Implode context [i.e: it's private data].
 * A pointer to the following structure is forwarded
 * verbatim to the array walker callback defined below.
 */
struct implode_data {
	libcox_context *pCtx;    /* Call context */
	int bRecursive;       /* TRUE if recursive implode [this is a symisc eXtension] */
	const char *zSep;     /* Arguments separator if any */
	int nSeplen;          /* Separator length */
	int bFirst;           /* TRUE if first call */
	int nRecCount;        /* Recursion count to avoid infinite loop */
};
/*
 * Implode walker callback for the [libcox_array_walk()] interface.
 * The following routine is invoked for each array entry passed
 * to the implode() function.
 */
static int implode_callback(libcox_value *pValue, void *pUserData)
{
	struct implode_data *pData = (struct implode_data *)pUserData;
	const char *zData;
	int nLen;
	if( pData->bRecursive && libcox_value_is_array(pValue) && pData->nRecCount < 32 ){
		if( pData->nSeplen > 0 ){
			if( !pData->bFirst ){
				/* append the separator first */
				libcox_result_string(pData->pCtx, pData->zSep, pData->nSeplen);
			}else{
				pData->bFirst = 0;
			}
		}
		/* Recurse */
		pData->bFirst = 1;
		pData->nRecCount++;
		libcoxHashmapWalk((libcox_hashmap *)pValue->x.pOther, implode_callback, pData);
		pData->nRecCount--;
		return LIBCOX_OK;
	}
	/* Extract the string representation of the entry value */
	zData = libcox_value_to_string(pValue, &nLen);
	if( nLen > 0 ){
		if( pData->nSeplen > 0 ){
			if( !pData->bFirst ){
				/* append the separator first */
				libcox_result_string(pData->pCtx, pData->zSep, pData->nSeplen);
			}else{
				pData->bFirst = 0;
			}
		}
		libcox_result_string(pData->pCtx, zData, nLen);
	}
	return LIBCOX_OK;
}
/*
 * string implode(string $glue, array $pieces, ...)
 * string implode(array $pieces, ...)
 *  Join array elements with a string.
 * $glue
 *   Defaults to an empty string. This is not the preferred usage of implode() as glue
 *   would be the second parameter and thus, the bad prototype would be used.
 * $pieces
 *   The array of strings to implode.
 * Return
 *  Returns a string containing a string representation of all the array elements in the same
 *  order, with the glue string between each element. 
 */
static int libcoxCmd_implode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	struct implode_data imp_data;
	int i = 1;
	if( nArg < 1 ){
		/* Missing argument, return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Prepare the implode context */
	imp_data.pCtx = pCtx;
	imp_data.bRecursive = 0;
	imp_data.bFirst = 1;
	imp_data.nRecCount = 0;
	if( !libcox_value_is_array(apArg[0]) ){
		imp_data.zSep = libcox_value_to_string(apArg[0], &imp_data.nSeplen);
	}else{
		imp_data.zSep = 0;
		imp_data.nSeplen = 0;
		i = 0;
	}
	libcox_result_string(pCtx, "", 0); /* Set an empty stirng */
	/* Start the 'join' process */
	while( i < nArg ){
		if( libcox_value_is_array(apArg[i]) ){
			/* Iterate throw array entries */
			libcox_array_walk(apArg[i], implode_callback, &imp_data);
		}else{
			const char *zData;
			int nLen;
			/* Extract the string representation of the libcox value */
			zData = libcox_value_to_string(apArg[i], &nLen);
			if( nLen > 0 ){
				if( imp_data.nSeplen > 0 ){
					if( !imp_data.bFirst ){
						/* append the separator first */
						libcox_result_string(pCtx, imp_data.zSep, imp_data.nSeplen);
					}else{
						imp_data.bFirst = 0;
					}
				}
				libcox_result_string(pCtx, zData, nLen);
			}
		}
		i++;
	}
	return LIBCOX_OK;
}
/*
 * array explode(string $delimiter, string $string[, int $limit ])
 *  Returns an array of strings, each of which is a substring of string 
 *  formed by splitting it on boundaries formed by the string delimiter. 
 * Parameters
 *  $delimiter
 *   The boundary string.
 * $string
 *   The input string.
 * $limit
 *   If limit is set and positive, the returned array will contain a maximum
 *   of limit elements with the last element containing the rest of string.
 *   If the limit parameter is negative, all fields except the last -limit are returned.
 *   If the limit parameter is zero, then this is treated as 1.
 * Returns
 *  Returns an array of strings created by splitting the string parameter
 *  on boundaries formed by the delimiter.
 *  If delimiter is an empty string (""), explode() will return FALSE. 
 *  If delimiter contains a value that is not contained in string and a negative
 *  limit is used, then an empty array will be returned, otherwise an array containing string
 *  will be returned. 
 * NOTE:
 *  Negative limit is not supported.
 */
static int libcoxCmd_explode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zDelim, *zString, *zCur, *zEnd;
	int nDelim, nStrlen, iLimit;
	libcox_value *pArray;
	libcox_value *pValue;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the delimiter */
	zDelim = libcox_value_to_string(apArg[0], &nDelim);
	if( nDelim < 1 ){
		/* Empty delimiter, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the string */
	zString = libcox_value_to_string(apArg[1], &nStrlen);
	if( nStrlen < 1 ){
		/* Empty delimiter, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the end of the string */
	zEnd = &zString[nStrlen];
	/* Create the array */
	pArray =  libcox_context_new_array(pCtx);
	pValue = libcox_context_new_scalar(pCtx);
	if( pArray == 0 || pValue == 0 ){
		/* Out of memory, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Set a defualt limit */
	iLimit = SXI32_HIGH;
	if( nArg > 2 ){
		iLimit = libcox_value_to_int(apArg[2]);
		 if( iLimit < 0 ){
			iLimit = -iLimit;
		}
		if( iLimit == 0 ){
			iLimit = 1;
		}
		iLimit--;
	}
	/* Start exploding */
	for(;;){
		if( zString >= zEnd ){
			/* No more entry to process */
			break;
		}
		rc = SyBlobSearch(zString, (sxu32)(zEnd-zString), zDelim, nDelim, &nOfft);
		if( rc != SXRET_OK || iLimit <= (int)libcox_array_count(pArray) ){
			/* Limit reached, insert the rest of the string and break */
			if( zEnd > zString ){
				libcox_value_string(pValue, zString, (int)(zEnd-zString));
				libcox_array_insert(pArray, pValue);
			}
			break;
		}
		/* Point to the desired offset */
		zCur = &zString[nOfft];
		if( zCur > zString ){
			/* Perform the store operation */
			libcox_value_string(pValue, zString, (int)(zCur-zString));
			libcox_array_insert(pArray, pValue);
		}
		/* Point beyond the delimiter */
		zString = &zCur[nDelim];
		/* Reset the cursor */
		libcox_value_reset_string_cursor(pValue);
	}
	/* Return the freshly created array */
	libcox_result_value(pCtx, pArray);
	/* NOTE that every allocated libcox_value will be automatically 
	 * released as soon we return from this foregin function.
	 */
	return LIBCOX_OK;
}
/*
 * string trim(string $str[, string $charlist ])
 *  Strip whitespace (or other characters) from the beginning and end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  The processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int libcoxCmd_trim(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Start the trim process */
	if( nArg < 2 ){
		SyString sStr;
		/* Remove white spaces and NUL bytes */
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringFullTrimSafe(&sStr);
		libcox_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	}else{
		/* Char list */
		const char *zList;
		int nListlen;
		zList = libcox_value_to_string(apArg[1], &nListlen);
		if( nListlen < 1 ){
			/* Return the string unchanged */
			libcox_result_string(pCtx, zString, nLen);
		}else{
			const char *zEnd = &zString[nLen];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Left trim */
			for(;;){
				if( zCur >= zEnd ){
					break;
				}
				zPtr = zCur;
				for( i = 0 ; i < nListlen ; i++ ){
					if( zCur < zEnd && zCur[0] == zList[i] ){
						zCur++;
					}
				}
				if( zCur == zPtr ){
					/* No match, break immediately */
					break;
				}
			}
			/* Right trim */
			zEnd--;
			for(;;){
				if( zEnd <= zCur ){
					break;
				}
				zPtr = zEnd;
				for( i = 0 ; i < nListlen ; i++ ){
					if( zEnd > zCur && zEnd[0] == zList[i] ){
						zEnd--;
					}
				}
				if( zEnd == zPtr ){
					break;
				}
			}
			if( zCur >= zEnd ){
				/* Return the empty string */
				libcox_result_string(pCtx, "", 0);
			}else{
				zEnd++;
				libcox_result_string(pCtx, zCur, (int)(zEnd-zCur));
			}
		}
	}
	return LIBCOX_OK;
}
/*
 * string rtrim(string $str[, string $charlist ])
 *  Strip whitespace (or other characters) from the end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  The processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int libcoxCmd_rtrim(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Start the trim process */
	if( nArg < 2 ){
		SyString sStr;
		/* Remove white spaces and NUL bytes*/
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringRightTrimSafe(&sStr);
		libcox_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	}else{
		/* Char list */
		const char *zList;
		int nListlen;
		zList = libcox_value_to_string(apArg[1], &nListlen);
		if( nListlen < 1 ){
			/* Return the string unchanged */
			libcox_result_string(pCtx, zString, nLen);
		}else{
			const char *zEnd = &zString[nLen - 1];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Right trim */
			for(;;){
				if( zEnd <= zCur ){
					break;
				}
				zPtr = zEnd;
				for( i = 0 ; i < nListlen ; i++ ){
					if( zEnd > zCur && zEnd[0] == zList[i] ){
						zEnd--;
					}
				}
				if( zEnd == zPtr ){
					break;
				}
			}
			if( zEnd <= zCur ){
				/* Return the empty string */
				libcox_result_string(pCtx, "", 0);
			}else{
				zEnd++;
				libcox_result_string(pCtx, zCur, (int)(zEnd-zCur));
			}
		}
	}
	return LIBCOX_OK;
}
/*
 * string ltrim(string $str[, string $charlist ])
 *  Strip whitespace (or other characters) from the beginning and end of a string.
 * Parameters
 *  $str
 *   The string that will be trimmed.
 * $charlist
 *   Optionally, the stripped characters can also be specified using the charlist parameter.
 *   Simply list all characters that you want to be stripped.
 *   With .. you can specify a range of characters.
 * Returns.
 *  The processed string.
 * NOTE:
 *   RANGE CHARACTERS [I.E: 'a'..'z'] are not supported.
 */
static int libcoxCmd_ltrim(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Start the trim process */
	if( nArg < 2 ){
		SyString sStr;
		/* Remove white spaces and NUL byte */
		SyStringInitFromBuf(&sStr, zString, nLen);
		SyStringLeftTrimSafe(&sStr);
		libcox_result_string(pCtx, sStr.zString, (int)sStr.nByte);
	}else{
		/* Char list */
		const char *zList;
		int nListlen;
		zList = libcox_value_to_string(apArg[1], &nListlen);
		if( nListlen < 1 ){
			/* Return the string unchanged */
			libcox_result_string(pCtx, zString, nLen);
		}else{
			const char *zEnd = &zString[nLen];
			const char *zCur = zString;
			const char *zPtr;
			int i;
			/* Left trim */
			for(;;){
				if( zCur >= zEnd ){
					break;
				}
				zPtr = zCur;
				for( i = 0 ; i < nListlen ; i++ ){
					if( zCur < zEnd && zCur[0] == zList[i] ){
						zCur++;
					}
				}
				if( zCur == zPtr ){
					/* No match, break immediately */
					break;
				}
			}
			if( zCur >= zEnd ){
				/* Return the empty string */
				libcox_result_string(pCtx, "", 0);
			}else{
				libcox_result_string(pCtx, zCur, (int)(zEnd-zCur));
			}
		}
	}
	return LIBCOX_OK;
}
/*
 * string strtolower(string $str)
 *  Make a string lowercase.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The lowercased string.
 */
static int libcoxCmd_strtolower(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString, *zCur, *zEnd;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	for(;;){
		if( zString >= zEnd ){
			/* No more input, break immediately */
			break;
		}
		if( (unsigned char)zString[0] >= 0xc0 ){
			/* UTF-8 stream, output verbatim */
			zCur = zString;
			zString++;
			while( zString < zEnd && ((unsigned char)zString[0] & 0xc0) == 0x80){
				zString++;
			}
			/* Append UTF-8 stream */
			libcox_result_string(pCtx, zCur, (int)(zString-zCur));
		}else{
			int c = zString[0];
			if( SyisUpper(c) ){
				c = SyToLower(zString[0]);
			}
			/* Append character */
			libcox_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			/* Advance the cursor */
			zString++;
		}
	}
	return LIBCOX_OK;
}
/*
 * string strtoupper(string $str)
 *  Make a string uppercase.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  The uppercased string.
 */
static int libcoxCmd_strtoupper(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString, *zCur, *zEnd;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	zEnd = &zString[nLen];
	for(;;){
		if( zString >= zEnd ){
			/* No more input, break immediately */
			break;
		}
		if( (unsigned char)zString[0] >= 0xc0 ){
			/* UTF-8 stream, output verbatim */
			zCur = zString;
			zString++;
			while( zString < zEnd && ((unsigned char)zString[0] & 0xc0) == 0x80){
				zString++;
			}
			/* Append UTF-8 stream */
			libcox_result_string(pCtx, zCur, (int)(zString-zCur));
		}else{
			int c = zString[0];
			if( SyisLower(c) ){
				c = SyToUpper(zString[0]);
			}
			/* Append character */
			libcox_result_string(pCtx, (const char *)&c, (int)sizeof(char));
			/* Advance the cursor */
			zString++;
		}
	}
	return LIBCOX_OK;
}
/*
 * Binary to hex consumer callback.
 * This callback is the default consumer used by the hash functions
 * [i.e: bin2hex(), md5(), sha1(), md5_file() ... ] defined below.
 */
static int HashConsumer(const void *pData, unsigned int nLen, void *pUserData)
{
	/* Append hex chunk verbatim */
	libcox_result_string((libcox_context *)pUserData, (const char *)pData, (int)nLen);
	return SXRET_OK;
}
/*
 * string bin2hex(string $str)
 *  Convert binary data into hexadecimal representation.
 * Parameters
 *  $str
 *   The input string.
 * Returns.
 *  Returns the hexadecimal representation of the given string.
 */
static int libcoxCmd_bin2hex(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zString;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zString = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string, return */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	SyBinToHexConsumer((const void *)zString, (sxu32)nLen, HashConsumer, pCtx);
	return LIBCOX_OK;
}
/* Search callback signature */
typedef sxi32 (*ProcStringMatch)(const void *, sxu32, const void *, sxu32, sxu32 *);
/*
 * Case-insensitive pattern match.
 * Brute force is the default search method used here.
 * This is due to the fact that brute-forcing works quite
 * well for short/medium texts on modern hardware.
 */
static sxi32 iPatternMatch(const void *pText, sxu32 nLen, const void *pPattern, sxu32 iPatLen, sxu32 *pOfft)
{
	const char *zpIn = (const char *)pPattern;
	const char *zIn = (const char *)pText;
	const char *zpEnd = &zpIn[iPatLen];
	const char *zEnd = &zIn[nLen];
	const char *zPtr, *zPtr2;
	int c, d;
	if( iPatLen > nLen ){
		/* Don't bother processing */
		return SXERR_NOTFOUND;
	}
	for(;;){
		if( zIn >= zEnd ){
			break;
		}
		c = SyToLower(zIn[0]);
		d = SyToLower(zpIn[0]);
		if( c == d ){
			zPtr   = &zIn[1];
			zPtr2  = &zpIn[1];
			for(;;){
				if( zPtr2 >= zpEnd ){
					/* Pattern found */
					if( pOfft ){ *pOfft = (sxu32)(zIn-(const char *)pText); }
					return SXRET_OK;
				}
				if( zPtr >= zEnd ){
					break;
				}
				c = SyToLower(zPtr[0]);
				d = SyToLower(zPtr2[0]);
				if( c != d ){
					break;
				}
				zPtr++; zPtr2++;
			}
		}
		zIn++;
	}
	/* Pattern not found */
	return SXERR_NOTFOUND;
}
/*
 * string strstr(string $haystack, string $needle[, bool $before_needle = false ])
 *  Find the first occurrence of a string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $before_needle
 *   If TRUE, strstr() returns the part of the haystack before the first occurrence 
 *   of the needle (excluding the needle).
 * Return
 *  Returns the portion of string, or FALSE if needle is not found.
 */
static int libcoxCmd_strstr(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	if( nLen > 0 && nPatLen > 0 ){
		int before = 0;
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if( rc != SXRET_OK ){
			/* Pattern not found, return FALSE */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Return the portion of the string */
		if( nArg > 2 ){
			before = libcox_value_to_int(apArg[2]);
		}
		if( before ){
			libcox_result_string(pCtx, zBlob, (int)(&zBlob[nOfft]-zBlob));
		}else{
			libcox_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen]-&zBlob[nOfft]));
		}
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * string stristr(string $haystack, string $needle[, bool $before_needle = false ])
 *  Case-insensitive strstr().
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $before_needle
 *   If TRUE, stristr() returns the part of the haystack before the first occurrence 
 *   of the needle (excluding the needle).
 * Return
 *  Returns the portion of string, or FALSE if needle is not found.
 */
static int libcoxCmd_stristr(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	if( nLen > 0 && nPatLen > 0 ){
		int before = 0;
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if( rc != SXRET_OK ){
			/* Pattern not found, return FALSE */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Return the portion of the string */
		if( nArg > 2 ){
			before = libcox_value_to_int(apArg[2]);
		}
		if( before ){
			libcox_result_string(pCtx, zBlob, (int)(&zBlob[nOfft]-zBlob));
		}else{
			libcox_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen]-&zBlob[nOfft]));
		}
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * int strpos(string $haystack, string $needle [, int $offset = 0 ] )
 *  Returns the numeric position of the first occurrence of needle in the haystack string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   This optional offset parameter allows you to specify which character in haystack
 *   to start searching. The position returned is still relative to the beginning
 *   of haystack.
 * Return
 *  Returns the position as an integer. If needle is not found, strpos() will return FALSE.
 */
static int libcoxCmd_strpos(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen, nStart;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	nStart = 0;
	/* Peek the starting offset if available */
	if( nArg > 2 ){
		nStart = libcox_value_to_int(apArg[2]);
		if( nStart < 0 ){
			nStart = -nStart;
		}
		if( nStart >= nLen ){
			/* Invalid offset */
			nStart = 0;
		}else{
			zBlob += nStart;
			nLen -= nStart;
		}
	}
	if( nLen > 0 && nPatLen > 0 ){
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if( rc != SXRET_OK ){
			/* Pattern not found, return FALSE */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Return the pattern position */
		libcox_result_int64(pCtx, (libcox_int64)(nOfft+nStart));
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * int stripos(string $haystack, string $needle [, int $offset = 0 ] )
 *  Case-insensitive strpos.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   This optional offset parameter allows you to specify which character in haystack
 *   to start searching. The position returned is still relative to the beginning
 *   of haystack.
 * Return
 *  Returns the position as an integer. If needle is not found, stripos() will return FALSE.
 */
static int libcoxCmd_stripos(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	const char *zBlob, *zPattern;
	int nLen, nPatLen, nStart;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	nOfft = 0; /* cc warning */
	nStart = 0;
	/* Peek the starting offset if available */
	if( nArg > 2 ){
		nStart = libcox_value_to_int(apArg[2]);
		if( nStart < 0 ){
			nStart = -nStart;
		}
		if( nStart >= nLen ){
			/* Invalid offset */
			nStart = 0;
		}else{
			zBlob += nStart;
			nLen -= nStart;
		}
	}
	if( nLen > 0 && nPatLen > 0 ){
		/* Perform the lookup */
		rc = xPatternMatch(zBlob, (sxu32)nLen, zPattern, (sxu32)nPatLen, &nOfft);
		if( rc != SXRET_OK ){
			/* Pattern not found, return FALSE */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Return the pattern position */
		libcox_result_int64(pCtx, (libcox_int64)(nOfft+nStart));
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * int strrpos(string $haystack, string $needle [, int $offset = 0 ] )
 *  Find the numeric position of the last occurrence of needle in the haystack string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   If specified, search will start this number of characters counted from the beginning
 *   of the string. If the value is negative, search will instead start from that many 
 *   characters from the end of the string, searching backwards.
 * Return
 *  Returns the position as an integer. If needle is not found, strrpos() will return FALSE.
 */
static int libcoxCmd_strrpos(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zStart, *zBlob, *zPattern, *zPtr, *zEnd;
	ProcStringMatch xPatternMatch = SyBlobSearch; /* Case-sensitive pattern match */
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	/* Point to the end of the pattern */
	zPtr = &zBlob[nLen - 1];
	zEnd = &zBlob[nLen];
	/* Save the starting posistion */
	zStart = zBlob;
	nOfft = 0; /* cc warning */
	/* Peek the starting offset if available */
	if( nArg > 2 ){
		int nStart;
		nStart = libcox_value_to_int(apArg[2]);
		if( nStart < 0 ){
			nStart = -nStart;
			if( nStart >= nLen ){
				/* Invalid offset */
				libcox_result_bool(pCtx, 0);
				return LIBCOX_OK;
			}else{
				nLen -= nStart;
				zPtr = &zBlob[nLen - 1];
				zEnd = &zBlob[nLen];
			}
		}else{
			if( nStart >= nLen ){
				/* Invalid offset */
				libcox_result_bool(pCtx, 0);
				return LIBCOX_OK;
			}else{
				zBlob += nStart;
				nLen -= nStart;
			}
		}
	}
	if( nLen > 0 && nPatLen > 0 ){
		/* Perform the lookup */
		for(;;){
			if( zBlob >= zPtr ){
				break;
			}
			rc = xPatternMatch((const void *)zPtr, (sxu32)(zEnd-zPtr), (const void *)zPattern, (sxu32)nPatLen, &nOfft);
			if( rc == SXRET_OK ){
				/* Pattern found, return it's position */
				libcox_result_int64(pCtx, (libcox_int64)(&zPtr[nOfft] - zStart));
				return LIBCOX_OK;
			}
			zPtr--;
		}
		/* Pattern not found, return FALSE */
		libcox_result_bool(pCtx, 0);
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * int strripos(string $haystack, string $needle [, int $offset = 0 ] )
 *  Case-insensitive strrpos.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *   Search pattern (must be a string).
 * $offset
 *   If specified, search will start this number of characters counted from the beginning
 *   of the string. If the value is negative, search will instead start from that many 
 *   characters from the end of the string, searching backwards.
 * Return
 *  Returns the position as an integer. If needle is not found, strripos() will return FALSE.
 */
static int libcoxCmd_strripos(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zStart, *zBlob, *zPattern, *zPtr, *zEnd;
	ProcStringMatch xPatternMatch = iPatternMatch; /* Case-insensitive pattern match */
	int nLen, nPatLen;
	sxu32 nOfft;
	sxi32 rc;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the needle and the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	zPattern = libcox_value_to_string(apArg[1], &nPatLen);
	/* Point to the end of the pattern */
	zPtr = &zBlob[nLen - 1];
	zEnd = &zBlob[nLen];
	/* Save the starting posistion */
	zStart = zBlob;
	nOfft = 0; /* cc warning */
	/* Peek the starting offset if available */
	if( nArg > 2 ){
		int nStart;
		nStart = libcox_value_to_int(apArg[2]);
		if( nStart < 0 ){
			nStart = -nStart;
			if( nStart >= nLen ){
				/* Invalid offset */
				libcox_result_bool(pCtx, 0);
				return LIBCOX_OK;
			}else{
				nLen -= nStart;
				zPtr = &zBlob[nLen - 1];
				zEnd = &zBlob[nLen];
			}
		}else{
			if( nStart >= nLen ){
				/* Invalid offset */
				libcox_result_bool(pCtx, 0);
				return LIBCOX_OK;
			}else{
				zBlob += nStart;
				nLen -= nStart;
			}
		}
	}
	if( nLen > 0 && nPatLen > 0 ){
		/* Perform the lookup */
		for(;;){
			if( zBlob >= zPtr ){
				break;
			}
			rc = xPatternMatch((const void *)zPtr, (sxu32)(zEnd-zPtr), (const void *)zPattern, (sxu32)nPatLen, &nOfft);
			if( rc == SXRET_OK ){
				/* Pattern found, return it's position */
				libcox_result_int64(pCtx, (libcox_int64)(&zPtr[nOfft] - zStart));
				return LIBCOX_OK;
			}
			zPtr--;
		}
		/* Pattern not found, return FALSE */
		libcox_result_bool(pCtx, 0);
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * int strrchr(string $haystack, mixed $needle)
 *  Find the last occurrence of a character in a string.
 * Parameters
 *  $haystack
 *   The input string.
 * $needle
 *  If needle contains more than one character, only the first is used.
 *  This behaviour is different from that of strstr().
 *  If needle is not a string, it is converted to an integer and applied
 *  as the ordinal value of a character.
 * Return
 *  This function returns the portion of string, or FALSE if needle is not found.
 */
static int libcoxCmd_strrchr(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zBlob;
	int nLen, c;
	if( nArg < 2 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the haystack */
	zBlob = libcox_value_to_string(apArg[0], &nLen);
	c = 0; /* cc warning */
	if( nLen > 0 ){
		sxu32 nOfft;
		sxi32 rc;
		if( libcox_value_is_string(apArg[1]) ){
			const char *zPattern;
			zPattern = libcox_value_to_string(apArg[1], 0); /* Never fail, so there is no need to check
														 * for NULL pointer.
														 */
			c = zPattern[0];
		}else{
			/* Int cast */
			c = libcox_value_to_int(apArg[1]);
		}
		/* Perform the lookup */
		rc = SyByteFind2(zBlob, (sxu32)nLen, c, &nOfft);
		if( rc != SXRET_OK ){
			/* No such entry, return FALSE */
			libcox_result_bool(pCtx, 0);
			return LIBCOX_OK;
		}
		/* Return the string portion */
		libcox_result_string(pCtx, &zBlob[nOfft], (int)(&zBlob[nLen]-&zBlob[nOfft]));
	}else{
		libcox_result_bool(pCtx, 0);
	}
	return LIBCOX_OK;
}
/*
 * string strrev(string $string)
 *  Reverse a string.
 * Parameters
 *  $string
 *   String to be reversed.
 * Return
 *  The reversed string.
 */
static int libcoxCmd_strrev(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn, *zEnd;
	int nLen, c;
	if( nArg < 1 ){
		/* Missing arguments, return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Extract the target string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Empty string Return null */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Perform the requested operation */
	zEnd = &zIn[nLen - 1];
	for(;;){
		if( zEnd < zIn ){
			/* No more input to process */
			break;
		}
		/* Append current character */
		c = zEnd[0];
		libcox_result_string(pCtx, (const char *)&c, (int)sizeof(char));
		zEnd--;
	}
	return LIBCOX_OK;
}
/*
 * Symisc eXtension.
 * string size_format(int64 $size)
 *  Return a smart string representation of the given size [i.e: 64-bit integer]
 *  Example:
 *     size_format 1073741824  // 1GB
 *     size_format 536870912 // 512 MB
 *     size_format 8192      //8KB
 * Parameter
 *  $size
 *    Entity size in bytes.
 * Return
 *   Formatted string representation of the given size.
 */
static int libcoxCmd_size_format(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	/*Kilo*/ /*Mega*/ /*Giga*/ /*Tera*/ /*Peta*/ /*Exa*/ /*Zeta*/
	static const char zUnit[] = {"KMGTPEZ"};
	sxi32 nRest, i_32;
	libcox_int64 iSize;
	int c = -1; /* index in zUnit[] */

	if( nArg < 1 ){
		/* Missing argument, return the empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	/* Extract the given size */
	iSize = libcox_value_to_int64(apArg[0]);
	if( iSize < 100 /* Bytes */ ){
		/* Don't bother formatting, return immediately */
		libcox_result_string(pCtx, "0.1 KB", (int)sizeof("0.1 KB")-1);
		return LIBCOX_OK;
	}
	for(;;){
		nRest = (sxi32)(iSize & 0x3FF); 
		iSize >>= 10;
		c++;
		if( (iSize & (~0 ^ 1023)) == 0 ){
			break;
		}
	}
	nRest /= 100;
	if( nRest > 9 ){
		nRest = 9;
	}
	if( iSize > 999 ){
		c++;
		nRest = 9;
		iSize = 0;
	}
	i_32 = (sxi32)iSize;
	/* Format */
	libcox_result_string_format(pCtx, "%d.%d %cB", i_32, nRest, zUnit[c]);
	return LIBCOX_OK;
}
/*
 * Date/Time functions
 * Authors:
 *    Symisc Systems, devel@symisc.net.
 *    Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Devel.
 */
#include <time.h>
#ifdef __WINNT__
/* GetSystemTime() */
#include <Windows.h> 
#ifdef _WIN32_WCE
/*
** WindowsCE does not have a localtime() function.  So create a
** substitute.
** Taken from the SQLite3 source tree.
** Status: Public domain
*/
struct tm *__cdecl localtime(const time_t *t)
{
  static struct tm y;
  FILETIME uTm, lTm;
  SYSTEMTIME pTm;
  libcox_int64 t64;
  t64 = *t;
  t64 = (t64 + 11644473600)*10000000;
  uTm.dwLowDateTime = (DWORD)(t64 & 0xFFFFFFFF);
  uTm.dwHighDateTime= (DWORD)(t64 >> 32);
  FileTimeToLocalFileTime(&uTm, &lTm);
  FileTimeToSystemTime(&lTm, &pTm);
  y.tm_year = pTm.wYear - 1900;
  y.tm_mon = pTm.wMonth - 1;
  y.tm_wday = pTm.wDayOfWeek;
  y.tm_mday = pTm.wDay;
  y.tm_hour = pTm.wHour;
  y.tm_min = pTm.wMinute;
  y.tm_sec = pTm.wSecond;
  return &y;
}
#endif /*_WIN32_WCE */
#elif defined(__UNIXES__)
#include <sys/time.h>
#endif /* __WINNT__*/
 /*
  * int64 time(void)
  *  Current Unix timestamp
  * Parameters
  *  None.
  * Return
  *  Returns the current time measured in the number of seconds
  *  since the Unix Epoch (January 1 1970 00:00:00 GMT).
  */
static int libcoxCmd_time(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	time_t tt;
	SXUNUSED(nArg); /* cc warning */
	SXUNUSED(apArg);
	/* Extract the current time */
	time(&tt);
	/* Return as 64-bit integer */
	libcox_result_int64(pCtx, (libcox_int64)tt);
	return  LIBCOX_OK;
}
/*
  * string/float microtime([ bool $get_as_float = false ])
  *  microtime() returns the current Unix timestamp with microseconds.
  * Parameters
  *  $get_as_float
  *   If used and set to TRUE, microtime() will return a float instead of a string
  *   as described in the return values section below.
  * Return
  *  By default, microtime() returns a string in the form "msec sec", where sec 
  *  is the current time measured in the number of seconds since the Unix 
  *  epoch (0:00:00 January 1, 1970 GMT), and msec is the number of microseconds
  *  that have elapsed since sec expressed in seconds.
  *  If get_as_float is set to TRUE, then microtime() returns a float, which represents
  *  the current time in seconds since the Unix epoch accurate to the nearest microsecond. 
  */
static int libcoxCmd_microtime(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int bFloat = 0;
	sytime sTime;	
#if defined(__UNIXES__)
	struct timeval tv;
	gettimeofday(&tv, 0);
	sTime.tm_sec  = (long)tv.tv_sec;
	sTime.tm_usec = (long)tv.tv_usec;
#else
	time_t tt;
	time(&tt);
	sTime.tm_sec  = (long)tt;
	sTime.tm_usec = (long)(tt%SX_USEC_PER_SEC);
#endif /* __UNIXES__ */
	if( nArg > 0 ){
		bFloat = libcox_value_to_bool(apArg[0]);
	}
	if( bFloat ){
		/* Return as float */
		libcox_result_double(pCtx, (double)sTime.tm_sec);
	}else{
		/* Return as string */
		libcox_result_string_format(pCtx, "%ld %ld", sTime.tm_usec, sTime.tm_sec);
	}
	return LIBCOX_OK;
}
/*
 * array getdate ([ int $timestamp = time() ])
 *  Get date/time information.
 * Parameter
 *  $timestamp: The optional timestamp parameter is an integer Unix timestamp
 *     that defaults to the current local time if a timestamp is not given.
 *     In other words, it defaults to the value of time().
 * Returns
 *  Returns an associative array of information related to the timestamp.
 *  Elements from the returned associative array are as follows: 
 *   KEY                                                         VALUE
 * ---------                                                    -------
 * "seconds" 	Numeric representation of seconds 	            0 to 59
 * "minutes" 	Numeric representation of minutes 	            0 to 59
 * "hours" 	    Numeric representation of hours 	            0 to 23
 * "mday" 	    Numeric representation of the day of the month 	1 to 31
 * "wday" 	    Numeric representation of the day of the week 	0 (for Sunday) through 6 (for Saturday)
 * "mon" 	    Numeric representation of a month 	            1 through 12
 * "year" 	    A full numeric representation of a year,        4 digits 	Examples: 1999 or 2003
 * "yday" 	    Numeric representation of the day of the year   0 through 365
 * "weekday" 	A full textual representation of the day of the week 	Sunday through Saturday
 * "month" 	    A full textual representation of a month, such as January or March 	January through December
 * 0 	        Seconds since the Unix Epoch, similar to the values returned by time() and used by date(). 
 * NOTE:
 *   NULL is returned on failure.
 */
static int libcoxCmd_getdate(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	libcox_value *pValue, *pArray;
	Sytm sTm;
	if( nArg < 1 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
#ifdef __WINNT__
#ifdef _MSC_VER
#if _MSC_VER >= 1400 /* Visual Studio 2005 and up */
#pragma warning(disable:4996) /* _CRT_SECURE...*/
#endif
#endif
#endif
		if( libcox_value_is_int(apArg[0]) ){
			t = (time_t)libcox_value_to_int64(apArg[0]);
			pTm = localtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Element value */
	pValue = libcox_context_new_scalar(pCtx);
	if( pValue == 0 ){
		/* Return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Create a new array */
	pArray = libcox_context_new_array(pCtx);
	if( pArray == 0 ){
		/* Return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Fill the array */
	/* Seconds */
	libcox_value_int(pValue, sTm.tm_sec);
	libcox_array_insert_strkey_elem(pArray, "seconds", pValue);
	/* Minutes */
	libcox_value_int(pValue, sTm.tm_min);
	libcox_array_insert_strkey_elem(pArray, "minutes", pValue);
	/* Hours */
	libcox_value_int(pValue, sTm.tm_hour);
	libcox_array_insert_strkey_elem(pArray, "hours", pValue);
	/* mday */
	libcox_value_int(pValue, sTm.tm_mday);
	libcox_array_insert_strkey_elem(pArray, "mday", pValue);
	/* wday */
	libcox_value_int(pValue, sTm.tm_wday);
	libcox_array_insert_strkey_elem(pArray, "wday", pValue);
	/* mon */
	libcox_value_int(pValue, sTm.tm_mon+1);
	libcox_array_insert_strkey_elem(pArray, "mon", pValue);
	/* year */
	libcox_value_int(pValue, sTm.tm_year);
	libcox_array_insert_strkey_elem(pArray, "year", pValue);
	/* yday */
	libcox_value_int(pValue, sTm.tm_yday);
	libcox_array_insert_strkey_elem(pArray, "yday", pValue);
	/* Weekday */
	libcox_value_string(pValue, SyTimeGetDay(sTm.tm_wday), -1);
	libcox_array_insert_strkey_elem(pArray, "weekday", pValue);
	/* Month */
	libcox_value_reset_string_cursor(pValue);
	libcox_value_string(pValue, SyTimeGetMonth(sTm.tm_mon), -1);
	libcox_array_insert_strkey_elem(pArray, "month", pValue);
	/* Seconds since the epoch */
	libcox_value_int64(pValue, (libcox_int64)time(0));
	libcox_array_insert(pArray,  pValue);
	/* Return the freshly created array */
	libcox_result_value(pCtx, pArray);
	return LIBCOX_OK;
}
/*
 * mixed gettimeofday([ bool $return_float = false ] )
 *   Returns an associative array containing the data returned from the system call.
 * Parameters
 *  $return_float
 *   When set to TRUE, a float instead of an array is returned.
 * Return
 *   By default an array is returned. If return_float is set, then
 *   a float is returned. 
 */
static int libcoxCmd_gettimeofday(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int bFloat = 0;
	sytime sTime;
#if defined(__UNIXES__)
	struct timeval tv;
	gettimeofday(&tv, 0);
	sTime.tm_sec  = (long)tv.tv_sec;
	sTime.tm_usec = (long)tv.tv_usec;
#else
	time_t tt;
	time(&tt);
	sTime.tm_sec  = (long)tt;
	sTime.tm_usec = (long)(tt%SX_USEC_PER_SEC);
#endif /* __UNIXES__ */
	if( nArg > 0 ){
		bFloat = libcox_value_to_bool(apArg[0]);
	}
	if( bFloat ){
		/* Return as float */
		libcox_result_double(pCtx, (double)sTime.tm_sec);
	}else{
		/* Return an associative array */
		libcox_value *pValue, *pArray;
		/* Create a new array */
		pArray = libcox_context_new_array(pCtx);
		/* Element value */
		pValue = libcox_context_new_scalar(pCtx);
		if( pValue == 0 || pArray == 0 ){
			/* Return NULL */
			libcox_result_null(pCtx);
			return LIBCOX_OK;
		}
		/* Fill the array */
		/* sec */
		libcox_value_int64(pValue, sTime.tm_sec);
		libcox_array_insert_strkey_elem(pArray, "sec", pValue);
		/* usec */
		libcox_value_int64(pValue, sTime.tm_usec);
		libcox_array_insert_strkey_elem(pArray, "usec", pValue);
		/* Return the array */
		libcox_result_value(pCtx, pArray);
	}
	return LIBCOX_OK;
}
/* Check if the given year is leap or not */
#define IS_LEAP_YEAR(YEAR)	(YEAR % 400 ? ( YEAR % 100 ? ( YEAR % 4 ? 0 : 1 ) : 0 ) : 1)
/* ISO-8601 numeric representation of the day of the week */
static const int aISO8601[] = { 7 /* Sunday */, 1 /* Monday */, 2, 3, 4, 5, 6 };
/*
 * Format a given date string.
 * Supported format: (Taken from PHP online docs)
 * character 	Description
 * d          Day of the month 
 * D          A textual representation of a days
 * j          Day of the month without leading zeros
 * l          A full textual representation of the day of the week 	
 * N          ISO-8601 numeric representation of the day of the week 
 * w          Numeric representation of the day of the week
 * z          The day of the year (starting from 0) 	
 * F          A full textual representation of a month, such as January or March
 * m          Numeric representation of a month, with leading zeros 	01 through 12
 * M          A short textual representation of a month, three letters 	Jan through Dec
 * n          Numeric representation of a month, without leading zeros 	1 through 12
 * t          Number of days in the given month 	28 through 31
 * L          Whether it's a leap year 	1 if it is a leap year, 0 otherwise.
 * o          ISO-8601 year number. This has the same value as Y, except that if the ISO week number
 *            (W) belongs to the previous or next year, that year is used instead. (added in PHP 5.1.0) Examples: 1999 or 2003
 * Y          A full numeric representation of a year, 4 digits 	Examples: 1999 or 2003
 * y          A two digit representation of a year 	Examples: 99 or 03
 * a          Lowercase Ante meridiem and Post meridiem 	am or pm
 * A          Uppercase Ante meridiem and Post meridiem 	AM or PM
 * g          12-hour format of an hour without leading zeros 	1 through 12
 * G          24-hour format of an hour without leading zeros 	0 through 23
 * h          12-hour format of an hour with leading zeros 	01 through 12
 * H          24-hour format of an hour with leading zeros 	00 through 23
 * i          Minutes with leading zeros 	00 to 59
 * s          Seconds, with leading zeros 	00 through 59
 * u          Microseconds Example: 654321
 * e          Timezone identifier 	Examples: UTC, GMT, Atlantic/Azores
 * I          (capital i) Whether or not the date is in daylight saving time 	1 if Daylight Saving Time, 0 otherwise.
 * r          RFC 2822 formatted date 	Example: Thu, 21 Dec 2000 16:01:07 +0200
 * U          Seconds since the Unix Epoch (January 1 1970 00:00:00 GMT)
 * S          English ordinal suffix for the day of the month, 2 characters
 * O          Difference to Greenwich time (GMT) in hours
 * Z          Timezone offset in seconds. The offset for timezones west of UTC is always negative, and for those
 *            east of UTC is always positive.
 * c         ISO 8601 date
 */
static sxi32 DateFormat(libcox_context *pCtx, const char *zIn, int nLen, Sytm *pTm)
{
	const char *zEnd = &zIn[nLen];
	const char *zCur;
	/* Start the format process */
	for(;;){
		if( zIn >= zEnd ){
			/* No more input to process */
			break;
		}
		switch(zIn[0]){
		case 'd':
			/* Day of the month, 2 digits with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_mday);
			break;
		case 'D':
			/*A textual representation of a day, three letters*/
			zCur = SyTimeGetDay(pTm->tm_wday);
			libcox_result_string(pCtx, zCur, 3);
			break;
		case 'j':
			/*	Day of the month without leading zeros */
			libcox_result_string_format(pCtx, "%d", pTm->tm_mday);
			break;
		case 'l':
			/* A full textual representation of the day of the week */
			zCur = SyTimeGetDay(pTm->tm_wday);
			libcox_result_string(pCtx, zCur, -1/*Compute length automatically*/);
			break;
		case 'N':{
			/* ISO-8601 numeric representation of the day of the week */
			libcox_result_string_format(pCtx, "%d", aISO8601[pTm->tm_wday % 7 ]);
			break;
				 }
		case 'w':
			/*Numeric representation of the day of the week*/
			libcox_result_string_format(pCtx, "%d", pTm->tm_wday);
			break;
		case 'z':
			/*The day of the year*/
			libcox_result_string_format(pCtx, "%d", pTm->tm_yday);
			break;
		case 'F':
			/*A full textual representation of a month, such as January or March*/
			zCur = SyTimeGetMonth(pTm->tm_mon);
			libcox_result_string(pCtx, zCur, -1/*Compute length automatically*/);
			break;
		case 'm':
			/*Numeric representation of a month, with leading zeros*/
			libcox_result_string_format(pCtx, "%02d", pTm->tm_mon + 1);
			break;
		case 'M':
			/*A short textual representation of a month, three letters*/
			zCur = SyTimeGetMonth(pTm->tm_mon);
			libcox_result_string(pCtx, zCur, 3);
			break;
		case 'n':
			/*Numeric representation of a month, without leading zeros*/
			libcox_result_string_format(pCtx, "%d", pTm->tm_mon + 1);
			break;
		case 't':{
			static const int aMonDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
			int nDays = aMonDays[pTm->tm_mon % 12 ];
			if( pTm->tm_mon == 1 /* 'February' */ && !IS_LEAP_YEAR(pTm->tm_year) ){
				nDays = 28;
			}
			/*Number of days in the given month*/
			libcox_result_string_format(pCtx, "%d", nDays);
			break;
				 }
		case 'L':{
			int isLeap = IS_LEAP_YEAR(pTm->tm_year);
			/* Whether it's a leap year */
			libcox_result_string_format(pCtx, "%d", isLeap);
			break;
				 }
		case 'o':
			/* ISO-8601 year number.*/
			libcox_result_string_format(pCtx, "%4d", pTm->tm_year);
			break;
		case 'Y':
			/*	A full numeric representation of a year, 4 digits */
			libcox_result_string_format(pCtx, "%4d", pTm->tm_year);
			break;
		case 'y':
			/*A two digit representation of a year*/
			libcox_result_string_format(pCtx, "%02d", pTm->tm_year%100);
			break;
		case 'a':
			/*	Lowercase Ante meridiem and Post meridiem */
			libcox_result_string(pCtx, pTm->tm_hour > 12 ? "pm" : "am", 2);
			break;
		case 'A':
			/*	Uppercase Ante meridiem and Post meridiem */
			libcox_result_string(pCtx, pTm->tm_hour > 12 ? "PM" : "AM", 2);
			break;
		case 'g':
			/*	12-hour format of an hour without leading zeros*/
			libcox_result_string_format(pCtx, "%d", 1+(pTm->tm_hour%12));
			break;
		case 'G':
			/* 24-hour format of an hour without leading zeros */
			libcox_result_string_format(pCtx, "%d", pTm->tm_hour);
			break;
		case 'h':
			/* 12-hour format of an hour with leading zeros */
			libcox_result_string_format(pCtx, "%02d", 1+(pTm->tm_hour%12));
			break;
		case 'H':
			/*	24-hour format of an hour with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_hour);
			break;
		case 'i':
			/* 	Minutes with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_min);
			break;
		case 's':
			/* 	second with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_sec);
			break;
		case 'u':
			/* 	Microseconds */
			libcox_result_string_format(pCtx, "%u", pTm->tm_sec * SX_USEC_PER_SEC);
			break;
		case 'S':{
			/* English ordinal suffix for the day of the month, 2 characters */
			static const char zSuffix[] = "thstndrdthththththth";
			int v = pTm->tm_mday;
			libcox_result_string(pCtx, &zSuffix[2 * (int)(v / 10 % 10 != 1 ? v % 10 : 0)], (int)sizeof(char) * 2);
			break;
				 }
		case 'e':
			/* 	Timezone identifier */
			zCur = pTm->tm_zone;
			if( zCur == 0 ){
				/* Assume GMT */
				zCur = "GMT";
			}
			libcox_result_string(pCtx, zCur, -1);
			break;
		case 'I':
			/* Whether or not the date is in daylight saving time */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
			_get_daylight(&pTm->tm_isdst);
#endif
#endif
#endif
			libcox_result_string_format(pCtx, "%d", pTm->tm_isdst == 1);
			break;
		case 'r':
			/* RFC 2822 formatted date 	Example: Thu, 21 Dec 2000 16:01:07 */
			libcox_result_string_format(pCtx, "%.3s, %02d %.3s %4d %02d:%02d:%02d", 
				SyTimeGetDay(pTm->tm_wday), 
				pTm->tm_mday, 
				SyTimeGetMonth(pTm->tm_mon), 
				pTm->tm_year, 
				pTm->tm_hour, 
				pTm->tm_min, 
				pTm->tm_sec
				);
			break;
		case 'U':{
			time_t tt;
			/* Seconds since the Unix Epoch */
			time(&tt);
			libcox_result_string_format(pCtx, "%u", (unsigned int)tt);
			break;
				 }
		case 'O':
		case 'P':
			/* Difference to Greenwich time (GMT) in hours */
			libcox_result_string_format(pCtx, "%+05d", pTm->tm_gmtoff);
			break;
		case 'Z':
			/* Timezone offset in seconds. The offset for timezones west of UTC
			 * is always negative, and for those east of UTC is always positive.
			 */
			libcox_result_string_format(pCtx, "%+05d", pTm->tm_gmtoff);
			break;
		case 'c':
			/* 	ISO 8601 date */
			libcox_result_string_format(pCtx, "%4d-%02d-%02dT%02d:%02d:%02d%+05d", 
				pTm->tm_year, 
				pTm->tm_mon+1, 
				pTm->tm_mday, 
				pTm->tm_hour, 
				pTm->tm_min, 
				pTm->tm_sec, 
				pTm->tm_gmtoff
				);
			break;
		case '\\':
			zIn++;
			/* Expand verbatim */
			if( zIn < zEnd ){
				libcox_result_string(pCtx, zIn, (int)sizeof(char));
			}
			break;
		default:
			/* Unknown format specifer, expand verbatim */
			libcox_result_string(pCtx, zIn, (int)sizeof(char));
			break;
		}
		/* Point to the next character */
		zIn++;
	}
	return SXRET_OK;
}
/*
 * PH7 implementation of the strftime() function.
 * The following formats are supported:
 * %a 	An abbreviated textual representation of the day
 * %A 	A full textual representation of the day
 * %d 	Two-digit day of the month (with leading zeros)
 * %e 	Day of the month, with a space preceding single digits.
 * %j 	Day of the year, 3 digits with leading zeros 
 * %u 	ISO-8601 numeric representation of the day of the week 	1 (for Monday) though 7 (for Sunday)
 * %w 	Numeric representation of the day of the week 0 (for Sunday) through 6 (for Saturday)
 * %U 	Week number of the given year, starting with the first Sunday as the first week
 * %V 	ISO-8601:1988 week number of the given year, starting with the first week of the year with at least
 *   4 weekdays, with Monday being the start of the week.
 * %W 	A numeric representation of the week of the year
 * %b 	Abbreviated month name, based on the locale
 * %B 	Full month name, based on the locale
 * %h 	Abbreviated month name, based on the locale (an alias of %b)
 * %m 	Two digit representation of the month
 * %C 	Two digit representation of the century (year divided by 100, truncated to an integer)
 * %g 	Two digit representation of the year going by ISO-8601:1988 standards (see %V)
 * %G 	The full four-digit version of %g
 * %y 	Two digit representation of the year
 * %Y 	Four digit representation for the year
 * %H 	Two digit representation of the hour in 24-hour format
 * %I 	Two digit representation of the hour in 12-hour format
 * %l (lower-case 'L') 	Hour in 12-hour format, with a space preceeding single digits
 * %M 	Two digit representation of the minute
 * %p 	UPPER-CASE 'AM' or 'PM' based on the given time
 * %P 	lower-case 'am' or 'pm' based on the given time
 * %r 	Same as "%I:%M:%S %p"
 * %R 	Same as "%H:%M"
 * %S 	Two digit representation of the second
 * %T 	Same as "%H:%M:%S"
 * %X 	Preferred time representation based on locale, without the date
 * %z 	Either the time zone offset from UTC or the abbreviation
 * %Z 	The time zone offset/abbreviation option NOT given by %z
 * %c 	Preferred date and time stamp based on local
 * %D 	Same as "%m/%d/%y"
 * %F 	Same as "%Y-%m-%d"
 * %s 	Unix Epoch Time timestamp (same as the time() function)
 * %x 	Preferred date representation based on locale, without the time
 * %n 	A newline character ("\n")
 * %t 	A Tab character ("\t")
 * %% 	A literal percentage character ("%")
 */
static int PH7_Strftime(
	libcox_context *pCtx,  /* Call context */
	const char *zIn,    /* Input string */
	int nLen,           /* Input length */
	Sytm *pTm           /* Parse of the given time */
	)
{
	const char *zCur, *zEnd = &zIn[nLen];
	int c;
	/* Start the format process */
	for(;;){
		zCur = zIn;
		while(zIn < zEnd && zIn[0] != '%' ){
			zIn++;
		}
		if( zIn > zCur ){
			/* Consume input verbatim */
			libcox_result_string(pCtx, zCur, (int)(zIn-zCur));
		}
		zIn++; /* Jump the percent sign */
		if( zIn >= zEnd ){
			/* No more input to process */
			break;
		}
		c = zIn[0];
		/* Act according to the current specifer */
		switch(c){
		case '%':
			/* A literal percentage character ("%") */
			libcox_result_string(pCtx, "%", (int)sizeof(char));
			break;
		case 't':
			/* A Tab character */
			libcox_result_string(pCtx, "\t", (int)sizeof(char));
			break;
		case 'n':
			/* A newline character */
			libcox_result_string(pCtx, "\n", (int)sizeof(char));
			break;
		case 'a':
			/* An abbreviated textual representation of the day */
			libcox_result_string(pCtx, SyTimeGetDay(pTm->tm_wday), (int)sizeof(char)*3);
			break;
		case 'A':
			/* A full textual representation of the day */
			libcox_result_string(pCtx, SyTimeGetDay(pTm->tm_wday), -1/*Compute length automatically*/);
			break;
		case 'e':
			/* Day of the month, 2 digits with leading space for single digit*/
			libcox_result_string_format(pCtx, "%2d", pTm->tm_mday);
			break;
		case 'd':
			/* Two-digit day of the month (with leading zeros) */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_mon+1);
			break;
		case 'j':
			/*The day of the year, 3 digits with leading zeros*/
			libcox_result_string_format(pCtx, "%03d", pTm->tm_yday);
			break;
		case 'u':
			/* ISO-8601 numeric representation of the day of the week */
			libcox_result_string_format(pCtx, "%d", aISO8601[pTm->tm_wday % 7 ]);
			break;
		case 'w':
			/* Numeric representation of the day of the week */
			libcox_result_string_format(pCtx, "%d", pTm->tm_wday);
			break;
		case 'b':
		case 'h':
			/*A short textual representation of a month, three letters (Not based on locale)*/
			libcox_result_string(pCtx, SyTimeGetMonth(pTm->tm_mon), (int)sizeof(char)*3);
			break;
		case 'B':
			/* Full month name (Not based on locale) */
			libcox_result_string(pCtx, SyTimeGetMonth(pTm->tm_mon), -1/*Compute length automatically*/);
			break;
		case 'm':
			/*Numeric representation of a month, with leading zeros*/
			libcox_result_string_format(pCtx, "%02d", pTm->tm_mon + 1);
			break;
		case 'C':
			/* Two digit representation of the century */
			libcox_result_string_format(pCtx, "%2d", pTm->tm_year/100);
			break;
		case 'y':
		case 'g':
			/* Two digit representation of the year */
			libcox_result_string_format(pCtx, "%2d", pTm->tm_year%100);
			break;
		case 'Y':
		case 'G':
			/* Four digit representation of the year */
			libcox_result_string_format(pCtx, "%4d", pTm->tm_year);
			break;
		case 'I':
			/* 12-hour format of an hour with leading zeros */
			libcox_result_string_format(pCtx, "%02d", 1+(pTm->tm_hour%12));
			break;
		case 'l':
			/* 12-hour format of an hour with leading space */
			libcox_result_string_format(pCtx, "%2d", 1+(pTm->tm_hour%12));
			break;
		case 'H':
			/* 24-hour format of an hour with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_hour);
			break;
		case 'M':
			/* Minutes with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_min);
			break;
		case 'S':
			/* Seconds with leading zeros */
			libcox_result_string_format(pCtx, "%02d", pTm->tm_sec);
			break;
		case 'z':
		case 'Z':
			/* 	Timezone identifier */
			zCur = pTm->tm_zone;
			if( zCur == 0 ){
				/* Assume GMT */
				zCur = "GMT";
			}
			libcox_result_string(pCtx, zCur, -1);
			break;
		case 'T':
		case 'X':
			/* Same as "%H:%M:%S" */
			libcox_result_string_format(pCtx, "%02d:%02d:%02d", pTm->tm_hour, pTm->tm_min, pTm->tm_sec);
			break;
		case 'R':
			/* Same as "%H:%M" */
			libcox_result_string_format(pCtx, "%02d:%02d", pTm->tm_hour, pTm->tm_min);
			break;
		case 'P':
			/*	Lowercase Ante meridiem and Post meridiem */
			libcox_result_string(pCtx, pTm->tm_hour > 12 ? "pm" : "am", (int)sizeof(char)*2);
			break;
		case 'p':
			/*	Uppercase Ante meridiem and Post meridiem */
			libcox_result_string(pCtx, pTm->tm_hour > 12 ? "PM" : "AM", (int)sizeof(char)*2);
			break;
		case 'r':
			/* Same as "%I:%M:%S %p" */
			libcox_result_string_format(pCtx, "%02d:%02d:%02d %s", 
				1+(pTm->tm_hour%12), 
				pTm->tm_min, 
				pTm->tm_sec, 
				pTm->tm_hour > 12 ? "PM" : "AM"
				);
			break;
		case 'D':
		case 'x':
			/* Same as "%m/%d/%y" */
			libcox_result_string_format(pCtx, "%02d/%02d/%02d", 
				pTm->tm_mon+1, 
				pTm->tm_mday, 
				pTm->tm_year%100
				);
			break;
		case 'F':
			/* Same as "%Y-%m-%d" */
			libcox_result_string_format(pCtx, "%d-%02d-%02d", 
				pTm->tm_year, 
				pTm->tm_mon+1, 
				pTm->tm_mday
				);
			break;
		case 'c':
			libcox_result_string_format(pCtx, "%d-%02d-%02d %02d:%02d:%02d", 
				pTm->tm_year, 
				pTm->tm_mon+1, 
				pTm->tm_mday, 
				pTm->tm_hour, 
				pTm->tm_min, 
				pTm->tm_sec
				);
			break;
		case 's':{
			time_t tt;
			/* Seconds since the Unix Epoch */
			time(&tt);
			libcox_result_string_format(pCtx, "%u", (unsigned int)tt);
			break;
				 }
		default:
			/* unknown specifer, simply ignore*/
			break;
		}
		/* Advance the cursor */
		zIn++;
	}
	return SXRET_OK;
}
/*
 * string date(string $format [, int $timestamp = time() ] )
 *  Returns a string formatted according to the given format string using
 *  the given integer timestamp or the current time if no timestamp is given.
 *  In other words, timestamp is optional and defaults to the value of time(). 
 * Parameters
 *  $format
 *   The format of the outputted date string (See code above)
 * $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time(). 
 * Return
 *  A formatted date string. If a non-numeric value is used for timestamp, FALSE is returned.
 */
static int libcoxCmd_date(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zFormat;
	int nLen = 0;
	Sytm sTm;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* RFC */
		zFormat = "c";
		nLen = sizeof("c") - 1;
	}else{
		zFormat = libcox_value_to_string(apArg[0], &nLen);
		if( nLen < 1 ){
			/* RFC */
			zFormat = "c";
			nLen = sizeof("c") - 1;
		}
	}
	if( nArg < 2 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if( libcox_value_is_int(apArg[1]) ){
			t = (time_t)libcox_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	DateFormat(pCtx, zFormat, nLen, &sTm);
	return LIBCOX_OK;
}
/*
 * string strftime(string $format [, int $timestamp = time() ] )
 *  Format a local time/date (PLATFORM INDEPENDENT IMPLEMENTATION  NOT BASED ON LOCALE)
 * Parameters
 *  $format
 *   The format of the outputted date string (See code above)
 * $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time(). 
 * Return
 * Returns a string formatted according format using the given timestamp
 * or the current local time if no timestamp is given.
 */
static int libcoxCmd_strftime(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zFormat;
	int nLen;
	Sytm sTm;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	zFormat = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Don't bother processing return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	if( nArg < 2 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if( libcox_value_is_int(apArg[1]) ){
			t = (time_t)libcox_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	PH7_Strftime(pCtx, zFormat, nLen, &sTm);

	return LIBCOX_OK;
}
/*
 * string gmdate(string $format [, int $timestamp = time() ] )
 *  Identical to the date() function except that the time returned
 *  is Greenwich Mean Time (GMT).
 * Parameters
 *  $format
 *  The format of the outputted date string (See code above)
 *  $timestamp
 *   The optional timestamp parameter is an integer Unix timestamp
 *   that defaults to the current local time if a timestamp is not given.
 *   In other words, it defaults to the value of time(). 
 * Return
 *  A formatted date string. If a non-numeric value is used for timestamp, FALSE is returned.
 */
static int libcoxCmd_gmdate(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zFormat;
	int nLen;
	Sytm sTm;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	zFormat = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Don't bother processing return the empty string */
		libcox_result_string(pCtx, "", 0);
		return LIBCOX_OK;
	}
	if( nArg < 2 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = gmtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if( libcox_value_is_int(apArg[1]) ){
			t = (time_t)libcox_value_to_int64(apArg[1]);
			pTm = gmtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = gmtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Format the given string */
	DateFormat(pCtx, zFormat, nLen, &sTm);
	return LIBCOX_OK;
}
/*
 * array localtime([ int $timestamp = time() [, bool $is_associative = false ]])
 *  Return the local time.
 * Parameter
 *  $timestamp: The optional timestamp parameter is an integer Unix timestamp
 *     that defaults to the current local time if a timestamp is not given.
 *     In other words, it defaults to the value of time().
 * $is_associative
 *   If set to FALSE or not supplied then the array is returned as a regular, numerically
 *   indexed array. If the argument is set to TRUE then localtime() returns an associative
 *   array containing all the different elements of the structure returned by the C function
 *   call to localtime. The names of the different keys of the associative array are as follows:
 *      "tm_sec" - seconds, 0 to 59
 *      "tm_min" - minutes, 0 to 59
 *      "tm_hour" - hours, 0 to 23
 *      "tm_mday" - day of the month, 1 to 31
 *      "tm_mon" - month of the year, 0 (Jan) to 11 (Dec)
 *      "tm_year" - years since 1900
 *      "tm_wday" - day of the week, 0 (Sun) to 6 (Sat)
 *      "tm_yday" - day of the year, 0 to 365
 *      "tm_isdst" - is daylight savings time in effect? Positive if yes, 0 if not, negative if unknown.
 * Returns
 *  An associative array of information related to the timestamp.
 */
static int libcoxCmd_localtime(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	libcox_value *pValue, *pArray;
	int isAssoc = 0;
	Sytm sTm;
	if( nArg < 1 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS); /* TODO(chems): GMT not local */
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if( libcox_value_is_int(apArg[0]) ){
			t = (time_t)libcox_value_to_int64(apArg[0]);
			pTm = localtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Element value */
	pValue = libcox_context_new_scalar(pCtx);
	if( pValue == 0 ){
		/* Return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	/* Create a new array */
	pArray = libcox_context_new_array(pCtx);
	if( pArray == 0 ){
		/* Return NULL */
		libcox_result_null(pCtx);
		return LIBCOX_OK;
	}
	if( nArg > 1 ){
		isAssoc = libcox_value_to_bool(apArg[1]); 
	}
	/* Fill the array */
	/* Seconds */
	libcox_value_int(pValue, sTm.tm_sec);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_sec", pValue);
	}else{
		libcox_array_insert(pArray,  pValue); /* tm_sec */
	}
	/* Minutes */
	libcox_value_int(pValue, sTm.tm_min);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_min", pValue);
	}else{
		libcox_array_insert(pArray,  pValue);
	}
	/* Hours */
	libcox_value_int(pValue, sTm.tm_hour);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_hour", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* mday */
	libcox_value_int(pValue, sTm.tm_mday);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_mday", pValue);
	}else{
		libcox_array_insert(pArray,  pValue);
	}
	/* mon */
	libcox_value_int(pValue, sTm.tm_mon);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_mon", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* year since 1900 */
	libcox_value_int(pValue, sTm.tm_year-1900);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_year", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* wday */
	libcox_value_int(pValue, sTm.tm_wday);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_wday", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* yday */
	libcox_value_int(pValue, sTm.tm_yday);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_yday", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* isdst */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
			_get_daylight(&sTm.tm_isdst);
#endif
#endif
#endif
	libcox_value_int(pValue, sTm.tm_isdst);
	if( isAssoc ){
		libcox_array_insert_strkey_elem(pArray, "tm_isdst", pValue);
	}else{
		libcox_array_insert(pArray, pValue);
	}
	/* Return the array */
	libcox_result_value(pCtx, pArray);
	return LIBCOX_OK;
}
/*
 * int idate(string $format [, int $timestamp = time() ])
 *  Returns a number formatted according to the given format string
 *  using the given integer timestamp or the current local time if 
 *  no timestamp is given. In other words, timestamp is optional and defaults
 *  to the value of time().
 *  Unlike the function date(), idate() accepts just one char in the format
 *  parameter.
 * $Parameters
 *  Supported format
 *   d 	Day of the month
 *   h 	Hour (12 hour format)
 *   H 	Hour (24 hour format)
 *   i 	Minutes
 *   I (uppercase i)1 if DST is activated, 0 otherwise
 *   L (uppercase l) returns 1 for leap year, 0 otherwise
 *   m 	Month number
 *   s 	Seconds
 *   t 	Days in current month
 *   U 	Seconds since the Unix Epoch - January 1 1970 00:00:00 UTC - this is the same as time()
 *   w 	Day of the week (0 on Sunday)
 *   W 	ISO-8601 week number of year, weeks starting on Monday
 *   y 	Year (1 or 2 digits - check note below)
 *   Y 	Year (4 digits)
 *   z 	Day of the year
 *   Z 	Timezone offset in seconds
 * $timestamp
 *  The optional timestamp parameter is an integer Unix timestamp that defaults
 *  to the current local time if a timestamp is not given. In other words, it defaults
 *  to the value of time(). 
 * Return
 *  An integer. 
 */
static int libcoxCmd_idate(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zFormat;
	libcox_int64 iVal = 0;
	int nLen;
	Sytm sTm;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return -1 */
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	zFormat = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Don't bother processing return -1*/
		libcox_result_int(pCtx, -1);
		return LIBCOX_OK;
	}
	if( nArg < 2 ){
#ifdef __WINNT__
		SYSTEMTIME sOS;
		GetSystemTime(&sOS);
		SYSTEMTIME_TO_SYTM(&sOS, &sTm);
#else
		struct tm *pTm;
		time_t t;
		time(&t);
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
#endif
	}else{
		/* Use the given timestamp */
		time_t t;
		struct tm *pTm;
		if( libcox_value_is_int(apArg[1]) ){
			t = (time_t)libcox_value_to_int64(apArg[1]);
			pTm = localtime(&t);
			if( pTm == 0 ){
				time(&t);
			}
		}else{
			time(&t);
		}
		pTm = localtime(&t);
		STRUCT_TM_TO_SYTM(pTm, &sTm);
	}
	/* Perform the requested operation */
	switch(zFormat[0]){
	case 'd':
		/* Day of the month */
		iVal = sTm.tm_mday;
		break;
	case 'h':
		/*	Hour (12 hour format)*/
		iVal = 1 + (sTm.tm_hour % 12);
		break;
	case 'H':
		/* Hour (24 hour format)*/
		iVal = sTm.tm_hour;
		break;
	case 'i':
		/*Minutes*/
		iVal = sTm.tm_min;
		break;
	case 'I':
		/*	returns 1 if DST is activated, 0 otherwise */
#ifdef __WINNT__
#ifdef _MSC_VER
#ifndef _WIN32_WCE
			_get_daylight(&sTm.tm_isdst);
#endif
#endif
#endif
		iVal = sTm.tm_isdst;
		break;
	case 'L':
		/* 	returns 1 for leap year, 0 otherwise */
		iVal = IS_LEAP_YEAR(sTm.tm_year);
		break;
	case 'm':
		/* Month number*/
		iVal = sTm.tm_mon;
		break;
	case 's':
		/*Seconds*/
		iVal = sTm.tm_sec;
		break;
	case 't':{
		/*Days in current month*/
		static const int aMonDays[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
		int nDays = aMonDays[sTm.tm_mon % 12 ];
		if( sTm.tm_mon == 1 /* 'February' */ && !IS_LEAP_YEAR(sTm.tm_year) ){
			nDays = 28;
		}
		iVal = nDays;
		break;
			 }
	case 'U':
		/*Seconds since the Unix Epoch*/
		iVal = (libcox_int64)time(0);
		break;
	case 'w':
		/*	Day of the week (0 on Sunday) */
		iVal = sTm.tm_wday;
		break;
	case 'W': {
		/* ISO-8601 week number of year, weeks starting on Monday */
		static const int aISO8601[] = { 7 /* Sunday */, 1 /* Monday */, 2, 3, 4, 5, 6 };
		iVal = aISO8601[sTm.tm_wday % 7 ];
		break;
			  }
	case 'y':
		/* Year (2 digits) */
		iVal = sTm.tm_year % 100;
		break;
	case 'Y':
		/* Year (4 digits) */
		iVal = sTm.tm_year;
		break;
	case 'z':
		/* Day of the year */
		iVal = sTm.tm_yday;
		break;
	case 'Z':
		/*Timezone offset in seconds*/
		iVal = sTm.tm_gmtoff;
		break;
	default:
		/* unknown format, throw a warning */
		libcox_context_throw_error(pCtx, LIBCOX_CTX_WARNING, "Unknown date format token");
		break;
	}
	/* Return the time value */
	libcox_result_int64(pCtx, iVal);
	return LIBCOX_OK;
}
/*
 * int mktime/gmmktime([ int $hour = date("H") [, int $minute = date("i") [, int $second = date("s") 
 *  [, int $month = date("n") [, int $day = date("j") [, int $year = date("Y") [, int $is_dst = -1 ]]]]]]] )
 *  Returns the Unix timestamp corresponding to the arguments given. This timestamp is a 64bit integer 
 *  containing the number of seconds between the Unix Epoch (January 1 1970 00:00:00 GMT) and the time
 *  specified.
 *  Arguments may be left out in order from right to left; any arguments thus omitted will be set to
 *  the current value according to the local date and time.
 * Parameters
 * $hour
 *  The number of the hour relevant to the start of the day determined by month, day and year.
 *  Negative values reference the hour before midnight of the day in question. Values greater
 *  than 23 reference the appropriate hour in the following day(s).
 * $minute
 *  The number of the minute relevant to the start of the hour. Negative values reference
 *  the minute in the previous hour. Values greater than 59 reference the appropriate minute
 *  in the following hour(s).
 * $second
 *  The number of seconds relevant to the start of the minute. Negative values reference 
 *  the second in the previous minute. Values greater than 59 reference the appropriate 
 * second in the following minute(s).
 * $month
 *  The number of the month relevant to the end of the previous year. Values 1 to 12 reference
 *  the normal calendar months of the year in question. Values less than 1 (including negative values)
 *  reference the months in the previous year in reverse order, so 0 is December, -1 is November)...
 * $day
 *  The number of the day relevant to the end of the previous month. Values 1 to 28, 29, 30 or 31 
 *  (depending upon the month) reference the normal days in the relevant month. Values less than 1
 *  (including negative values) reference the days in the previous month, so 0 is the last day 
 *  of the previous month, -1 is the day before that, etc. Values greater than the number of days
 *  in the relevant month reference the appropriate day in the following month(s).
 * $year
 *  The number of the year, may be a two or four digit value, with values between 0-69 mapping
 *  to 2000-2069 and 70-100 to 1970-2000. On systems where time_t is a 32bit signed integer, as 
 *  most common today, the valid range for year is somewhere between 1901 and 2038.
 * $is_dst
 *  This parameter can be set to 1 if the time is during daylight savings time (DST), 0 if it is not, 
 *  or -1 (the default) if it is unknown whether the time is within daylight savings time or not. 
 * Return
 *   mktime() returns the Unix timestamp of the arguments given. 
 *   If the arguments are invalid, the function returns FALSE
 */
static int libcoxCmd_mktime(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	libcox_int64 iVal = 0;
	struct tm *pTm;
	time_t t;
	
	/* Get the current time */
	time(&t);
	
		/* localtime */
		pTm = localtime(&t);
	if( nArg > 0 ){
		int iVal;
		/* Hour */
		iVal = libcox_value_to_int(apArg[0]);
		pTm->tm_hour = iVal;
		if( nArg > 1 ){
			/* Minutes */
			iVal = libcox_value_to_int(apArg[1]);
			pTm->tm_min = iVal;
			if( nArg > 2 ){
				/* Seconds */
				iVal = libcox_value_to_int(apArg[2]);
				pTm->tm_sec = iVal;
				if( nArg > 3 ){
					/* Month */
					iVal = libcox_value_to_int(apArg[3]);
					pTm->tm_mon = iVal - 1;
					if( nArg > 4 ){
						/* mday */
						iVal = libcox_value_to_int(apArg[4]);
						pTm->tm_mday = iVal;
						if( nArg > 5 ){
							/* Year */
							iVal = libcox_value_to_int(apArg[5]);
							if( iVal > 1900 ){
								iVal -= 1900;
							}
							pTm->tm_year = iVal;
							if( nArg > 6 ){
								/* is_dst */
								iVal = libcox_value_to_bool(apArg[6]);
								pTm->tm_isdst = iVal;
							}
						}
					}
				}
			}
		}
	}
	/* Make the time */
	iVal = (libcox_int64)mktime(pTm);
	/* Return the timesatmp as a 64bit integer */
	libcox_result_int64(pCtx, iVal);
	return LIBCOX_OK;
}
/*
 * Section:
 *    URL handling Functions.
 * Authors:
 *    Symisc Systems, devel@symisc.net.
 *    Copyright (C) Symisc Systems, http://libcox.net
 * Status:
 *    Stable.
 */
/*
 * Output consumer callback for the standard Symisc routines.
 * [i.e: SyBase64Encode(), SyBase64Decode(), SyUriEncode(), ...].
 */
static int Consumer(const void *pData, unsigned int nLen, void *pUserData)
{
	/* Store in the call context result buffer */
	libcox_result_string((libcox_context *)pUserData, (const char *)pData, (int)nLen);
	return SXRET_OK;
}
/*
 * string base64_encode(string $data)
 * string convert_uuencode(string $data)  
 *  Encodes data with MIME base64.
 * Parameter
 *  $data
 *    Data to encode
 * Return
 *  Encoded data or FALSE on failure.
 */
static int libcoxCmd_base64_encode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the input string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Nothing to process, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the BASE64 encoding */
	SyBase64Encode(zIn, (sxu32)nLen, Consumer, pCtx);
	return LIBCOX_OK;
}
/*
 * string base64_decode(string $data)
 * string convert_uudecode(string $data)
 *  Decodes data encoded with MIME base64.
 * Parameter
 *  $data
 *    Encoded data.
 * Return
 *  Returns the original data or FALSE on failure.
 */
static int libcoxCmd_base64_decode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the input string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Nothing to process, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the BASE64 decoding */
	SyBase64Decode(zIn, (sxu32)nLen, Consumer, pCtx);
	return LIBCOX_OK;
}
/*
 * string urlencode(string $url)
 *  URL encoding
 * Parameter
 *  $url
 *   Input string.
 * Return
 *  Returns a string in which all non-alphanumeric characters except -_. have
 *  been replaced with a percent (%) sign followed by two hex digits and spaces
 *  encoded as plus (+) signs.
 */
static int libcoxCmd_urlencode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the input string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Nothing to process, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the URL encoding */
	SyUriEncode(zIn, (sxu32)nLen, Consumer, pCtx);
	return LIBCOX_OK;
}
/*
 * string urldecode(string $str)
 *  Decodes any %## encoding in the given string.
 *  Plus symbols ('+') are decoded to a space character. 
 * Parameter
 *  $data
 *    Input string.
 * Return
 *  Decoded URL or FALSE on failure.
 */
static int libcoxCmd_urldecode(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const char *zIn;
	int nLen;
	if( nArg < 1 ){
		/* Missing arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the input string */
	zIn = libcox_value_to_string(apArg[0], &nLen);
	if( nLen < 1 ){
		/* Nothing to process, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Perform the URL decoding */
	SyUriDecode(zIn, (sxu32)nLen, Consumer, pCtx, TRUE);
	return LIBCOX_OK;
}
/*
 * CMD: CMD_LIST. Refer to the official documentation for additional informations.
 */
static int libcoxCmdlist(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	libcox *pStore = (libcox *)libcox_context_user_data(pCtx);
	libcox_value *pArray,*pScalar;
	libcox_cmd *pCmd;
	sxu32 n;
	
	/* Allocate a new scalar and array */
	pScalar = libcox_context_new_scalar(pCtx);
	pArray = libcox_context_new_array(pCtx);
	if( pScalar == 0 || pArray == 0 ){
		libcox_context_throw_error(pCtx,LIBCOX_CTX_ERR,"Out of memory");
		/* return null */
		libcox_result_null(pCtx);
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		return LIBCOX_OK;
	}
	pCmd = pStore->pList;
	for( n = 0 ; n < pStore->nCmd; ++n ){
		libcox_value_reset_string_cursor(pScalar);
		/* Copy the command name */
		libcox_value_string(pScalar,SyStringData(&pCmd->sName),(int)SyStringLength(&pCmd->sName));
		/* Perform the insertion */
		libcox_array_insert(pArray,pScalar);
		/* Point to the next entry */
		pCmd = pCmd->pNext;
	}
	/* Return our array */
	libcox_result_value(pCtx,pArray);
	/* pScalar will be automatically destroyed */
	
	return LIBCOX_OK;
}
/*
 * bool mkdir(string $pathname[, int $mode = 0777 [, bool $recursive = false])
 *  Make a directory.
 * Parameters
 *  $pathname
 *   The directory path.
 * $mode
 *  The mode is 0777 by default, which means the widest possible access.
 *  Note:
 *   mode is ignored on Windows.
 *   Note that you probably want to specify the mode as an octal number, which means
 *   it should have a leading zero. The mode is also modified by the current umask
 *   which you can change using umask().
 * $recursive
 *  Allows the creation of nested directories specified in the pathname.
 *  Defaults to FALSE. (Not used)
 * Return
 *  TRUE on success or FALSE on failure.
 */
static int libcoxCmdmkdir(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	int iRecursive = 0;
	const char *zPath;
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int iMode, rc;
	if( nArg < 1 || !libcox_value_is_string(apArg[0]) ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	
	if( pVfs == 0 || pVfs->xMkdir == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Point to the desired directory */
	zPath = libcox_value_to_string(apArg[0], 0);
#ifdef __WINNT__
	iMode = 0;
#else
	/* Assume UNIX */
	iMode = 0777;
#endif
	if( nArg > 1 ){
		iMode = libcox_value_to_int(apArg[1]);
		if( nArg > 2 ){
			iRecursive = libcox_value_to_bool(apArg[2]);
		}
	}
	/* Perform the requested operation */
	rc = pVfs->xMkdir(zPath, iMode, iRecursive);
	/* IO return value */
	libcox_result_bool(pCtx, rc == LIBCOX_OK);
	return LIBCOX_OK;
}
/*
 * Command CAT/MMAP: Refer to the official documentation for additional informations.
 */
static int libcoxCmdCat(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	int i,nLen,rc;
	if( nArg < 1  ){
		/* Missing/Invalid argument, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	if( pVfs == 0 || pVfs->xMmap == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Obtain a memory view of the whole given files */
	for(i = 0 ; i < nArg ; ++i ){
		const char *zFile = libcox_value_to_string(apArg[i],&nLen);
		if( nLen > 0 ){
			void *pView = 0; /* cc warning */
			libcox_int64 nSz = 0;
			/* Read-only memory map of the whole file */
			rc = pVfs->xMmap(zFile,&pView,&nSz);
			if( rc == LIBCOX_OK && nSz > 0 ){
				/* A callback should be installed rather than a buffer to consume the whole output */
				rc = libcox_result_string(pCtx,(const char *)pView,(int)nSz/* xxx Size cast*/);
				/* Unmap the view */
				if( pVfs->xUnmap ){
					pVfs->xUnmap(pView,nSz);
				}
				if( rc != LIBCOX_OK ){ break; /* No need to continue */}
			}
		}

	}

	return LIBCOX_OK;
}
/*
 * CMD: LS. Refer to the official documentation for additional informations.
 */
static int libcoxCmdLs(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	const char *zDir = "./"; /* Use the current directory */
	void *pHandle = 0; /* cc warning */
	libcox_value *pArray,*pScalar;
	int rc;

	if( pVfs == 0 || pVfs->xOpenDir == 0 || pVfs->xDirRead == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Allocate a new scalar and array */
	pScalar = libcox_context_new_scalar(pCtx);
	pArray = libcox_context_new_array(pCtx);
	if( pScalar == 0 || pArray == 0 ){
		libcox_context_throw_error(pCtx,LIBCOX_CTX_ERR,"Out of memory");
		/* return null */
		libcox_result_null(pCtx);
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		return LIBCOX_OK;
	}
	if( nArg > 0 ){
		/* Dir name */
		zDir = libcox_value_to_string(apArg[0],0);
	}
	/* Open it */
	rc = pVfs->xOpenDir(zDir,0/*Ignore*/,&pHandle);
	if( rc != LIBCOX_OK ){
		/* Return false */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Iterate over the entry */
	while((rc = pVfs->xDirRead(pHandle,pScalar)) == LIBCOX_OK){
		/* Insert in the array if everything is ok */
		libcox_array_insert(pArray,pScalar);
		/* Reset the string cursor */
		libcox_value_reset_string_cursor(pScalar);
	}

	/* Close the target dir */
	if( pVfs->xCloseDir ){
		pVfs->xCloseDir(pHandle);
	}
	/* Return our array */
	libcox_result_value(pCtx,pArray);
	/* pScalar will be automatically destroyed */
	return LIBCOX_OK;
}
/*
 * CMD: GLOB. Refer to the official documentation for additional informations.
 */
static int libcoxCmdLsGlob(libcox_context *pCtx, int nArg, libcox_value **apArg)
{
	const libcox_vfs *pVfs = libcoxExportBuiltinVfs(); /* Built-in VFS */
	libcox_value *pArray,*pScalar;
	const char *zDir = "./"; /* Use the current directory */
	const char *zPattern;
	void *pHandle = 0; /* cc warning */
	int iEsc = '\\';
	int nLen,rc;

	
	if( nArg < 1  || !libcox_value_is_string(apArg[0])  ){
		/* Missing/Invalid arguments, return FALSE */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	if( pVfs == 0 || pVfs->xOpenDir == 0 || pVfs->xDirRead == 0 ){
		/* IO command not implemented, return NULL */
		libcox_context_throw_error_format(pCtx, LIBCOX_CTX_WARNING, 
			"IO command(%s) not implemented in the underlying VFS, LIBCOX is returning FALSE", 
			libcox_command_name(pCtx)
			);
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Extract the pattern  */
	zPattern  = libcox_value_to_string(apArg[0], &nLen);
	
	/* Allocate a new scalar and array */
	pScalar = libcox_context_new_scalar(pCtx);
	pArray = libcox_context_new_array(pCtx);
	if( pScalar == 0 || pArray == 0 ){
		libcox_context_throw_error(pCtx,LIBCOX_CTX_ERR,"Out of memory");
		/* return null */
		libcox_result_null(pCtx);
		SXUNUSED(nArg); /* cc warning */
		SXUNUSED(apArg);
		return LIBCOX_OK;
	}
	if( nArg > 1 ){
		/* Dir name */
		zDir = libcox_value_to_string(apArg[1],0);
	}
	/* Open it */
	rc = pVfs->xOpenDir(zDir,0/*Ignore*/,&pHandle);
	if( rc != LIBCOX_OK ){
		/* Return false */
		libcox_result_bool(pCtx, 0);
		return LIBCOX_OK;
	}
	/* Iterate over the entry */
	while((rc = pVfs->xDirRead(pHandle,pScalar)) == LIBCOX_OK){
		if( nLen > 0 ){
			const char *zName = libcox_value_to_string(pScalar,0);
			/* Glob */
			rc = Glob((const unsigned char *)zPattern,(const unsigned char *)zName,iEsc,0);
			if( !rc ){
				/* Ignore, Reset the string cursor */
				libcox_value_reset_string_cursor(pScalar);
				continue;
			}
		}	
		/* Insert in the array if everything is ok */
		libcox_array_insert(pArray,pScalar);
		/* Reset the string cursor */
		libcox_value_reset_string_cursor(pScalar);
	}

	/* Close the target dir */
	if( pVfs->xCloseDir ){
		pVfs->xCloseDir(pHandle);
	}
	/* Return our array */
	libcox_result_value(pCtx,pArray);
	/* pScalar will be automatically destroyed */
	return LIBCOX_OK;
}
/* TODO: SYSERROR */
/*
 * Register the built-in libcox command defined above.
 */
LIBCOX_PRIVATE int libcoxRegisterBuiltinCommands(libcox *pHandle)
{
	static const struct libcox_built_command {
		const char *zName; /* Command name */
		ProclibcoxCmd xCmd; /* Implementation of the command */
	}aCmd[] = {
		{"cd",   libcoxCmdChdir},
		{"chdir",libcoxCmdChdir},
		{"pwd",  libcoxCmdPwd},
		{"cwd",  libcoxCmdPwd},
		{"getcwd",  libcoxCmdPwd},
		{"rmdir", libcoxCmdRmDir},
		{"mkdir", libcoxCmdmkdir},
		{"echo",  libcoxCmdEcho},
		{"env",   libcoxCmdEnv},
		{"putenv", libcoxCmdSetEnv},
		{"setenv", libcoxCmdSetEnv},
		{"set_env", libcoxCmdSetEnv},
		{"rename", libcoxCmdRename},
		{"realpath",libcoxCmdRealPath},
		{"real_path", libcoxCmdRealPath},
		{"full_path", libcoxCmdRealPath},
		{"fullpath", libcoxCmdRealPath},
		{"getenv", libcoxCmdEnv},
		{"rand", libcoxCmdRandomNum},
		{"random", libcoxCmdRandomNum},
		{"pid",    libcoxCmdPid},
		{"getpid", libcoxCmdPid},
		{"username", libcoxCmdUsername},
		{"getusername", libcoxCmdUsername},
		{"uid", libcoxCmdUid},
		{"gid", libcoxCmdGid},
		{"getuid", libcoxCmdUid},
		{"getgid", libcoxCmdGid},
		{"is_dir", libcoxCmdisDir},
		{"isdir", libcoxCmdisDir},
		{"is_link", libcoxCmdisLink},
		{"islink", libcoxCmdisLink},
		{"is_lnk", libcoxCmdisLink},
		{"islnk", libcoxCmdisLink},
		{"is_file", libcoxCmdisFile},
		{"isfile", libcoxCmdisFile},
		{"is_readable", libcoxCmdisReadable},
		{"is_rd",  libcoxCmdisReadable},
		{"isrd",  libcoxCmdisReadable},
		{"is_writable", libcoxCmdisWritable},
		{"is_wr", libcoxCmdisWritable},
		{"iswr", libcoxCmdisWritable},
		{"is_executable", libcoxCmdisExecutable},
		{"is_exec", libcoxCmdisExecutable},
		{"isexec", libcoxCmdisExecutable},
		{"file_size", libcoxCmdFileSize},
		{"filesize", libcoxCmdFileSize},
		{"file_atime", libcoxCmdFileAtime},
		{"fileatime", libcoxCmdFileAtime},
		{"file_ctime", libcoxCmdFileCtime},
		{"filectime", libcoxCmdFileCtime},
		{"file_mtime", libcoxCmdFileMtime},
		{"filemtime", libcoxCmdFileMtime},
		{"file_exists", libcoxCmdFileExists},
		{"fileexists", libcoxCmdFileExists},
		{"tmp_dir",     libcoxCmdTmpDir},
		{"temp_dir",    libcoxCmdTmpDir},
		{"tmpdir",      libcoxCmdTmpDir},
		{"stat",        libcoxCmdStat},
		{"lstat",       libcoxCmdLstat},
		{"chroot",      libcoxCmdChroot},
		{"sleep",       libcoxCmdSleep},
		{"usleep",      libcoxCmdUsleep},
		{"unlink",      libcoxCmdUnlink},
		{"rm",          libcoxCmdUnlink},
		{"remove",      libcoxCmdUnlink},
		{"delete",      libcoxCmdUnlink},
		{"chmod",       libcoxCmdchmod},
		{"chown",       libcoxCmdchown},
		{"chgrp",       libcoxCmdchgrp},
		{"disk_free_space", libcoxCmd_disk_free_space},
		{"df",              libcoxCmd_disk_free_space},
		{"disk_total_space", libcoxCmd_disk_total_space},
		{"dt",               libcoxCmd_disk_total_space},
		{"filetype",    libcoxCmdfiletype},
		{"file_type",    libcoxCmdfiletype},
		{"touch",       libcoxCmdtouch},
		{"dirname",     libcoxCmddirname},
		{"basename",    libcoxCmdbasename},
		{"pathinfo",    libcoxCmdpathinfo},
		{"strglob",     libcoxCmdstrglob},
		{"fnmatch",     libcoxCmdfnmatch},
		{"link",        libcoxCmdlink},
		{"lnk",         libcoxCmdlink},
		{"symlink",     libcoxCmdsymlink},
		{"slink",       libcoxCmdsymlink},
		{"umask",       libcoxCmdumask},
		{"uname",       libcoxCmdUname},
		{"osname",      libcoxCmdUname},
		{"os",          libcoxCmdUname},
		{"round",       libcoxCmd_round},
		{"dechex",      libcoxCmd_dechex},
		{"decoct",      libcoxCmd_decoct},
		{"decbin",      libcoxCmd_decbin},
		{"hexdec",      libcoxCmd_hexdec},
		{"bindec",      libcoxCmd_bindec},
		{"octdec",      libcoxCmd_octdec},
		{"baseconvert",  libcoxCmd_base_convert},
		{"base_convert",  libcoxCmd_base_convert},
		{"substr",      libcoxCmd_substr},
		{"substr_compare", libcoxCmd_substr_compare},
		{"substr_count",   libcoxCmd_substr_count},
		{"chunk_split",    libcoxCmd_chunk_split},
		{"html_escape",    libcoxCmd_htmlspecialchars},
		{"html_decode",    libcoxCmd_htmlspecialchars_decode},
		{"strlen",         libcoxCmd_strlen},
		{"strcmp",         libcoxCmd_strcmp},
		{"strncmp",        libcoxCmd_strncmp},
		{"strcasecmp",     libcoxCmd_strcasecmp},
		{"strncasecmp",    libcoxCmd_strncasecmp},
		{"implode",        libcoxCmd_implode},
		{"explode",        libcoxCmd_explode},
		{"trim",           libcoxCmd_trim},
		{"ltrim",          libcoxCmd_ltrim},
		{"rtrim",          libcoxCmd_rtrim},
		{"strtolower",     libcoxCmd_strtolower},
		{"strtoupper",     libcoxCmd_strtoupper},
		{"bin2hex",        libcoxCmd_bin2hex},
		{"strstr",         libcoxCmd_strstr},
		{"stristr",        libcoxCmd_stristr},
		{"strpos",         libcoxCmd_strpos},
		{"stripos",        libcoxCmd_stripos},
		{"strrpos",        libcoxCmd_strrpos }, 
        {"strripos",       libcoxCmd_strripos }, 
	    {"strrchr",       libcoxCmd_strrchr    }, 
	    {"strrev",         libcoxCmd_strrev     },
		{"size_format",   libcoxCmd_size_format},
		{"urlencode", libcoxCmd_urlencode},
		{"urldecode", libcoxCmd_urldecode},
		{"base64_encode", libcoxCmd_base64_encode},
		{"base64_decode", libcoxCmd_base64_decode},
		{"mktime",        libcoxCmd_mktime},
		{"idate",         libcoxCmd_idate},
		{"localtime",     libcoxCmd_localtime},
		{"gmdate",        libcoxCmd_gmdate},
		{"strftime",      libcoxCmd_strftime},
		{"date",          libcoxCmd_date},
		{"gettimeofday",  libcoxCmd_gettimeofday},
		{"getdate",       libcoxCmd_getdate},
		{"microtime",     libcoxCmd_microtime},
		{"time",          libcoxCmd_time},
		{"CMD_LIST",      libcoxCmdlist},
		{"cat",           libcoxCmdCat},
		{"mmap",          libcoxCmdCat},
		{"ls",            libcoxCmdLs},
		{"list",          libcoxCmdLs},
		{"glob",          libcoxCmdLsGlob}/*,*/
	};
	int rc = LIBCOX_OK;
	sxu32 n;
	for( n = 0 ; n < SX_ARRAYSIZE(aCmd); ++n ){
		/* Create the command */
		rc = libcox_register_command(pHandle,aCmd[n].zName,aCmd[n].xCmd,pHandle);
		/* We'll not exit during failure */
	}
	return rc;
}
/*
 * ----------------------------------------------------------
 * File: api.c
 * MD5: 2d032822d3c6c171435213d2609a942f
 * ----------------------------------------------------------
 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       legal@symisc.net
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */ 
/* $SymiscID: api.c v2.0 FreeBSD 2012-11-08 23:07 stable <chm@symisc.net> $ */
#ifndef LIBCOX_AMALGAMATION
#include "libcoxInt.h"
#endif
/* Libcox Magic Number */
#define LIBCOX_DB_MAGIC   0xCB1EF721
/* This file implement the public interfaces presented to host-applications.
 * Routines in other files are for internal use by libcox and should not be
 * accessed by users of the library.
 */
#define LIBCOX_DB_MISUSE(DB) (DB == 0 || DB->nMagic != LIBCOX_DB_MAGIC)
/* If another thread have released a working instance, the following macros
 * evaluates to true. These macros are only used when the library
 * is built with threading support enabled.
 */
#define LIBCOX_THRD_DB_RELEASE(DB) (DB->nMagic != LIBCOX_DB_MAGIC)
/* IMPLEMENTATION: net.symisc.embedded.libcox 345-09-46 */
/*
 * All global variables are collected in the structure named "slibcoxMPGlobal".
 * That way it is clear in the code when we are using static variable because
 * its name start with slibcoxMPGlobal.
 */
static struct libcoxGlobal_Data
{
	SyMemBackend sAllocator;                /* Global low level memory allocator */
#if defined(LIBCOX_ENABLE_THREADS)
	const SyMutexMethods *pMutexMethods;   /* Mutex methods */
	SyMutex *pMutex;                       /* Global mutex */
	sxu32 nThreadingLevel;                 /* Threading level: 0 == Single threaded/1 == Multi-Threaded 
										    * The threading level can be set using the [libcox_lib_config()]
											* interface with a configuration verb set to
											* LIBCOX_LIB_CONFIG_THREAD_LEVEL_SINGLE or 
											* LIBCOX_LIB_CONFIG_THREAD_LEVEL_MULTI
											*/
#endif
	libcox_vfs *pVfs;                        /* Underlying virtual file system (Vfs) */
	sxi32 nStore;                           /* Total number of active libcox engines */
	libcox *pHandle;                          /* List of active engines */
	sxu32 nMagic;                           /* Sanity check against library misuse */
}slibcoxMPGlobal = {
	{0, 0, 0, 0, 0, 0, 0, 0, {0}}, 
#if defined(LIBCOX_ENABLE_THREADS)
	0, 
	0, 
	0, 
#endif
	0, 
	0, 
	0, 
	0
};
#define LIBCOX_LIB_MAGIC  0xEB7673FA
#define LIBCOX_LIB_MISUSE (slibcoxMPGlobal.nMagic != LIBCOX_LIB_MAGIC)
/*
 * Supported threading level.
 * These options have meaning only when the library is compiled with multi-threading
 * support. That is, the LIBCOX_ENABLE_THREADS compile time directive must be defined
 * when libcox is built.
 * LIBCOX_THREAD_LEVEL_SINGLE:
 *  In this mode, mutexing is disabled and the library can only be used by a single thread.
 * LIBCOX_THREAD_LEVEL_MULTI
 *  In this mode, all mutexes including the recursive mutexes on [libcox] objects
 *  are enabled so that the application is free to share the same engine
 *  between different threads at the same time.
 */
#define LIBCOX_THREAD_LEVEL_SINGLE 1 
#define LIBCOX_THREAD_LEVEL_MULTI  2
/*
 * Configure the libcox library.
 * Return LIBCOX_OK on success. Any other return value indicates failure.
 * Refer to [libcox_lib_config()].
 */
static sxi32 libcoxCoreConfigure(sxi32 nOp, va_list ap)
{
	int rc = LIBCOX_OK;
	switch(nOp){
	    case LIBCOX_LIB_CONFIG_VFS:{
			/* Install a virtual file system */
			libcox_vfs *pVfs = va_arg(ap,libcox_vfs *);
			if( pVfs ){
			 slibcoxMPGlobal.pVfs = pVfs;
			}
			break;
								}
		case LIBCOX_LIB_CONFIG_USER_MALLOC: {
			/* Use an alternative low-level memory allocation routines */
			const SyMemMethods *pMethods = va_arg(ap, const SyMemMethods *);
			/* Save the memory failure callback (if available) */
			ProcMemError xMemErr = slibcoxMPGlobal.sAllocator.xMemError;
			void *pMemErr = slibcoxMPGlobal.sAllocator.pUserData;
			if( pMethods == 0 ){
				/* Use the built-in memory allocation subsystem */
				rc = SyMemBackendInit(&slibcoxMPGlobal.sAllocator, xMemErr, pMemErr);
			}else{
				rc = SyMemBackendInitFromOthers(&slibcoxMPGlobal.sAllocator, pMethods, xMemErr, pMemErr);
			}
			break;
										  }
		case LIBCOX_LIB_CONFIG_MEM_ERR_CALLBACK: {
			/* Memory failure callback */
			ProcMemError xMemErr = va_arg(ap, ProcMemError);
			void *pUserData = va_arg(ap, void *);
			slibcoxMPGlobal.sAllocator.xMemError = xMemErr;
			slibcoxMPGlobal.sAllocator.pUserData = pUserData;
			break;
												 }	  
		case LIBCOX_LIB_CONFIG_USER_MUTEX: {
#if defined(LIBCOX_ENABLE_THREADS)
			/* Use an alternative low-level mutex subsystem */
			const SyMutexMethods *pMethods = va_arg(ap, const SyMutexMethods *);
#if defined (UNTRUST)
			if( pMethods == 0 ){
				rc = LIBCOX_CORRUPT;
			}
#endif
			/* Sanity check */
			if( pMethods->xEnter == 0 || pMethods->xLeave == 0 || pMethods->xNew == 0){
				/* At least three criticial callbacks xEnter(), xLeave() and xNew() must be supplied */
				rc = LIBCOX_CORRUPT;
				break;
			}
			if( slibcoxMPGlobal.pMutexMethods ){
				/* Overwrite the previous mutex subsystem */
				SyMutexRelease(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex);
				if( slibcoxMPGlobal.pMutexMethods->xGlobalRelease ){
					slibcoxMPGlobal.pMutexMethods->xGlobalRelease();
				}
				slibcoxMPGlobal.pMutex = 0;
			}
			/* Initialize and install the new mutex subsystem */
			if( pMethods->xGlobalInit ){
				rc = pMethods->xGlobalInit();
				if ( rc != LIBCOX_OK ){
					break;
				}
			}
			/* Create the global mutex */
			slibcoxMPGlobal.pMutex = pMethods->xNew(SXMUTEX_TYPE_FAST);
			if( slibcoxMPGlobal.pMutex == 0 ){
				/*
				 * If the supplied mutex subsystem is so sick that we are unable to
				 * create a single mutex, there is no much we can do here.
				 */
				if( pMethods->xGlobalRelease ){
					pMethods->xGlobalRelease();
				}
				rc = LIBCOX_CORRUPT;
				break;
			}
			slibcoxMPGlobal.pMutexMethods = pMethods;			
			if( slibcoxMPGlobal.nThreadingLevel == 0 ){
				/* Set a default threading level */
				slibcoxMPGlobal.nThreadingLevel = LIBCOX_THREAD_LEVEL_MULTI; 
			}
#endif
			break;
										   }
		case LIBCOX_LIB_CONFIG_THREAD_LEVEL_SINGLE:
#if defined(LIBCOX_ENABLE_THREADS)
			/* Single thread mode (Only one thread is allowed to play with the library) */
			slibcoxMPGlobal.nThreadingLevel = LIBCOX_THREAD_LEVEL_SINGLE;
#endif
			break;
		case LIBCOX_LIB_CONFIG_THREAD_LEVEL_MULTI:
#if defined(LIBCOX_ENABLE_THREADS)
			/* Multi-threading mode (library is thread safe and engines and virtual machines
			 * may be shared between multiple threads).
			 */
			slibcoxMPGlobal.nThreadingLevel = LIBCOX_THREAD_LEVEL_MULTI;
#endif
			break;
		default:
			/* Unknown configuration option */
			rc = LIBCOX_CORRUPT;
			break;
	}
	return rc;
}
/*
 * [CAPIREF: libcox_lib_config()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_lib_config(int nConfigOp,...)
{
	va_list ap;
	int rc;
	if( slibcoxMPGlobal.nMagic == LIBCOX_LIB_MAGIC ){
		/* Library is already initialized, this operation is forbidden */
		return LIBCOX_LOCKED;
	}
	va_start(ap,nConfigOp);
	rc = libcoxCoreConfigure(nConfigOp,ap);
	va_end(ap);
	return rc;
}
/*
 * Global library initialization
 * Refer to [libcox_lib_init()]
 * This routine must be called to initialize the memory allocation subsystem, the mutex 
 * subsystem prior to doing any serious work with the library. The first thread to call
 * this routine does the initialization process and set the magic number so no body later
 * can re-initialize the library. If subsequent threads call this  routine before the first
 * thread have finished the initialization process, then the subsequent threads must block 
 * until the initialization process is done.
 */
static sxi32 libcoxCoreInitialize(void)
{
	const libcox_vfs *pVfs; /* Built-in vfs */
#if defined(LIBCOX_ENABLE_THREADS)
	const SyMutexMethods *pMutexMethods = 0;
	SyMutex *pMaster = 0;
#endif
	int rc;
	/*
	 * If the library is already initialized, then a call to this routine
	 * is a no-op.
	 */
	if( slibcoxMPGlobal.nMagic == LIBCOX_LIB_MAGIC ){
		return LIBCOX_OK; /* Already initialized */
	}
#if defined(LIBCOX_ENABLE_THREADS)
	if( slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_SINGLE ){
		pMutexMethods = slibcoxMPGlobal.pMutexMethods;
		if( pMutexMethods == 0 ){
			/* Use the built-in mutex subsystem */
			pMutexMethods = SyMutexExportMethods();
			if( pMutexMethods == 0 ){
				return LIBCOX_CORRUPT; /* Can't happen */
			}
			/* Install the mutex subsystem */
			rc = libcox_lib_config(LIBCOX_LIB_CONFIG_USER_MUTEX, pMutexMethods);
			if( rc != LIBCOX_OK ){
				return rc;
			}
		}
		/* Obtain a static mutex so we can initialize the library without calling malloc() */
		pMaster = SyMutexNew(pMutexMethods, SXMUTEX_TYPE_STATIC_1);
		if( pMaster == 0 ){
			return LIBCOX_CORRUPT; /* Can't happen */
		}
	}
	/* Lock the master mutex */
	rc = LIBCOX_OK;
	SyMutexEnter(pMutexMethods, pMaster); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
	if( slibcoxMPGlobal.nMagic != LIBCOX_LIB_MAGIC ){
#endif
		if( slibcoxMPGlobal.sAllocator.pMethods == 0 ){
			/* Install a memory subsystem */
			rc = libcox_lib_config(LIBCOX_LIB_CONFIG_USER_MALLOC, 0); /* zero mean use the built-in memory backend */
			if( rc != LIBCOX_OK ){
				/* If we are unable to initialize the memory backend, there is no much we can do here.*/
				goto End;
			}
		}
#if defined(LIBCOX_ENABLE_THREADS)
		if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE ){
			/* Protect the memory allocation subsystem */
			rc = SyMemBackendMakeThreadSafe(&slibcoxMPGlobal.sAllocator, slibcoxMPGlobal.pMutexMethods);
			if( rc != LIBCOX_OK ){
				goto End;
			}
		}
#endif
		/* Point to the built-in vfs */
		pVfs = libcoxExportBuiltinVfs();
		if( slibcoxMPGlobal.pVfs == 0 ){
			/* Install it */
			libcox_lib_config(LIBCOX_LIB_CONFIG_VFS, pVfs);
		}
		/* Our library is initialized, set the magic number */
		slibcoxMPGlobal.nMagic = LIBCOX_LIB_MAGIC;
		rc = LIBCOX_OK;
#if defined(LIBCOX_ENABLE_THREADS)
	} /* slibcoxMPGlobal.nMagic != LIBCOX_LIB_MAGIC */
#endif
End:
#if defined(LIBCOX_ENABLE_THREADS)
	/* Unlock the master mutex */
	SyMutexLeave(pMutexMethods, pMaster); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
#endif
	return rc;
}
/*
 * Release a single instance of a libcox engine.
 */
static int libcoxEngineRelease(libcox *pHandle)
{
	int rc = LIBCOX_OK;
	/* Set a dummy magic number */
	pHandle->nMagic = 0x7250;
	/* Release the whole memory subsystem */
	SyMemBackendRelease(&pHandle->sMem);
	/* Commit or rollback result */
	return rc;
}
/*
 * Release all resources consumed by the library.
 * Note: This call is not thread safe. Refer to [libcox_lib_shutdown()].
 */
static void libcoxCoreShutdown(void)
{
	libcox *pHandle, *pNext;
	/* Release all active databases handles */
	pHandle = slibcoxMPGlobal.pHandle;
	for(;;){
		if( slibcoxMPGlobal.nStore < 1 ){
			break;
		}
		pNext = pHandle->pNext;
		libcoxEngineRelease(pHandle); 
		pHandle = pNext;
		slibcoxMPGlobal.nStore--;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	/* Release the mutex subsystem */
	if( slibcoxMPGlobal.pMutexMethods ){
		if( slibcoxMPGlobal.pMutex ){
			SyMutexRelease(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex);
			slibcoxMPGlobal.pMutex = 0;
		}
		if( slibcoxMPGlobal.pMutexMethods->xGlobalRelease ){
			slibcoxMPGlobal.pMutexMethods->xGlobalRelease();
		}
		slibcoxMPGlobal.pMutexMethods = 0;
	}
	slibcoxMPGlobal.nThreadingLevel = 0;
#endif
	if( slibcoxMPGlobal.sAllocator.pMethods ){
		/* Release the memory backend */
		SyMemBackendRelease(&slibcoxMPGlobal.sAllocator);
	}
	slibcoxMPGlobal.nMagic = 0x1764;
}
/*
 * [CAPIREF: libcox_lib_init()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_lib_init(void)
{
	int rc;
	rc = libcoxCoreInitialize();
	return rc;
}
/*
 * [CAPIREF: libcox_lib_shutdown()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_lib_shutdown(void)
{
	if( slibcoxMPGlobal.nMagic != LIBCOX_LIB_MAGIC ){
		/* Already shut */
		return LIBCOX_OK;
	}
	libcoxCoreShutdown();
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_lib_is_threadsafe()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_lib_is_threadsafe(void)
{
	if( slibcoxMPGlobal.nMagic != LIBCOX_LIB_MAGIC ){
		return 0;
	}
#if defined(LIBCOX_ENABLE_THREADS)
		if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE ){
			/* Muli-threading support is enabled */
			return 1;
		}else{
			/* Single-threading */
			return 0;
		}
#else
	return 0;
#endif
}
/*
 *
 * [CAPIREF: libcox_lib_version()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_lib_version(void)
{
	return LIBCOX_VERSION;
}
/*
 *
 * [CAPIREF: libcox_lib_signature()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_lib_signature(void)
{
	return LIBCOX_SIG;
}
/*
 *
 * [CAPIREF: libcox_lib_ident()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_lib_ident(void)
{
	return LIBCOX_IDENT;
}
/*
 *
 * [CAPIREF: libcox_lib_copyright()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_lib_copyright(void)
{
	return LIBCOX_COPYRIGHT;
}
/*
 * This routine does the work of initializing a engine on behalf
 * of [libcox_init()].
 */
static int libcoxInit(
	libcox *pHandle,            /* Database handle */
	SyMemBackend *pParent   /* Master memory backend */
	)
{
	libcox_cmd **apTable;
	/* Initialiaze the memory subsystem */
	SyMemBackendInitFromParent(&pHandle->sMem,pParent);
#if defined(LIBCOX_ENABLE_THREADS)
	/* No need for internal mutexes */
	SyMemBackendDisbaleMutexing(&pHandle->sMem);
#endif
	SyBlobInit(&pHandle->sErr,&pHandle->sMem);	
	/* Allocate the command table */
	apTable = (libcox_cmd **)SyMemBackendAlloc(&pHandle->sMem,sizeof(libcox_cmd *) * 64);
	if( apTable == 0 ){
		return LIBCOX_NOMEM;
	}
	/* Zero the table */
	SyZero((void *)apTable,sizeof(libcox_cmd *) * 64);
	pHandle->apCmd = apTable;
	pHandle->nSize = 64;
	/* Randomness */
	SyRandomnessInit(&pHandle->sRand,0,0);
	return LIBCOX_OK;
}
/*
 * Generate an error message.
 */
LIBCOX_PRIVATE int libcoxGenError(libcox *pHandle,const char *zErr)
{
	int rc;
	/* Append the error message */
	rc = SyBlobAppend(&pHandle->sErr,(const void *)zErr,SyStrlen(zErr));
	/* Append a new line */
	SyBlobAppend(&pHandle->sErr,(const void *)"\n",sizeof(char));
	return rc;
}
/*
 * Generate an error message (Printf like).
 */
LIBCOX_PRIVATE int libcoxGenErrorFormat(libcox *pHandle,const char *zFmt,...)
{
	va_list ap;
	int rc;
	va_start(ap,zFmt);
	rc = SyBlobFormatAp(&pHandle->sErr,zFmt,ap);
	va_end(ap);
	/* Append a new line */
	SyBlobAppend(&pHandle->sErr,(const void *)"\n",sizeof(char));
	return rc;
}
/*
 * Generate an error message (Out of memory).
 */
LIBCOX_PRIVATE int libcoxGenOutofMem(libcox *pHandle)
{
	int rc;
	rc = libcoxGenError(pHandle,"libcox is running out of memory");
	return rc;
}
/*
 * Configure a working libcox instance.
 */
static int libcoxConfigure(libcox *pHandle,int nOp,va_list ap)
{
	int rc = LIBCOX_OK;
	switch(nOp){
	case LIBCOX_CONFIG_ERR_LOG: {
		/* Database error log if any */
		const char **pzPtr = va_arg(ap, const char **);
		int *pLen = va_arg(ap, int *);
		if( pzPtr == 0 ){
			rc = LIBCOX_CORRUPT;
			break;
		}
		/* NULL terminate the error-log buffer */
		SyBlobNullAppend(&pHandle->sErr);
		/* Point to the error-log buffer */
		*pzPtr = (const char *)SyBlobData(&pHandle->sErr);
		if( pLen ){
			if( SyBlobLength(&pHandle->sErr) > 1 /* NULL '\0' terminator */ ){
				*pLen = (int)SyBlobLength(&pHandle->sErr);
			}else{
				*pLen = 0;
			}
		}
		SyBlobReset(&pHandle->sErr);
		break;
								 }
	case LIBCOX_CONFIG_OUTPUT_CONSUMER: {
		/* Output consumer callback */
		ProcCmdConsumer xCons = va_arg(ap,ProcCmdConsumer);
		void *pUserData = va_arg(ap,void *);
		pHandle->xResultConsumer = xCons;
		pHandle->pUserData = pUserData;
		break;
									   }
	default:
		/* Unknown configuration option */
		rc = LIBCOX_UNKNOWN;
		break;
	}
	return rc;
}
/*
 * Fetch an installed libcox command.
 */
LIBCOX_PRIVATE libcox_cmd * libcoxFetchCommand(libcox *plibcox,SyString *pName)
{
	libcox_cmd *pCmd;
	sxu32 nH;
	if( plibcox->nCmd < 1 ){
		/* Don't bother hashing */
		return 0;
	}
	/* Hash the name */
	nH = SyBinHash(pName->zString,pName->nByte);
	/* Point to the corresponding bucket */
	pCmd = plibcox->apCmd[nH & (plibcox->nSize - 1)];
	/* Perform the lookup */
	for(;;){
		if( pCmd == 0 ){
			break;
		}
		if( pCmd->nHash == nH && SyStringCmp(&pCmd->sName,pName,SyMemcmp) == 0 ){
			/* Got command */
			return pCmd;
		}
		/* Point to the next item */
		pCmd = pCmd->pNextCol;
	}
	/* No such command */
	return 0;
}
/*
 * Install a libcox command.
 */
static int libcoxInstallCommand(libcox *plibcox,const char *zName,ProclibcoxCmd xCmd,void *pUserData)
{
	SyMemBackend *pAlloc = &slibcoxMPGlobal.sAllocator;
	libcox_cmd *pCmd;
	SyString sName;
	sxu32 nBucket;
	char *zDup;
	sxu32 nLen;
	/* Check for an existing command with the same name */
	nLen = SyStrlen(zName);
	SyStringInitFromBuf(&sName,zName,nLen);
	pCmd = libcoxFetchCommand(plibcox,&sName);
	if( pCmd ){
		/* Already installed */
		pCmd->xCmd = xCmd;
		pCmd->pUserData = pUserData;
		SySetReset(&pCmd->aAux);
		return LIBCOX_OK;
	}
	/* Allocate a new instance */
	pCmd = (libcox_cmd *)SyMemBackendAlloc(pAlloc,sizeof(libcox_cmd)+nLen+1);
	if( pCmd == 0 ){
		return LIBCOX_NOMEM;
	}
	/* Zero the structure */
	SyZero(pCmd,sizeof(libcox_cmd));
	/* Fill-in */
	SySetInit(&pCmd->aAux,&plibcox->sMem,sizeof(libcox_aux_data));
	pCmd->nHash = SyBinHash(zName,nLen);
	pCmd->xCmd = xCmd;
	pCmd->pUserData = pUserData;
	zDup = (char *)&pCmd[1];
	SyMemcpy(zName,zDup,nLen);
	SyStringInitFromBuf(&pCmd->sName,zDup,nLen);
	zDup[nLen] = 0;
	/* Install the command */
	MACRO_LD_PUSH(plibcox->pList,pCmd);
	plibcox->nCmd++;
	nBucket = pCmd->nHash & (plibcox->nSize - 1);
	pCmd->pNextCol = plibcox->apCmd[nBucket];
	if( plibcox->apCmd[nBucket] ){
		plibcox->apCmd[nBucket]->pPrevCol = pCmd;
	}
	plibcox->apCmd[nBucket] = pCmd;
	if( (plibcox->nCmd >= plibcox->nSize * 3) && plibcox->nCmd < 100000 ){
		/* Rehash */
		sxu32 nNewSize = plibcox->nSize << 1;
		libcox_cmd *pEntry;
		libcox_cmd **apNew;
		sxu32 n;
		/* Allocate a new larger table */
		apNew = (libcox_cmd **)SyMemBackendAlloc(&plibcox->sMem, nNewSize * sizeof(libcox_cmd *));
		if( apNew ){
			/* Zero the new table */
			SyZero((void *)apNew, nNewSize * sizeof(libcox_cmd *));
			/* Rehash all entries */
			n = 0;
			pEntry = plibcox->pList;
			for(;;){
				/* Loop one */
				if( n >= plibcox->nCmd ){
					break;
				}
				pEntry->pNextCol = pEntry->pPrevCol = 0;
				/* Install in the new bucket */
				nBucket = pEntry->nHash & (nNewSize - 1);
				pEntry->pNextCol = apNew[nBucket];
				if( apNew[nBucket] ){
					apNew[nBucket]->pPrevCol = pEntry;
				}
				apNew[nBucket] = pEntry;
				/* Point to the next entry */
				pEntry = pEntry->pNext;
				n++;
			}
			/* Release the old table and reflect the change */
			SyMemBackendFree(&plibcox->sMem,(void *)plibcox->apCmd);
			plibcox->apCmd = apNew;
			plibcox->nSize  = nNewSize;
		}
	}
	return LIBCOX_OK;
}
/*
 * Remove a libcox command.
 */
static int libcoxRemoveCommand(libcox *plibcox,const char *zCmd)
{
	libcox_cmd *pCmd;
	SyString sName;
	SyStringInitFromBuf(&sName,zCmd,SyStrlen(zCmd));
	/* Fetch the command first */
	pCmd = libcoxFetchCommand(plibcox,&sName);
	if( pCmd == 0 ){
		/* No such command */
		return LIBCOX_NOTFOUND;
	}
	/* Unlink */
	if( pCmd->pNextCol ){
		pCmd->pNextCol->pPrevCol = pCmd->pPrevCol;
	}
	if( pCmd->pPrevCol ){
		pCmd->pPrevCol->pNextCol = pCmd->pNextCol;
	}else{
		sxu32 nBucket;
		nBucket = pCmd->nHash & (plibcox->nSize - 1);
		plibcox->apCmd[nBucket] = pCmd->pNextCol;
	}
	MACRO_LD_REMOVE(plibcox->pList,pCmd);
	plibcox->nCmd--;
	/* Release */
	SyMemBackendFree(&slibcoxMPGlobal.sAllocator,pCmd);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_init()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_init(libcox **ppHandle)
{
	libcox *pHandle;
	int rc;
#if defined(UNTRUST)
	if( ppHandle == 0 ){
		return LIBCOX_CORRUPT;
	}
#endif
	*ppHandle = 0;
	/* One-time automatic library initialization */
	rc = libcoxCoreInitialize();
	if( rc != LIBCOX_OK ){
		return rc;
	}
	/* Allocate a new engine instance */
	pHandle = (libcox *)SyMemBackendPoolAlloc(&slibcoxMPGlobal.sAllocator, sizeof(libcox));
	if( pHandle == 0 ){
		return LIBCOX_NOMEM;
	}
	/* Zero the structure */
	SyZero(pHandle,sizeof(libcox));
	/* Init the database */
	rc = libcoxInit(pHandle,&slibcoxMPGlobal.sAllocator);
	if( rc != LIBCOX_OK ){
		goto Release;
	}
	/* Set the magic number to identify a valid DB handle */
	 pHandle->nMagic = LIBCOX_DB_MAGIC;
	 /* Register built-in libcox commands */
	libcoxRegisterBuiltinCommands(pHandle);
#if defined(LIBCOX_ENABLE_THREADS)
	if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE ){
		 /* Associate a recursive mutex with this instance */
		 pHandle->pMutex = SyMutexNew(slibcoxMPGlobal.pMutexMethods, SXMUTEX_TYPE_RECURSIVE);
		 if( pHandle->pMutex == 0 ){
			 rc = LIBCOX_NOMEM;
			 goto Release;
		 }
	 }
#endif
	/* Link to the list of active engines */
#if defined(LIBCOX_ENABLE_THREADS)
	/* Enter the global mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
#endif
	 MACRO_LD_PUSH(slibcoxMPGlobal.pHandle,pHandle);
	 slibcoxMPGlobal.nStore++;
#if defined(LIBCOX_ENABLE_THREADS)
	/* Leave the global mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
#endif
	/* Make the handle available to the caller */
	*ppHandle = pHandle;
	return LIBCOX_OK;
Release:
	SyMemBackendRelease(&pHandle->sMem);
	SyMemBackendPoolFree(&slibcoxMPGlobal.sAllocator,pHandle);
	return rc;
}
/*
 * [CAPIREF: libcox_config()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_config(libcox *pHandle,int nConfigOp,...)
{
	va_list ap;
	int rc;
	if( LIBCOX_DB_MISUSE(pHandle) ){
		return LIBCOX_CORRUPT;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 va_start(ap, nConfigOp);
	 rc = libcoxConfigure(&(*pHandle),nConfigOp, ap);
	 va_end(ap);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: libcox_release()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_release(libcox *pHandle)
{
	int rc;
	if( LIBCOX_DB_MISUSE(pHandle) ){
		return LIBCOX_CORRUPT;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	/* Release the engine */
	rc = libcoxEngineRelease(pHandle);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 /* Release mutex */
	 SyMutexRelease(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex) /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
#if defined(LIBCOX_ENABLE_THREADS)
	/* Enter the global mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
#endif
	/* Unlink from the list of active engines */
	 MACRO_LD_REMOVE(slibcoxMPGlobal.pHandle, pHandle);
	slibcoxMPGlobal.nStore--;
#if defined(LIBCOX_ENABLE_THREADS)
	/* Leave the global mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods, slibcoxMPGlobal.pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel == LIBCOX_THREAD_LEVEL_SINGLE */
#endif
	/* Release the memory chunk allocated to this handle */
	SyMemBackendPoolFree(&slibcoxMPGlobal.sAllocator,pHandle);
	return rc;
}
/*
 * [CAPIREF: libcox_exec()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_exec(libcox *pHandle,libcox_value **ppOut,const char *zCmd,int nLen)
{
	int rc;
	if( LIBCOX_DB_MISUSE(pHandle) ){
		return LIBCOX_CORRUPT;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 /* Tokenize, parse and execute */
	 rc = libcoxProcessInput(pHandle,ppOut,zCmd,nLen < 0 ? /* Assume a null terminated string */ SyStrlen(zCmd) : (sxu32)nLen);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	 /* Execution result */
	return rc;
}
/*
 * [CAPIREF: libcox_exec_fmt()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_exec_fmt(libcox *pHandle,libcox_value **ppOut,const char *zFmt,...)
{
	SyBlob sWorker;
	va_list ap;
	int rc;
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 SyBlobInit(&sWorker,&pHandle->sMem);
	 va_start(ap,zFmt);
	 SyBlobFormatAp(&sWorker,zFmt,ap);
	 va_end(ap);
	 /* Execute */
	 rc = libcoxProcessInput(pHandle,ppOut,(const char *)SyBlobData(&sWorker),SyBlobLength(&sWorker));
	 /* Cleanup */
	 SyBlobRelease(&sWorker);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	 /* Execution result */
	return rc;
}
/*
 * [CAPIREF: libcox_exec_result_destroy()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_exec_result_destroy(libcox *pHandle,libcox_value *pResult)
{
	int rc = LIBCOX_OK;
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 if( pResult ){
		 libcoxObjectValueDestroy(pHandle,pResult);
	 }
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	 /* Execution result */
	return rc;
}
/*
 * [CAPIREF: libcox_register_command()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_register_command(libcox *pHandle,const char *zName,int (*xCmd)(libcox_context *,int,libcox_value **),void *pUserdata)
{
	int rc;
	if( LIBCOX_DB_MISUSE(pHandle) || xCmd == 0){
		return LIBCOX_CORRUPT;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 /* Install the command */
	 rc = libcoxInstallCommand(pHandle,zName,xCmd,pUserdata);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: libcox_delete_command()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_delete_command(libcox *pHandle,const char *zName)
{
	int rc;
	if( LIBCOX_DB_MISUSE(pHandle) ){
		return LIBCOX_CORRUPT;
	}
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Acquire mutex */
	 SyMutexEnter(slibcoxMPGlobal.pMutexMethods, pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
	 if( slibcoxMPGlobal.nThreadingLevel > LIBCOX_THREAD_LEVEL_SINGLE && 
		 LIBCOX_THRD_DB_RELEASE(pHandle) ){
			 return LIBCOX_ABORT; /* Another thread have released this instance */
	 }
#endif
	 /* Delete the command */
	 rc = libcoxRemoveCommand(pHandle,zName);
#if defined(LIBCOX_ENABLE_THREADS)
	 /* Leave mutex */
	 SyMutexLeave(slibcoxMPGlobal.pMutexMethods,pHandle->pMutex); /* NO-OP if slibcoxMPGlobal.nThreadingLevel != LIBCOX_THREAD_LEVEL_MULTI */
#endif
	return rc;
}
/*
 * [CAPIREF: libcox_context_throw_error()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_context_throw_error(libcox_context *pCtx, int iErr, const char *zErr)
{
	if( zErr ){
		SyBlob *pErr = &pCtx->plibcox->sErr;
		const char *zErrType = "-Error-";
		/* Severity */
		switch(iErr){
		case LIBCOX_CTX_WARNING: zErrType = "-Warning-"; break;
		case LIBCOX_CTX_NOTICE:  zErrType = "-Notice-";  break;
		default: break;
		}
		/* Generate the error message */
		SyBlobFormat(pErr,"%z: %s %s\n",&pCtx->pCmd->sName,zErrType,zErr);
	}
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_context_throw_error_format()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_context_throw_error_format(libcox_context *pCtx, int iErr, const char *zFormat, ...)
{
	SyBlob *pErr = &pCtx->plibcox->sErr;
	const char *zErr = "-Error-";
	va_list ap;
	
	if( zFormat == 0){
		return LIBCOX_OK;
	}
	/* Severity */
	switch(iErr){
	case LIBCOX_CTX_WARNING: zErr = "-Warning-"; break;
	case LIBCOX_CTX_NOTICE:  zErr = "-Notice-";  break;
	default: break;
	}
	/* Generate the error message */
	SyBlobFormat(pErr,"%z: %s",&pCtx->pCmd->sName,zErr);
	va_start(ap, zFormat);
	SyBlobFormatAp(pErr,zFormat,ap);
	va_end(ap);
	SyBlobAppend(pErr,(const void *)"\n",sizeof(char));
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_context_user_data()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * libcox_context_user_data(libcox_context *pCtx)
{
	return pCtx->pCmd->pUserData;
}
/*
 * [CAPIREF: libcox_context_push_aux_data()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_context_push_aux_data(libcox_context *pCtx, void *pUserData)
{
	libcox_aux_data sAux;
	int rc;
	sAux.pAuxData = pUserData;
	rc = SySetPut(&pCtx->pCmd->aAux, (const void *)&sAux);
	return rc;
}
/*
 * [CAPIREF: libcox_context_peek_aux_data()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * libcox_context_peek_aux_data(libcox_context *pCtx)
{
	libcox_aux_data *pAux;
	pAux = (libcox_aux_data *)SySetPeek(&pCtx->pCmd->aAux);
	return pAux ? pAux->pAuxData : 0;
}
/*
 * [CAPIREF: libcox_context_pop_aux_data()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void * libcox_context_pop_aux_data(libcox_context *pCtx)
{
	libcox_aux_data *pAux;
	pAux = (libcox_aux_data *)SySetPop(&pCtx->pCmd->aAux);
	return pAux ? pAux->pAuxData : 0;
}
/*
 * [CAPIREF: libcox_command_name()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_command_name(libcox_context *pCtx)
{
	return pCtx->pCmd->sName.zString;
}
/*
 * [CAPIREF: libcox_context_new_scalar()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_value * libcox_context_new_scalar(libcox_context *pCtx)
{
	libcox_value *pVal;
	pVal = libcoxNewObjectValue(pCtx->plibcox,0);
	if( pVal ){
		/* Record value address so it can be freed automatically
		 * when the calling function returns. 
		 */
		SySetPut(&pCtx->sVar, (const void *)&pVal);
	}
	return pVal;
}
/*
 * [CAPIREF: libcox_context_new_array()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_value * libcox_context_new_array(libcox_context *pCtx)
{
	libcox_value *pVal;
	pVal = libcoxNewObjectArrayValue(pCtx->plibcox);
	if( pVal ){
		/* Record value address so it can be freed automatically
		 * when the calling function returns. 
		 */
		SySetPut(&pCtx->sVar, (const void *)&pVal);
	}
	return pVal;
}
/*
 * [CAPIREF: libcox_context_release_value()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
void libcox_context_release_value(libcox_context *pCtx, libcox_value *pValue)
{
	if( pValue == 0 ){
		/* NULL value is a harmless operation */
		return;
	}
	if( SySetUsed(&pCtx->sVar) > 0 ){
		libcox_value **apObj = (libcox_value **)SySetBasePtr(&pCtx->sVar);
		sxu32 n;
		for( n = 0 ; n < SySetUsed(&pCtx->sVar) ; ++n ){
			if( apObj[n] == pValue ){
				libcoxObjectValueDestroy(pCtx->plibcox,pValue);
				/* Mark as released */
				apObj[n] = 0;
				break;
			}
		}
	}
}
/*
 * [CAPIREF: libcox_array_walk()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_array_walk(libcox_value *pArray, int (*xWalk)(libcox_value *, void *), void *pUserData)
{
	int rc;
	if( xWalk == 0 ){
		return LIBCOX_CORRUPT;
	}
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return LIBCOX_CORRUPT;
	}
	/* Start the walk process */
	rc = libcoxHashmapWalk((libcox_hashmap *)pArray->x.pOther, xWalk, pUserData);
	return rc != LIBCOX_OK ? LIBCOX_ABORT /* User callback request an operation abort*/ : LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_array_reset()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_array_reset(libcox_value *pArray)
{
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return 0;
	}
	libcoxHashmapResetLoopCursor((libcox_hashmap *)pArray->x.pOther);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_array_fetch()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_value * libcox_array_fetch(libcox_value *pArray,unsigned int index)
{
	libcox_value *pValue = 0; /* cc warning */
	libcox_hashmap *pMap;
	libcox_value skey;
	int rc;
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return 0;
	}
	pMap = (libcox_hashmap *)pArray->x.pOther;
	/* Convert the key to a libcox_value  */
	libcoxMemObjInitFromInt(libcoxHashmapGetEngine(pMap),&skey,(libcox_int64)index);
	/* Perform the lookup */
	rc = libcoxHashmapLookup(pMap,&skey,&pValue);
	libcoxMemObjRelease(&skey);
	if( rc != LIBCOX_OK ){
		/* No such entry */
		return 0;
	}
	return pValue;
}
/*
 * [CAPIREF: libcox_array_fetch_by_key()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_value *  libcox_array_fetch_by_key(libcox_value *pArray, const char *zKey, int nByte)
{
	libcox_value *pValue = 0; /* cc warning */
	libcox_hashmap *pMap;
	libcox_value sKey;
	SyString sVal;
	int rc;
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return 0;
	}
	if( nByte < 0 ){
		nByte = (int)SyStrlen(zKey);
	}
	SyStringInitFromBuf(&sVal,zKey,nByte);
	/* Convert the key to a libcox_value  */
	pMap = (libcox_hashmap *)pArray->x.pOther;
	libcoxMemObjInitFromString(libcoxHashmapGetEngine(pMap),&sKey,&sVal);
	/* Perform the lookup */
	rc = libcoxHashmapLookup(pMap, &sKey, &pValue);
	libcoxMemObjRelease(&sKey);
	if( rc != LIBCOX_OK ){
		/* No such entry */
		return 0;
	}
	/* Return */
	return pValue;
}
/*
 * [CAPIREF: libcox_array_insert()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_array_insert(libcox_value *pArray,libcox_value *pValue)
{
	int rc;
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return LIBCOX_CORRUPT;
	}
	/* Perform the insertion */
	rc = libcoxHashmapInsert((libcox_hashmap *)pArray->x.pOther, 0 /* Assign an automatic index */, &(*pValue));
	return rc;
}
/*
 * [CAPIREF: libcox_array_insert_strkey_elem()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_array_insert_strkey_elem(libcox_value *pArray, const char *zKey, libcox_value *pValue)
{
	int rc;
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return LIBCOX_CORRUPT;
	}
	/* Perform the insertion */
	if( SX_EMPTY_STR(zKey) ){
		/* Empty key, assign an automatic index */
		rc = libcoxHashmapInsert((libcox_hashmap *)pArray->x.pOther, 0, &(*pValue));
	}else{
		libcox_value sKey;
		SyString sVal;

		SyStringInitFromBuf(&sVal,zKey,(int)SyStrlen(zKey));
		libcoxMemObjInitFromString(libcoxHashmapGetEngine((libcox_hashmap *)pArray->x.pOther), &sKey, &sVal);
		rc = libcoxHashmapInsert((libcox_hashmap *)pArray->x.pOther, &sKey, &(*pValue));
		libcoxMemObjRelease(&sKey);

	}
	return rc;
}
/*
 * [CAPIREF: libcox_array_next_elem()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_value * libcox_array_next_elem(libcox_value *pArray)
{
	libcox_value *pValue;
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return 0;
	}
	/* Extract the current element */
	pValue = libcoxHashmapGetNextEntry((libcox_hashmap *)pArray->x.pOther);
	return pValue;
}
/*
 * [CAPIREF: libcox_array_count()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
unsigned int libcox_array_count(libcox_value *pArray)
{
	/* Make sure we are dealing with a valid hashmap */
	if( (pArray->iFlags & MEMOBJ_HASHMAP) == 0 ){
		return 0;
	}
	return libcoxHashmapCount((libcox_hashmap *)pArray->x.pOther);
}
/*
 * [CAPIREF: libcox_result_int()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_int(libcox_context *pCtx, int iValue)
{
	return libcox_value_int(pCtx->pRet, iValue);
}
/*
 * [CAPIREF: libcox_result_int64()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_int64(libcox_context *pCtx, libcox_int64 iValue)
{
	return libcox_value_int64(pCtx->pRet, iValue);
}
/*
 * [CAPIREF: libcox_result_bool()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_bool(libcox_context *pCtx, int iBool)
{
	return libcox_value_bool(pCtx->pRet, iBool);
}
/*
 * [CAPIREF: libcox_result_double()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_double(libcox_context *pCtx, double Value)
{
	return libcox_value_double(pCtx->pRet, Value);
}
/*
 * [CAPIREF: libcox_result_null()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_null(libcox_context *pCtx)
{
	/* Invalidate any prior representation and set the NULL flag */
	libcoxMemObjRelease(pCtx->pRet);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_result_string()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_string(libcox_context *pCtx, const char *zString, int nLen)
{
	return libcox_value_string(pCtx->pRet, zString, nLen);
}
/*
 * [CAPIREF: libcox_result_string_format()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_string_format(libcox_context *pCtx, const char *zFormat, ...)
{
	libcox_value *p;
	va_list ap;
	int rc;
	p = pCtx->pRet;
	if( (p->iFlags & MEMOBJ_STRING) == 0 ){
		/* Invalidate any prior representation */
		libcoxMemObjRelease(p);
		MemObjSetType(p, MEMOBJ_STRING);
	}
	/* Format the given string */
	va_start(ap, zFormat);
	rc = SyBlobFormatAp(&p->sBlob, zFormat, ap);
	va_end(ap);
	return rc;
}
/*
 * [CAPIREF: libcox_result_value()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_result_value(libcox_context *pCtx, libcox_value *pValue)
{
	int rc = LIBCOX_OK;
	if( pValue == 0 ){
		libcoxMemObjRelease(pCtx->pRet);
	}else{
		rc = libcoxMemObjStore(pValue, pCtx->pRet);
	}
	return rc;
}
/*
 * [CAPIREF: libcox_value_to_int()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_to_int(libcox_value *pValue)
{
	int rc;
	rc = libcoxMemObjToInteger(pValue);
	if( rc != LIBCOX_OK ){
		return 0;
	}
	return (int)pValue->x.iVal;
}
/*
 * [CAPIREF: libcox_value_to_bool()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_to_bool(libcox_value *pValue)
{
	int rc;
	rc = libcoxMemObjToBool(pValue);
	if( rc != LIBCOX_OK ){
		return 0;
	}
	return (int)pValue->x.iVal;
}
/*
 * [CAPIREF: libcox_value_to_int64()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
libcox_int64 libcox_value_to_int64(libcox_value *pValue)
{
	int rc;
	rc = libcoxMemObjToInteger(pValue);
	if( rc != LIBCOX_OK ){
		return 0;
	}
	return pValue->x.iVal;
}
/*
 * [CAPIREF: libcox_value_to_double()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
double libcox_value_to_double(libcox_value *pValue)
{
	int rc;
	rc = libcoxMemObjToReal(pValue);
	if( rc != LIBCOX_OK ){
		return (double)0;
	}
	return (double)pValue->x.rVal;
}
/*
 * [CAPIREF: libcox_value_to_string()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
const char * libcox_value_to_string(libcox_value *pValue, int *pLen)
{
	libcoxMemObjToString(pValue);
	if( SyBlobLength(&pValue->sBlob) > 0 ){
		SyBlobNullAppend(&pValue->sBlob);
		if( pLen ){
			*pLen = (int)SyBlobLength(&pValue->sBlob);
		}
		return (const char *)SyBlobData(&pValue->sBlob);
	}else{
		/* Return the empty string */
		if( pLen ){
			*pLen = 0;
		}
		return "";
	}
}
/*
 * [CAPIREF: libcox_value_int()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_int(libcox_value *pVal, int iValue)
{
	/* Invalidate any prior representation */
	libcoxMemObjRelease(pVal);
	pVal->x.iVal = (libcox_int64)iValue;
	MemObjSetType(pVal, MEMOBJ_INT);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_int64()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_int64(libcox_value *pVal, libcox_int64 iValue)
{
	/* Invalidate any prior representation */
	libcoxMemObjRelease(pVal);
	pVal->x.iVal = iValue;
	MemObjSetType(pVal, MEMOBJ_INT);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_bool()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_bool(libcox_value *pVal, int iBool)
{
	/* Invalidate any prior representation */
	libcoxMemObjRelease(pVal);
	pVal->x.iVal = iBool ? 1 : 0;
	MemObjSetType(pVal, MEMOBJ_BOOL);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_null()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_null(libcox_value *pVal)
{
	/* Invalidate any prior representation and set the NULL flag */
	libcoxMemObjRelease(pVal);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_double()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_double(libcox_value *pVal, double Value)
{
	/* Invalidate any prior representation */
	libcoxMemObjRelease(pVal);
	pVal->x.rVal = (libcox_real)Value;
	MemObjSetType(pVal, MEMOBJ_REAL);
	/* Try to get an integer representation also */
	libcoxMemObjTryInteger(pVal);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_string()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_string(libcox_value *pVal, const char *zString, int nLen)
{
	if((pVal->iFlags & MEMOBJ_STRING) == 0 ){
		/* Invalidate any prior representation */
		libcoxMemObjRelease(pVal);
		MemObjSetType(pVal, MEMOBJ_STRING);
	}
	if( zString ){
		if( nLen < 0 ){
			/* Compute length automatically */
			nLen = (int)SyStrlen(zString);
		}
		SyBlobAppend(&pVal->sBlob, (const void *)zString, (sxu32)nLen);
	}
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_string_format()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_string_format(libcox_value *pVal, const char *zFormat, ...)
{
	va_list ap;
	int rc;
	if((pVal->iFlags & MEMOBJ_STRING) == 0 ){
		/* Invalidate any prior representation */
		libcoxMemObjRelease(pVal);
		MemObjSetType(pVal, MEMOBJ_STRING);
	}
	va_start(ap, zFormat);
	rc = SyBlobFormatAp(&pVal->sBlob, zFormat, ap);
	va_end(ap);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_reset_string_cursor()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_reset_string_cursor(libcox_value *pVal)
{
	/* Reset the string cursor */
	SyBlobReset(&pVal->sBlob);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_release()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_release(libcox_value *pVal)
{
	libcoxMemObjRelease(pVal);
	return LIBCOX_OK;
}
/*
 * [CAPIREF: libcox_value_is_int()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_int(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_INT) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_float()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_float(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_REAL) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_bool()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_bool(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_BOOL) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_string()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_string(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_STRING) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_null()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_null(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_NULL) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_numeric()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_numeric(libcox_value *pVal)
{
	int rc;
	rc = libcoxMemObjIsNumeric(pVal);
	return rc;
}
/*
 * [CAPIREF: libcox_value_is_scalar()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_scalar(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_SCALAR) ? TRUE : FALSE;
}
/*
 * [CAPIREF: libcox_value_is_json_array()]
 * Please refer to the official documentation for function purpose and expected parameters.
 */
int libcox_value_is_array(libcox_value *pVal)
{
	return (pVal->iFlags & MEMOBJ_HASHMAP) ? TRUE : FALSE;
}
/* END-OF-IMPLEMENTATION: net.symisc.embedded.libcox 345-09-46 */
/*
 * Symisc libcox: Cross Platform Utilities & System Calls.
 * Copyright (C) 2014, 2015 Symisc Systems http://libcox.net/
 * Version 1.7
 * For information on licensing, redistribution of this file, and for a DISCLAIMER OF ALL WARRANTIES
 * please contact Symisc Systems via:
 *       licensing@symisc.net
 *       contact@symisc.net
 * or visit:
 *      http://libcox.net/
 */
