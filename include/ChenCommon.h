#ifndef __CHEN_COMMON_H__
#define __CHEN_COMMON_H__
#include <pthread.h>
#include <event.h>
#include <queue>
#include <netinet/tcp.h>
#include <sys/time.h>

const int RET_SUCCESS = 0;
const int RET_FAILURE = 1;
const int THREADNUMBER = 2;

#define ChenGettimeofday(tp)  (void) gettimeofday(tp, NULL);
#define ChenMsleep(ms)        (void) usleep(ms * 1000)
#define ChenSleep(s)          (void) sleep(s)

typedef struct 
{
    int index;
	pthread_t thread_id;
	struct event_base *base;
	struct event notify_event;
	int send_notify_fd;
	int receive_notify_fd;
}EVENT_HANDLER;

typedef struct ConnQueue
{
  pthread_mutex_t lock;
  pthread_cond_t  cond;
  std::queue <int >  fdQ;
}ConnQueue;

#endif