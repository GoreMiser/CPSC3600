/*********************************************************
*
*  Client.c
*  Purpose:  This client will connect to a sever, and once connected attempt to break
*	         password on the server
*
*
*
*********************************************************/
#include "UDPIncludes.h"
#include <signal.h>
#include <time.h>


void clientCNTCCode();
void nextPass(char* old, int len);

int main(int argc, char *argv[])
{
    /* Start the clock */
    clock_t begin, end;
    double time_spent;
    begin = clock();

    int sock;                        /* Socket descriptor */
    struct sockaddr_in servAddr;     /* Echo server address */
    struct sockaddr_in fromAddr;     /* Source address of echo */
    struct hostent *thehost;         /* Hostent from gethostbyname() */
    unsigned short servPort;         /* Echo server port */
    unsigned int fromSize;           /* In-out of address size for recvfrom() */
    char *servIP;                    /* IP address of server */
    char password[*argv[3]];		     /* String to send to echo server */
    char successOrNah[*argv[3]];	     /* String to test if we have been successful or now */
    char success[8];		     /* String that holds the value we want */
    int definiteSuccess = 0;	     /* Control the while() with this */
    int msgSize = 0;		     /* Holds the size of the message received */
    int len = *argv[3];              /* Holds the size of the password given by argv[3] */
    int tryCount = 0, sucCount = 0;  /* The count of the number of tries and successful breaks */

    if ((argc < 3) || (argc > 4))    /* Test for correct number of arguments */
    {
        fprintf(stderr,"Usage: %s <Server IP> [<Port>] <Password Size>\n", argv[0]);
        exit(1);
    }

    signal (SIGINT, clientCNTCCode);

    servIP = argv[1];           /* First arg: server IP address (dotted quad) */

    if (argc == 4)
        servPort = atoi(argv[2]);  /* Use given port, if any */
    else
        servPort = 7;  /* 7 is the well-known port for the echo service */

    /* Create a datagram/UDP socket */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct the server address structure */
    memset(&servAddr, 0, sizeof(servAddr));    /* Zero out structure */
    servAddr.sin_family = AF_INET;                 /* Internet addr family */
    servAddr.sin_addr.s_addr = inet_addr(servIP);  /* Server IP address */
    servAddr.sin_port   = htons(servPort);     /* Server port */

    /* If user gave a dotted decimal address, we need to resolve it  */
    if (servAddr.sin_addr.s_addr == -1) {
        thehost = gethostbyname(servIP);
            servAddr.sin_addr.s_addr = *((unsigned long *) thehost->h_addr_list[0]);
    }

    memset(password, 0, len);
    strcpy(success, "SUCCESS");

    printf("\nClient: Beginning to crack the server\n");

    while(definiteSuccess != 1){
        /* Send the string to the server */
        if (sendto(sock, password, len, 0, (struct sockaddr *)
                   &servAddr, sizeof(servAddr)) != len)
          DieWithError("sendto() sent a different number of bytes than expected");

        /* Recv a response */
        fromSize = sizeof(fromAddr);
        if ( (msgSize = recvfrom(sock, successOrNah, PASSMAX, 0, 
             (struct sockaddr *) &fromAddr, &fromSize)) != PASSMAX)
		DieWithError("recvfrom() failed");

	if(strcmp(successOrNah, success) != 0) {
            nextPass(password, len);
	    tryCount++;
	}
	else{
	    definiteSuccess = 1;
	    sucCount++;
	}

        if (servAddr.sin_addr.s_addr != fromAddr.sin_addr.s_addr)
        {
             fprintf(stderr,"Error: received a packet from unknown source \n");
        }

    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("%d\t%d\n%f\n", tryCount, sucCount, time_spent);
    
    /* null-terminate the received data */
    close(sock);
    fflush(stdout);
    exit(0);
}

void clientCNTCCode() {

  printf("\nClient:  CNT-C Interrupt,  exiting....\n");
  exit(0);

}

void nextPass(char* old, int len){
    int carry = 1;
    int pos = 0;

    do{
        carry = 0;
	old[pos] += 1;
	if(old[pos] > 57 && old[pos] < 65)
	    old[pos] = 65;
	if(old[pos] > 90 && old[pos] < 97)
	    old[pos] = 97;
	if(old[pos] > 122) {
	    old[pos] = 48;
	    carry = 1;
	    pos++;
	}
    } while(carry && pos != len);

    if(pos == len)
	DieWithError("passwordBreaker has run out of guesses");
}
