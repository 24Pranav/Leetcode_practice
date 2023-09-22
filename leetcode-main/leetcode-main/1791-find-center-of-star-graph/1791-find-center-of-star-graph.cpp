class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> mp;
        for(auto &x:edges)
            for(auto &j:x)
            {
                mp[j]++;
                if(mp[j]>1)
                    return j;
            }
        return 0;
    }
};