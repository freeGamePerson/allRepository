#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define MAXLINIE 4096
using namespace std;

void log(string msg)
{
    cout << msg <<endl;
}

int main()
{
    //listenfd 服务器的socket 句柄
    int listenfd,connfd;

    struct sockaddr_in serveraddr;

    char buff[MAXLINIE] ;

    int n ;

    string errcode = strerror(errno);
    if((listenfd = socket(AF_INET,SOCK_STREAM ,0)) == -1)
    {
        string errormsg = "create socket failed :" + errcode + "\t" + to_string(errno);
        log(errormsg);
        exit(0);
    }

    memset(&serveraddr, 0 , sizeof(serveraddr));


    serveraddr.sin_family = AF_INET;

    serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

    serveraddr.sin_port = htons(6666);

    if(bind (listenfd , (struct sockaddr *) &serveraddr, sizeof(serveraddr)) == -1 )
    {
        string msg = "bind socket error:" + errcode + to_string(errno);
        log(msg);
        exit(0);
    }

    if(listen(listenfd , 10) == -1)
    {
        string msg = "linster socket error:"+ errcode + to_string(errno);
        log(msg);

        exit(0);
    }

   
    while(true)
    {
        //log("waiting connect");        
    }
    close(listenfd);
}
