#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void timeout(int sig) {
  if (sig == SIGALRM) {
    puts("Time out!");
  }
  alarm(2);
}

void keycontrol(int sig) {
  if (sig == SIGINT) {
    puts("CTRL+C Pressed");
  }
}

// 发生信号时将唤醒由于调用 sleep 函数而进入阻塞状态的进程
int main(int argc, char *argv[]) {
  int i;
  signal(SIGALRM, timeout);
  signal(SIGINT, keycontrol);
  alarm(2);

  for (i = 0; i < 3; i++) {
    puts("wait...");
    sleep(100);
  }

  return 0;
}