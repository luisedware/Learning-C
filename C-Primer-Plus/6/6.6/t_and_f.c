/* t_and_f.c -- C 中的真和假 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int true_val, false_val;

	true_val = (10 > 2); /* 一个真表达式的值 */
	false_val = (10 == 2); /* 一个假表达式的值 */
	printf("true = %d; false = %d \n",true_val, false_val);
	return 0;
}
