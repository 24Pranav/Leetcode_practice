class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        if(nums[left]==target)
            return left;
        if(nums[right]==target)
            return right;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(nums[mid]==target)
                return mid;
            //Left increasing check
            if(nums[left]<=nums[mid])
            {
                if(target>=nums[left] && target<nums[mid])
                    right=mid-1;
                else
                    left=mid+1;
            }
            //Right Part increasing
            else
            {
                if(target>nums[mid] && target<=nums[right])
                    left=mid+1;
                else
                    right=mid-1;
            }
        }
        return -1;
    }
};