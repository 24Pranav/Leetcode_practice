class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        int n=nums.size();
        int i;
        for(i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1]-1)
                ans.push_back(to_string(nums[i]));
            else
            {
                string tmp=to_string(nums[i]);
                tmp+="->";
                while(i<n-1 && nums[i]==nums[i+1]-1)
                {
                    i++;
                }
                tmp+=to_string(nums[i]);
                ans.push_back(tmp);
            }
        }
        if(i<n)
            ans.push_back(to_string(nums[i]));
        return ans;
    }
};