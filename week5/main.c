#include <dev/board.h>
#include <stdio.h>
#include <io.h>
 
#include <sys/thread.h>
#include <sys/timer.h>
#include <sys/confnet.h>
#include <sys/socket.h>
 
#include <arpa/inet.h>
#include <net/route.h>
#include <netinet/tcp.h>
 
#include <pro/dhcp.h>
#include <dev/nicrtl.h>

#include <string.h>
 
THREAD(TelnetThread, arg)
{
    TCPSOCKET *my_sock = NULL;
    char *text = "Hello user! If this wasn't just an example you could now enter commands!";
 
    my_sock = NutTcpCreateSocket();
    NutTcpAccept(my_sock, 23);
 
    NutThreadCreate("telnetd", TelnetThread, NULL, 512);
    NutTcpSend(my_sock, text, strlen(text));
 
    NutTcpCloseSocket(my_sock);
    NutThreadExit();
 
    for (;;) {
    }
}
 
int main(void)
{
    unsigned long baud = 115200;
 
    NutRegisterDevice(&DEV_DEBUG, 0, 0);
 
    freopen(DEV_DEBUG_NAME, "w", stdout);
    _ioctl(_fileno(stdout), UART_SETSPEED, &baud);
 
    puts("\nNut/OS Dynamic Server Threads Demo");
 
    if (NutRegisterDevice(&DEV_ETHER, 0, 0)) {
        puts("Registering " DEV_ETHER_NAME " failed.");
    }
 
    else if (NutDhcpIfConfig(DEV_ETHER_NAME, NULL, 0)) {
        puts("Configuring " DEV_ETHER_NAME " failed.");
    }
 
    printf("Network configured. Listening on IP %s, port 23.", inet_ntoa(confnet.cdn_ip_addr));
    NutThreadCreate("telnetd", TelnetThread, NULL, 512);
 
    for (;;) {
        NutThreadYield();
    }
    return 0;
}
