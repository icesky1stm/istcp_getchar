//
// Created by suitm on 2021/01/06.
//

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "istcp.h"

int main(int argc, char * argv[]){
    char * ip;
    int port = 0;
    int ret = 0;

    int listen_sock = 0;
    int conn_sock = 0;

    char msg[200];

    if( argc != 2){
        printf("please input the port to listen!!!\n");
        return -5;
    }
    port = atoi(argv[1]);
    if( port <= 0){
        printf("[%d] is not a valid port!!!\n", port);
        return -5;
    }


    listen_sock = istcp_listen(port);
    if( listen_sock < 0 ){
        printf("listen error [%d],[%s]\n", listen_sock, strerror(errno));
        return -5;
    }
    printf("Bind success, local port is %d\n", port);
    while(1){
        printf("Accept Waiting......\n");
        conn_sock = istcp_accept_gethost(listen_sock, &ip);
        if( conn_sock < 0) {
            printf("recv error [%d]", ret);
            return -5;
        }
        printf("Accept new connect from ip[%s]\n", ip);

        while(1) {
            memset(msg, 0x00, sizeof(msg));
            ret = istcp_recv(conn_sock, msg, 1, 10);
            if (ret < 0) {
                printf("recv error[%d], [%s]\n", ret, strerror(errno));
                break;
            }
            printf("%s", msg);
        }

        istcp_close(conn_sock);
    }
    return 0;
}
