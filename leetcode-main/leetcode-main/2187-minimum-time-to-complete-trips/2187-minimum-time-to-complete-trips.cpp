class Solution {
public:
    long long fun(vector<int> &time,long long x)
    {
        long long ans=0;
        for(auto it:time)
            ans+=x/it;
        return ans;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=1;
        long long min=time[0];
        long long high=min*totalTrips;
        long long ans=high;
        while(low<high)
        {
            long long mid =(low+high)>>1; //Divided by 2
            long long res=fun(time,mid);
            if(res<totalTrips)
                low=mid+1;
            else
                high=mid;
                
        }
        return low;
    }
};