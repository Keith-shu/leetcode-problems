#include<iostream>
#include <vector>

using namespace std;


class Solution {
public:
    class trienode{
    public:
        trienode *left;
        trienode *right;
        trienode() {left=NULL;right=NULL;};
    };
    int findMaximumXOR(vector<int>& nums) {
        trienode *root = new trienode();
        trienode *cur=NULL;
        int i,j;
        int tmp,_max,res;
        for(i=0;i<nums.size();i++){
            cur=root;
            tmp=nums[i];
            for(j=30;j>=0;j--){
                if((!((tmp>>j)&1))){
                    if(cur->left==NULL)
                        cur->left=new trienode();
                    cur=cur->left;
                }
                else{
                    if(cur->right==NULL)
                        cur->right=new trienode();
                    cur=cur->right;
                }
            }
        }
        res=0;
        for(i=0;i<nums.size();i++){
            cur=root;
            tmp=nums[i];
            _max=0;
            for(j=30;j>=0;j--){
                if(!((tmp>>j)&1)){ //0 bit
                    if(cur->right){
                        cur=cur->right;
                        _max|=1<<j;                
                    }
                    else if(cur->left){
                        cur=cur->left;
                    }
                }
                else{              //1 bit
                    if(cur->left){
                        cur=cur->left;
                        _max|=1<<j;               
                    }
                    else if(cur->right){
                        cur=cur->right;
                    }
                }
            }
            cout<<_max<<endl;
            res=std::max(res,_max);
        }
        return res;
    }           
};


int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> a;
    a.push_back(2);
    a.push_back(4);
    s.findMaximumXOR(a);
    return 0;
}