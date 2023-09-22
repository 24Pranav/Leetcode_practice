class Solution {
public:
    bool check(map<char,int> &mp)
    {
        bool flag=false;
        int freq;
        for(auto &[a,b]:mp){
            if(b==0)
                continue;
            if(flag)
            {
            if(b!=freq)
            return false;
            }
            else{
            flag=true;
            freq=b;
            }
        }
        return true;
    }
    bool equalFrequency(string word) {
        map<char,int> mp;
        for(auto &x:word)
        mp[x]++;
        for(auto &[a,b]:mp)
        {
            b--;
            bool ch=check(mp);
            b++;
            if(ch)
            return true;
        }
        return false;
    }
};