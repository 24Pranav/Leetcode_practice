//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to count the number of possible triangles.
    int findNumberOfTriangles(int arr[], int n)
    {
        // code here
        sort(arr,arr+n);
        int count=0;
        for(int j=n-1;j>=0;j--)
        {
            int left=0;
            int right=j-1;
            while(left<right)
            {
                if(arr[left]+arr[right]>arr[j])
                {
                    count+=right-left;
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return count;
    }
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}
// } Driver Code Ends