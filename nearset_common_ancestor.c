#include <stdio.h>
#include <math.h>

int find_anc(int a,int b)
{
	if(a==b)
		return a;
	return a>b?find_anc(a/2,b):find_anc(a,b/2);
}

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d %d",&a,&b);
    printf("%d\n",find_anc(a,b));

	return 0;
}