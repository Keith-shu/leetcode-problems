#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double dp(double memo[200][200],int a,int b){
    if(a<=0 && b>0) return 1;
    else if(a<=0 && b<=0) return 0.5;
    else if(a>0 && b<=0) return 0;
    else if(memo[a][b]>0) return memo[a][b];
    else memo[a][b]=0.25*(dp(memo,a-4,b)+dp(memo,a-3,b-1)+dp(memo,a-2,b-2)+dp(memo,a-1,b-3));
    return memo[a][b];
}



int main(int argc, char const *argv[]) {
    int N;
    scanf("%d",&N );
    double memo[200][200];
    int i,j;
    for(i=0;i<200;i++)
        for(j=0;j<200;j++)
            memo[i][j]=0;
    double result;
    if(N>5000)result=1;
    else
        result=dp(memo,(N+24)/25,(N+24)/25);
    printf("%f\n",result );
    return 0;
}
