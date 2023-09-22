class Solution {
public:
    int maxi;
    int fun(vector<int> &nums, int n)
    {
        if(n==0) return 0;
        if(n==1) return nums[0];
        int prev=fun(nums,n-1)+nums[n-1];
        int curr=max(nums[n-1],prev);
        maxi=max(maxi,curr);
        return curr;
    }
    int maxSubArray(vector<int>& nums) {
        maxi=nums[0];
        fun(nums,nums.size());
        return maxi;
    }
};