#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREAD 4

void *thread_inc(void *arg);
void *thread_des(void *arg);

long long num = 0;

// 声明互斥量为全局变量，两个函数都需要访问
pthread_mutex_t mutex;

int main(int argc, char *argv[]) {
  pthread_t thread_id[NUM_THREAD];
  int i;

  pthread_mutex_init(&mutex, NULL);

  // 循环创建四个线程
  for (i = 0; i < NUM_THREAD; i++) {
    if (i % 2) {
      pthread_create(&(thread_id[i]), NULL, thread_inc, &(thread_id[i]));
    } else {
      pthread_create(&(thread_id[i]), NULL, thread_des, &(thread_id[i]));
    }
  }

  // 确保四个线程返回执行结果
  for (i = 0; i < NUM_THREAD; i++) {
    pthread_join(thread_id[i], NULL);
  }

  printf("result %lld \n", num);
  pthread_mutex_destroy(&mutex);

  return 0;
}

// 循环执行 10 次累加操作
void *thread_inc(void *arg) {
  int i;

  pthread_mutex_lock(&mutex);
  for (i = 0; i < 10; i++) {
    num += 10000;
    printf("num is: %lld \n", num);
  }
  pthread_mutex_unlock(&mutex);

  return NULL;
}

// 循环执行 10 次累减操作
void *thread_des(void *arg) {
  int i;
  for (i = 0; i < 10; i++) {
    pthread_mutex_lock(&mutex);
    num -= 10000;
    printf("num is: %lld \n", num);
    pthread_mutex_unlock(&mutex);
  }

  return NULL;
}
