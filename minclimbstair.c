#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int main(int argc, char const *argv[]) {
    int *cost,n,i,j;
    int result;
    scanf("%d",&n);
    cost=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",cost+i);
    int **dp;
    dp=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n+1;i++)
        dp[i]=(int *)calloc(n,sizeof(n));
    for(i=0;i<n-2;i++){
        dp[i][i+1]=cost[i];
        dp[i][i+2]=cost[i]+cost[i+1];
    }
    dp[n-2][n-1]=cost[n-2];
    //printf("%d\n",dp[n-2][n-1])
    for(i=0;i<n-1;i++)
        for(j=i+3;j<n;j++){
            dp[i][j]=min(dp[i][j-1]+cost[j-1],dp[i][j-2]+cost[j-2]+cost[j-1]);
        }
    result=dp[0][n-1]<dp[1][n-1]?dp[0][n-1]:dp[1][n-1];
    printf("%d\n",result);
    return 0;
}
