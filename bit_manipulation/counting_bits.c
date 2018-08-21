/*
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the 
number of 1's in their binary representation and return them as an array.


 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize) {
    int *res,i;
    res=(int*)malloc((num+1)*sizeof(int));
    res[0]=0;
    res[1]=1;
    for(i=2;i<=num;i++){
        res[i]=res[i&(i-1)]+1;
    }
    *returnSize=num+1;
    return res;
    
}