/* flags.c -- 一些格式标识的使用示例 */
#include<stdio.h>

int main(int argc, char const *argv[])
{
	printf("%x %X %#x",31,31,31);
	printf("**%d**% d**% d**\n",42,42,-42);
	printf("**%5d**%5.3d**%05.3d**\n",6,6,6,6);
	return 0;
}
