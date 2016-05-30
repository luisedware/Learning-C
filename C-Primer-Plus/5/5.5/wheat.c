/* wheat.c -- 指数增长 */
#include <stdio.h>
#define SQUARES 64 /* 棋盘上的方格数 */
#define CROP 1E15 /* 以粒计的美国小麦产量 */

/* 这个例子演示了指数增长的现象。世界人口增长和我们对能源的使用都遵循同样的模式 */
int main(int argc, char const *argv[])
{
	double current,total;
	int count = 1;

	printf("square grains total  ");
	printf("fraction of \n");
	printf("    added      grain        ");
	printf("US total\n");
	total = current = 1.0; /* 开始时是1粒	*/
	printf("%4d %13.2e %12.2e %12.2e \n",count,current,total,total/CROP);
	while(count < SQUARES){
		count  = count + 1;
		current = 2.0 * current; /* 下个方格的粒数加倍 */
		total = total + current;
		printf("%4d %13.2e %12.2e %12.2e\n",count,current,total,total/CROP);
	}
	return 0;
}
