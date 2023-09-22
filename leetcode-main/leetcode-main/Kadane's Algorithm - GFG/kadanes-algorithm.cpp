//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxi=0;
    long long fun(int arr[],int n)
    {
        if(n==0)
        return 0;
        if(n==1)
        return arr[0];
        long long prev=fun(arr,n-1)+arr[n-1];
        long long curmax=max((long long)arr[n-1],(long long)prev);
        maxi=max(maxi,curmax);
        return curmax;
    }
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        maxi=*max_element(arr,arr+n);
        fun(arr,n);
        return maxi;
    }
};

//{ Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}

// } Driver Code Ends