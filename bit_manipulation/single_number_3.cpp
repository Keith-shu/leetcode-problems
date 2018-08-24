/*
Given an array of numbers nums, in which exactly two elements 
appear only once and all the other elements appear exactly twice. 
Find the two elements that appear only once.
*/


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int i;
        int _=0;
        for(i=0;i<nums.size();i++)
            _^=nums[i];
        _&=~(_-1);
        int a=0,b=0;
        for(i=0;i<nums.size();i++){
            if((nums[i]&_)==0)
                a^=nums[i];
            else
                b^=nums[i];
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        
        return res;
    }
};