/* rules.c -- 优先级规则的试验 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	int top, score;
	top = score = - (2 + 5) * 6 + (4 + 3 * (2 + 3));
	printf("top = %d \n", top);
	return 0;
}
