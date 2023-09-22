//{ Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int dp[17][17];
    int fun(int m,int n)
    {
        if(m==0 && n==0)
        return 1;
        if(m<0 || n<0)
        return 0;
        if(dp[m][n]!=-1)
        return dp[m][n];
        int d=fun(m-1,n);
        int r=fun(m,n-1);
        return dp[m][n]=d+r;
    }
    int NumberOfPath(int a, int b)
    {
        //code here
        memset(dp,-1,sizeof(dp));
        return fun(a-1,b-1);
    }
};


//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}


// } Driver Code Ends