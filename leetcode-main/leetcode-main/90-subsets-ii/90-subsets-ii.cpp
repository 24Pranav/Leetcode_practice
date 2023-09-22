#define pb push_back
#define pbb pop_back
class Solution {
public:
    void helperfun(int idx,vector<vector<int>> &ans, vector<int> arr, vector<int> &ds)
    {
        ans.pb(ds);
        for(int i=idx;i<arr.size();i++)
        {
            if(i!=idx && arr[i]==arr[i-1]) continue;
            ds.pb(arr[i]);
            helperfun(i+1,ans,arr,ds);
            ds.pbb();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        helperfun(0,ans,nums,ds);
        return ans;
    }
};