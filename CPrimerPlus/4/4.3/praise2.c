#include <stdio.h>
#include <string.h>
#define PRAISE "What a super marvelous name!"

int main(int argc, char const *argv[])
{
	char name[40];

	printf("What's your name?\n");
	scanf("%s",name);
	printf("Hello. %s. %s.\n",name,PRAISE);
	printf("Your name of %d letters occupies %d memory cells.\n",strlen(name),sizeof name);
	printf("The phrase of praise has %d letters\n",strlen(PRAISE));
	printf("and occupies %d memory cells.\n",sizeof PRAISE);

	return 0;
}
