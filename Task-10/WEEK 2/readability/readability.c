#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
void get_letters(char *a){

    int letters= 0;
    int words = 0;
    int sentences = 0;
    int size = strlen(a);
    for(int i = 0;i<size;i++){
        if (a[i]>='A' && a[i]<='Z' || a[i]>='a' && a[i]<='z'){
            letters++;
        }
        else if(isspace(a[i])){
            words++;
        }
        else if(*(a+i)=='.' || *(a+i)=='?' || *(a+i)=='!'){
            sentences++;
        }
        else{
            continue;
        }
        }
    float L = (letters*100/words);
    float s = (sentences*100/words);
    float subindex = (0.0588 * L - 0.296 * s) - 15.8;
    int index = round(subindex);
    if (index>16){
        printf("Grade 16\n");
    }
    else if (index<1){
        printf("Before Grade 1\n");
    }
    else{
        printf("Grade:%d\n",index);
    }
           
}
int main(){
    char text[1000];
    printf("Enter the string :");
    fgets(text, 1000, stdin);
    get_letters(text);
    return 0;
}