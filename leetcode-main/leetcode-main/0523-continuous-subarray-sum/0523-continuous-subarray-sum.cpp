class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        int i=0;
        for(auto x:nums)
        {
            sum+=x;
            int rem=sum%k;
            if(mp.find(rem)!=mp.end())
            {
                if((i-mp[rem])>1) return true;

            }
            else
            {
                mp[rem]=i;            
            }
            i++;
        }
        return false;
    }
};