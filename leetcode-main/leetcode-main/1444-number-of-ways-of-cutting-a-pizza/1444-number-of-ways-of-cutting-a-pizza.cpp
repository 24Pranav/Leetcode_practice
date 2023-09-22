#define MOD 1000000007
class Solution {
public:
    bool isValid(vector<string>&pizza, int sr, int er, int sc, int ec)
    {
        for (int i = sr; i <= er; i++)
        {
            for (int j = sc; j <= ec; j++)
            {
                if (pizza[i][j] == 'A') return true;
            }
        }
        return false;
    }
    int solve(vector<string>&pizza, vector<vector<vector<int>>>&dp, int i, int j, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        if (k == 0) return 1;
        
        if (dp[i][j][k] != -1) return dp[i][j][k];

        long long ans = 0;
        
        for (int row = i; row < m - 1; row++) 
        {
            bool upperHalfValid = isValid(pizza, i, row, j, n - 1);
            bool lowerHalfValid = isValid(pizza, row + 1, m - 1, j, n - 1);
            if (upperHalfValid && lowerHalfValid)
            {
                int nextWays =  (solve(pizza, dp, row + 1, j, k - 1)); 
                ans = (ans + nextWays) % MOD;
            }
        }
        for (int col = j; col < n - 1; col++)
        {
            bool leftHalfValid = isValid(pizza, i, m - 1, j, col); 
            bool rightHalfValid = isValid(pizza, i, m - 1, col + 1, n - 1);
            if (leftHalfValid && rightHalfValid) 
            {
                int nextWays = solve(pizza, dp, i, col + 1, k - 1); 
                ans = (ans + nextWays) % MOD;
            }
        }
        
        return dp[i][j][k] = (int)ans;
    }
    int ways(vector<string>& pizza, int k)
    {
        int m = pizza.size(), n = pizza[0].size();
        vector dp(m, vector(n, vector<int>(k, -1)));
        int ans = solve(pizza, dp, 0, 0, k - 1);
        return ans;
        
    }
};