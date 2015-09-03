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
		"cd",   libcoxCmdChdir,
		"chdir",libcoxCmdChdir,
		"pwd",  libcoxCmdPwd,
		"cwd",  libcoxCmdPwd,
		"getcwd",  libcoxCmdPwd,
		"rmdir", libcoxCmdRmDir,
		"mkdir", libcoxCmdmkdir,
		"echo",  libcoxCmdEcho,
		"env",   libcoxCmdEnv,
		"putenv", libcoxCmdSetEnv,
		"setenv", libcoxCmdSetEnv,
		"set_env", libcoxCmdSetEnv,
		"rename", libcoxCmdRename,
		"realpath",libcoxCmdRealPath,
		"real_path", libcoxCmdRealPath,
		"full_path", libcoxCmdRealPath,
		"fullpath", libcoxCmdRealPath,
		"getenv", libcoxCmdEnv,
		"rand", libcoxCmdRandomNum,
		"random", libcoxCmdRandomNum,
		"pid",    libcoxCmdPid,
		"getpid", libcoxCmdPid,
		"username", libcoxCmdUsername,
		"getusername", libcoxCmdUsername,
		"uid", libcoxCmdUid,
		"gid", libcoxCmdGid,
		"getuid", libcoxCmdUid,
		"getgid", libcoxCmdGid,
		"is_dir", libcoxCmdisDir,
		"isdir", libcoxCmdisDir,
		"is_link", libcoxCmdisLink,
		"islink", libcoxCmdisLink,
		"is_lnk", libcoxCmdisLink,
		"islnk", libcoxCmdisLink,
		"is_file", libcoxCmdisFile,
		"isfile", libcoxCmdisFile,
		"is_readable", libcoxCmdisReadable,
		"is_rd",  libcoxCmdisReadable,
		"isrd",  libcoxCmdisReadable,
		"is_writable", libcoxCmdisWritable,
		"is_wr", libcoxCmdisWritable,
		"iswr", libcoxCmdisWritable,
		"is_executable", libcoxCmdisExecutable,
		"is_exec", libcoxCmdisExecutable,
		"isexec", libcoxCmdisExecutable,
		"file_size", libcoxCmdFileSize,
		"filesize", libcoxCmdFileSize,
		"file_atime", libcoxCmdFileAtime,
		"fileatime", libcoxCmdFileAtime,
		"file_ctime", libcoxCmdFileCtime,
		"filectime", libcoxCmdFileCtime,
		"file_mtime", libcoxCmdFileMtime,
		"filemtime", libcoxCmdFileMtime,
		"file_exists", libcoxCmdFileExists,
		"fileexists", libcoxCmdFileExists,
		"tmp_dir",     libcoxCmdTmpDir,
		"temp_dir",    libcoxCmdTmpDir,
		"tmpdir",      libcoxCmdTmpDir,
		"stat",        libcoxCmdStat,
		"lstat",       libcoxCmdLstat,
		"chroot",      libcoxCmdChroot,
		"sleep",       libcoxCmdSleep,
		"usleep",      libcoxCmdUsleep,
		"unlink",      libcoxCmdUnlink,
		"rm",          libcoxCmdUnlink,
		"remove",      libcoxCmdUnlink,
		"delete",      libcoxCmdUnlink,
		"chmod",       libcoxCmdchmod,
		"chown",       libcoxCmdchown,
		"chgrp",       libcoxCmdchgrp,
		"disk_free_space", libcoxCmd_disk_free_space,
		"df",              libcoxCmd_disk_free_space,
		"disk_total_space", libcoxCmd_disk_total_space,
		"dt",               libcoxCmd_disk_total_space,
		"filetype",    libcoxCmdfiletype,
		"file_type",    libcoxCmdfiletype,
		"touch",       libcoxCmdtouch,
		"dirname",     libcoxCmddirname,
		"basename",    libcoxCmdbasename,
		"pathinfo",    libcoxCmdpathinfo,
		"strglob",     libcoxCmdstrglob,
		"fnmatch",     libcoxCmdfnmatch,
		"link",        libcoxCmdlink,
		"lnk",         libcoxCmdlink,
		"symlink",     libcoxCmdsymlink,
		"slink",       libcoxCmdsymlink,
		"umask",       libcoxCmdumask,
		"uname",       libcoxCmdUname,
		"osname",      libcoxCmdUname,
		"os",          libcoxCmdUname,
		"round",       libcoxCmd_round,
		"dechex",      libcoxCmd_dechex,
		"decoct",      libcoxCmd_decoct,
		"decbin",      libcoxCmd_decbin,
		"hexdec",      libcoxCmd_hexdec,
		"bindec",      libcoxCmd_bindec,
		"octdec",      libcoxCmd_octdec,
		"baseconvert",  libcoxCmd_base_convert,
		"base_convert",  libcoxCmd_base_convert,
		"substr",      libcoxCmd_substr,
		"substr_compare", libcoxCmd_substr_compare,
		"substr_count",   libcoxCmd_substr_count,
		"chunk_split",    libcoxCmd_chunk_split,
		"html_escape",    libcoxCmd_htmlspecialchars,
		"html_decode",    libcoxCmd_htmlspecialchars_decode,
		"strlen",         libcoxCmd_strlen,
		"strcmp",         libcoxCmd_strcmp,
		"strncmp",        libcoxCmd_strncmp,
		"strcasecmp",     libcoxCmd_strcasecmp,
		"strncasecmp",    libcoxCmd_strncasecmp,
		"implode",        libcoxCmd_implode,
		"explode",        libcoxCmd_explode,
		"trim",           libcoxCmd_trim,
		"ltrim",          libcoxCmd_ltrim,
		"rtrim",          libcoxCmd_rtrim,
		"strtolower",     libcoxCmd_strtolower,
		"strtoupper",     libcoxCmd_strtoupper,
		"bin2hex",        libcoxCmd_bin2hex,
		"strstr",         libcoxCmd_strstr,
		"stristr",        libcoxCmd_stristr,
		"strpos",         libcoxCmd_strpos,
		"stripos",        libcoxCmd_stripos,
		"strrpos",        libcoxCmd_strrpos    , 
        "strripos",       libcoxCmd_strripos , 
	    "strrchr",       libcoxCmd_strrchr    , 
	    "strrev",         libcoxCmd_strrev     ,
		"size_format",   libcoxCmd_size_format,
		"urlencode", libcoxCmd_urlencode,
		"urldecode", libcoxCmd_urldecode,
		"base64_encode", libcoxCmd_base64_encode,
		"base64_decode", libcoxCmd_base64_decode,
		"mktime",        libcoxCmd_mktime,
		"idate",         libcoxCmd_idate,
		"localtime",     libcoxCmd_localtime,
		"gmdate",        libcoxCmd_gmdate,
		"strftime",      libcoxCmd_strftime,
		"date",          libcoxCmd_date,
		"gettimeofday",  libcoxCmd_gettimeofday,
		"getdate",       libcoxCmd_getdate,
		"microtime",     libcoxCmd_microtime,
		"time",          libcoxCmd_time,
		"CMD_LIST",      libcoxCmdlist,
		"cat",           libcoxCmdCat,
		"mmap",          libcoxCmdCat,
		"ls",            libcoxCmdLs,
		"list",          libcoxCmdLs,
		"glob",          libcoxCmdLsGlob,
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
