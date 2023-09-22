class Solution {
public:
    int fun(int i,vector<int> &nums,vector<int> &dp)
    {
        if(i>=nums.size())
            return 0;
        if(dp[i]!=-1)
            return dp[i];
        return dp[i]=max((nums[i]+fun(i+2,nums,dp)),(0+fun(i+1,nums,dp)));
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        vector<int> arr(maxi+1,0);
        for(auto x:nums)
            arr[x]+=x;
        vector<int> dp(maxi+1,-1);
        return fun(0,arr,dp);
    }
};