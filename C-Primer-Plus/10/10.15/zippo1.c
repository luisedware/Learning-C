/* zippol.c -- 有关zippo的信息 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int zippo[4][2] = {{2,4},{6,8},{1,3},{5,7}};

	printf("================\n");
	printf("zippo = %p, zippo + 1 = %p\n",
		zippo, zippo + 1);
	printf("*zippo = %p, *zippo + 1 = %p\n",
		*zippo,*zippo +1);
	printf("zippo[0] = %p, zippo[0] + 1 = %p\n",
		zippo[0],zippo[0] + 1);
	/*
		输出显示二维数组 zippo 的地址和一维数组 zippo[0] 的地址是相同
		均为相应的数组首页元素的地址，它的值是和&zippo[0][0]相同的。
		然而，差别也是有的。在我们的系统上，int 是 4 个字节长。zippo[0] 指向
		4 字节长的数据对象。对 zippo[0] 加 1 导致它的值增加4。数组名 zippo
		是包含两个 int 数的数组的地址，因此它指向 8 字节长的数据对象。
	*/

	printf("================\n");
	printf("    **zippo = %d\n",**zippo);
	printf("  *zippo[0] = %d\n",*zippo[0]);
	printf("zippo[0][0] = %d\n",zippo[0][0]);
	/*
		程序显示 zippo[0] 和 *zippo 是相同的，这点是正确的。另一方面，
		二维数组名必须两次取值才可以取出数组中存储的数据。这可以两次使用
		间接运算符 * 来实现，或者两次使用方括号运算符 [] 来实现，也可以是采用
		一次 * 和 一次 [] 来实现
	 */

	printf("================\n");
	printf("       zippo[2][1] = %d \n",zippo[2][1]);
	printf("*(*(zippo +2) + 1) = %d\n",*(*(zippo+2)+1));
	/*
		zippo 第 1 个大小为 2 个 int 的元素的地址
		zippo+2 第 3 个大小为 2 个 int 的元素的地址
		* (zippo+2) 第 3 个元素，即包含 2 个 int 值的数组，因此也是其第 1 个元素的地址
		* (zippo+2) + 1 包含2个 int 值的数组的第2元素的地址
		* (*(zippo+2)+1) 数组第3行第2个int(zippo[2][1])的值
	 */

	return 0;
}
