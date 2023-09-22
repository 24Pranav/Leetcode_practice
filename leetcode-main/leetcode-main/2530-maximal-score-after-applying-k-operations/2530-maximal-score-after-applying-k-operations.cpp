class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score=0;
        priority_queue<int> pq;
        for(auto &x:nums)
            pq.push(x);
        while(k--)
        {
            score+=pq.top();
            int c=ceil(pq.top()/3.0);
            pq.pop();
            pq.push(c);
        }
        return score;
    }
};