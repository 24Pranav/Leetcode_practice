class Solution {
public:
    int dp[21][10001];
    int fun(int i,vector<int> &nums,int diff)
    {
        if(i>=nums.size())
        {
            if(diff==0)
                return 0;
            else
                return INT_MIN;
        }
        if(dp[i][diff+5001]!=-1)
            return dp[i][diff+5001];
        int take1=nums[i]+fun(i+1,nums,diff+nums[i]);
        int take2=nums[i]+fun(i+1,nums,diff-nums[i]);
        int not_take=fun(i+1,nums,diff);
        return dp[i][diff+5001]=max({take1,take2,not_take});
    }
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        memset(dp,-1,sizeof(dp));
        return fun(0,rods,0)/2;
    }
};