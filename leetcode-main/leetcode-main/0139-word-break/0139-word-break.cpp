class Solution {
public:
    bool fun(string s, set<string> &wordDict,int i,vector<int> &dp)
    {
        //Base Case
        if(i==s.size())
            return true;
        if(dp[i]!=-1)
            return dp[i];
        string temp="";
        for(int j=i;j<s.size();j++)
        {
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end())
            {
                if(fun(s,wordDict,j+1,dp))
                    return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(301,-1);
        set<string> st;
        for(auto &x:wordDict)
            st.insert(x);
        return fun(s,st,0,dp);
    }
};