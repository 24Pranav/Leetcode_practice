class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            int count=1;
            long long sqr=(long long)nums[i]*nums[i];
            while(binary_search(nums.begin(),nums.end(),sqr))
            {
                count++;
                sqr*=sqr;
                ans=max(ans,count);
            }
        }
        return ans>1?ans:-1; //If answer greater than 1 return -1 else count
    }
};