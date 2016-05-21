/* rain.c -- 针对若干年的降水量数据，计算年降水总量、年降水平均量，以及月降水平均量 */
#include <stdio.h>
#define MONTHS 12
#define YEARS 5

int main(int argc, char const *argv[])
{
	// 把数组初始化为 2000 年到 2004 年的降水量数据
	const float rain[YEARS][MONTHS] = {
		{1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9,1.1,1.1,1.1},
		{2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2,2.2},
		{3.9,3.9,3.9,3.9,3.9,3.9,3.9,3.9,3.9,3.9,3.9,3.9},
		{4.8,4.8,4.8,4.8,4.8,4.8,4.8,4.8,4.8,4.8,4.8,4.8},
		{5.7,5.7,5.7,5.7,5.7,5.7,5.7,5.7,5.7,5.7,5.7,5.7}
	};

	int year, month;
	float subtot, total;
	printf("YEAR RAINFALL (inches)\n");

	for (year = 0,total = 0;year < YEARS; year++)
	{
		// 对于每一年、各个月的总降水量
		for (month = 0,subtot = 0; month < MONTHS; month++)
		{
			subtot += rain[year][month];
		}
		printf("%5d %15.1f\n",2000 + year,subtot );
		total += subtot; // 所有年度的总降水量
	}
	printf("\nThe yearly average is %.1f inches.\n\n",total/YEARS );
	printf("MONTHLY AVERAGES:\n\n");
	printf(" Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dec \n");

	for (month = 0; month < MONTHS; month++)
	{
		// 对于每个月，各年该月份的总降水量
		for (year = 0,subtot = 0;year < YEARS; year++)
		{
			subtot += rain[year][month];
		}
		printf("%4.1f",subtot/YEARS );
	}
	printf("\n");

	return 0;
}
