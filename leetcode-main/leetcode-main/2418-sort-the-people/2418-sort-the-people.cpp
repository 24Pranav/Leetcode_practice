#define mp make_pair
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> v;
        vector<string> ans;
        for(int i=0;i<(int)names.size();i++){
            v.push_back(mp(heights[i],names[i]));
        }
        sort(v.rbegin(),v.rend());
        for(auto x:v){
            ans.push_back(x.second);
        }
        return ans;
    }
};