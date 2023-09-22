class Solution {
public:
    vector<int> countBits(int n) {
        //O(N)log(k)
        // vector<int> ans;
        // for(int i=0;i<=n;i++)
        // {
        //     ans.push_back(__builtin_popcount(i));
        // }
        // return ans;
        
        //O(N)
        vector<int> ans(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
                ans[i]=ans[i/2];
            else
                ans[i]=ans[i/2]+1;
        }
        return ans;
    }
};