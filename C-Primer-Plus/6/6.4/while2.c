/* while2.c -- 注意分号的使用 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n = 0;

	// 一个单独的分号也算做一个语句，循环将在此处终止
	while(n++ < 3);
		printf("n is %d\n",n);
	printf("That 's all this program does.\n");

	return 0;
}
