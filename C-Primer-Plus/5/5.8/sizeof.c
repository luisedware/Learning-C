/* sizeof.c -- 使用 sizeof 运算符 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n = 0;
	size_t intsize;
	intsize = sizeof(int);
	printf("n = %d, n as %zd bytes: all ints have %zd bytes.\n",n,sizeof n,intsize );
	return 0;
}
