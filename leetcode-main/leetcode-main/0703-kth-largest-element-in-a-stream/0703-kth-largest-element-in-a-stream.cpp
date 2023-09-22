class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k1;
    KthLargest(int k, vector<int>& nums) {
        for(auto &x:nums){
        pq.push(x);
        if(pq.size()>k) pq.pop();
        }
        k1=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k1) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */