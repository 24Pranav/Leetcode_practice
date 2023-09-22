class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        int l=0;
        int r=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            // if(sum==target)
            //     ans=min(ans,i-l);
            while(sum>=target)
            {
                ans=min(ans,i-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return (ans==INT_MAX)?0:ans;
    }
};