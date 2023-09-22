class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ss;
        // 1st Apprach
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]*nums[i];
        }
        sort(nums.begin(),nums.end());
        return nums;
        //2nd Approach
        // for(int i=0;i<nums.size();i++)
        // {
        //     nums[i]=nums[i]*nums[i];
        // }
        // int lp=0,rp=nums.size()-1;
        // while(lp<rp)
        // {
        //     if(nums[lp]>nums[rp])
        //     {
        //         ss.push_back(nums[lp]);
        //         lp++;
        //     }
        //     else
        //     {
        //         ss.push_back(nums[rp]);
        //         rp--;
        //     }
        // }
        // ss.push_back(nums[lp]);
        // reverse(ss.begin(),ss.end());
        // return ss;
    }
};