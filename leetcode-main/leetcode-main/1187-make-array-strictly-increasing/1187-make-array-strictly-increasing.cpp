class Solution {
public:
    map<pair<int,int>,int> dp;
    int fun(int i,int prev,vector<int>& arr1, vector<int>& arr2)
    {
        if(i>=arr1.size())
            return 0;
        int take=1e9;
        int not_take=1e9;
        if(dp.find(make_pair(i,prev))!=dp.end())
            return dp[{i,prev}];
        // if(prev>=arr1[i]){
            int tmp_ind=upper_bound(arr2.begin(),arr2.end(),prev)-arr2.begin();
            // cout<<tmp_ind<<" ";
            if(tmp_ind<arr2.size())
            {
            take=1+fun(i+1,arr2[tmp_ind],arr1,arr2);
            }
        // }
        if(arr1[i] > prev)
        {
            not_take=fun(i+1,arr1[i],arr1,arr2);
        }
        return dp[make_pair(i,prev)]=min(take,not_take);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(),arr2.end());
        // memset(dp,-1,sizeof(dp));
        int ans=fun(0,-1,arr1,arr2);
        if(ans==1e9)
            return -1;
        else
            return ans;
    }
};