//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
using ll=long long;
    bool fun(int i,int arr[],int n,int sum,vector<vector<int>> &dp)
    {
        if(i>=n)
        return false;
        if(sum==0)
        return true;
        if(dp[i][sum]!=-1)
        return dp[i][sum];
        bool take=false;
        bool not_take=false;
        if(arr[i]<=sum)
        take=fun(i+1,arr,n,sum-arr[i],dp);
        not_take=fun(i+1,arr,n,sum,dp);
        return dp[i][sum]=take||not_take;
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        ll sum=0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        if(sum%2!=0)
        return false;
        int target=sum/2;
        vector<vector<int>> dp(N,vector<int>(target+1,-1));
        return fun(0,arr,N,target,dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends