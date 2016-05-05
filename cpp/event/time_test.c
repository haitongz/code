#include <stdio.h>
#include <event.h>

void onTime(int sock, short event, void *arg)
{
  printf("Game over\n");

  struct timeval tv;
  tv.tv_sec = 1;
  tv.tv_usec = 0;

  /// 事件执行后，默认就被删除，需要重新add, 使之重复执行
  event_add((struct event*)arg, &tv);
}

int main(int argc, char *argv[])
{
  event_init();

  struct event evTime;
  evtimer_set(&evTime, onTime, &evTime);

  struct timeval tv;
  tv.tv_sec = 1;
  tv.tv_usec = 0;

  // 添加事件
  event_add(&evTime, &tv);
  // 循环派发事件
  event_dispatch();

  return 0;
}

// gcc time_test.c -levent
