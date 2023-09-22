class Solution {
    private:
    struct comp
    {
        bool operator()(const pair<string,int> &a , const pair<string,int> &b)
        {
            return a.second>b.second || (a.second==b.second && a.first<b.first);
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> map;
        for(auto x:words)
        {
            map[x]++;
        }
        priority_queue<pair<string,int>,vector<pair<string,int>>,comp> pq;
        
        for(auto p:map)
        {
            pq.push(p);
            if(pq.size()>k)
                pq.pop();
        }
        vector<string> ans;
        while(!pq.empty())
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};