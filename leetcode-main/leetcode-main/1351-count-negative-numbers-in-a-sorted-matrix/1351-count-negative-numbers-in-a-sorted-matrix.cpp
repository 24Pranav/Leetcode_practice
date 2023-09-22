class Solution {
public:
    using ll=long long;
    int countNegatives(vector<vector<int>>& grid) {
       ll count=0;
       int n=grid[0].size();
        for(auto &x:grid)
        {
            int left=0;
            int right=grid[0].size()-1;
            int mid;
            int ans=INT_MAX;;
            while(left<=right)
            {
                mid=(left+right)>>1;
                // cout<<mid<<"-"<<endl;
                if(x[mid]<0)
                {
                 ans=mid;
                 right=mid-1;
                }
                else if(x[mid]>=0){
                    left=mid+1;
                }
            }
            // cout<<n-ans<<" "<<endl;
            if(ans!=INT_MAX)
            count+=(n-ans);
        }
        return (int)count;
    }
};