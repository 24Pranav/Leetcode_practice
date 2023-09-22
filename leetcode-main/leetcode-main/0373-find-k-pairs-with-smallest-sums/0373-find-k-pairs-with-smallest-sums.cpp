#define pii pair<int,int>
struct comp
{
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        return a.first+a.second<b.first+b.second;
    }
};
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans1;
        priority_queue<pii,vector<pii>,comp> pq;
        int n1=nums1.size();
        int n2=nums2.size();
        
        for(int i=0;i<n1;i++)
            for(int j=0;j<n2;j++){
                int sum=nums1[i]+nums2[j];
                if(pq.size()<k){
                pq.push({nums1[i],nums2[j]});
                }
                else if(pq.top().first+pq.top().second>sum){
                    pq.pop();
                    pq.push({nums1[i],nums2[j]});
                }
                else
                {
                    break;
                }
            }
        // cout<<1<<" ";
    int k1=0;
    while(!pq.empty() && k1<k)
    {
        ans1.push_back({pq.top().first,pq.top().second});
        pq.pop();
        k1++;
    }
    return ans1;
    }
};