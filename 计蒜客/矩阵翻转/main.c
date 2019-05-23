#include<stdio.h>

int main()
{
	//M为行数，N为列数，Mode为上下(0)/左右(1)模式的选择
	int m,n,type;
	int i,j;
	int beforeArr[200][200]={0},afterArr[200][200]={0};

	//输入矩阵的行数、列数、翻转模式和需要翻转的数组
	scanf("%d%d%d",&m,&n,&type);
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d",&beforeArr[i][j]);
		}
	}

	//输入矩阵的翻转模式
	if (type == 0)
	{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				afterArr[i][j] = beforeArr[i][n-j-1];
			}
		}
	}else{
		for (i = 0; i < m; i++)
		{
			for (j = 0; j < n; j++)
			{
				afterArr[i][j] = beforeArr[m-i-1][j];
			}
		}
	}

	//输出矩阵翻转后的结果
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ",afterArr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
