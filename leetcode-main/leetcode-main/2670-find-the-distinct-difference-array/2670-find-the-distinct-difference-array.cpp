class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        set<int> s2;
        for(int i=0;i<n;i++)
        {
            set<int> s1;
            s2.insert(nums[i]);
            for(int j=i+1;j<n;j++)
                s1.insert(nums[j]);
            ans[i]=s2.size()-s1.size();
        }
        return ans;
    }
};