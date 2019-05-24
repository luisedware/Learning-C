/*
 * Created by SebastianKennedy on 2019-05-23.
 *
 * 字节序转换 - 主机字节序转换成网络字节序
 *
 * */

#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  unsigned short host_port = 0x1234;
  unsigned long host_addr = 0x12345678;

  unsigned short net_port;
  unsigned long net_addr;

  net_port = htons(host_port);
  net_addr = htonl(host_addr);

  printf("Host ordered port: %#x \n", host_port);
  printf("Network ordered port: %#x \n", net_port);
  printf("Host ordered address: %#lx \n", host_addr);
  printf("Network ordered address: %#lx \n", net_addr);
}