class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
//         unordered_map<int,int> mp;
//         for(auto &x:nums)
//             mp[x]++;
//         priority_queue<pair<int,int>,vector<pair<int,int>>> pq;
        
//         for(auto &x:mp)
//         {
//             pq.push({x.second,x.first});
//         }
//         vector<int> ans;
//         while(k--)
//         {
//             int p=pq.top().second;
//             pq.pop();
//             ans.push_back(p);
//         }
//         return ans;
        
        //Bucket Sort
        
        int n=nums.size()+1;
        vector<int> bucket[n];
        unordered_map<int,int> mp;
        for(auto &x:nums)
            mp[x]++;
        
        for(auto &x:mp)
        {
            bucket[x.second].push_back(x.first);
        }
        vector<int> ans;
        
        for(int i=n-1;i>=0 && k>0;i--)
        {
            for(auto &x:bucket[i]){
            ans.push_back(x);
                k--;
            }
        }
        return ans;
    }
};