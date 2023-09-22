class Solution {
public:
    using ll=long long;
    ll dp[21][21];
    ll fun(int i,int j,vector<int> &nums)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        ll p1_i=nums[i]+min(fun(i+2,j,nums),fun(i+1,j-1,nums));
        ll p1_j=nums[j]+min(fun(i+1,j-1,nums),fun(i,j-2,nums));
        return dp[i][j]=max(p1_i,p1_j);
    }
    // Alternate solution using difference
    ll fun1(int i,int j,vector<int> &nums)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        ll p1_i=nums[i]-fun1(i+1,j,nums);
        ll p1_j=nums[j]-fun1(i,j-1,nums);
        return dp[i][j]=max(p1_i,p1_j);
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        // ll player1=fun(0,nums.size()-1,nums); // pl score
        // ll total=accumulate(nums.begin(),nums.end(),0); // total score
        // ll player2=total-player1; // p2 score
        // return player1>=player2;
        
        return fun1(0,nums.size()-1,nums)>=0;
    }
};