/* strings.c -- 使用字符串与用户交互 */
#include <stdio.h>
#define MSG "You must have many talents. Tell me some."
#define LIM 5
#define LINELEN 81 // 最大字符串长度+1

int main(int argc, char const *argv[])
{
	char name[LINELEN];
	char talents[LINELEN];
	int i;
	// 初始化一个大小已确定的char数组
	const char m1[40] = "Limit yourself to one line's worth";

	// 让编译器计算数组大小
	const char m2[] = "If you can't think of anything, fake it.";

	// 初始化一个指针
	const char *m3 = "";

	// 初始化一个字符串指针的数组
	const char *mytal[LIM] = {
		"Adding numbers swiftly",
		"Multiplying accurately",
		"Stashing data",
		"Following instructions to the letter",
		"Understanding the C language"
	};
	return 0;
}
