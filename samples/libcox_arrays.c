/*
 * Compile this file together with the libcox source code to generate
 * the desired executable. For example: 
 *  gcc -W -Wall -O6 libcox_arrays.c libcox.c -o libcox_arrays
 */
/*
 * This simple program is a quick introduction on how to embed and start
 * experimenting with Libcox arrays without having to do a lot of tedious
 * reading and configuration.
 *
 * Libcox is shipped with a multitude of very useful commands that return
 * a libcox_value of type array. That is, two or more entries are returned from
 * a single command call. Some of these commands are: ls, stat, glob, getdate and many more.
 *
 * The workflow is typically the same as working with standard commands except that we added
 * the very few interfaces that deals with arrays:
 *
 *   libcox_array_next_elem() which can be used to iterate over the elements of a given array.
 *   libcox_array_fetch()/libcox_array_fetch_by_key() which are used to extract a given array entry by its index or key.
 *   libcox_array_walk() which apply a walker callback to iterate over the array entries.
 *   libcox_array_count() which returns the total number of entries in a given array.
 *   libcox_value_is_array() which check if the given libcox_value is of type array.
 *   The unmentioned interfaces: libcox_array_reset(), libcox_array_insert(), libcox_array_insert_strkey_elem() that deals with arrays also.
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
/* $SymiscID: libcox_arrays.c v1.0 Win7 2015-09-02 14:38 stable <chm@symisc.net> $ */
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
	"Libcox Command Arrays                                       \n"
	"                                          http://libcox.net/\n"
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
		}else if( zMsg ){
			puts(zMsg);
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
/* Forward declaration */
struct array_rend
{
	int is_first;
	int cnt;
};
static int array_render(libcox_value *pEntry,void *pUserdata);
/*
 * Usage: libcox_array "/path/to/directory"
 *
 * If no arguments are given, then the current working directory is used for listing.
 */
int main(int argc,char *argv[])
{
	libcox *pHandle;            /* Libcox handle */
	libcox_value *pResult;      /* Return value of the last executed command */
	libcox_value *pEntry;       /* Array entries */
	int rc;
	
	const char *zDir = argc > 1 ? argv[1] /* User supplied directory */ : "./" /* current working diretcory */;
	/*
	 * You could use here the 'isdir' command to make sure that zDir is a valid directory.
	 * libcox_exec_fmt(pHandle,&pResult,"isdir '%s'",zDir)
	 * http://libcox.net/cmd/isdir.html
	 */
	puts(zBanner);

	/* Obtain a new libcox handle */
	rc = libcox_init(&pHandle);
	if( rc != LIBCOX_OK ){
		Fatal(0,"Out of memory");
	}
	
	/* List all entries within this directory using the ls command: http://libcox.net/cmd/ls.html */
	rc = libcox_exec_fmt(pHandle,&pResult,"ls '%s'",zDir); /*Don't forget the single quotes around 'zDir' */
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	if( libcox_value_is_array(pResult) ){
		if( argc > 1 ){
			/* Change the working directory so we could stat on items */
			libcox_exec_fmt(pHandle,NULL/*We do not need command return value*/,"chdir '%s'",zDir);
		}
		/* Iterate over the array which hold zDir entries */
		while( (pEntry = libcox_array_next_elem(pResult)) != NULL ){
			/* Get the file name */
			const char *zEntry = libcox_value_to_string(pEntry,NULL);
			/*
			 * You could use here the 'isfile' command to make sure that zDir is a valid directory.
			 * libcox_exec_fmt(pHandle,&pResult,"isfile '%s'",zEntry)
			 * http://libcox.net/cmd/isfile.html
			 */
			libcox_value *pStat;

			/* Get the file size, access time, etc. using the stat command: http://libcox.net/cmd/stat.html  */
			rc = libcox_exec_fmt(pHandle,&pStat,"stat '%s'",zEntry); /*Don't forget the single quotes around 'zEntry' */
			if( rc != LIBCOX_OK ){
				/* Seriously? */
				Fatal(pHandle,0);
			}
			if( libcox_value_is_array(pStat) ){
				libcox_int64 nSize;  /* File size */
				libcox_int64 aTime;  /* Access time */
				const char *zSize;   /* Presentable nSize (i.e 2GB, 563MB, etc) */
				const char *zTime;   /* Presentable time format */
				libcox_value *pSize,*pAccess; /* stat() fields */

				/* Get the file size */
				pSize = libcox_array_fetch_by_key(pStat,"size",-1);
				nSize = libcox_value_to_int64(pSize); /* File size in bytes */

				/* File last access */
				pAccess = libcox_array_fetch_by_key(pStat,"atime",-1);
				aTime = libcox_value_to_int64(pAccess); /* File last access since the UNIX epoch */

				/* Make all the thing presentable
				 * 
				 * Formatted nSize (i.e 2GB, 563MB, etc). Note the "qd" format which mean
				 * that we expect a quad number (64bit).
				 *
				 */
				libcox_exec_fmt(pHandle,&pSize,"size_format %qd",nSize); 
				zSize = "";
				if( libcox_value_is_string(pSize) ) {
					zSize = libcox_value_to_string(pSize,NULL);
				}
				/* Obtain a string representation of the file access timestamp */
				libcox_exec_fmt(pHandle,&pAccess,"date c %qd",aTime); /* http://libcox.net/cmd/date.html */
				zTime = "";
				if( libcox_value_is_string(pAccess) ) {
					zTime = libcox_value_to_string(pAccess,NULL);
				}
				/* Output */
				printf("%s\t\t%s\t\t%s\n",zEntry,zSize,zTime); /* You should see something like that: intel.xdk 166MB 2014-11-23T12:45:00+0000 */

				/* Release pSize and pAccess used in the last two libcox_exec_fmt() */
				libcox_exec_result_destroy(pHandle,pSize);
				libcox_exec_result_destroy(pHandle,pAccess);
			}
			/* Release pStat */
			libcox_exec_result_destroy(pHandle,pStat);
		} /* while(;;) */

	}else{
		Fatal(pHandle,"Expected an array!");
	}

	libcox_exec_result_destroy(pHandle,pResult);
	/*
	 * List all PDF files within this directory using the glob command:  http://libcox.net/cmd/glob.html
	 *
	 * Note that we'll use a walker callback to list all array entries instead of manually iterating over the elements.
	 * http://libcox.net/c_api/libcox_array_walk.html
	 *
	 */
	rc = libcox_exec_fmt(pHandle,&pResult,"glob *.pdf '%s'",zDir); /*Don't forget the single quotes around 'zDir' */
	if( rc != LIBCOX_OK ){
		/* Seriously? */
		Fatal(pHandle,0);
	}
	if( libcox_value_is_array(pResult) ){
		struct array_rend sRend = { 1 , 0 };

		printf("\nTotal number of PDF files: %u\n",libcox_array_count(pResult));
		/* Apply the walker callback */
		libcox_array_walk(pResult,array_render,(void *)&sRend);
	}

	/* All done, clean up */
	libcox_exec_result_destroy(pHandle,pResult);
	/* Release the libcox handle */
	libcox_release(pHandle);

	/*
	 * As you can see, Libcox is very easy to learn, even for new programmer. Refer to the following for advanced stuff:
	 * 
	 * Libcox Shell:      http://libcox.net/libcox_shell.c
	 *
	 * Libcox Built-in Commands:  http://libcox.net/cmd.html
	 */ 
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
