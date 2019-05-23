/* animals.c -- 使用switch语句 */
#include <stdio.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char ch;
	printf("Give me a letter of the alphabet, and I will give ");
	printf("an animal name\nbeginning with that letter. \n");
	printf("Please type in a letter: type # to end my act. \n");
	while((ch = getchar()) != '#'){
		if('\n' == ch){
			continue;
		}
		if(islower(ch)){/* 只识别小写字母 */
			switch(ch){
				case 'a':
				printf("argali, a wild sheep of Asia \n");
				break;
				case 'b':
				printf("argali, b wild sheep of Asia \n");
				break;
				case 'c':
				printf("argali, c wild sheep of Asia \n");
				break;
				case 'd':
				printf("argali, d wild sheep of Asia \n");
				break;
				case 'e':
				printf("argali, e wild sheep of Asia \n");
				break;
				case 'f':
				printf("argali, f wild sheep of Asia \n");
				break;
				default:
				printf("That 's a stumper!\n");
			}
		}else{
			printf("I recognize only lowercase letters.\n");
		}
		while(getchar() != '\n'){
			continue;
		}
		printf("Please type another letter or a #.\n");
	}
	printf("Bye");
	return 0;
}
