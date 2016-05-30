/* add_one.c -- 增量: 前缀和后缀 */
#include <stdio.h>


int main(int argc, char const *argv[])
{
	int front = 0,back = 0;
	while(back < 5){
		back++;
		++front;
		printf("back = %d ,front = %d \n", back,front);
	}
	return 0;
}
