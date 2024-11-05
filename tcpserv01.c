#include	"unp.h"//unp.h"

int main(int argc, char **argv)
{
	// declaring
	int					listenfd, connfd;	// listening socket, connecting socket
	pid_t				childpid;
	socklen_t			clilen;
	struct sockaddr_in	cliaddr, servaddr;
	//

	// Setting up listening socket
	listenfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family      = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port        = htons(SERV_PORT);

	bind(listenfd, (SA *) &servaddr, sizeof(servaddr));
	//

	// start listening
	listen(listenfd, LISTENQ);

	// infinite loop
	for ( ; ; ) {
		clilen = sizeof(cliaddr);

		// accept client
		connfd = accept(listenfd, (SA *) &cliaddr, &clilen);

		// check if connection is successful
		if(connfd < 0) {
			printf("Cannot accept a connection\n");
			exit(1);
		}
		else {
			printf("A client has connected\n");
		}
		//

		// create fork to duplicate server
		if ( (childpid = fork()) == 0) {	/* child process */
			close(listenfd);	/* close listening socket */

			// Create buffer to store messages
			char sendline[MAXLINE], recvline[MAXLINE];

			while(1) {
				// Read message from client
				memset(recvline, 0, MAXLINE);
				if (read(connfd, recvline, MAXLINE) == 0){
					printf("Client has disconnected");
					exit(1);
				}
				printf("Client: ");
				fputs(recvline, stdout);

				// Write message back to client
				printf("Server: ");
				fgets(sendline, MAXLINE, stdin);
				write(connfd, sendline, strlen(sendline));
			}
			exit(0);
		}
		//
		else {
			// waiting for child process to finish
			wait(NULL);
		}
		//
		
		close(connfd);			/* parent closes connected socket */
	}
}