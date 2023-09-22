class Solution {
public:
    double fun(vector<int> &nums,int speed)
    {
        double time=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            double cal=1.0*nums[i]/speed;
            time+=ceil(cal);
        }
        time+=1.0*nums[nums.size()-1]/speed; // last train no need to add ceil beacuse no need to wait more
        return time;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int r=1e7;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            double time=fun(dist,mid);
            if(time<=hour)
            {
                // cout<<time<<" ";
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};