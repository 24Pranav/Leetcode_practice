class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> map;
        set<int> s;
        for(auto x: arr)
        {
            map[x]++;
        }
        for(auto it:map)
        {
            s.insert(it.second);
        }
        return map.size()==s.size();
    }
};