#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

char* pushDominoes(char* dominoes) {
    int i=0,j;
    int pos=0;
    int mid=0;
    while(dominoes[i]!='\0'){
        if(dominoes[i]=='L'){
            for(j=pos;j<i;j++)
                dominoes[j]='L';
            pos=i+1;
            i++;
        }
        else if(dominoes[i]=='R'){
            pos=i;
            i++;
            while(dominoes[i]=='.' && dominoes[i]!='\0')
                i++;
            if(dominoes[i]=='R'){
                printf("%d %d\n",pos ,i );
                for(j=pos;j<i;j++)
                    dominoes[j]='R';
                pos=i;
            
            }

            else if(dominoes[i]=='\0'){
                printf("%d %d\n",pos,i );
                for(j=pos;j<i;j++)
                    dominoes[j]='R';
            }

            else{
                //printf("%d %d\n",pos,i );
                mid=(pos+i)/2;
                if((pos+i)%2==0){
                    for(j=pos;j<mid;j++)
                        dominoes[j]='R';
                    for(j=mid+1;j<i;j++)
                        dominoes[j]='L';
                }
                else{
                    for(j=pos;j<=mid;j++)
                        dominoes[j]='R';
                    for(j=mid+1;j<i;j++)
                        dominoes[j]='L';
                }
                i++;
                pos=i;
            }
        }
        else if(dominoes[i]=='.'){
            i++;
            printf("%d\n",i );
        }

    }
    return dominoes;
}
int main(int argc, char const *argv[]) {
    char dominoes[]="R.R.L";
    char *result;
    result=pushDominoes(dominoes);
    puts(result);
    return 0;
}
