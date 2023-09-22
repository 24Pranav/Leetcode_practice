class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int n=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int n1=lower_bound(nums.begin(),nums.end(),target+1)-nums.begin()-1;
        for(int i=n;i<=n1;i++)
            ans.push_back(i);
        return ans;
    }
};