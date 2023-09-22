#define ll long long
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<ll,ll> totcount,totsum,curcount,cursum;
        int n=nums.size();
        vector<ll> ans(n,0);
        for(int i=0;i<n;i++)
        {
            totsum[nums[i]]+=i;
            totcount[nums[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            cursum[nums[i]]+=i;
            curcount[nums[i]]++;
            ll psum=totsum[nums[i]]-cursum[nums[i]];
            ll pcount=totcount[nums[i]]-curcount[nums[i]];
            ans[i]=abs(curcount[nums[i]]*i-cursum[nums[i]]) + abs(pcount*i-psum);
        }
        return ans;
    }
};