#define ll long long
class Solution {
public:
    bool isPossible(vector<int> nums,ll mid)
    {
        ll sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mid*(i+1))
                return false;
        }
        return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int left=*min_element(nums.begin(),nums.end());
        int right=*max_element(nums.begin(),nums.end());
        ll ans=right-1;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(nums,mid))
            {
                ans=mid;
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return ans;
    }
};