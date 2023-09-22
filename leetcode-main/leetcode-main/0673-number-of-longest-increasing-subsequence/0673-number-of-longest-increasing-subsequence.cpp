class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int maxi=1;
        int n=arr.size();
	vector<int> dp(n,1) , cnt(n,1);
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++)
		{
			if(arr[prev]<arr[i] && 1+dp[prev] > dp[i])
			{
				dp[i]=1+dp[prev];
                cnt[i]=cnt[prev]; //inherit
			}
            else if(arr[prev]<arr[i] && 1+dp[prev]==dp[i])
            {
                cnt[i]+=cnt[prev]; //same length so increase the count
            }
		}
		if(dp[i]>maxi)
		{
			maxi=dp[i];
		}
		
	}
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]==maxi)
                count+=cnt[i];
        }
        return count;
        // return maxi;
    }
};