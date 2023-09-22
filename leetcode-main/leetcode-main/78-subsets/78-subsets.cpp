class Solution {
public:
    void helperfun(int idx,vector<vector<int>> &ans, vector<int> arr, vector<int> &ds)
    {
        ans.push_back(ds);
        for(int i=idx;i<arr.size();i++)
        {
            ds.push_back(arr[i]);
            helperfun(i+1,ans,arr,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helperfun(0,ans,nums,ds);
        return ans;
    }
};