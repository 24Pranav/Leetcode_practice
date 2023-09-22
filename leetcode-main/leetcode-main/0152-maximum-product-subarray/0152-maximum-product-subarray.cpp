class Solution {
public:
    using ll=long long;
    int maxProduct(vector<int>& nums) {
        int pref=1;
        int suff=1;
        ll maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pref==0)
                pref=1;
            if(suff==0)
                suff=1;
            pref*=nums[i];
            suff*=nums[n-i-1];
            maxi=max(maxi,(ll)max(pref,suff));
        }
        return (int)maxi;
    }
};