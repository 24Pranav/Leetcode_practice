class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if(a[0]<b[0])
            return true;
        if(a[0]==b[0])
            return a[1]>b[1];
        return false;
    }
    int lis(vector<int> &nums)
    {
        if(nums.size()==0)
            return 0;
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
                ans.push_back(nums[i]);
            else
            {
                int lb=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[lb]=nums[i];
            }
        }
        return ans.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end(),comp);
        vector<int> ans;
        for(auto &x:envelopes)
            ans.push_back(x[1]);
        return lis(ans);
    }
};