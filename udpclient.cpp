#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>


#define BUFLEN 512
#define NPACK 10
#define PORT 9930
#define SRV_IP "127.0.0.1"

using namespace std;

void diep(const char *s)
{
    perror(s);
    exit(1);
}
 

/* diep(), #includes and #defines like in the server */
     
int main(void)
{
    struct sockaddr_in si_other;
    int s , nBytes;
    char buf[BUFLEN];
    //char input;
     
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP))==-1)
        diep("socket");
  
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
    if (inet_aton(SRV_IP, &si_other.sin_addr)==0) {
        fprintf(stderr, "inet_aton() failed\n");
        exit(1);
    }
    /*
    while(fgets(buf, BUFLEN, f)) {
        printf("Sending: %s\n", buf);
        nBytes = strlen(buf) + 1;
        if (sendto(s, buf, nBytes, 0, &si_other, sizeof(si_other))==-1)
            diep("sendto()");
    } */
    
    for (; ;) {
        printf("Enter string: ");
        fgets (buf, sizeof(buf), stdin);
        nBytes = strlen(buf) + 1;
        //scanf(" %c", &input);
        //printf("Sending packet %c\n", input);
        //sprintf(buf, "%c\n", input);
        if (strcmp(buf,"q\n") == 0){
            printf("\n 'q' pressed, exiting program. \n");
            close(s);
            exit(0);
        }
        if (sendto(s, buf, nBytes, 0, (sockaddr*)&si_other, sizeof(si_other))==-1)
            diep("sendto()");
    }
    close(s);
    return 0;
}
