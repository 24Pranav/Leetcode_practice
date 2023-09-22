class Solution {
public:
  void helperfun(int i,vector<int> arr, vector<int> &ds,vector<vector<int>> &ans,int target)
    {
        if(i==arr.size())
        {
            if(target==0) ans.push_back(ds);
            return;
        }
        if(arr[i]<=target)
        {  //We can reuse an element thats why we are not incrementing index
        ds.push_back(arr[i]);
        helperfun(i,arr,ds,ans,target-arr[i]);
        ds.pop_back();
        }
        helperfun(i+1,arr,ds,ans,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        helperfun(0,candidates,ds,ans,target);
        return ans;
    }
};