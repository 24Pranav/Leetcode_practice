class Solution {
public:
    bool isPossible(vector<int> &nums,int days,int mid)
    {
        int day=1;
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>mid)
            {
                day++;
                sum=nums[i];
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int left=0;
        int sum=0;
        for(auto x:weights)
        {
            left=max(left,x);
            sum+=x;
        }
        int right=sum;
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            int curload=0;
            if(isPossible(weights,days,mid))
            {
                ans=mid;
                //Try to decrease the load
                right=mid-1;
            }
            else
            {
                //Increase the load
                left=mid+1;
            }
        }
        return ans;
    }
};