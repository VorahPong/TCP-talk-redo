Server/Client Talk Application
Developed by VorahPong, Mean
Date 10/27/2024

* Overview
    The purpose of this code is to demonstrate the TCP socket functions and data exchanging through sockets.

* Features
    The two programs client and server allowed two computers to talk to each other.

* Usage
To compile this project, you must have these files:
    tcpcli01.c
    tcpserv01.c
    unp.h
    makefile

To compile:
    1. Open the folder that includes the files in your command prompt.
    2. Execute the command "make" which will run the makefile and create two executables which are server and client.
    3. Open another command prompt in that same folder.
    4. On one command prompt, start a tcp server by executing "./server"
       the chosen port is fixed on 9877.
       To change you must modify it in unp.h
    5. On the second command prompt, start a client by executing "./client 127.0.0.1"
    6. After making sure both executables have no error, the client is ready to send message to server, and server can also send back message.

    Example:

    Command Prompt 1                        Command Prompt 2
    ./server                   
    Waiting for connection...
                                            ./client 127.0.0.1
    A client has connected
                                            Client: Hello
    Client: Hello
    Server: Hi, how are you?                  
                                            Server: Hi, how are you?
                                            Client: I'm good
    Client: I'm good
                                            Control + D (To Quit on Window) or Control + C (On Mac to terminate the client)
    Client has disconnected.
    Control + C (To terminate the server)
