#define ll long long
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll onez=0;
        ll count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                count++;
                onez+=count;
            }
            else
                count=0;
        }
        return onez;
    }
};