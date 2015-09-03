/*
 * Compile this file together with the libcox source code to generate
 * the desired executable. For example: 
 *  gcc -W -Wall -O6 libcox_shell.c libcox.c -o shell
 */
/*
 * The Libcox shell is a simple standalone program which let you execute
 * built-in Libcox commands from your command line interface (CLI).
 *
 * For an introduction to the Libcox C/C++ interface, please refer to:
 *        http://libcox.net/api_intro.html
 * For the full C/C++ API reference guide, please refer to:
 *        http://libcox.net/c_api.html
 * Libcox in 3 Minutes or Less:
 *        http://libcox.net/intro.html
 * Built-in Libcox Commands:
 *        http://libcox.net/cmd.html
 */
/* $SymiscID: libcox_shell.c v1.0.4 Win7 2015-08-21 23:26 stable <devel@symisc.net> $ */

/* Make sure you have the latest release of Libcox from:
 *  http://libcox.net/downloads.html
 */
#include <stdio.h>
#include <stdlib.h>
/* Make sure this header file is available.*/
#include "libcox.h"

/* 
 * Display an error message and exit.
 */
static void Fatal(const char *zMsg)
{
	puts(zMsg);
	/* Shutdown the library */
	libcox_lib_shutdown();
	/* Exit immediately */
	exit(0);
}
/*
 * Banner.
 */
static const char zBanner[] = {
	"============================================================\n"
	" Simple Libcox  Shell                                       \n"
	"                                    http://libcox.net/\n"
	" Enter one or more Libcox commands.                         \n"
	"                                                            \n"
	" Type 'CMD_LIST' for a list of built-in Libcox commands.     \n"
	"                                                            \n"
	" Enter a blank line to exit the shell                       \n"
	"============================================================\n"
};
/*
 * atexit() callback. Shutdown the Libcox library.
 */
void libcox_exit(void)
{
	libcox_lib_shutdown();
}
#include <ctype.h>
/*
 * Return true only if we are dealing with a blank line.
 */
int isBlank(const char *zIn,unsigned int nByte)
{
	const char *zEnd = &zIn[nByte];
	while( zIn < zEnd && (isspace(zIn[0])) ){
		/* Advance the cursor */
		zIn++;
	}
	return (zIn[0] == 0 || zIn >= zEnd) ? 1 : 0;
}
/* Forward declaration */
struct array_rend
{
	int is_first;
	int cnt;
};
static int array_render(libcox_value *pEntry,void *pUserdata);
/*
 * Command result consumer callback. Each time a command is executed
 * the engine will invoke this callback in order to consume the
 * execution result (i.e. return value) of the last executed command.
 *
 * This callback is registered later via libcox_config() using LIBCOX_CONFIG_OUTPUT_CONSUMER
 * as a configuration option. 
 */
static int command_result_render(libcox_value *pResult,void *pUnused /* userdata */)
{
	const char *zResult = 0;
	if( libcox_value_is_null(pResult) ){
		zResult = "<null>";
	}else if( libcox_value_is_array(pResult) ){
		struct array_rend sRend = { 1 , 0 };
		/* Command return an array, render it */
		libcox_array_walk(pResult,array_render,&sRend);
	}else{
		/* Explicitly cast the result to a null terminated string */
		zResult = libcox_value_to_string(pResult,0);
	}
	if( zResult ){
		puts(zResult);
	}
	return LIBCOX_OK;
}
/* Libcox shell */
int main(int argc,char **argv)
{
	libcox *pCtx;         /* Libcox context */
	char zBuf[4096],*zPtr; /* Read buffer */
	int rc;

	/* Obtain a new libcox handle */
	rc = libcox_init(&pCtx);
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal("Libcox is running out of memory");
	}

	/* Register the result (command return value) consumer callback */
	libcox_config(pCtx,LIBCOX_CONFIG_OUTPUT_CONSUMER,command_result_render,0 /* userdata */);
	
	/* Register the atexit() callback */
	atexit(libcox_exit);
	
	/* Start the shell */
	puts(zBanner);
	
	for(;;){
		
		fputs("libcox>",stdout);
		zPtr = fgets(zBuf,sizeof(zBuf),stdin);
		if( !zPtr || isBlank(zBuf,sizeof(zBuf)) ){
			/* Blank line - exit */
			puts("Exiting...");
			break;
		}

		/* Exectute the command */
		rc = libcox_exec(pCtx,NULL/* Return result will be redirected to the callback*/,zBuf,-1);
		if( rc != LIBCOX_OK ){
			/* Error during execution. Extract the error log */
			const char *zErr;
			int nLen;
			libcox_config(pCtx,LIBCOX_CONFIG_ERR_LOG,&zErr,&nLen);
			if( nLen > 0 ){
				puts(zErr);
			}
			if( rc != LIBCOX_UNKNOWN /* Unknown command */){
				/* Exit immediately */
				break;
			}
		}
		
	}/* for(;;) */

	/* release the libcox handle */
	libcox_release(pCtx);
	return 0;
}
/*
 * Array walker callback: Output array fields.
 *
 * This function is passed to the array_walk() interface which is
 * invoked for each array entry.
 */
static int array_render(libcox_value *pEntry,void *pUserdata)
{
	struct array_rend *pRend = (struct array_rend *)pUserdata;
	const char *zValue;
	int nByte;
	if( libcox_value_is_null(pEntry) ){
		zValue = "<null>";
		nByte = (int)sizeof("<null>") - 1;
	}else{
		/* Extract entry contents */
		zValue = libcox_value_to_string(pEntry,&nByte);
	}
	printf("%d) %.*s\n",++pRend->cnt,nByte,zValue);
	return LIBCOX_OK;
}
