class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> map;
        priority_queue<pair<int,char>> pq;
        for(auto x:s)
            map[x]++;
        for(auto it:map)
        {
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty())
        {
            for(int i=0;i<map[pq.top().second];i++)
            ans+=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};