/* summing.c -- 对用户输入的整数求和 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	long num;
	long sum = 0L; /* 把 sum 初始化为 0L，类型为 long 的零 */
	int status;

	printf("Please enter an integer to be summed.");
	printf("q to quit): ");
 
	// 如果 scanf() 成功读取了一个整数，就把这个整数放在 num 中并返回值 1
	status = scanf("%ld",&num);

	while(status == 1){
		sum = sum + num;
		printf("Please enter next integer (q to quit):");
		status = scanf("%ld",&num);
	}
	printf("Those integers sum to %ld.\n",sum);
	return 0;
}
