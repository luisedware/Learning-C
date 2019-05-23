#include<stdio.h>
/* C99 为类型大小提供一个 %zd 说明符 */
int main(int argc, char const *argv[])
{
	printf("Type int has a size of %u bytes\n",sizeof(int));
	printf("Type char has a size of %u bytes\n",sizeof(char));
	printf("Type long has a size of %u bytes.\n",sizeof(long));
	printf("Type double has a size of %u bytes.\n",sizeof(double));

	return 0;
}
