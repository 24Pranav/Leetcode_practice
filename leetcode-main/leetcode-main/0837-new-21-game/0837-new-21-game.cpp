// class Solution {
// public:
// double game(int curr,int k,int n,int maxPts,vector<double>&dp){
//         if(curr>=k) return curr<=n;
//         if(dp[curr]!=-1) return dp[curr];
//         double sum = 0;
//         for(int i=1;i<=maxPts;i++){
//             sum+=game(curr+i,k,n,maxPts,dp);
//         }
//         return dp[curr] = sum/maxPts;
        
//     }
//     double new21Game(int n, int k, int maxPts) {
//         vector<double> dp(n,-1.0);
//         return game(0,k,n,maxPts,dp);
//     }
    
    
// };

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

           if (k == 0 || n >= k + maxPts) {
            return 1.0;
        }
        vector<double> dp(n + 1);
        double currSum = 1.0;
        double ans = 0.0;

         dp[0] = 1.0;

        for (int i = 1; i < n+1; i++) {

            dp[i] = currSum / maxPts;

            if (i < k) 
                currSum += dp[i];

             else 
                ans += dp[i];
            
            if (i - maxPts >= 0) 
                currSum -= dp[i - maxPts];
            
        }

        return ans;
    }
};