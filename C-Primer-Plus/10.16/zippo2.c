/* zippo2.c -- 通过一个指针变量获取有关 zippo 的信息 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	// 声明一个二维数组
	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};

	// 声明一个指向二维数组的指针变量
	int (*pz)[2];

	// 将二维数组zippo的起始地址赋值给指针变量pz
	pz = zippo;

	printf("pz    = %p, pz + 1 = %p\n",
		pz,pz+1);
	printf("*pz   = %p,*pz + 1 = %p\n",
		*pz,*pz + 1);
	printf("pz[0] = %p,pz[0] + 1 = %p\n",
		pz[0],pz[0] + 1);
	printf("==============================\n");

	printf("    **pz = %d\n",**pz);
	printf("  *pz[0] = %d\n",*pz[0]);
	printf("pz[0][0] = %d\n",pz[0][0]);
	printf("==============================\n");
	printf("      	pz[2][1] = %d\n",pz[2][1]);
	printf("* (* (pz+2) + 1) = %d\n",* (* (pz+2) + 1));
	return 0;
}
