class Solution {
public:
    int fun(vector<int> &nums, int idx,int prev,int n, int diff)
    {
        //Base Case
        if(idx>=n)
            return 0;
        if(nums[idx]-prev!=diff)
            return 0;
        return 1+fun(nums,idx+1,nums[idx],n,diff);
    }
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=1;i<n;i++)
        {
            int diff=nums[i]-nums[i-1];
            ans+=fun(nums,i+1,nums[i],n,diff);
        }
        return ans;
    }
};