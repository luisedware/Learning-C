/* designate.c -- 使用指定初始化项目 */
#include <stdio.h>
#define MONTHS 12

int main(int argc, char const *argv[])
{
	int days[MONTHS] = {31,28,[4]=31,30,31,[1]=29};
	int i;

	/*
		第一，如果在一个指定初始化项目后跟有不止一个值，例如在序列[4]=31，30，31中这样，
		则这些数值将用于对后续的数组元素初始化。也就是说，把31赋给days[4]之后，接着把30和31
		赋给days[5]和days[6]
	 */
	/*
		第二，如果多次对一个元素进行初始化，则最后一次有效。
	 */
	for ( i = 0; i < MONTHS; i++)
	{
		printf("%2d %d\n",i+1,days[i] );
	}
	return 0;
}
