#include <iostream>

#include <cstdlib>

#include <cstring>

#include <cerrno>
#include <unistd.h>

#include <sys/types.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

using namespace std;

void log(string msg)
{
    cout << msg << endl;
}

string getError()
{
    string er = strerror(errno);
    return er;
}

#define MAXLINE 4096

int main()
{
    char severaddr_str[] = "127.0.0.1";
    int sockfd ,n;

    char recvline[MAXLINE],sendline[MAXLINE];

    struct sockaddr_in serveraddr;


    if( (sockfd = socket(AF_INET,SOCK_STREAM , 0)) < 0 )
    {
        string msg = "create faild socket:" + getError() +"\t" + to_string(errno);
        log(msg);
        exit(0);
    }
    
    memset(&serveraddr,0,sizeof(serveraddr));

    serveraddr.sin_family = AF_INET;

    serveraddr.sin_port = htons(6666);

    if( inet_pton(AF_INET,severaddr_str,&serveraddr.sin_addr) <=0 )
    {
        string addstr =  severaddr_str;
        string msg = "inet_pton faild for :" + addstr;
        log(msg);
        exit(0);
    }
    if(connect(sockfd ,(struct sockaddr * )&serveraddr,sizeof(serveraddr) )<0 )
    {
        string msg = "connect error:" + getError() + to_string(errno);

        log(msg);

        exit(0);
    }
    

    log("connect success");
    close(sockfd);

}
