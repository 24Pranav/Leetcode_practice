#define pb push_back
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(nums.empty() || n<4)
            return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            long long target_3=target-nums[i];
            for(int j=i+1;j<n;j++)
            {
                int start=j+1;
                int end=n-1;
                long long target_2=target_3-nums[j];
                while(start<end)
                {
                    long long sum=nums[start]+nums[end];
                    if(sum>target_2) end--;
                    else if(sum<target_2) start++;
                    else
                    {
                        vector<int> quads(4,0);
                        quads[0]=(nums[i]);
                        quads[1]=(nums[j]);
                        quads[2]=(nums[start]);
                        quads[3]=(nums[end]);
                        ans.pb(quads);
                        while(start<end && nums[start]==quads[2]) ++start; 
                        // above loop to avoid front duplicates
                        while(start<end && nums[end]==nums[3]) --end;
                        //above code to avoid end duplicates
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) ++j;
            }
            while(i+1<n && nums[i]==nums[i+1]) ++i;
        }
        return ans;
    }
};