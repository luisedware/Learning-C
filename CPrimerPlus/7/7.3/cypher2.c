/* cypher2.c -- 改变输入，只保留非字母字符 */
#include <stdio.h>
#include <ctype.h>
#define SPACE ' ' /* SPACE 相当于 "引号-空格-引号"*/

int main(int argc, char const *argv[])
{
	char ch;

	while((ch = getchar()) != '\n'){
		if(isalpha(ch))
			putchar(ch + 1);
		else
			putchar(ch);
	}

	// 等同于printf("%c", ch);
	putchar(ch);

	return 0;
}
