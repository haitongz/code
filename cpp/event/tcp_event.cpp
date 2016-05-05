/*#include <stdio.h>*/
/*#include <string.h>*/
/*#include <sys/socket.h>*/
/*#include <netinet/in.h>*/
/*#include <arpa/inet.h>*/
/*#include <netdb.h>*/
/*#include <event.h>*/

/*struct event_base *base;*/

/*// 读事件*/
/*void onRead(int clifd, short event, void *arg)*/
/*{*/
  /*int ilen;*/
  /*char buf[1500];*/

  /*ilen = recv(clifd, buf, 1500, 0);*/
  /*if (ilen <= 0)*/
  /*{*/
    /*printf("Client close\n");*/

    /*struct event *pread = (struct event*)arg;*/
    /*event_del(pread);*/
    /*delete pread;*/

    /*close(clifd);*/
    /*return;*/
  /*}*/

  /*buf[ilen] = '\0';*/
  /*printf("Accept: %s\n", buf);*/
/*}*/

/*void onAccept(int svrfd, short event, void *arg)*/
/*{*/
  /*int clifd;*/
  /*struct sockaddr_in cliaddr;*/

  /*socklen_t sinsize = sizeof(cliaddr);*/
  /*clifd = accept(svrfd, (struct sockaddr*)&cliaddr, &sinsize);*/

  /*struct event *pread = new event;*/
  /*event_set(pread, clifd, EV_READ|EV_PERSIST, onRead, pread); //注册读（写）事件*/
  /*event_base_set(base, pread);*/
  /*event_add(pread, NULL);*/
/*}*/

/*int main(int argc, char *argv[])*/
/*{*/
  /*int svrfd;*/
  /*struct sockaddr_in svraddr;*/

  /*memset(&svrfd, 0, sizeof(svraddr));*/
  /*svraddr.sin_family = AF_INET;*/
  /*svraddr.sin_port = htons(1234);*/
  /*svraddr.sin_addr.s_addr = inet_addr("127.0.0.1");*/

  /*svrfd = socket(AF_INET, SOCK_STREAM, 0);*/
  /*bind(svrfd, (struct sockaddr*)&svraddr, sizeof(svraddr));*/

  /*listen(svrfd, 10);*/

  /*// 初始化事件库*/
  /*base = event_base_new();*/

  /*// 初始化一个连接事件，EV_PRESIST指定重复执行该事件*/
  /*struct event evlisten;*/
  /*event_set(&evlisten, svrfd, EV_READ|EV_PERSIST, onAccept, NULL);*/

  /*// 设置为base事件*/
  /*event_base_set(base, &evlisten);*/
  /*// 添加事件*/
  /*event_add(&evlisten, NULL);*/
  /*// 事件循环*/
  /*event_base_dispatch(base);*/

  /*return 0;*/
/*}*/

/*#include <stdio.h>*/
/*#include <string.h>*/
/*#include <sys/socket.h>*/
/*#include <netinet/in.h>*/
/*#include <arpa/inet.h>*/
/*#include <netdb.h>*/
/*#include <event.h>*/


/*struct event_base *base;*/

/*// 读事件*/
/*void onRead(int clifd,short ievent,void *arg)*/
/*{*/
	/*int ilen;*/
	/*char buf[1500];*/

	/*ilen = recv(clifd,buf,1500,0);*/

	/*if(ilen <= 0)*/
	/*{*/
		/*printf("Client close\n");*/

		/*struct event *pread = (struct event*)arg;*/
		/*event_del(pread);*/
		/*delete pread;*/

		/*close(clifd);*/
		/*return;*/
	/*}*/

	/*buf[ilen] = '\0';*/
	/*printf("Accpet: %s\n",buf);*/
/*}*/

/*// 连接事件*/
/*void onAccept(int svrfd,short ievent,void *arg)*/
/*{*/
	/*int clifd;*/
	/*struct sockaddr_in cliaddr;*/

	/*socklen_t sinsize = sizeof(cliaddr);*/
	/*clifd = accept(svrfd,(struct sockaddr*)&cliaddr,&sinsize);*/

	/*struct event *pread = new event;*/
	/*event_set(pread,clifd,EV_READ|EV_PERSIST,onRead,pread);  // 注册读(写)事件*/
	/*event_base_set(base,pread);*/
	/*event_add(pread,NULL);*/
/*}*/


/*int main()*/
/*{*/
	/*int svrfd;*/
	/*struct sockaddr_in svraddr;*/

	/*memset(&svrfd,0,sizeof(svraddr));*/
	/*svraddr.sin_family = AF_INET;*/
	/*svraddr.sin_port = htons(1234);*/
	/*svraddr.sin_addr.s_addr = inet_addr("127.0.0.1");*/

	/*svrfd = socket(AF_INET,SOCK_STREAM,0);*/
	/*bind(svrfd,(struct sockaddr*)&svraddr,sizeof(svraddr));*/

	/*listen(svrfd,10);*/

	/*// 初始化事件库*/
	/*base = event_base_new();*/

	/*// 初始化一个连接事件,EV_PRESIST指定重复执行该事件*/
	/*struct event evlisten;*/
	/*event_set(&evlisten,svrfd,EV_READ|EV_PERSIST,onAccept,NULL);*/

	/*// 设置为base事件*/
	/*event_base_set(base,&evlisten);*/
	/*// 添加事件*/
	/*event_add(&evlisten,NULL);*/
	/*// 事件循环*/
	/*event_base_dispatch(base);*/

	/*return 0;*/

