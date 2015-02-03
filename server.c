/*  Server.c
*   Purpose: To put up a server that will listen for clients to connect
*	         this server has a password, and if that password gets found, it generates
*		 a new password
*
*
*/

#include "UDPIncludes.h"
#include <stdlib.h>
#include <time.h>
#include <signal.h>

int attempts, successes, clientsConnected;
unsigned long clientList[128];



static char* nextPass(char* pass, size_t size); /* Password handler */
void DieWithError(char *errorMessage);  /* External error handling function */
int testClientPassword(char* pass, char* test); /* Password tester */
void recordClient(unsigned long clientAddr);
void ctrlcHandler(int signo);

int main(int argc, char *argv[])
{
    int sock;                        	/* Socket */
    struct sockaddr_in servAddr;     	/* Local address */
    struct sockaddr_in clntAddr;     	/* Client address */
    unsigned short servPort;         	/* Server port */
    unsigned int cliAddrLen;		/* Length of message */
    int msgSize;                     	/* Size of received message */
    char clntPass[PASSMAX];	     	/* The clients password */
    char *curPass = NULL;	     	/* Current password */
    char successOrNah[8]; 		/* Variables to send back with Success or Failure */
    srand(time(0));		     	/* For generating a new password */
    int attemptCount = 0, successCount = 0;
    

    if (argc < 3 || argc > 4)         	/* Test for correct number of parameters */
    {
        fprintf(stderr,
                "Usage:  %s <UDP SERVER PORT> <PASSWORD_LENGTH> <OPTIONAL PASSWORD>\n", 
                argv[0]);
        exit(1);
    }

    servPort = atoi(argv[1]);  /* First arg:  local port */

    /* Create socket for sending/receiving datagrams */
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
        DieWithError("socket() failed");

    /* Construct local address structure */
    memset(&servAddr, 0, sizeof(servAddr));   /* Zero out structure */
    servAddr.sin_family = AF_INET;                /* Internet address family */
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); /* Any incoming interface */
    servAddr.sin_port = htons(servPort);      /* Local port */

    signal(SIGINT, ctrlcHandler);

    /* Bind to the local address */
    if (bind(sock, (struct sockaddr *) &servAddr, sizeof(servAddr)) < 0)
        DieWithError("bind() failed");

    /* Set server password(either from argv[3] or as a random string */
    if(argc == 4){
        curPass = argv[3];
    }
    else curPass = nextPass(curPass, 8);
 
	clientsConnected++;
 
    for (;;) /* Run forever */
    {
        /* Set the size of the in-out parameter */
        cliAddrLen = sizeof(clntAddr);

	recordClient(clntAddr.sin_addr.s_addr);

        /* Block until receive message from a client */
        if ((msgSize = recvfrom(sock, clntPass, PASSMAX, 0,
            (struct sockaddr *) &clntAddr, &cliAddrLen)) < 0)
            DieWithError("recvfrom() failed");
	
	/* Check to see if the passwords match */
	if(strcmp(curPass, clntPass) == 0){ //success
	    strcpy(successOrNah, "SUCCESS");
	    curPass = nextPass(curPass, 8);
	    successCount += 1;
	    attemptCount += 1;
	}
	else { //failure
            strcpy(successOrNah, "FAILURE");
	    attemptCount += 1;    
	}

        /* Send received datagram back to the client */
        if (sendto(sock, successOrNah, msgSize, 0, 
             (struct sockaddr *) &clntAddr, sizeof(clntAddr)) != msgSize)
            DieWithError("sendto() sent a different number of bytes than expected");

	attempts = attemptCount;
	successes = successCount;
    }
    /* NOT REACHED */
}

/* Generate a new random password */
static char* nextPass(char* pass, size_t size){
    const char set[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    size_t n;

    if(size) {
        --size;

	for(n = 0; n < size; n++){
	    int key = rand() % (int) (sizeof set - 1);
	    pass[n] = set[key];
	}

	pass[size] = '\0';
    }

    return pass;
}

/* Test to see if the client pass is the same as the current password */
int testClientPassword(char* pass, char* test){
    int retVal = 0;
    if(strcmp(pass, test) == 0){
        retVal = 1;
    }

    return retVal;
}

/* Record the clients into a list */
void recordClient(unsigned long clientAddr){
    int i;

    for(i = 0; i < clientsConnected; i++){
	if(clientList[i] == clientAddr){
	    return;
	}
    }

    clientList[i] = clientAddr;
    clientsConnected++;
}

/* Handle what to do when the server is stopped */
void ctrlcHandler(int signo){
    printf("\n%d\t%d\n", attempts, successes);

    int i;
    struct in_addr addr;

    for(i = 0; i < clientsConnected; i++){
	addr.s_addr = clientList[i];
	puts(inet_ntoa(addr));
    }

    fflush(stdout);

    exit(0);
}
