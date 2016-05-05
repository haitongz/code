#include <zmq.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

/*
 * push作为bind端，由多个pull连接。
 */
int main(int argc, char** argv)
{
  if (argc < 4) {
    printf("usage : %s bind_ip bind_port pusher_name\n", argv[0]);
    printf("example : %s 127.0.0.1 36890 pusher_leo\n", argv[0]);
    printf("example : %s 127.0.0.1 36891 pusher_ox\n", argv[0]);
    return -1;
  }


  int major, minor, patch;
  zmq_version (&major, &minor, &patch);
  printf ("Current 0MQ version is %d.%d.%d\n", major, minor, patch);
  printf("===========================================\n\n");

  /* 创建ZMQ_PUSH套接字 */
  void* context = zmq_ctx_new();
  void* pusher = zmq_socket(context, ZMQ_PUSH);
  char addr[128] = {0};
  snprintf(addr, sizeof(addr), "tcp://%s:%s", argv[1], argv[2]);
  printf("bind %s ...\n", addr);
  int rec = zmq_bind(pusher, addr);
  if (rec) {
    printf("zmq_bind %s error(%d):%s\n", addr, rec, zmq_strerror(rec));
    zmq_close(pusher);
    zmq_ctx_term(context);
    return -2;
  }

  printf("bind %s ... success!\n", addr);

  char buf[128] = {0};
  uint8_t index = 0;
  while (1) {
    snprintf(buf, sizeof(buf), "pusher=%s&taskid=%d&time=%ld", argv[3], index++, time(NULL));
    int rec = zmq_send(pusher, buf, strlen(buf), 0);
    printf("[%ld] send task(%s) to puller, rec = %d, task.len = %lu\n", time(NULL), buf, rec, strlen(buf));
    printf("[%ld]------------------------\n\n", time(NULL));
    sleep(5);
  }

  zmq_close(pusher);
  zmq_ctx_term(context);

  printf("good bye and good luck!\n");
  return 0;
}
