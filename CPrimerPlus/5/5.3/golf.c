/* golf.c -- 高尔夫锦标赛积分卡 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int jane,tarzan,cheeta;

	/*
		许多程序语言将在本程序里的三重赋值处卡壳，但是 C 可以顺利接受它
		赋值是从右到左进行的。首页jane得到值68，然后 tarzan 得到值 68，最后 cheeta 得到值 68。
	*/

	cheeta = tarzan = jane = 68;
	printf("                  cheeta tarzan jane\n");
	printf("First round score %4d %6d %5d\nf",cheeta,tarzan,jane );
	return 0;
}
