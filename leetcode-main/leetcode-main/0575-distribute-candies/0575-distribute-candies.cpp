class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        int n=nums.size();
        n/=2;
        unordered_set<int> s(nums.begin(),nums.end());
        return s.size()>n?n:s.size();
    }
};