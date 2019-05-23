/* defines.c -- 使用limits.h 和 float.h 中定义的常量 */
#include<stdio.h>
#include<limits.h>
#include<float.h>

int main(int argc, char const *argv[])
{
	printf("Some number limits for this system:\n");
	printf("Biggest int:%d\n",INT_MAX);
	printf("Smallest unsigned long:%lld.\n",LLONG_MIN);
	printf("One byte = %d bits on this system.\n",CHAR_BIT);
	printf("Larggest double:%e\n",DBL_MAX);
	printf("Smallest normal float:%e\n",FLT_MIN);
	printf("float precision = %d digits\n",FLT_DIG);
	printf("float epsilon = %e\n",FLT_EPSILON);

	return 0;
}
