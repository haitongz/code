#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*
 * puller作为连接端，主动连接pusher。
 * ZMQ_PUSH 端进行bind操作,由各个ZMQ_PULL进行connect 操作， 连接到同一个ZMQ_PUSH.
 */

int main(int argc, char** argv)
{
  if (argc < 4) {
    printf("usage : %s pusher_cnt pusher_ip1 pusher_port1 pusher_ip2 pusher_port2\n", argv[0]);
    printf("example: %s 2 127.0.0.1 36890 127.0.0.1 36891\n", argv[0]);
    return -1;
  }

  int pusher_cnt = atoi(argv[1]);
  if (pusher_cnt * 2 != (argc - 2)) {
    printf("pusher addr invalid!\n");
    printf("usage : %s pusher_cnt pusher_ip1 pusher_port1 pusher_ip2 pusher_port2\n", argv[0]);
    printf("example: %s 2 127.0.0.1 36890 127.0.0.1 36891\n", argv[0]);
    return -2;
  }

  int major, minor, patch;
  zmq_version (&major, &minor, &patch);
  printf ("Current 0MQ version is %d.%d.%d\n", major, minor, patch);
  printf("===========================================\n\n");

  /* 创建ZMQ_PULL套接字 */
  void* context = zmq_ctx_new();
  void* puller = zmq_socket(context, ZMQ_PULL);
  for (int i = 2; i < argc; i+=2) {
    char addr[128] = {0};
    snprintf(addr, sizeof(addr), "tcp://%s:%s", argv[i], argv[i+1]);
    printf("connect %s ...\n", addr);
    int rec = zmq_connect(puller, addr);
    if (rec) {
      printf("zmq_connect %s error(%d):%s\n", addr, rec, zmq_strerror(rec));
      zmq_close(puller);
      zmq_ctx_term(context);
      return -3;
    }

    printf("connect %s ... success!\n", addr);
  }

  while (1) {
    char buf[128] = {0};
    int rec = zmq_recv(puller, buf, sizeof(buf), 0);
    printf("[%ld][%s] recv request(%s) from pusher, rec = %d, request.len = %lu\n", time(NULL), argv[0], buf, rec, strlen(buf));
  }

  zmq_close(puller);
  zmq_ctx_term(context);

  printf("good bye and good luck!\n");
  return 0;
}

// problem
// ZMQ_PUSH发送的频率大于ZMQ_PULL接收的频率的时候，ZMQ_PULL端会缓存起所有消息。
// 即使ZMQ_PULL端还没调用zmq_recv函数接收消息，而ZMQ_PUSH端发送完消息就退出，
// ZMQ_PULL端也不会丢失消息。ZMQ_PULL端最终还是可以通过zmq_recv函数拿到消息。
// 可以理解为ZMQ_PULL端有一个接收队列保存收到的消息，可以慢慢的通过zmq_recv函数来消费。
