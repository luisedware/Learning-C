#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 100

void error_handling(char *message);

int main(int argc, char *argv[]) {
  int server_socket, client_socket;
  struct sockaddr_in server_address, client_address;
  socklen_t server_address_size, client_address_size;

  struct timeval timeout;
  fd_set reads, copy_reads;
  int fd_max, str_len, fd_num, i;
  char buffer[BUFFER_SIZE];

  if (argc != 3) {
    printf("Usage: %s <ip> <port>", argv[0]);
    exit(1);
  }

  // 创建套接字
  server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (server_socket == -1) {
    error_handling("socket() error");
  }

  // 初始化网络地址
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(argv[1]);
  server_address.sin_port = htons(atoi(argv[2]));

  // 分配套接字地址
  server_address_size = sizeof(server_address);
  if (bind(server_socket, (struct sockaddr *)&server_address,
           server_address_size) == -1) {
    error_handling("bind() error");
  }

  // 套接字转换受理请求状态
  if (listen(server_socket, 5) == -1) {
    error_handling("listen() error");
  }

  // 将 fd_set 变量的所有位初始化为 0
  FD_ZERO(&reads);

  // 在 fd_set 变量中注册指定文件描述符信息
  FD_SET(server_socket, &reads);
  fd_max = server_socket;

  while (1) {
    // 设置 select 事件监听阻塞过期时间
    copy_reads = reads;
    timeout.tv_sec = 5;
    timeout.tv_usec = 5000;

    if ((fd_num = select(fd_max + 1, &copy_reads, 0, 0, &timeout)) == -1) {
      break;
    }

    if (fd_num == 0) {
      continue;
    }

    for (i = 0; i < fd_max + 1; i++) {
      // 如果 fd_set 变量中存在指定文件描述符，则返回 true
      if (FD_ISSET(i, &copy_reads)) {

        if (i == server_socket) {
          client_address_size = sizeof(client_address);
          client_socket =
              accept(server_socket, (struct sockaddr *)&client_socket,
                     &client_address_size);

          // 在 fd_set 变量中注册指定文件描述符信息
          FD_SET(client_socket, &reads);

          if (fd_max < client_socket) {
            fd_max = client_socket;
          }

          printf("connected client: %d \n", client_socket);
        } else {
          str_len = read(i, buffer, BUFFER_SIZE);
          if (str_len == 0) {
            // 在 fd_set 变量中清除指定文件描述符
            FD_CLR(i, &reads);
            close(i);
            printf("closed client: %d \n", i);
          } else {
            write(i, buffer, str_len);
          }
        }
      }
    }
  }

  // 关闭套接字连接
  close(server_socket);
  return 0;
}

void error_handling(char *message) {
  fputs(message, stderr);
  fputc('\n', stderr);
}