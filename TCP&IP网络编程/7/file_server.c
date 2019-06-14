#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 30

void error_handling(char *message);

int main(int argc, char *argv[]) {
  int serv_sd, clnt_sd;
  FILE *fp;
  char buf[BUF_SIZE];
  int read_cnt;

  struct sockaddr_in serv_adr, clnt_adr;
  socklen_t clnt_adr_sz;

  if (argc != 2) {
    printf("Usage: %s <port> \n", argv[0]);
    exit(1);
  }

  // 打开文件，用以向客户端传输文件 file_server.c
  fp = fopen("file_server.c", "rb");
  serv_sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
  serv_adr.sin_port = htons(atoi(argv[1]));

  bind(serv_sd, (struct sockaddr *)&serv_adr, sizeof(serv_adr));
  listen(serv_sd, 5);

  clnt_adr_sz = sizeof(clnt_adr);
  clnt_sd = accept(serv_sd, (struct sockaddr *)&clnt_adr, &clnt_adr_sz);

  while (1) {
    // 为向客户端传输文件数据而编写的循环语句
    read_cnt = fread((void *)buf, 1, BUF_SIZE, fp);
    if (read_cnt < BUF_SIZE) {
      write(clnt_sd, buf, read_cnt);
      break;
    }
    write(clnt_sd, buf, BUF_SIZE);
  }

  // 针对输出流进行半关闭，向客户端传输 EOF
  shutdown(clnt_sd, SHUT_WR);

  // 通过输入流接受数据
  read(clnt_sd, buf, BUF_SIZE);
  printf("Message from client: %s \n", buf);

  fclose(fp);
  close(clnt_sd), close(serv_sd);
  return 0;
}

void error_handling(char *buf) {
  fputs(buf, stderr);
  fputc('\n', stderr);
  exit(1);
}