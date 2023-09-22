class Solution {
public:
// int fun(vector<int> &nums , int ind, int prev_ind, int n, vector<vector<int>> &dp)
//     {
//         //Base Case
//         if(ind==n)
//             return 0;
//     if(dp[ind][prev_ind+1]!=-1)
//         return dp[ind][prev_ind+1];
//         int len1=0+fun(nums,ind+1,prev_ind,n,dp); //not take
//         int len2=0;
//         if( prev_ind==-1 || nums[ind]>nums[prev_ind])
//             len2=1+fun(nums,ind+1,ind,n,dp);
//         return dp[ind][prev_ind+1]=max(len1,len2);
//     }
    
    // DP+Binary Search
    int solveOptimal(int n, vector<int> &a){
       
        if(n == 0)
            return 0;
            
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1; i<n; i++){
            if(a[i] > ans.back())
                ans.push_back(a[i]);
                
            else{
                // find index of just bigger element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        
        return ans.size();
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // DP+MEMOIZED
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return fun(nums,0,-1,n,dp);
        
        //Tabulation
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    //     for(int ind=n-1;ind>=0;ind--)
    //         for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--)
    //         {
    //     int len1=0+dp[ind+1][prev_ind+1]; //not take cordinate shift therefore second parameter +1
    //     int len2=0;
    //     if( prev_ind==-1 || nums[ind]>nums[prev_ind])
    //         len2=1+dp[ind+1][ind+1]; //cordinate shift therefore second parameter +1
    //    dp[ind][prev_ind+1]=max(len1,len2);
    //     }
    //     return dp[0][-1+1]; //cordinate shift therefore second parameter +1
        return solveOptimal(n,nums);
    }
};