class Solution {
public:
     void helperfun(int idx,vector<int> arr, vector<int> &ds,vector<vector<int>> &ans,int target)
    {
            if(target==0) 
            {
                ans.push_back(ds);
                return;
            }
         for(int i=idx;i<arr.size();i++)
         {
            if(i>idx && arr[i]==arr[i-1]) continue; //** IMP i>idx
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            helperfun(i+1,arr,ds,ans,target-arr[i]);
            ds.pop_back();
         }
        // helperfun(i+1,arr,ds,ans,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> ds;
        vector<vector<int>> ans;
        helperfun(0,candidates,ds,ans,target);
        return ans;
    }
};