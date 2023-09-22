class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size()==0)
            {
            if(n>1)
                return -1;
            else
                return n;
        }
        vector<pair<int,int>> v(n+1,{0,0});
        for(auto x:trust)
     {
            v[x[0]].first++;
            v[x[1]].second++;
     }
        int person=0;
        for(auto x:v)
        {
            if(x.first==0 && x.second==n-1)
                return person;
            person++;
        }
        return -1;
    }
};