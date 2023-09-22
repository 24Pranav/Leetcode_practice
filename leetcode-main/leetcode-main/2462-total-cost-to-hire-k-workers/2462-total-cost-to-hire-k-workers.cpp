class Solution {
public:
    using ll=long long;
    long long totalCost(vector<int>& nums, int k, int candidates) {
        priority_queue<ll,vector<ll>,greater<ll>> pq1;
        priority_queue<ll,vector<ll>,greater<ll>> pq2;
        int i1=0;
        while(i1<candidates){
            pq1.push(nums[i1++]);
        }
        if(candidates > nums.size()- candidates){
            candidates= nums.size()- candidates;
        }
        int i2=nums.size()-1;
        int k1=candidates;
        int k2=0;
        while(k1--){
            pq2.push(nums[i2--]);
        }
        // while(!pq1.empty()){
        //     cout<<pq1.top()<<" ";
        //     pq1.pop();
        // }
        // cout<<endl;
        // while(!pq2.empty()){
        //     cout<<pq2.top()<<" ";
        //     pq2.pop();
        // }
        ll ans=0;
        while(k2<k)
        {
            if(pq1.size()==0)
            {
                ans+=pq2.top();
                pq2.pop();
                if(i1<=i2)
                    pq2.push(nums[i2--]);
            }
            else if(pq2.size()==0)
            {
                ans+=pq1.top();
                pq1.pop();
                if(i1<=i2)
                    pq1.push(nums[i1++]);
            }
            else if(pq1.top()<=pq2.top())
            {
                ans+=pq1.top();
                cout<<pq1.top()<<" ";
                pq1.pop();
                if(i1<nums.size() && i1<=i2){
                pq1.push(nums[i1++]);
                }
            }
            else
            {
                ans+=pq2.top();
                cout<<pq2.top()<<" ";
                pq2.pop();
                if(i2>=0 && i1<=i2){
                pq2.push(nums[i2--]);}
                
            }
            k2++;
        }
        return ans;
    }
};