class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        //To find duplicate we can use hashmap
        unordered_map<int,int> mp;
        int i=0;
        for(auto x:nums)
        {
            if(!mp[x])
            mp[x]++;
            else
            {
                ans.push_back(x);
            }
        }
        int n=nums.size();
        for(int i=1;i<=n+1;i++)
        {
            if(mp.find(i)==mp.end())
            {
                ans.push_back(i);
                break;
            }
        }
        return ans;
    }
};