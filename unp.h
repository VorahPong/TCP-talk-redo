#ifndef	__unp_h
#define	__unp_h

// #include	<sys/types.h>	/* basic system data types */
#include	<sys/socket.h>	/* basic socket definitions */
#include	<netinet/in.h>	/* sockaddr_in{} and other Internet defns */
#include	<arpa/inet.h>	/* inet(3) functions */
#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>
// #include	<sys/wait.h>
// #include	<sys/un.h>		/* for Unix domain sockets */






/* Following could be derived from SOMAXCONN in <sys/socket.h>, but many
   kernels still #define it as 5, while actually supporting many more */
#define	LISTENQ		1024	/* 2nd argument to listen() */

/* Miscellaneous constants */
#define	MAXLINE		4096	/* max text line length */
#define	BUFFSIZE	8192	/* buffer size for reads and writes */

/* Define some port number that can be used for our examples */
#define	SERV_PORT		 9877			/* TCP and UDP */
#define	SERV_PORT_STR	"9877"			/* TCP and UDP */
// #define	UNIXSTR_PATH	"/tmp/unix.str"	/* Unix domain stream */
// #define	UNIXDG_PATH		"/tmp/unix.dg"	/* Unix domain datagram */


/* Following shortens all the typecasts of pointer arguments: */
#define	SA	struct sockaddr


#endif	/* __unp_h */