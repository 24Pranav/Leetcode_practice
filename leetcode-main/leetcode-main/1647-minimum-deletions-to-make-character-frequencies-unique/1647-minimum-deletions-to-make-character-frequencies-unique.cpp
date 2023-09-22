class Solution {
public:
    int minop(map<int,int> &nums)
    {
        map<int,int> mp;
        int ans=0;
        for(auto &[a,it]:nums)
        {
            if(mp.find(it)!=mp.end())
            {
                while(mp.find(it)!=mp.end() && mp[it]>0)
                {
                    it--;
                    ans++;
                }
            }
            if(it>0){
                mp[it]++;
            }
        }
        return ans;
    }
    int minDeletions(string s) {
        map<int,int> mp;
        for(auto &x:s)
            mp[x]++;
        int ans=minop(mp);
        return ans;
    }
};