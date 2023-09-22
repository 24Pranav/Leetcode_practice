class Solution {
public:
    using ll=long long;
    ll check(ll mid,vector<int> &nums,vector<int> &costs)
    {
        ll cost=0;
        for(int i=0;i<nums.size();i++)
        {
            cost+=costs[i]*abs(nums[i]-mid);
        }
        return cost;
    }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n=nums.size();
        ll left=0;
        ll right=*max_element(nums.begin(),nums.end());
        ll ans=LLONG_MAX;
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            ll x=check(mid,nums,cost);
            ll y=check(mid+1,nums,cost);
            if(x<y)   
            {
                ans=min(ans,x);
                right=mid-1;
            }
            else
            {
                ans=min(ans,y);
                left=mid+2;
            }
        }
        return ans;
    }
};