//Subset Sum Equal To K
//similar question S=s1+s2 our target sum is s1 here (s1=s2)
class Solution {
public:
    // bool fun(int n, int k, vector<int> nums, vector<vector<int>> dp)
    // {
    //  if(k==0) return true;
    //  if(n==0) return nums[0]==k;
    //  if(dp[n][k]!=-1) return dp[n][k];
    // bool nottake=fun(n-1,k,nums,dp);
    // bool take=false;
    // if(nums[n]<=k)
    // take=fun(n-1,k-nums[n],nums,dp);
    // return dp[n][k]=take|| nottake;
    // }
    bool canPartition(vector<int>& nums) {
        if(nums.size()<2) return false;
        int sum=0;
        for(auto x:nums) sum+=x;
        if(sum%2) return false;
        int k=sum/2;
        // vector<vector<int>> dp(nums.size(),vector<int>(k+1,-1));
        // return fun(nums.size()-1,k,nums,dp); 
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum,0));
        for(int i=0;i<nums.size();i++) dp[i][0]=true;
        dp[0][nums[0]]=true;
        for(int i=1;i<nums.size();i++)
        {
            for(int j=1;j<=k;j++)
            {
                bool nottake=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j)
                take=dp[i-1][j-nums[i]];
                dp[i][j]=take|| nottake;
            }
        }
        return dp[nums.size()-1][k];
    }
};