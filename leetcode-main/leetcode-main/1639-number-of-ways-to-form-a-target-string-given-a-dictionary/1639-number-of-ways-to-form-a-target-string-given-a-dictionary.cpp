#define ll long long
class Solution {
public:
    int n; //target len
    int k; //word len
    string tar;
    int dp[1001][1001];
    const int MOD=1e9+7;
    int fun(int i, int j, vector<vector<int>> &freq)
    {
        if(i==n)
            return 1;
        if(j==k)
            return 0; //target not able to form
        if(dp[i][j]!=-1)
            return dp[i][j];
        ll take= ((ll)freq[tar[i]-'a'][j] * fun(i+1,j+1,freq)) % MOD;
        ll nottake=(fun(i,j+1,freq))%MOD;
        return dp[i][j]=(take+nottake)%MOD;
    }
    int numWays(vector<string>& words, string target) {
        n=target.size();
        k=words[0].size();
        tar=target;
        vector<vector<int>> freq(26,vector<int>(k,0));
        //frequency matrix
        for(int i=0;i<k;i++){ // column
            for(auto &x:words){
                int ch=x[i]-'a';
                freq[ch][i]++;
            }
        }
                
        //debug
        // for(auto &x:freq){
        //     for(auto &j:x){
        //         cout<<j<<" ";}
        //     cout<<endl;
        // }
        
        memset(dp,-1,sizeof(dp));
        return (int)(fun(0,0,freq)%MOD);
    }
    
};