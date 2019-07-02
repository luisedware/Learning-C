#include <stdio.h>
#include <unistd.h>

int gval = 10;
int main(int argc, char *argv[]) {
  pid_t pid;
  int lval = 20;
  gval++, lval += 5;

  // fork 函数创建进程副本
  pid = fork();

  // 父进程和子进程都将执行 fork 函数调用后的语句
  if (pid == 0)
    gval += 2, lval += 2;
  else
    gval -= 2, lval -= 2;

  // PID 为 0 为子进程
  if (pid == 0)
    printf("Child Proc: [%d, %d] \n", gval, lval);
  else
    printf("Parent Proc: [%d, %d] \n", gval, lval);

  return 0;
}