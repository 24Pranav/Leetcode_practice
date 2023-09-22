class Solution {
public:
    bool check(string s,string t)
    {
        map<char,char> mp;
        for(int i=0;i<s.size();i++)
        {
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i])
                    return false;
            }
            else
                mp[s[i]]=t[i];
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        return check(s,t) && check(t,s);
    }
};