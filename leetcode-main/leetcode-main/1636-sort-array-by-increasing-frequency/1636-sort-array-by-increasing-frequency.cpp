#define pi pair<int,int>
class Solution {
public:
    class comp{
        public:
    bool operator() (const pi a,const pi b)
    {
        if(a.first==b.first)
        {
            return b.second>a.second;
        }
        else
            return a.first>b.first;
    }
    };
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto &x:nums)
            mp[x]++;
        priority_queue<pi,vector<pi>,comp> pq;
        for(auto &[a,b]:mp)
            pq.push({b,a});
        
        vector<int> ans;
        while(!pq.empty())
        {
            auto it=pq.top();
            int f=it.first;
            int s=it.second;
            pq.pop();
            while(f--)
                ans.push_back(s);
        }
        return ans;
    }
};