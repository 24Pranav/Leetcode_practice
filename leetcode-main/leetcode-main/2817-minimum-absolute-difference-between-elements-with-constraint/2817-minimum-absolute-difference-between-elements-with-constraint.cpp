class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set<int> s;
        int mini=1e9;
        for(int i=x;i<nums.size();i++)
        {
            s.insert(nums[i-x]);
            auto it=s.lower_bound(nums[i]);
            if(it==s.end())
            {
                --it;
            }
            mini=min(mini,abs(*it-nums[i]));
            if(it!=s.begin()) // if not the first element (mid ele) check curr-prev
            {
                --it;
                 mini=min(mini,abs(*it-nums[i]));
            }
            
        }
        return mini;
    }
};