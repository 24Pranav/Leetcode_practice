class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_map<int,int> mp;
        for(auto &x:nums)
            mp[x]++;
        for(auto &[a,b]:mp)
            if(b==1)
                return a;
    return 0;
    }
};