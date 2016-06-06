/* echo_eof.c -- 重复输入，知道文件的结尾 */
#include <stdio.h>

int main(int argc, const char * argv[])
{
    int ch;
    /*
        每次您按下回车键，就会处理缓冲区中存储的字符，并且打印该行的一个副本
     */
    while ((ch = getchar()) != EOF) {
        putchar(ch);
    }

    return 0;
}
