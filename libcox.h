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
