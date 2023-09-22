class Solution {
public:
    void helperfun(int i,vector<vector<int>> &ans,vector<int> &nums,vector<int> &ds)
    {
        ans.push_back(ds);
        for(int idx=i;i<nums.size();i++)
        {
            ds.push_back(nums[i]);
            helperfun(i+1,ans,nums,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        helperfun(0,ans,nums,ds);
        return ans;
    }
};