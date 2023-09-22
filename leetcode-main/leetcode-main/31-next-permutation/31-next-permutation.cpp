class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int x,l;
        if(n<=1) return;
        for(x=n-2;x>=0;x--)
        {
            if(nums[x]<nums[x+1]) // First breakpoint Leftside
            {
                break;
            }
        }
        if(x<0) reverse(nums.begin(),nums.end()); //If ascending order
            else
            {
                for(l=n-1;l>=0;l--) //Second breakpoint
                {
                    if(nums[l]>nums[x])  break;
                }
                swap(nums[x],nums[l]);
                sort(nums.begin()+x+1,nums.end());
            }
    }
};