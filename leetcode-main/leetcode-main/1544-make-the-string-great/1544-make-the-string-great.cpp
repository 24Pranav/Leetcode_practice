class Solution {
public:
    string makeGood(string s) {
        string ans="";
        ans+=s[0];
        for(int i=1;i<s.size();i++)
        {
            if(ans.back()==s[i]+32 || ans.back()==s[i]-32)
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};