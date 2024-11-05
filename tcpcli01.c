#include	"unp.h" //unp.h"

int main(int argc, char **argv)
{
	// declaring sockets
	int					sockfd;
	struct sockaddr_in	servaddr;

	// check if user provide ip address
	if (argc != 2){
		printf("usage: tcpcli <IPaddress>");
		exit(1);
	}
	//

	// setting up socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	//

	// check if connection is successful
	if(connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) {
		printf("Connection failed\n");
		exit(1);
	}
	else{
		printf("Connection is successful\n");
	}
	//


	// buffer to store messages
	char sendline[MAXLINE], recvline[MAXLINE]; 

	// infinite loop till client terminate
	while(1) {
		// send message to server
		printf("Client: ");
		fgets(sendline, MAXLINE, stdin);
		write(sockfd, sendline, strlen(sendline));

		// read message from server
		memset(recvline, 0, MAXLINE);
		if (read(sockfd, recvline, MAXLINE) == 0){
			printf("Server terminated prematurely");
			exit(1);
		}
		printf("Server: ");
		fputs(recvline, stdout);

	}

	exit(0);
}