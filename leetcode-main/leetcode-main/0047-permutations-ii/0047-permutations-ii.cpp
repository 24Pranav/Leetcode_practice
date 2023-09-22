class Solution {
public:
    void fun(set<vector<int>> &ans, vector<int> &nums,int i)
    {
        if(i==nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int ii=i;ii<nums.size();ii++)
        {
            swap(nums[ii],nums[i]);
            fun(ans,nums,i+1);
            swap(nums[ii],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        fun(ans,nums,0);
        vector<vector<int>> ans1;
        for(auto &x:ans)
            ans1.push_back(x);
        return ans1;
    }
};