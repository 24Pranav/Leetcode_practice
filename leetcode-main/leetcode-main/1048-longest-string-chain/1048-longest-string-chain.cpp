class Solution {
public:
    bool check(string &w1, string &w2)
    {
        if(w1.size()!=w2.size()+1)
            return false;
        int first=0;
        int second=0;
        while(first<w1.size())
        {
            if(w1[first]==w2[second])
            {
                first++;
                second++;
            }
            else
            {
                first++;
            }
        }
            if(w1.size()==first && w2.size()==second)
                return true;
                return false;
    }
    static bool comp(const string &w1, const string &w2)
    {
        return w1.size()<w2.size();
    }
    int longestStrChain(vector<string>& arr) {
        int maxi=1;
        int n=arr.size();
        sort(arr.begin(),arr.end(),comp);
	vector<int> dp(n,1);
	for(int i=0;i<n;i++){
		for(int prev=0;prev<i;prev++)
		{
			if(check(arr[i],arr[prev]) && 1+dp[prev] > dp[i])
			{
				dp[i]=1+dp[prev];
			}
		}
		if(dp[i]>maxi)
		{
			maxi=dp[i];
		}
	}
        return maxi;
    }
};