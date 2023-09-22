class Solution {
public:
    int fun(int ind,int sum,vector<int> &nums, vector<vector<int>> &dp)
    {
        if(ind==0)
        {
            if(sum==0 && nums[0]==0) return 2;
            if(sum==0 || sum==nums[0]) return 1;
            return 0;
        }
        // if(dp[ind][sum]!=-1) return dp[ind][sum];
        int notpick=fun(ind-1,sum,nums,dp);
        int pick=0;
        if(nums[ind]<=sum)
            pick=fun(ind-1,sum-nums[ind],nums,dp);
        cout<<pick+notpick<<"--";
        return dp[ind][sum]=pick+notpick;
    }
    int countpart(vector<int> &nums, int target)
    {
        //https://www.codingninjas.com/codestudio/problems/partitions-with-given-difference_3751628
        // int totsum=0;
        // for(auto x:nums)
        //     totsum+=x;
        // //s1-s2=target or sum
        // int s2=(totsum-target);
        // if(s2%2 || s2<0) return 0; // Partion cannot be created
        // s2=s2/2;
        // vector<vector<int>> dp(nums.size(),vector<int>(totsum+1,-1));
        // return fun(nums.size()-1,s2,nums,dp);
        int totsum=0;
        for(auto x:nums)
            totsum+=x;
        //s1-s2=target or sum
        int s2=(totsum-target);
        if(s2%2 || s2<0) return 0; // Partion cannot be created
        s2=s2/2;
        int n=nums.size();
        int M=s2;
        int t[n+1][M+1];
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }

        //t[0][0] = 1;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<=M; j++)
            {
                if(nums[i-1]<=j)
                    t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
                else
                    t[i][j]=t[i-1][j];
            }
        }

        return t[n][M];  
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        //same question as Partitions with given difference
        return countpart(nums,target);
    }
};