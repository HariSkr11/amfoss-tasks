#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int flag(int len,char *key[]){
    if (len!=2){
        printf("Usage: ./substitution key.\n");
        return 1;
    }
    int len2 = strlen(key[1]);
    for (int i=0;i<len2;i++){
        if (isalpha(key[1][i])){
            printf("Usage ./ceaser key.\n");
            return 1;
        }
    }
    return 0;

}
int main(int argc,char *key[]){
     int flag1 = flag(argc,key);
     if (flag1){
        return flag1;
     }
     else{
        char text[1500];
        printf("plaintext: ");
        fgets(text,1000,stdin);
        int ke = atoi(key[1]);
        int lenn = strlen(text);
        char cipher[lenn];
        for (int i=0;i<lenn;i++){
            int c = text[i];
            char ci;
            if isalpha(c){
                if (isupper(c)){
                    ci = (c-'A'+ke)%26+'A';
                }
                if (islower(c)){
                    ci = (c-'a'+ke)%26+'a';
                }
            }
            else{
                ci = c;
            }
            cipher[i] = ci;
        }
        printf("Cipher: %s",cipher);
     }
     return 0;
}