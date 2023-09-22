//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
using ll=long long;
int n;
ll fun(int i,int j,vector<vector<int>> &nums,vector<vector<ll>> &dp)
{
    if(i==n-1 && j<=n-1)
    {
        return nums[i][j];
    }
    if(j>=n|| j<0)
    return -1e9;
    if(dp[i][j]!=-1)
    return dp[i][j];
    ll x=nums[i][j]+fun(i+1,j,nums,dp);
    ll y=nums[i][j]+fun(i+1,j-1,nums,dp);
    ll z=nums[i][j]+fun(i+1,j+1,nums,dp);
    return dp[i][j]=max({x,y,z});
}
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        n=N;
        vector<vector<ll>> dp(N+1,vector<ll>(N+1,-1));
        ll ans=INT_MIN;
        for(int i=0;i<n;i++)
        {
        ans=max(ans,fun(0,i,Matrix,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends