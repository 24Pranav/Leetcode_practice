#define mp make_pair
#define pb push_back
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        //Max Heap for closest Pairs
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(auto it:arr)
        {
            pq.push(mp(abs(it-x),it));
            // If heap size > k max diff (element-x) pops out closest ones remain
            if(pq.size()>k) pq.pop();
        }
        while(k--)
        {
            ans.pb(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};