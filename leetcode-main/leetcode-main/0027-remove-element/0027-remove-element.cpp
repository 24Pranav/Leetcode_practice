class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> num1;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
            {
                num1.push_back(nums[i]);
                count++;
            }
        }
        for(int i=0;i<nums.size()-count;i++)
            num1.push_back(0);
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=num1[i];
        }
        return count;
    }
};