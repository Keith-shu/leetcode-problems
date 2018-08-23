class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a=(n^(n>>1))+1;
        return !(a&(a-1));
    }
};