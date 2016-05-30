/* pound.c -- 定义带有一个参数的函数 */
#include <stdio.h>
void pound(int n);	/* ANST 风格的原型*/

int main(int argc, char const *argv[])
{
	int times = 5;
	char ch = '!';
	float f = 6.0;
	pound(times);
	pound(ch);
	pound((int) f);
	return 0;
}
/*
	如果函数不接受参数，函数头里的圆括号将包含关键字 void。
	因为此函数接受一个 int 类型的参数，所有圆括号里包含了
	一个名字为 n 的 int 类型变量的声明。你可以使用符合 C
	的命名规则的任何名字
 */
void pound(int n){
	while(n-- > 0){
		printf("#");

	}
	printf("\n");
}
