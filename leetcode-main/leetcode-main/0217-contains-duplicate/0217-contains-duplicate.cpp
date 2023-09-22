class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> map;
        for(auto &x:nums)
        {
            map[x]++;
            if(map[x]>=2)
                return true;
        }
        return false;
    }
};