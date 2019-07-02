#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid = fork();

  if (pid == 0) {
    // 子进程提前执行完毕
    puts("Hi, I am a child process");
  } else {
    // 父进程暂定 30 秒
    printf("Child Process ID: %d \n", pid);
    sleep(30);
  }

  if (pid == 0) {
    // 没有向父进程传递子进程的 exit 参数或 return
    // 语句的返回值，子进程成为僵尸进程
    puts("End child process");
  } else {
    puts("End parent process");
  }

  // 执行 ps aux | grep pid 结果
  // sebastian  4785   0.0  0.0  0  0 s002  ZN   11:19AM   0:00.00 (zombie)

  return 0;
}