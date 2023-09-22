class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Floyd  Cycle Detection
        int n=nums.size();
        if(n<=1) return 0;
        int slow=nums[0];
        int fast=nums[0];
        do
        {
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        while(fast!=slow)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};