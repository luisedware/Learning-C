/* sweetie2.c -- 一个使用 for 的计数循环 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	const int NUMBER = 22;
	int n;
	int x;
	int y = 55;
	int ans;
	int num;
	int secs;
	int count;
	char ch;
	double debt;

	for (count = 1; count <= NUMBER; count++)
	{
		printf("Be my Valentine!,Number %d\n", count);
	}

	/*
		利用 for 的灵活性
		1. 使用减量运算符来减少计数器而不是增加它。
	 */
	for (secs = 5; secs > 0; secs--)
	{
		printf("%d seconds!\n", secs);
	}

	/*
		2. 可以让计数器依次加2, 加10
	 */
	for (n = 2; n < 60; n+=13)
	{
		printf("%d\n",n);
	}

	printf("We have ignition!\n");

	/*
		3. 也可以用字符代替数字来进行计数
		4. 也可以判断迭代次数之外的条件
	 */
	for (ch = 'a'; ch <= 'z'; ch++)
	{
		printf("The ASCII value for %c is %d.\n",ch,ch);
	}

	/* 5. 也可以让数量几何增加而不是算术增加 */
	for (debt = 100.0; debt < 150.0; debt = debt * 1.1)
	{
		printf("Your debt is now $%.2f.\n",debt);
	}

	/* 6. 在第三个表达式中，你可以使用所需的任何合法表达式。 */
	for (x = 1; y <= 75; y = (++x * 5) + 50)
	{
		printf("%10d %10d\n",x,y);
	}

	/* 7. 可以让一个或多个表达式为空，但是不要遗漏分号 */
	ans = 2;
	for (n = 3; ans <= 25;)
	{
		ans = ans * n;
	}
	printf("n = %d; ans = %d\n", n, ans);
	// for(;;){
	// 	printf("I want some action\n");
	// }

	/*
		8. 第一个表达式不必初始化一个变量，它也可以是某种类型的 printf() 语句
		要记住第一个表达式只在执行循环的其他部分之前被求值或执行一次
	*/
	for (printf("Keep entering numbers!\n"); num != 6;)
	{
		scanf("%d", &num);
	}
	printf("That 's the one I want !\n");

	/*
		9. 循环中的动作可以改变循环表达式的参数
	 */
	// for (n = 1; n < 10000; n = n +delta)
	// {
	// }

	return 0;
}
