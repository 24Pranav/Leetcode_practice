class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count=0;
        int k=0;
        int i;
        for(i=0;i<nums.size();i++)
        {
            if(nums[i]==0) count++;
            if(nums[i]!=0) nums[k++]=nums[i];
        }
        int size=nums.size()-count;
        while(size<nums.size())
        {
            nums[size++]=0;
        }
    }
};