#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

void helper(int l,int r,string final,std::vector<string> &res)
{
    if(l==0&&r==0){
        res.push_back(final);
        //cout<<res<<endl;
        return;
    }

    else if(l==r)
        helper(l-1,r,final+'(',res);
    else{
        if(l!=0)
            helper(l-1,r,final+'(',res);

        if(r!=0)
            helper(l,r-1,final+')',res);
    }
}

int main()
{
    int n;
    cin>>n;
    string final;
    vector<string> res;
    final.push_back('(');
    helper(n-1,n,final,res);
    int i;
    for(i=0;i<res.size()-1;i++){
        cout<<res[i]<<',';
    }
    cout<<res[i]<<endl;
    return 0;

}
