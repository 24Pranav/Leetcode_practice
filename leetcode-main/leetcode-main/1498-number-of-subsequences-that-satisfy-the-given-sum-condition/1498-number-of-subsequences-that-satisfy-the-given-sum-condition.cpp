class Solution {
public:
    const int MOD=1e9+7;
    vector<int> pow;
    void calc(int n)
    {
        pow[0]=1;
        for(int i=1;i<=n;i++)
        {
            pow[i]=(2*pow[i-1])%MOD;
        }
    }
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        //power calc
        pow.resize(n+1);
        calc(n);
        sort(nums.begin(),nums.end());
        int count=0;
        int i=0;
        int j=n-1;
        while(i<=j)
        {
            int tar=target-nums[i];
            if(nums[i]+nums[j]<=target)
            {
                count=(count+pow[j-i])%MOD;
                i++;
            }
            else
            {
                j--;
            }
        }
        return count;
    }
};