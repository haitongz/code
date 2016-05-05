#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
/*
 * push作为连接端，去连接多个pull端
 */

int main(int argc, char *argv[])
{
  if (argc < 4) {
    printf("usage : %s puller_cnt puller_ip1 puller_port1 puller_ip2 puller_port2\n", argv[0]);
    printf("example : %s 2 127.0.0.1 36888 127.0.0.1 36889\n", argv[0]);
    return -2;
  }

  int puller_cnt = atoi(argv[1]);
  if (puller_cnt * 2 != (argc -2))
  {
    printf("puller addr invalid!\n");
    printf("usage : %s puller_cnt puller_ip1 puller_port1 puller_ip2 puller_port2\n", argv[0]);
    printf("example : %s 2 127.0.0.1 36888 127.0.0.1 36889\n", argv[0]);
    return -2;
  }
  int major, minor, patch;
  zmq_version (&major, &minor, &patch);
  printf("Current ZMQ version is %d.%d.%d\n", major, minor, patch);
  printf("========================================\n\n");

  //创建ZMQ_PUSH套接字
  void* context = zmq_ctx_new();
  void* pusher = zmq_socket(context, ZMQ_PUSH);
  for (int i = 2; i < argc; i+=2)
  {
    char addr[128] = {0};
    snprintf(addr, sizeof(addr), "tcp://%s:%s", argv[i], argv[i+1]);
    printf("connect %s ...\n", addr);
    int rec = zmq_connect(pusher, addr);
    if (rec)
    {
      printf("zmq_connect %s error(%d):%s\n", addr, rec, zmq_strerror(rec));
      zmq_close(pusher);
      zmq_ctx_term(context);
      return -3;
    }
    printf("connect %s ... success!\n", addr);
  }

  char buf[128] = {0};
  uint8_t index = 0;
  while(1) {
    snprintf(buf, sizeof(buf), "taskid=%d&time=%ld", index++, time(NULL));
    int rec = zmq_send(pusher, buf, strlen(buf), 0);

    printf("[%ld] send task(%s) to puller, rec = %d, task.len= %lu\n", time(NULL), buf, rec, strlen(buf));
    printf("[%ld]--------------------------------\n\n", time(NULL));
    sleep(5);
  }

  zmq_close(pusher);
  zmq_ctx_term(context);

  printf("good bye and good luck, pusher\n");
  return 0;
}
