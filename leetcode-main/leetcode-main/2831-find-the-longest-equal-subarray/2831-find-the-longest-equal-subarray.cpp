class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp; // index map
        // mapping index for numbers
        int i=0;
        int maxi=0;
        for(auto &x:nums){
            mp[x].push_back(i);
            i++;
            }
        // for(auto &[a,b]:mp)
        // {
        //     cout<<a<<"||| ";
        //     for(auto &x:b)
        //         cout<<x<<" ";
        //     cout<<endl;
        // }
        for(auto &[a,it]:mp)
        {
            int n=it.size();
            int l=0;
            int r=0;
            while(l<n)
            {
                while(r+1 < n && ((it[r+1])-it[l])-(r+1-l)<=k)
                    r++;
                maxi=max(maxi,r-l+1);
                l++;
            }
        }
        return maxi;
    }
};