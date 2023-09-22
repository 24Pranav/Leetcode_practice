class Solution {
public:
//     map<pair<int,int>,int> dp;
//     int fun(int i,vector<int> &nums,int diff,int ele)
//     {
//         if(i>=nums.size())
//             return 0;
//         int ans=0;
//         int take=0;
//         int not_take=0;
//         if(dp.find({i,ele})!=dp.end())
//             return dp[{i,ele}];
//         if(nums[i]==ele)
//         {
//             // cout<<ele<<" ";
//             take=1+fun(i+1,nums,diff,ele+diff);
//             not_take=fun(i+1,nums,diff,ele);
//             ans=max(take,not_take);
//         }
//         else
//         {
//             ans=fun(i+1,nums,diff,ele);
//         }
//         return dp[{i,ele}]=ans;
            
//     }
//     int longestSubsequence(vector<int>& arr, int difference) {
//         int maxi=0;
//         for(int i=0;i<arr.size();i++)
//         {
//             // cout<<arr[i]<<endl;
//             maxi=max(maxi,fun(i+1,arr,difference,arr[i]+difference));
//         }
//         return 1+maxi;
//     }
    //Optimal Approach
    unordered_map<int,int> mp;
    int longestSubsequence(vector<int>& arr, int difference) {
        int maxi=1;
        for(auto &x:arr)
        {
            mp[x]=1+mp[x-difference];
            maxi=max(maxi,mp[x]);
        }
        return maxi;
    }
};