class Solution {
public:
    int minimumMountainRemovals(vector<int>& arr) {
        int n=arr.size();
        int maxi=1;
    vector<int> dp(n,1) , dp1(n,1);
    for(int i=0;i<n;i++){
        for(int prev=0;prev<i;prev++)
        {
            if(arr[prev]<arr[i] && 1+dp[prev] > dp[i])
            {
                dp[i]=1+dp[prev];
            }
        }
        if(dp[i]>maxi)
        {
            maxi=dp[i];
        }
        
    }
    maxi=1;
       for(int i=n-1;i>=0;i--){
        for(int prev=n-1;prev>i;prev--)
        {
            if(arr[prev]<arr[i] && 1+dp1[prev] > dp1[i])
            {
                dp1[i]=1+dp1[prev];
            }
        }
        if(dp1[i]>maxi)
        {
            maxi=dp1[i];
        }
        
    }
    int maxi1=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==1 || dp1[i]==1)
        continue;
        maxi1=max(maxi1,dp[i]+dp1[i]-1);
    }
    return n-maxi1;
    }
};