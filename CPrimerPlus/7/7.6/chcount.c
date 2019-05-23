/* chcount.c -- 使用逻辑运算符 */
#include <stdio.h>
#define PERIOD '.'

int main(int argc, char const *argv[])
{
	int ch;
	int charcount = 0;
	/*
		程序读入一个字符并检查它是否是一个句号，因为句号标识着一个句子的技术。接下来的语句中，
		使用了逻辑与运算符&&，可以翻译为：“如果字符不是双引号并且它不是单引号，那么 charcount 增加1”
	 */
	while((ch = getchar()) != PERIOD){
		if(ch != '"' && ch != '\'')
			charcount++;
	}
	printf("There are %d non-quote characters.\n", charcount);
	return 0;
}
