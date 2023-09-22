class Solution {
public:
    void print(vector<int> &nums)
    {
        for(auto &x:nums)
            cout<<x<<" ";
        cout<<endl;
    }
    int getMaximumGenerated(int n) {
        vector<int> nums(n +2);
        if(n==0 || n==1)
            return n;
        nums[0]=0;
        nums[1]=1;
        int maxi=0;
        for(int i=2;i<n+1;i++)
        {
            if(i%2==0)
            {
                nums[i]=nums[i/2];
            }
            else
            {
                nums[i]=nums[i/2]+nums[i/2 +1];
            }
            maxi=max(maxi,nums[i]);
            
        }
        print(nums);
        return maxi;
    }
};