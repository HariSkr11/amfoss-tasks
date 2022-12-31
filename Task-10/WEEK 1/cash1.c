#include <stdio.h>
#include <stdbool.h>
int count_cash[4] ={0,0,0,0};
void get_countcash(int cash){
    while (cash>25){
        cash = cash-25;
        count_cash[0]++;
    }
    while (cash>10){
        cash = cash-10;
        count_cash[1]++;
    }
    while (cash>5){
        cash = cash-5;
        count_cash[2]++;
    }
    while (cash>0){
        cash = cash-1;
        count_cash[3]++;
    }
}

int main(){

    int cash;
    while (true){
    printf("Enter the number of cents you have : ");
    scanf("%d",&cash);
        if (cash>0){

    char money[4][15] = {"25","10","5","1"};
    
    get_countcash(cash);
    for(int i=0;i<4;i++){
        printf("\n The number of %s needed is %d\n",money[i],count_cash[i]);
    }
        break;
        }
        else{
            continue;
        }
    }
    return 0;   
}