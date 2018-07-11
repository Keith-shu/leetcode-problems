#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int dp(int *a,int n)
{
    if(n==1)
        return 1;
    if(n==2)
        return 2;
    if(a[n]>0)
        return a[n];
    a[n]=(dp(a,n-1)+dp(a,n-2));
    return a[n];
}

int climbStairs(int n) {
    int *a;
    a=(int *)calloc(n+1,sizeof(int));
    //a[1]=1;
    //a[2]=2;
    return dp(a,n);
}

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d",&n);
    printf("%d\n",climbStairs(n) );
    return 0;
}
