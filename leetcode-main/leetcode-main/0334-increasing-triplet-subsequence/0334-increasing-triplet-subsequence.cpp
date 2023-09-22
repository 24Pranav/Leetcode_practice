class Solution {
public:
    //lcs
       int solveOptimal(int n, vector<int> &a){
       
        if(n == 0)
            return 0;
            
        vector<int> ans;
        ans.push_back(a[0]);
        
        for(int i=1; i<n; i++){
            if(a[i] > ans.back())
                ans.push_back(a[i]);
                
            else{
                // find index of just bigger element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        
        return ans.size();
    }
    bool increasingTriplet(vector<int>& nums) {
        // int x=INT_MAX, y=INT_MAX;
        // for(auto it:nums)
        // {
        //     if(it<x) x=it;
        //     else if(it<y && it>x) y=it;
        //     else
        //     {
        //         if(y<it) return true;
        //     }
        // }
        // return false;
        return solveOptimal(nums.size(),nums)>2; //If lcs>=3
    }
};