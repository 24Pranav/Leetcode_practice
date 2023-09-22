class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int x=INT_MAX;
        int max_profit=0;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            x=min(x,prices[i]);
            max_profit=max(max_profit,prices[i]-x);
        }
        return max_profit;
    }
};