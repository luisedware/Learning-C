/* squares.c -- 产生前20个整数的平方表 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int num = 1;
	while(num < 21){
		printf("%4d %6d\n",num,num*num );
		num = num + 1;
	}
	return 0;
}
