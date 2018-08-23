/*
Given a positive integer, check whether it has alternating bits: namely, if 
two adjacent bits will always have different values.
*/



class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=(n^(n>>1))+1;
        return !(a&(a-1));
    }
};