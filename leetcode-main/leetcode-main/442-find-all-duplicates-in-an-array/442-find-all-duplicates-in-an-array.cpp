#define pb push_back
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(nums.empty()) return {};
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            int x=abs(nums[i])-1;
            if(nums[x]>0)
            {
                nums[x]=-(nums[x]);
            }
            else
                ans.pb(abs(nums[i]));
        }
        return ans;
    }
};