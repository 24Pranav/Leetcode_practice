class Solution {
public:
    set<string> words;
    int dp[51];
    int fun(int i,string &s)
    {
        if(i>=s.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        string tmp="";
        int ans=s.size();
        for(int j=i;j<s.size();j++)
        {
            tmp+=s[j];
            int extra=0;
            if(words.find(tmp)!=words.end())
                extra=0+fun(j+1,s); // present
            else
                extra=tmp.size()+fun(j+1,s); // not present add to extra
            ans=min(ans,extra);
        }
        return dp[i]=ans;
        
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp,-1,sizeof(dp));
        for(auto &x:dictionary)
            words.insert(x);
        return fun(0,s);
    }
};