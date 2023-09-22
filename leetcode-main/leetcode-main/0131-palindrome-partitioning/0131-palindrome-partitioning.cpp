#define pb push_back
#define pbb pop_back
class Solution {
public:
    bool isPalindrome(int i, int j, string s)
    {
        while(i<=j)
        {
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(int index, string s, vector<vector<string>> &ans, vector<string> &ds)
    {
    if(index==s.size())
        {
            ans.pb(ds);
        }
    for(int i=index;i<s.size();i++)
    {
        if(isPalindrome(index,i,s))
        {
            ds.pb(s.substr(index,i-index+1));
            solve(i+1,s,ans,ds);
            ds.pbb();
        }
    }
    }
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        solve(0,s,ans,ds);
        return ans;
    }
};