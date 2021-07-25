#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[256];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    if (argc < 2)
    {
        fprintf(stderr, "ERROR, no port provided\n");
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Socket file descriptor
    if (sockfd < 0)
    {
        error("ERROR opening socket");
    }
    memset((char *)&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;      // Sockaddr_in has four fields, first is address family
    serv_addr.sin_port = htons(portno);  // Set port for this file (set it to network order).
    // look up big/little endian numbers for more context.
    serv_addr.sin_addr.s_addr = INADDR_ANY;  // Internet address of this socket address.
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        error("ERROR on binding");
    }

    // Listening for and then accepting a connection.
    listen(sockfd, 5);
    clilen = sizeof(cli_addr);
    // Accept is where the waiting actually happens. If there is nothing in the queue then
    // program execution pauses here until connection request comes.
    newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
    if (newsockfd < 0)
    {
        error("ERROR on accept");
    }

    memset(buffer, 0, 256);
    int bytesRead = 0;
    // Okay, so when you read it removes them from the file descriptor/the file descriptor pointer
    // moves forward.
    // while (bytesRead < 8) {
    //     n = read(newsockfd, buffer, 1); // Reads one less byte than the array size so it's still
    //     // null-terminated. Smart!
    //     if (n < 0) {
    //         error("ERROR reading from socket");
    //     }
    //     std::cout << "byte #" << bytesRead + 1 << buffer[0] << "\n";
    //     bytesRead += 1;
    // }

    /* Based on test: listen blocks while file stream is empty. Some specific cases:
        -read() is called and there is still data in the file stream from a previous write():
            ->read going off of where the file stream was previously at.
        -Read() is called and it reads fewer bytes than have been written():
            ->Reads however many bytes be it due to error or not, and file stream pointer or
       whatever moves forward that many bytes. -Read() is called and there are no bytes in the file
       stream:
            ->Read() blocks the caller thread until the client writes to the stream()
                :: Even if the client writes fewer bytes than the read has been set to read
                the read will unblock after the write, reading as many bytes as possible.
    */
    n = read(newsockfd, buffer, 5);
    if (n < 9 and n >= 0)
    {
        std::cout << "A short read has occurred\n";
    }
    std::cout << "message after first read: " << buffer << "\n";
    // std::cout << "Here is the message: " << buffer;
    n = write(newsockfd, "I got your message", 18);
    if (n < 0)
    {
        error("ERROR writing to socket");
    }
    // Based on this test, client socket and server socket in a connection read and write to
    // two separate things. i.e.: Whatever the server writes to newsockfd, it won't find when
    // it reads. It'll only read things that the client wrote.
    // n = write(newsockfd, "this is something I wrote towards the end", 43);

    // If client closes socket on their end read will automatically read 0 characters, I think
    // null terminated is a special char? Nope, \0 will NOT cause short read.
    n = read(newsockfd, buffer, 255);
    buffer[255] = '\0';
    std::cout << "message after second read: " << buffer << std::endl;
    close(newsockfd);
    close(sockfd);
    return 0;
}
