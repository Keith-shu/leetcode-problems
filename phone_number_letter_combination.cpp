class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> map={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
        if(digits.empty())
            return res;
        int i,j,k;
        res.push_back("");
        for(i=0;i<digits.size();i++){
            if(map[digits[i]-'0'].empty())
                continue;
            vector<string> tmp;
            for(j=0;j<res.size();j++)
                for(k=0;k<map[digits[i]-'0'].size();k++)
                    tmp.push_back(res[j]+map[digits[i]-'0'][k]);
            res=tmp;
        }
        return res;
    }
};