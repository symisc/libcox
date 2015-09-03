/*
 * Compile this file together with the libcox source code to generate
 * the desired executable. For example: 
 *  gcc -W -Wall -O6 libcox_intro.c libcox.c -o libcox_intro
 */
/*
 * This simple program is a quick introduction on how to embed and start
 * experimenting with Libcox without having to do a lot of tedious
 * reading and configuration.
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
/* $SymiscID: libcox_intro.c v1.0 Win8.1 2015-08-24 14:48 stable <chm@symisc.net> $ */
/* 
 * Make sure you have the latest release of Libcox from:
 *  http://libcox.net/downloads.html
 */
#include <stdio.h>  /* puts() */
#include <stdlib.h> /* exit() */
/* Make sure this header file is available.*/
#include "libcox.h"
/*
 * Banner.
 */
static const char zBanner[] = {
	"============================================================\n"
	"Libcox Command Execution Intro                               \n"
	"                                    http://libcox.net/\n"
	"============================================================\n"
};
/*
 * Extract the command exec error log and exit.
 */
static void Fatal(libcox *pHandle,const char *zMsg)
{
	if( pHandle ){
		const char *zErr;
		int iLen = 0; /* Stupid cc warning */

		/* Extract the datastore error log */
		libcox_config(pHandle,LIBCOX_CONFIG_ERR_LOG,&zErr,&iLen);
		if( iLen > 0 ){
			/* Output the error log */
			puts(zErr); /* Always null termniated */
		}
	}else{
		if( zMsg ){
			puts(zMsg);
		}
	}
	/* Manually shutdown the library */
	libcox_lib_shutdown();
	/* Exit immediately */
	exit(0);
}

int main(int argc,char *argv[])
{
	libcox *pHandle;            /* Libcox handle */
	libcox_value *pResult;     /* Return value of the last executed command */
	
	
	const char *zValue;           /* Cast the libcox_value to a string */
	libcox_int64 iValue;          /* Cast the libcox_value to a 64-bit integer  */
	int rc;
	
	
	puts(zBanner);

	/* Obtain a new libcox handle */
	rc = libcox_init(&pHandle);
	if( rc != LIBCOX_OK ){
		Fatal(0,"Out of memory");
	}
	
	/* Execute the simplest command - uname: Get the underlying OS info (name, version, etc.), http://libcox.net/cmd/uname.html */
	rc = libcox_exec(pHandle,&pResult,"uname",-1);
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	/* Get as a string representation and output the result */
	zValue = libcox_value_to_string(pResult,0);
	/* Output */
	printf("OS Info: %s\n\n",zValue);

	/* Destroy the libcox_value */
	libcox_exec_result_destroy(pHandle,pResult);

	/* Another simple command - getpwd: Get the current working directory,  http://libcox.net/cmd/getcwd.html */
	rc = libcox_exec(pHandle,&pResult,"getcwd",-1);
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	/* Get as a string representation and output the result */
	zValue = libcox_value_to_string(pResult,0);
	/* Output */
	printf("Current Working Directory: %s\n\n",zValue);

	/* Destroy the libcox_value */
	libcox_exec_result_destroy(pHandle,pResult);


	/* last simple one - date: Get the current system date,  http://libcox.net/cmd/date.html */
	rc = libcox_exec(pHandle,&pResult,"date c",-1);
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	/* Get as a string representation and output the result */
	zValue = libcox_value_to_string(pResult,0);
	/* Output */
	printf("System date: %s\n\n",zValue);

	/* Destroy the libcox_value */
	libcox_exec_result_destroy(pHandle,pResult);

	/* filesize: Get the size of  the 'libcox_intro.c' file (assuming the file is in the current working directory),  http://libcox.net/cmd/filesize.html 
	 * unless you use the file_exists command which check if the given filename is available or not. http://libcox.net/cmd/file_exists.html
	 */
	rc = libcox_exec(pHandle,&pResult,"file_size './libcox_intro.c'",-1);
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	/* Get as a 64-bit integer representation and output the result */
	iValue = libcox_value_to_int64(pResult);
	/* Output */
	printf("'libcox_intro.c' File size: %lld\n",iValue);

	/* Destroy the libcox_value */
	libcox_exec_result_destroy(pHandle,pResult);

	/* You could use the 'sizeformat' command for a smart string representation of the given size:
	 * Example: size_format 1073741824  ==> 1 GB
	 * http://libcox.net/cmd/size_format.html
	 */
	

	/* Release the libcox handle */
	libcox_release(pHandle);
	/*
	 * As you can see, Libcox is very easy to learn, even for new programmer. Refer to the following for advanced stuff:
	 *
	 * Working with array: http://libcox.net/libcox_arrays.c
	 * 
	 * Libcox Shell:      http://libcox.net/libcox_shell.c
	 *
	 * Libcox Built-in Commands:  http://libcox.net/cmd.html
	 */ 
	return 0;
}
