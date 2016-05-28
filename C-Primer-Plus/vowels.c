/* vowels.c -- 使用多重标签 */
#include <stdio.h>

int main(int argc, char const *argv[])
{
	char ch;
	int a_ct, e_ct, i_ct, o_ct, u_ct;

	a_ct = e_ct = i_ct = o_ct = u_ct = 0;
	printf("Enter some text: enter # to quit. \n");
	while((ch = getchar) != "#"){
		switch(ch){
			case 'a':
			case 'A':
				a_ct++;
			break;
		}
	}
	return 0;
}
