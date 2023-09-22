class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int x=0;
        if(nums.size()<=1) return nums.size();
        for(int i=1;i<nums.size();i++)
        {
            if(nums[x]!=nums[i])
            {
                nums[++x]=nums[i];
            }
        }
        return x+1;
    }
};