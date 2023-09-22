class Solution {
public:
    //  int fun(int i,vector<int> &nums,int d,int prev)  
    // {
    //     if(i>=nums.size())
    //         return 0;
    //     int ans=0;
    //     if(nums[i]-d==prev)
    //         ans=1+fun(i+1,nums,d,nums[i]);
    //     else
    //     {
    //         ans=fun(i+1,nums,d,prev);
    //         int ans1=fun(i+1,nums,d,nums[i]);
    //         ans=max(ans,ans1);
    //     }
    //     return ans;
    // }
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        int dp[n][1000+501];
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=1; i<n ; i++) {
            for(int j=0; j<i; j++) {
                int diff = nums[i] - nums[j];
                // if(diff>=0) {
                    dp[i][diff+501] = max(dp[i][diff+501], dp[j][diff+501] + 1);
                    ans = max(ans, dp[i][diff+501]);
                // }
            }
        }
        return 2+ans;
    }
};