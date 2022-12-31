#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAX 9
typedef struct {
    char name[1000];   
     int votes;
}
candidate;

candidate candidates[MAX];

int main(int argc,char *argv[]){
    int count_can = argc;
    for (int i=1;i<count_can;i++){
        strcpy(candidates[i-1].name,argv[i]);
        candidates[i-1].votes = 0;
    }
    int n_voters;
    printf("Number of voters: ");
    scanf("%d",&n_voters);
    for (int i=0;i<n_voters;i++){
        bool flag = false;
        printf("Vote: ");
        char names[1000];
        scanf("\n%s",names);
        for (int j=0;j<argc-1;j++){
            if (!strcmp(candidates[j].name,names)){
                flag=true;
                candidates[j].votes++;
                break;
            }
    }
    if (!flag){
            printf("Invalid vote.\n");
        }

}
int max_vote;
    for (int i=0;i<argc-1;i++){
        if (candidates[i].votes>max_vote){
        max_vote = candidates[i].votes;
        }
    }
    for (int i=0;i<argc-1;i++){
        if (candidates[i].votes == max_vote){
            printf("%s\n",candidates[i].name);
        }
    }
return 0;
}
