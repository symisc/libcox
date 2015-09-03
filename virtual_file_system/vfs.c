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
	0, /* int (*xChdir)(const char *) */
	0, /* int (*xChroot)(const char *); */
	0, /* int (*xGetcwd)(libcox_context *) */
	0, /* int (*xMkdir)(const char *, int, int) */
	0, /* int (*xRmdir)(const char *) */ 
	0, /* int (*xIsdir)(const char *) */
	0, /* int (*xRename)(const char *, const char *) */
	0, /*int (*xRealpath)(const char *, libcox_context *)*/
	0, /* int (*xSleep)(unsigned int) */
	0, /* int (*xUnlink)(const char *) */
	0, /* int (*xFileExists)(const char *) */
	0, /*int (*xChmod)(const char *, int)*/
	0, /*int (*xChown)(const char *, const char *)*/
	0, /*int (*xChgrp)(const char *, const char *)*/
	0, /* libcox_int64 (*xFreeSpace)(const char *) */
	0, /* libcox_int64 (*xTotalSpace)(const char *) */
	0, /* libcox_int64 (*xFileSize)(const char *) */
	0, /* libcox_int64 (*xFileAtime)(const char *) */
	0, /* libcox_int64 (*xFileMtime)(const char *) */
	0, /* libcox_int64 (*xFileCtime)(const char *) */
	0, /* int (*xStat)(const char *, libcox_value *, libcox_value *) */
	0, /* int (*xlStat)(const char *, libcox_value *, libcox_value *) */
	0, /* int (*xIsfile)(const char *) */
	0, /* int (*xIslink)(const char *) */
	0, /* int (*xReadable)(const char *) */
	0, /* int (*xWritable)(const char *) */
	0, /* int (*xExecutable)(const char *) */
	0, /* int (*xFiletype)(const char *, libcox_context *) */
	0, /* int (*xGetenv)(const char *, libcox_context *) */
	0, /* int (*xSetenv)(const char *, const char *) */ 
	0, /* int (*xTouch)(const char *, libcox_int64, libcox_int64) */
	0, /* int (*xMmap)(const char *, void **, libcox_int64 *) */
	0, /* void (*xUnmap)(void *, libcox_int64);  */
	0, /* int (*xLink)(const char *, const char *, int) */
	0, /* int (*xUmask)(int) */
	0, /* void (*xTempDir)(libcox_context *) */
	0, /* unsigned int (*xProcessId)(void) */
	0, /* int (*xUid)(void) */
	0, /* int (*xGid)(void) */
	0, /* void (*xUsername)(libcox_context *) */
	0  /* int (*xExec)(const char *, libcox_context *) */
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

/* Export the windows vfs */
static const libcox_vfs sWinVfs = {
	"Windows_vfs", 
	LIBCOX_VFS_VERSION,
	0,
	255,
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
	MAX_PATH,
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
