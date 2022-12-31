#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 9
typedef struct {
    char name[1000];   
     int votes[3];
}
candidate;

candidate candidates[MAX];
void vote(int index,int argc,char* names){
        bool flag=false;
        for (int j=0;j<argc-1;j++){
            if (!strcmp(candidates[j].name,names)){
                flag=true;
                candidates[j].votes[index]++;
                break;
            }

}
        if (flag==false){
            printf("Invalid Choice.\n");
        }
}
int check(int argc,int index){
int max_value=0;
 for (int i=0;i<argc-1;i++){
       if (candidates[i].votes[index]>max_value){
        max_value = candidates[i].votes[index];
        }
 }

char na[1000];
int d=0;
for (int i=0;i<argc-1;i++){

    if (candidates[i].votes[index]==max_value){
        strcpy(na,candidates[i].name);
        d++;
        if (d>1){
            return 0;
        }
    }
}
if (d==1){
    printf("%s\n",na);
}
 return 1;
}

int main(int argc,char *argv[]){
    int count_can = argc;
    for (int i=1;i<count_can;i++){
        strcpy(candidates[i-1].name,argv[i]);
        candidates[i-1].votes[0] = 0;
        candidates[i-1].votes[1] = 0;
        candidates[i-1].votes[2] = 0;
    }
    int n_voters;
    printf("Number of voters: ");
    scanf("%d",&n_voters);
    for (int i=0;i<n_voters;i++){
        printf("Rank 1: ");
        char name1[1000];
        scanf("\n%s",name1);
        vote(0,argc,name1);
        printf("Rank 2: ");
        char name2[1000];
        scanf("\n%s",name2);
        vote(1,argc,name2);
        printf("Rank 3: ");
        char name3[1000];
        scanf("\n%s",name3);
        vote(2,argc,name3);

        }


if(!check(argc,0)){
    if(!check(argc,1)){
        check(argc,2);
    };
}
return 0;
}
