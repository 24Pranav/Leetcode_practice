class Solution {
public:
    int fun(int ind,vector<int> &nums, int k,vector<int> &dp)
    {
        if(ind==nums.size())
            return 0;
        int len=0;
        int maxi=INT_MIN;
        int maxAns=INT_MIN;
        if(dp[ind]!=-1)
            return dp[ind];
        int n=nums.size();
        n=min(ind+k,n);
        for(int j=ind;j<n;j++)
        {
            len++;
            maxi=max(maxi,nums[j]);
            int sum=len*maxi + fun(j+1,nums,k,dp);
            maxAns=max(maxAns,sum);
        }
        return dp[ind]=maxAns;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // vector<int> dp(arr.size(),-1);
        // return fun(0,arr,k,dp);
        
        //Tabulation
        vector<int> dp(arr.size()+1,0);
        dp[arr.size()]=0; //Base Case
        for(int ind=arr.size()-1;ind>=0;ind--)
        {
            int len=0;
            int maxi=INT_MIN;
            int maxAns=INT_MIN;
            int n=arr.size();
            n=min(ind+k,n);
        for(int j=ind;j<n;j++)
        {
            len++;
            maxi=max(maxi,arr[j]);
            int sum=len*maxi + dp[j+1];
            maxAns=max(maxAns,sum);
        }
            dp[ind]=maxAns;
        }
        return dp[0];
        }
};