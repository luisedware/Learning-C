```
#include <sys/socket.h>

/*
 * 创建套接字
 *
 * @param int protocol_family - 套接字所使用的协议族：PF_INET、PF_INET6、PF_LOCAL
 * @param int type - 套接字数据传输类型：SOCK_STREAM、SOCK_DGRAM
 * @param int protocol - 计算机间通信中使用的具体协议信息：IPPROTO_TCP、IPPROTO_UDP
 * 
 * @return 成功时返回文件描述符
 */
int socket(int protocol_family, int type, int protocol);

/*
 * 分配套接字地址
 *
 * @param int sockfd - 需要分配地址的套接字的文件描述符
 * @param struct sockaddr * myaddr - 存有地址信息的结构体变量地址值
 * @param socklen_t addrlen - 参数 myaddr 的长度
 * 
 * @return 成功时返回 0，失败时返回 -1
 */
int bind(int sockfd, struct sockaddr * myaddr, socklen_t addrlen);


/* 
 * sockaddr_in 结构体
 * 
 * sin_family - 地址族：AF_INET、AF_INET6
 * sin_port - TCP/UDP 端口号
 * sin_addr - IP 地址
 * sin_zero - 无特殊含义
 */
struct sockaddr_in
{
  sa_family_t 		sin_family;
  uint16_t 			sin_port;
  struct in_addr 	sin_addr;
  char				sin_zero[8];
}

/*
 * in_addr 结构体
 *
 * s_addr - 32 位 IP 地址
 *
 */
struct in_addr
{
  in_addr_t 	s_addr;
}

/* 
 * sockaddr 结构体
 * 
 * sin_family - 地址族
 * sa_data[14] - 地址信息
 *
 * 使用 sockaddr_in 结构体填充地址信息，最后转换成 sockaddr 结构体变量传递给 bind 函数
 */
struct sockaddr
{
  sa_family_t 	sin_family;
  char			sa_data[14];
}

// 初始化内存，将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换
void *memset(void *s, int c, unsigned long n);

// 把参数 str 所指向的字符串转换为一个整数
int atoi(const char *str)

/*
 * 套接字进入等待连接请求状态
 *
 * @param int sock - 套接字描述符
 * @param int backlog - 连接请求等待队列长度
 * 
 * @return 成功时返回 0，失败时返回 -1
 */
int listen(int sock, int backlog);

/*
 * 套接字受理客户端连接请求
 *
 * @param int sock - 套接字描述符
 * @param sockaddr addr - 填充客户端地址
 * @param socklen_t addrlen - 填充客户端地址长度
 * 
 * @return 成功时返回 0，失败时返回 -1
 */
int accept(int sock, struct sockaddr * addr, socklen_t * addrlen);

/*
 * 客户端套接字连接服务端
 *
 * @param int sock - 套接字描述符
 * @param sockaddr servaddr - 目标服务端地址信息的变量地址值
 * @param socklen_t addrlen - 目标服务端地址信息的变量长度
 * 
 * @return 成功时返回 0，失败时返回 -1
 */
int connect(int sock, struct sockaddr * servaddr, socklen_t addrlen);


#include <unistd.h>

/*
 * 关闭套接字
 *
 * @param int sock - 套接字描述符
 * 
 * @return 成功时返回 0，失败时返回 -1
 */
int close(int sock);
```