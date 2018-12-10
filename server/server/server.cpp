#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cerrno>

#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <vector>
#include <netinet/in.h>
#include <Login.h>
#include <arpa/inet.h>
#define MAXLINIE 4096
using namespace std;
#define MAXCONNECT 10
void log(string msg)
{
    cout << msg <<endl;
}
void printVector(vector<ServiceLoginHandler * > vec)
{
    if(vec.empty())
    {

        log("vec is null");
        return;
    }

    //创建一个vector 迭代器
    
    vector<ServiceLoginHandler * >::iterator it;


    for(it = vec.begin(); it !=vec.end();it++)
    {
        cout << (*it)->socket;
    }

    cout <<endl;
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
	struct sockaddr *  clientaddr;
	socklen_t len = sizeof(clientaddr);	
    vector<ServiceLoginHandler * > handler;
    while(true)
    {
		connfd =accept(listenfd,(struct sockaddr *)&clientaddr , &len);
		if(connfd == -1)
		{
			errcode = strerror(errno);
			string msg = "accept socket error:" + errcode + to_string(errno);
			log("连接失败"+ msg);
			continue;
		}
		
		sockaddr_in sin;
		memcpy(&sin,&clientaddr,sizeof(sin));
		string addr = inet_ntoa(sin.sin_addr);
        	
		log("连接成功"+addr);
	    cout << connfd <<endl;	
		ServiceLoginHandler * service = new ServiceLoginHandler(connfd);
		handler.push_back(service);
        printVector(handler);		
        //log("waiting connect");        
    }
    close(listenfd);
}
