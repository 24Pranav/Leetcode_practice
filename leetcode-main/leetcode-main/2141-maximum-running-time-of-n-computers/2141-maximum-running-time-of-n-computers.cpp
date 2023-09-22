class Solution {
public:
    using ll=long long;
    ll fun(vector<int> &nums, ll mid,int n)
    {
        ll req_time=(ll)n*mid;
        ll time=0;
        for(int i=0;i<nums.size();i++)
            time+=min((ll)nums[i],mid);
        return time>=req_time;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        ll l=*min_element(batteries.begin(),batteries.end());
        ll r=0;
        for(auto &x:batteries)
            r+=x;
        r/=n;
        ll ans=0;
        while(l<=r)
        {
            ll mid=l+(r-l)/2;
            bool cal=fun(batteries,mid,n);
            if(cal)
            {
                ans=mid;
                l=mid+1;
            }
            else
                r=mid-1;
        }
        return ans;
    }
};