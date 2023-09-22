//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    using ll=long long;
    const int MOD=1e9+7;
    int countWays(int n)
    {
        // your code here
        if(n==1 || n==2 || n==3)
        return n;
        
        ll a=1;
        ll b=2;
        ll c;
        for(int i=2;i<n;i++)
        {
            c=(b+a)%MOD;
            a=b;
            b=c;
        }
        return c;
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends