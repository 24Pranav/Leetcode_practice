class Solution {
public:
    //Max subarray Sum
    int maxi;
    int fun(vector<int> &nums, int n)
    {
        if(n==0) return 0;
        if(n==1) return nums[0];
        int prev=fun(nums,n-1)+nums[n-1];
        int curr=max(nums[n-1],prev);
        maxi=max(maxi,curr);
        return curr;
    }
    int maxSubArray(vector<int>& nums) {
        maxi=nums[0];
        fun(nums,nums.size());
        return maxi;
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> num1dif(n,0);
        vector<int> num2dif(n,0);
        int sum1=0;
        int sum2=0;
        for(int i=0;i<n;i++)
        {
            num1dif[i]=nums2[i]-nums1[i];
            num2dif[i]=nums1[i]-nums2[i];
            sum1+=nums1[i];
            sum2+=nums2[i];
        }
        int ans1=maxSubArray(num1dif)+sum1;
        int ans2=maxSubArray(num2dif)+sum2;
        return max(ans1,ans2);
    }
};