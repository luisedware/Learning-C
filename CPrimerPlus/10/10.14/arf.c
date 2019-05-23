/* arf.c -- 处理数组的函数 */
#include <stdio.h>
#define SIZE 5
void show_array(const double ar[],int n);
void mult_array(double ar[],int n, double mult);

int main(int argc, char const *argv[])
{
	double dip[SIZE] = {20.0,17.66,8.2,15.3,22.22};

	printf("The original dip array:\n");
	show_array(dip, SIZE);
	mult_array(dip, SIZE, 2.5);
	printf("The dip array after calling mult_array():\n");
	show_array(dip, SIZE);

	return 0;
}

void show_array(const double ar[], int n){
	/*
		使用 const 并不要求原始数组是固定不变的，这只是说明函数在处理数组时，
		应把数组当作是固定不变的。使用 const 可以对数组进行保护，可阻止函数
		修改调用函数中的数据。
	 */
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%8.3f",ar[i]);
	}
	putchar('\n');
}

void mult_array(double ar[], int n, double mult){
	int i;

	for(i = 0; i < n; i++){
		ar[i] *= mult;
	}
}
