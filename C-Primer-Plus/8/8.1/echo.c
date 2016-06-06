/* echo.c -- 重复输入 */
#include <stdio.h>
/*
	getchat() 和 putchar() 每次输入和输出一个字符。
	这个例子是获取从键盘输入的字符并将其发送至屏幕
 */
int main(int argc, char const *argv[])
{
	char ch;
	while((ch = getchar()) != '#'){
		putchar(ch);
	}
	return 0;
}
