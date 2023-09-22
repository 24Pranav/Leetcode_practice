class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans,sum,s,e,n=nums.size(),close=INT_MAX;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            s=i+1;
            e=n-1;
            while(s<e)
            {
                sum=nums[i]+nums[s]+nums[e];
                if(abs(sum-target)<close)
                {
                    ans=sum;
                    close=abs(sum-target);
                    if(sum==target)
                        return sum;
                }
                if(sum>target)
                {
                    e--;
                }
                else
                {
                    s++;
                }
            }
        }
        return ans;
    }
};