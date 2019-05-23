/* cypher1.c -- 改变输入，只保留其中的空格 */
#include <stdio.h>
#define SPACE ' ' /* SPACE 相当于 "引号-空格-引号"*/

int main(int argc, char const *argv[])
{
	char ch;

	ch = getchar();

	while(ch != '\n'){
		if(ch == SPACE)
			putchar(ch);
		else
			putchar(ch + 1);
		ch = getchar();
	}
	// 等同于printf("%c", ch);
	putchar(ch);

	return 0;
}
