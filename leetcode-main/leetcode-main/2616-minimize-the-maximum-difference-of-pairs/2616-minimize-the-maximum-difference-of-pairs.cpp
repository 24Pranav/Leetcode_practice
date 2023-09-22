#define ll long long
class Solution {
private:
    bool isPossible(vector<int> &nums, ll mid,ll p)
    {
        int n=nums.size();
        for(int i=0;i<n-1;)
        {
            if(abs(nums[i]-nums[i+1])<=mid)
            {
                p--;
                i+=2; //inc 2
            }
            else
                i++;
        }
        return p<=0;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)
            return 0;
        ll left=0;
        ll right=*max_element(nums.begin(),nums.end());
        ll ans=INT_MAX;
        sort(nums.begin(),nums.end());
        while(left<=right)
        {
            ll mid=left+(right-left)/2;
            if(isPossible(nums,mid,p))
            {
                ans=min(ans,mid);
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return (int)ans;
    }
};