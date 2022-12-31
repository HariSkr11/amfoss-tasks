#include <stdio.h>
#include <string.h>
#include <stdbool.h>
int main(){
    char p[1000];
    bool a = strcmp(p,"");
    printf("%d",a);
    return 0;
}