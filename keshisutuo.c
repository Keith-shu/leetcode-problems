#include <stdio.h>
#include <stdlib.h>

int flag=0;

void combine(int k,int sum,int begin,int *res,int len)
{
	int i;
	if(k<0||sum<0)
		return;
	if(k==0 && sum==0){
		flag=1;
		for(i=0;i<len;i++)
			printf("%d ",res[i]);
		printf("\n");
		return;
	}
	for(i=begin+1;i<10;i++){
		res[len-k]=i;
		combine(k-1,sum-i,i,res,len);
	}

}


int main(int argc, char const *argv[])
{
	int k,n;
	scanf("%d %d",&k,&n);
	int min=0,max=0;
	int i;
	for(i=0;i<k;i++){
		max+=(9-i);
		min+=(i+1);
	}
	if(k<1 || k>9){
		printf("None");
		return 0;
	}
	if(n<min || n>max){
		printf("None");
		return 0;
	}
	int *res;
	res=(int *)malloc(k*sizeof(int));
	combine(k,n,0,res,k);
	if(!flag)
		printf("None");
	return 0;
}