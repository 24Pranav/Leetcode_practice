class Solution {
public:
    vector<vector<int>> ans;
    vector<int> ds;
    void fun(int i,vector<int> &nums,int sum)
    {
        if(sum==0){
            ans.push_back(ds);
            return;
        }
        for(int j=i;j<nums.size();j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
        if(sum-nums[j]>=0)
        {
            ds.push_back(nums[j]);
            fun(j+1,nums,sum-nums[j]);
            ds.pop_back();
        }
            else
                break;
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        fun(0,candidates,target);
        return ans;
    }
};