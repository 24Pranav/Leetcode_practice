class Solution {
public:
     void helperfun(int idx,vector<int> arr, vector<int> &ds,vector<vector<int>> &ans,int target,int k)
    {
         if(ds.size()==k)
         {
            if(target==0) 
            {
                ans.push_back(ds);
                return;
            }
         }
         for(int i=idx;i<arr.size();i++)
         {
            if(arr[i]>target) break;
            ds.push_back(arr[i]);
            helperfun(i+1,arr,ds,ans,target-arr[i],k);
            ds.pop_back();
         }
        // helperfun(i+1,arr,ds,ans,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> ds;
        vector<int> candidates;
        for(int i=1;i<=9;i++) candidates.push_back(i);
        vector<vector<int>> ans;
        helperfun(0,candidates,ds,ans,n,k);
        return ans;
    }
};