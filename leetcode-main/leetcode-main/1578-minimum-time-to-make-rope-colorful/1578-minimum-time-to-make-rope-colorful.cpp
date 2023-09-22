class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int sum=0;
        char prev='*';
        int lcost=0;
        for(int i=0;i<n;i++)
        {
            if(prev==colors[i]) 
            {
                if(neededTime[i]<lcost)
                {
                sum+=neededTime[i];
                }
                else
                {
                    sum+=lcost;
                    lcost=neededTime[i];
                }
            }
            else
            {
                lcost=neededTime[i];
                prev=colors[i];
            }
        }
        return sum;
    }
};