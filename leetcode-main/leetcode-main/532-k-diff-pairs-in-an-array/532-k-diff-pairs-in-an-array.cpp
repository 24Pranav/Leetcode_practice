class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty()) return 0;
        int n=nums.size();
        int count=0;
        unordered_map<int,int> map;
        for(int i=0;i<n;i++)
            map[nums[i]]++;
        if(k==0) // If k=0 we have to check the frequency of count otherwise x-x=0
                 //will count itself
        {
            for(auto x:map)
                if(x.second>1) count++; //if freq > 1 means x exists more than once and                                         //we can count it a pait
            return count;
        }
        else
        {
            for(auto x:map)
            {
                if(map.count(x.first-k)) count++;
            }
            return count;
        }
        return count;
    }
};