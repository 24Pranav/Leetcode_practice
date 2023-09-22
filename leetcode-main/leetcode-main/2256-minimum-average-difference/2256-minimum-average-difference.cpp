class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
    
        int n=nums.size();
        long long sum=0;
        for(auto x:nums)
            sum+=x;
        priority_queue<pair<long,int>, vector<pair<long,int>>, greater<pair<long,int>>> pq;
        long a=0;
        for(int i=0;i<nums.size();i++)
        {
            long a1;
            a+=nums[i];
            a1=a/(i+1);
            long b=(sum-a);
            if(i!=n-1)
            b=b/(n-i-1);
            long ans=abs(a1-b);
            if(ans<0) ans*=-1;
            pq.push({ans,i});
        }
        return pq.top().second;
    }
};