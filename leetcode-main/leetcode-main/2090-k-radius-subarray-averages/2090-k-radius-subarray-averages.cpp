class Solution {
public:
    using ll=long long;
    vector<int> getAverages(vector<int>& nums, int k) {
        cout<<nums.size();
        vector<int> ans(nums.size(),-1);
        if(k>nums.size())
            return ans;
        vector<ll> prefix(nums.size()+1,0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            prefix[i]=prefix[i-1]+nums[i];
            // cout<<prefix[i]<<" ";
        }
        prefix.insert(prefix.begin(),0);
        int ii=0;
        ll d=(2*k)+1;
        for(int i=k;i<nums.size()-k;i++)
        {
            // cout<<prefix[i+k+1]<<" "<<prefix[ii]<<endl;
            ans[i]=(prefix[i+k+1]-prefix[ii++])/d;
            // cout<<ans[i]<<" ";
        }
        return ans;
    }
};