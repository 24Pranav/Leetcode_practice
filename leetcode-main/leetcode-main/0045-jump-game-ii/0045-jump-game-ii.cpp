class Solution {
public:
    long long fun(vector<int> &nums,int start,int dest,vector<int>& dp)
    {
        if(start==dest) // or dest
            return 0;
        if(dp[start]!=-1)
            return dp[start];
        long long int minjump=INT_MAX;
        for(int i=1;i<=nums[start];i++){
            if(i+start>dest) break;
            minjump=min(minjump,1+fun(nums,start+i,dest,dp));
        }
        return dp[start]=minjump;
    }
    //DP Soultion
     // int jump(vector<int>& nums)
     // {
     //     vector<int> dp(nums.size(),-1);
     //     return fun(nums,0,nums.size()-1,dp);
     // }
    int jump(vector<int>& nums) {
        //Using Greedy Approach
        int jump=0;
        int pos=0;
        int max_reach=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            max_reach=max(max_reach,i+nums[i]);
            if(pos==i)
            {
                pos=max_reach;
                jump++;
            }
        }
        return jump;
    }
};