class Solution {
public:
//     int dp[501][501];
//     int fun(vector<int> &nums, int time, int ind)
//     {
//         //Base Case
//         if(ind==nums.size())
//             return 0;
//         if(dp[ind][time]!=-1)
//             return dp[ind][time];
//         int take=nums[ind]*time + fun(nums,time+1,ind+1);
//         int not_take=0+fun(nums,time,ind+1);
//         return dp[ind][time]=max(take,not_take);
        
//     }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        // memset(dp,-1,sizeof(dp));
        // return fun(satisfaction,1,0);
        
        //Tabulatiion
        int n=satisfaction.size();
        vector<vector<int>> dpt(n+1,vector<int>(n+1,0));
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int j=ind;j>=0;j--)
            {
                int take=satisfaction[ind]*(j+1) + dpt[ind+1][j+1];
                int not_take=0+dpt[ind+1][j];
                dpt[ind][j]=max(take,not_take);
            }
        }
        return dpt[0][0];
    }
};