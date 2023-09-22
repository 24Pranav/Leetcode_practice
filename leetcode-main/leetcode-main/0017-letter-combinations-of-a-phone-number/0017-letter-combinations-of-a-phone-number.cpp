class Solution {
public:
    void helperfun(int index,string digits, vector<string> &ans, string &ds, unordered_map<char,string> &m)
    {
        if(index==digits.size())
        {
            ans.push_back(ds);
            return;
        }
        string str=m[digits[index]];
        for(int i=0;i<str.size();i++)
        {
            ds.push_back(str[i]);
            helperfun(index+1,digits,ans,ds,m);
            ds.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> m;
        m['2']="abc";
        m['3']="def";
        m['4']="ghi";
        m['5']="jkl";
        m['6']="mno";
        m['7']="pqrs";
        m['8']="tuv";
        m['9']="wxyz";
        vector<string> ans;
        string ds;
        if(!digits.size()) return ans;
        helperfun(0,digits,ans,ds,m);
        return ans;
    }
};