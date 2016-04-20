#include<stdio.h>

int main(int argc, char const *argv[])
{
	double abet = 2.14e9;
	float aboat = 32000.0;
	float toobig = 3.4E38 * 100.0f;
	long double dip = 5.32e-5;
	printf("%f can be written %e\n",aboat,aboat);
	printf("%f can be written %e\n",abet,abet);
	printf("%f can be written %e\n",dip,dip);
	// 浮点数上溢
	printf("%e\n",toobig);
	return 0;
}
