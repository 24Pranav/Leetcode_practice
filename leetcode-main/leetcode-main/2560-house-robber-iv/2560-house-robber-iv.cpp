class Solution {
public:
    bool isPossible(vector<int>&nums,int mid,int k)
    {
        int take=0;
        for(int i=0;i<nums.size();i++)
        {
            if(mid>=nums[i])
            {
                take++;
                i++; //To avoid taking adjacent element
            }
        }
        return take>=k;
    }
    int minCapability(vector<int>& nums, int k) {
        int left=1;
        int right=INT_MAX;
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(nums,mid,k))
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};