#include "util.h"

#define BUFSIZE 1500

typedef struct rec {                /* outgoing UDP data */
  u_short seq;          /* sequence number */
} Rec;

      /* for signal handlers */

#define max(a,b) ((a) > (b) ? (a) : (b))

extern int max_ttl;
extern int datalen;

Sockaddr *sasend;    /* socket addresses for various purposes */
Sockaddr *sarecv;
Sockaddr *salast;
Sockaddr *sabind;

char recvbuf[BUFSIZE];
char sendbuf[BUFSIZE];

socklen_t salen; 


void sig_alrm (int signo);
int process_ip (struct ip *ip, int len);
int recv_dgram ();
void sub_tv (Timeval *plus, Timeval *minus, Timeval *res);
double time_to_double (Timeval *time);
void print_report ();
void send_dgram (int ttl);
int send_probes (int ttl);
void loop_ttl ();




