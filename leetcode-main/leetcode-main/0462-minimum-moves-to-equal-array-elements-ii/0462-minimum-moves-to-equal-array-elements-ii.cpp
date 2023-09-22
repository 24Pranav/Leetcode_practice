class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int m=nums.size()/2;
        int ans=0;
        for(auto &x:nums)
            ans+=abs(x-nums[m]);
        return ans;
    }
};