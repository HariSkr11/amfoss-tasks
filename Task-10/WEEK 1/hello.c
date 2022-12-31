#include <stdio.h>
int main(){
    printf("Hello World\n");
    printf("Getting string input from the user\n");
    char s[100];
    scanf("%[^\n]s",s);
    printf("The inputted string is : %s\n",s);
    return 0;
}