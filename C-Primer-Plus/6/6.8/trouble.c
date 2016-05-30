/* trouble.c -- 误用 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	long num;
	long sum = 0L;

	int status;
	printf("Please enter an integer to be summed. ");
	printf("(q to quit): ");

	status = scanf("%ld",&num);

	/* 它把 status 赋值为 1.等于是使用了 while(1) ，也就是说循环永远不会退出 */
	while(status = 1){
		sum = sum + num;
		printf("Please enter next integer (q to quit): ");
		/*
			当 scanf() 未能读取指定形式的输入时，它就留下这个不相容的输入，以供
			下次进行读取。当 scanf() 试着把 q 作为整数读取并失败时，它就把 q 留
			在那里。在下次循环中读取前面留下来的 q 时，scanf() 再次失败。
		 */
		status = scanf("%ld",&num);
	}
	printf("Those integers sum to %ld.\n",sum);
	return 0;
}
