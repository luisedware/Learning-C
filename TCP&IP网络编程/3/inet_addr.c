/*
 * Created by SebastianKennedy on 2019-05-23
 *
 * 将字符串形式的 IP 地址转换成 32 位整数型数据
 *
 * */

#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
  char *addr1 = "1.2.3.4";
  char *addr2 = "1.2.3.256";

  unsigned long conv_addr = inet_addr(addr1);
  if (conv_addr == INADDR_NONE)
    printf("Error occured! \n");
  else
    printf("Network ordered integer add: %#lx \n", conv_addr);

  conv_addr = inet_addr(addr2);
  if (conv_addr == INADDR_NONE)
    printf("Error occured! \n");
  else
    printf("Network ordered integer add: %#lx \n", conv_addr);
  return 0;
}