/*}*/

/*#include <stdio.h>*/
/*#include <string.h>*/
/*#include <sys/socket.h>*/
/*#include <netinet/in.h>*/
/*#include <arpa/inet.h>*/
/*#include <netdb.h>*/
/*#include <event.h>*/


/*struct event_base *base;*/

/*// 读事件*/
/*void onRead(int clifd,short ievent,void *arg)*/
/*{*/
	/*int ilen;*/
	/*char buf[1500];*/

	/*ilen = recv(clifd,buf,1500,0);*/

	/*if(ilen <= 0)*/
	/*{*/
		/*printf("Client close\n");*/

		/*struct event *pread = (struct event*)arg;*/
		/*event_del(pread);*/
		/*delete pread;*/

		/*close(clifd);*/
		/*return;*/
	/*}*/

	/*buf[ilen] = '\0';*/
	/*printf("Accpet: %s\n",buf);*/
/*}*/

/*// 连接事件*/
/*void onAccept(int svrfd,short ievent,void *arg)*/
/*{*/
	/*int clifd;*/
	/*struct sockaddr_in cliaddr;*/

	/*socklen_t sinsize = sizeof(cliaddr);*/
	/*clifd = accept(svrfd,(struct sockaddr*)&cliaddr,&sinsize);*/

	/*struct event *pread = new event;*/
	/*event_set(pread,clifd,EV_READ|EV_PERSIST,onRead,pread);  // 注册读(写)事件*/
	/*event_base_set(base,pread);*/
	/*event_add(pread,NULL);*/
/*}*/


/*int main()*/
/*{*/
	/*int svrfd;*/
	/*struct sockaddr_in svraddr;*/

	/*memset(&svrfd,0,sizeof(svraddr));*/
	/*svraddr.sin_family = AF_INET;*/
	/*svraddr.sin_port = htons(1234);*/
	/*svraddr.sin_addr.s_addr = inet_addr("127.0.0.1");*/

	/*svrfd = socket(AF_INET,SOCK_STREAM,0);*/
	/*bind(svrfd,(struct sockaddr*)&svraddr,sizeof(svraddr));*/

	/*listen(svrfd,10);*/

	/*// 初始化事件库*/
	/*base = event_base_new();*/

	/*// 初始化一个连接事件,EV_PRESIST指定重复执行该事件*/
	/*struct event evlisten;*/
	/*event_set(&evlisten,svrfd,EV_READ|EV_PERSIST,onAccept,NULL);*/

	/*// 设置为base事件*/
	/*event_base_set(base,&evlisten);*/
	/*// 添加事件*/
	/*event_add(&evlisten,NULL);*/
	/*// 事件循环*/
	/*event_base_dispatch(base);*/

	/*return 0;*/

/*}*/

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#include <event.h>
using namespace std;

// 事件base
struct event_base* base;

// 读事件回调函数
void onRead(int iCliFd, short iEvent, void *arg)
{
    int iLen;
    char buf[1500];

    iLen = recv(iCliFd, buf, 1500, 0);

    if (iLen <= 0) {
        cout << "Client Close" << endl;

		// 连接结束(=0)或连接错误(<0)，将事件删除并释放内存空间
        struct event *pEvRead = (struct event*)arg;
        event_del(pEvRead);
        delete pEvRead;

        close(iCliFd);
        return;
    }

    buf[iLen] = 0;
    cout << "Client Info:" << buf << endl;
}

// 连接请求事件回调函数
void onAccept(int iSvrFd, short iEvent, void *arg)
{
    int iCliFd;
    struct sockaddr_in sCliAddr;

    socklen_t iSinSize = sizeof(sCliAddr);
    iCliFd = accept(iSvrFd, (struct sockaddr*)&sCliAddr, &iSinSize);

	// 连接注册为新事件 (EV_PERSIST为事件触发后不默认删除)
    struct event *pEvRead = new event;
    event_set(pEvRead, iCliFd, EV_READ|EV_PERSIST, onRead, pEvRead);
    event_base_set(base, pEvRead);
    event_add(pEvRead, NULL);
}

int main()
{

    int iSvrFd;
    struct sockaddr_in sSvrAddr;

    memset(&sSvrAddr, 0, sizeof(sSvrAddr));
    sSvrAddr.sin_family = AF_INET;
    sSvrAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sSvrAddr.sin_port = htons(8888);

    // 创建tcpSocket（iSvrFd），监听本机8888端口
    iSvrFd = socket(AF_INET, SOCK_STREAM, 0);
    bind(iSvrFd, (struct sockaddr*)&sSvrAddr, sizeof(sSvrAddr));
    listen(iSvrFd, 10);

	// 初始化base
    base = event_base_new();

    struct event evListen;
	// 设置事件
    event_set(&evListen, iSvrFd, EV_READ|EV_PERSIST, onAccept, NULL);
	// 设置为base事件
    event_base_set(base, &evListen);
	// 添加事件
    event_add(&evListen, NULL);

	// 事件循环
    event_base_dispatch(base);

    return 0;
}
