class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int ans=0;
        for(auto &x:nums)
        {
            if(x==1)
            {
                maxi++;
                ans=max(ans,maxi);
            }
            else
                maxi=0;
        }
        return ans;
    }
};