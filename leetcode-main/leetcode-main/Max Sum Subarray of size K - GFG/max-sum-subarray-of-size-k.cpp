//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    using ll=long long;
    long maximumSumSubarray(int K, vector<int> &nums , int N){
        // code here 
        int i=0;
        int j=0;
        ll sum=0;
        ll maxi=0;
        while(j<N)
        {
            sum+=nums[j];
            if(j-i+1==K)
            {
                maxi=max(maxi,sum);
                sum-=nums[i];
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends