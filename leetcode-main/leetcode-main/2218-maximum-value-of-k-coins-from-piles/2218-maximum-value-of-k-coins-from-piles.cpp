#define ll long long
class Solution {
public:
      int fun(int i, vector<vector<int>>& piles, int k, vector<vector<int>>& dp){
        if(i == piles.size() || k <= 0){
            return 0;
        }
        
          if(dp[i][k] != -1){
            return dp[i][k];
        }
        
        ll ans = INT_MIN;
        for(int j = 0; j < piles[i].size(); j++){
            if(j > k-1)
                break;
            
            ll take = piles[i][j] + fun(i+1, piles, k-j-1, dp);
            
            ans = max(ans, take);
        }
        
        long long ntake = fun(i+1, piles, k, dp);
        ans = max(ans, ntake);
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        vector<vector<int>> dp(piles.size()+1,vector<int>(k+1,-1));
        
        //prefix
         vector<vector<int>> prefix;
        for(auto a: piles){
            int n = a.size();
            vector<int> temp(n);
            temp[0] = a[0];
            for(int i=1;i<n;i++){
                temp[i]=temp[i-1]+a[i];
            }
            prefix.push_back(temp);
        }
        return fun(0,prefix,k,dp);
    }
};