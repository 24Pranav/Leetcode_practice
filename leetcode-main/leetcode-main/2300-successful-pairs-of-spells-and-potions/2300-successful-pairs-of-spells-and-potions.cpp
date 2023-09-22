class Solution {
public:
    int bsearch(long long x, vector<int> &nums,long long k)
    {
        int l=0;
        int r=nums.size()-1;
        int n=r;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
                if(x*nums[mid]>=k)
                {
                    // cout<<nums[mid]<<" |"<<mid<<"| ";
                    ans=mid;
                    r=mid-1;
                }
            else
            {
                l=mid+1;
            }
        }
        cout<<endl;
        return n-r;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(auto &x:spells)
        {
            int temp=bsearch(x,potions,success);
            ans.push_back(temp);
        }
        return ans;
    }
};