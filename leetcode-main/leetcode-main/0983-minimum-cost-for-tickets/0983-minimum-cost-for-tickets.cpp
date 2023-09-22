class Solution {
public:
    int fun(vector<int>& days, vector<int>& costs, vector<int> &dp, int ind)
    {
        //Base Case
        if(ind>=days.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //One Day Pass
        int oneday=costs[0]+fun(days,costs,dp,ind+1);
        // Seven Day Pass
        int i;
        for(i=ind;i<days.size() && days[i]< days[ind]+7 ;i++);
        int sevenday=costs[1]+fun(days,costs,dp,i);
        //One Month
        for(i=ind;i<days.size()  && days[i]<days[ind]+30 ;i++);
        int onemonth=costs[2]+fun(days,costs,dp,i);
        return dp[ind]=min(oneday,min(sevenday,onemonth));
    }
    int fun1(vector<int>& days, vector<int>& costs, vector<int> &dp, int ind)
    {
        //Base Case
        if(ind>=days.size())
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        //One Day Pass
        int oneday=costs[0]+fun1(days,costs,dp,ind+1);
        // Seven Day Pass
        // int i;
        // for(i=ind;i<days.size() && days[i]< days[ind]+7 ;i++);
        int x=lower_bound(days.begin(),days.end(),days[ind]+7)-days.begin();
        int sevenday=costs[1]+fun1(days,costs,dp,x);
        //One Month
        // for(i=ind;i<days.size()  && days[i]<days[ind]+30 ;i++);
        int y=lower_bound(days.begin(),days.end(),days[ind]+30)-days.begin();
        int onemonth=costs[2]+fun1(days,costs,dp,y);
        return dp[ind]=min(oneday,min(sevenday,onemonth));
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size()+1,-1);
        return fun1(days,costs,dp,0);
    }
};