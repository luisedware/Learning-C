#include<stdio.h>

int main(){
    int num,i;
    int arr[50] = {0};

    scanf("%d",&num);

    arr[1] = 1;
    for(i = 2;i<50;i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    printf("%d\n",arr[num]);

    return 0;
}
