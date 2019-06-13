#include <arpa/inet.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <unistd.h>

#define BUFFER_SIZE 30

void error_handling(char *message);
void read_child_process(int sig);

int main(int argc, char *argv[]) {
  char buffer[BUFFER_SIZE];
  int server_socket, client_socket, result;
  struct sockaddr_in server_address, client_address;
  socklen_t server_address_size, client_address_size;

  struct sigaction action;
  int str_len, state;

  pid_t pid;

  // 判断是否传入 IP 地址和端口号
  if (argc != 3) {
    printf("Usage:%s <ip> <port>", argv[0]);
    exit(1);
  }

  // 注册信号处理函数
  action.sa_handler = read_child_process;
  sigemptyset(&action.sa_mask);
  action.sa_flags = 0;
  state = sigaction(SIGCHLD, &action, 0);

  // 创建套接字
  server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  // 初始化网络地址
  server_address_size = sizeof(server_address);
  memset(&server_address, 0, server_address_size);
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(argv[1]);
  server_address.sin_port = htons(atoi(argv[2]));

  // 分配套接字网络地址
  result = bind(server_socket, (struct sockaddr *)&server_address,
                sizeof(server_address));
  if (result == -1) {
    error_handling("bind() error.");
  }

  // 套接字进入请求受理状态，请求受理队列为 5
  result = listen(server_socket, 5);
  if (result == -1) {
    error_handling("listen() error");
  }

  // 套接字读取请求并进行受理
  while (1) {
    client_address_size = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address,
                           &client_address_size);
    if (client_socket == -1) {
      continue;
    } else {
      puts("new client connected...");
    }

    // fork 子进程去处理请求
    pid = fork();
    if (pid == -1) {
      close(client_socket);
      puts("fork() error");
      continue;
    }

    if (pid == 0) {
      // 关闭服务端套接字
      close(server_socket);

      // 客户端套接字输入
      while ((str_len = read(client_socket, buffer, BUFFER_SIZE)) != 0) {
        // 客户端套接字输出
        write(client_socket, buffer, str_len);
      }

      close(client_socket);
      puts("client disconnected...");

      return 0;
    } else {
      close(client_socket);
    }
  }

  // 关闭套接字
  close(server_socket);

  return 0;
}

void error_handling(char *message) {
  // 将指定的字符串写入到指定的流中
  fputs(message, stderr);

  // 将指定的字符写入到指定的流中
  fputc('\n', stderr);

  // stderr 标准错误输出，一种输出流
  exit(1);
}

void read_child_process(int sig) {
  pid_t pid;
  int status;

  // 非阻塞主动销毁僵尸进程
  pid = waitpid(-1, &status, WNOHANG);
  printf("removed process id: %d \n", pid);
}