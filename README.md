## Symisc Libcox - Cross Platform System Calls & Utilities
http://libcox.net Version [1.7.0](http://libcox.net/downloads.html)

*Note:* **For production build, please rely only on the amalgamation build-release available at the libcox download page [here](http://libcox.net/downloads.html).**

Libcox is an ANSI-C Library which permit cross platform system calls and standard utilities among different operating systems via a system of [commands](http://libcox.net/cmd.html) similar to the standard UNIX one and backed by the native OS API (Refer to [Libcox architecture](http://libcox.net/arch.html)).

Think of Libcox as an embedded shell to your application (without any external process execution) where you can perform your traditional system tasks such as listing directory entries, gathering file informations, interacting with the OS regardless of the underlying operating system. 

*Libcox features includes:*

* Cross platform system calls & utilities backed by native host OS API.
* Built with over 145 [commands](http://libcox.net/cmd.html) similar to the standard UNIX one.
* Libcox is [built-up on layers](http://libcox.net/arch.html) using a VFS approach.
* Libcox is a Self-Contained ANSI C library without dependency.
* Thread safe and full re-entrant.
* Simple, Clean and easy to use API.
* Highly available online support.

###Libcox Programming Interfaces

 Here is what you do to start experimenting with Libcox without having to do a lot of tedious reading and configuration.
  Get a copy of the last public release of Libcox. Visit the [download page](http://libcox.net/downloads.html) for additional information. The following are Some C/C++ samples to start experimenting with:
  * [libcox_intro.c](http://libcox.net/libcox_intro.c): Introduction to the command execution ([uname](http://libcox.net/cmd/uname.html), [getcwd](http://libcox.net/cmd/getcwd.html), [cd](http://libcox.net/cmd/cd.html), [mkdir](http://libcox.net/cmd/mkdir.html), etc.) API.
  * [libcox_array.c](http://libcox.net/libcox_arrays.c): Working with arrays and the commands that deal with them ([ls](http://libcox.net/cmd/ls.html), [stat](http://libcox.net/cmd/stat.html), [glob](http://libcox.net/cmd/glob.html), etc.).
  * [libcox_shell.c](http://libcox.net/libcox_shell.c): Libcox shell which let you execute [built-in commands](http://libcox.net/cmd.html) from your CLI.
  
####Usefull Links to start with

* [Libcox in 3 Minutes or Less](http://libcox.net/intro.html)
* [Built-in Commands](http://libcox.net/cmd.html)
* [The Libcox Architecture](http://libcox.net/arch.html)
* [Libcox API Introduction](http://libcox.net/api_intro.html)
* [C/C++ API Reference Guide](http://libcox.net/docs.html)
* [Download Page](http://libcox.net/downloads.html)
* [Licensing Page](http://libcox.net/licensing.html)
* [Online Support](http://libcox.net/support.html)

Below is a simple C program that demonstrates how to use the Command Execution C/C++ interface to Libcox. 

```C
#include "libcox.h"
int main(int argc, char **argv){
		
		libcox *pHandle;            /* Libcox handle */
		libcox_value *pResult;     /* Return value of the last executed command */
		
		const char *zValue;           /* Cast the 'libcox_value' to a string */
		int rc;
	
		/* Obtain a new libcox handle*/
		rc = libcox_init(&pHandle);
		if( rc != LIBCOX_OK ){
			/* Handle error */
			return -1;
		}

		/* Execute the simplest command - uname: Get the underlying OS info (name, version, etc.) */
		rc = libcox_exec(pHandle,&pResult,"uname",-1);
		if( rc != LIBCOX_OK ){ /* Handle error */	}
		
		
		/* Get as a string representation and output the result */
		zValue = libcox_value_to_string(pResult,0);
		/* Output */
		printf("OS Info: %s\n\n",zValue); /* Should output something similar to: Windows 8.1 x64 localhost Build 85746... */

		/* Destroy the libcox_value */
		libcox_exec_result_destroy(pHandle,pResult);
		
		/* Finally, release the libcox handle */
		libcox_release(pHandle);
	}

```
