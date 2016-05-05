#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*
 * puller 作为bind端，由push连接过来
 * ZMq_PULL 作为“服务端”， 进行bind操作
 */

int main(int argc, char *argv[])
{
  if (argc < 4)
  {
    printf("usage : %s bind_ip bind_port puller_name \n", argv[0]);
    printf("example : %s 127.0.0.1 36888 puller_leo\n", argv[0]);
    printf("example : %s 127.0.0.1 36888 puller_ox\n", argv[0]);
    return -1;
  }

  int major, minor, patch;
  zmq_version(&major, &minor, &patch);
  printf("Current OMQ version is %d.%d.%d\n", major, minor, patch);
  printf("=====================================\n\n");

  char addr[128] = {0};
  snprintf(addr, sizeof(addr), "tcp://%s:%s", argv[1], argv[2]);

  /* 创建ZMQ_PULL套接字 */
  void* context = zmq_ctx_new();
  void* puller = zmq_socket(context, ZMQ_PULL);
  int rec = zmq_bind(puller, addr);
  if (rec)
  {
    printf("zmq_bind %s error (%d):%s\n", addr, rec, zmq_strerror(rec));
    zmq_close(puller);
    zmq_ctx_term(context);
    return -2;
  }

  printf("puller zmq_bind %s done!\n", addr);
  char buf[128] = {0};

  while(1)
  {
    rec = zmq_recv(puller, buf, sizeof(buf), 0);
    printf("[%ld][%s] recv request(%s) from pusher, rec = %d, request.len = %d\n", time(NULL), argv[3], buf, rec, strlen(buf));
  }

  zmq_close(puller);
  zmq_ctx_term(context);
  printf("good bye and good luck\n");
  return 0;
}
