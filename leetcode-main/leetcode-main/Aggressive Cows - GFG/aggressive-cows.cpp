//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool isPossible(vector<int> &nums,int mid,int k)
    {
     int cnt=1;
     int cow_cor=nums[0];
     for(int i=1;i<nums.size();i++)
     {
         if(nums[i]-cow_cor>=mid)
         {
             cnt++;
             cow_cor=nums[i];
         }
         if(k==cnt)
         return true;
     }
     return false;
     }
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        sort(stalls.begin(),stalls.end());
        int left=1;
        int right=*max_element(stalls.begin(),stalls.end());
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(stalls,mid,k))
            {
                ans=mid;
                left=mid+1;
            }
            else
            right=mid-1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends