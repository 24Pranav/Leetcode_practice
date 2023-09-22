#define pii pair<int,int>
class Solution {
public:
    using ll=long long;
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pii> vec;
        int n=nums1.size();
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.begin(),vec.end(),greater<pii>());
//         for(int i=0;i<n;i++)
//         {
//             nums1[i]=vec[i].second;
//             nums2[i]=vec[i].first;
//         }
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        ll ksum=0;
        for(int i=0;i<k;i++)
        {
            ksum+=vec[i].second;
            pq.push(vec[i].second);
        }
        ll result=ksum*vec[k-1].first;
        for(int i=k;i<n;i++)
        {
            ksum+=vec[i].second-pq.top();
            pq.pop();
            pq.push(vec[i].second);
            result=max(result,ksum*vec[i].first);
        }
        return result;
    }
};