class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        int left_sum=0;
        int right_sum=0;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0) left_sum+=nums[i-1];
            right_sum=totalsum-left_sum-nums[i];
            if(left_sum==right_sum) return i;
        }
        return -1;
    }
};