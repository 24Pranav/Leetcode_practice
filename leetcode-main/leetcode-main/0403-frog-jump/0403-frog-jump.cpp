class Solution {
public:
    unordered_map<int,int> mp;
    int n;
    int dp[2001][2001];
    bool fun(int i,vector<int> &nums,int pj)
    {
        if(i==n-1)
            return true;
        bool res=false;
        if(dp[i][pj]!=-1)
            return dp[i][pj];
        for(int nextjump=pj-1;nextjump<=pj+1;nextjump++)
        {
            if(nextjump>0)
            {
                int nextstone=nums[i]+nextjump;
                if(mp.find(nextstone)!=mp.end())
                {
                    res|=fun(mp[nextstone],nums,nextjump);
                    if(res)
                        return dp[i][pj]=1;
                }
            }
        }
        return dp[i][pj]=res;
    }
    bool canCross(vector<int>& stones) {
        if(stones[1]!=1) //first jump should be 1 step
            return false;
        n=stones.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            mp[stones[i]]=i;
        }
        return fun(mp[0],stones,0);
    }
};