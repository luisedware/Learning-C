#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 30
void error_handling(char *message);

int main(int argc, char *argv[]) {
  int sd;
  FILE *fp;

  char buf[BUF_SIZE];
  int read_cnt;
  struct sockaddr_in serv_adr;

  if (argc != 3) {
    printf("Usage: %s <ip> <port> \n", argv[0]);
    exit(1);
  }

  // 创建新文件以保存服务端传输的文件数据
  fp = fopen("receive.dat", "wb");
  sd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

  memset(&serv_adr, 0, sizeof(serv_adr));
  serv_adr.sin_family = AF_INET;
  serv_adr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_adr.sin_port = htons(atoi(argv[2]));

  connect(sd, (struct sockaddr *)&serv_adr, sizeof(serv_adr));

  while ((read_cnt = read(sd, buf, BUF_SIZE)) != 0) {
    // 接收数据并保存到第 18 行创建的文件，直到接收 EOF 为止
    fwrite((void *)buf, 1, read_cnt, fp);
  }

  puts("Received file data");
  write(sd, "Thank You", 10);
  fclose(fp);
  close(sd);

  return 0;
}

void error_handling(char *buf) {
  fputs(buf, stderr);
  fputc('\n', stderr);
  exit(1);
}