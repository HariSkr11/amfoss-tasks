#include <stdio.h>
#include <string.h>
#include <stdbool.h>
void pattern(int n){
    for (int i=1; i<n+1;i++){
        char out[1000] = "";
        for (int j = 0;j<n-i;j++){
             strcat(out," ");
        }
        char hash[1000] = "";
        for(int h=0;h<i;h++){
            strcat(hash,"#");
        }
        strcat(out,hash);
        printf("%s\n",out);
    }
}
int main(){
    int n;
    while (true){
    printf("\nHeight:");
    scanf("%d",&n);
    if (n<=8 && n>0){
    pattern(n);
    break;
    }
    }
    return 0;
}