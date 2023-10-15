#include<stdio.h>
int main(){
    int a,b;
    printf("Enter a number\n");
    scanf("%d", &a);
    if(a%2 == 0){
        printf("%d is even\n");

    }
    else{
        printf("%d is odd\n");
    }
    return 0;

}
