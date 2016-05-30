/* zeno.c -- 序列的和 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
	int t_ct; // 项计数
	int limit;
	long double time,x;

	printf("Enter the number of terms you want: ");
	scanf("%d",&limit);
	for (time = 0, x = 1, t_ct = 1; t_ct <= limit; t_ct++,x *= 2.0)
	{
		time += 1.0/x;
		printf("time = %Lf when terms = %d\n",time,t_ct);
	}
	return 0;
}
