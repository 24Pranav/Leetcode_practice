class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int threshold) {
        int ans=0;
        int c=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0 && nums[i]<=threshold){
                c=1;
            for(int j=i;j<nums.size()-1;j++)
            {
                if(nums[j]%2!=nums[j+1]%2 && nums[j]<=threshold && nums[j+1]<=threshold){
                    c++;
                    // cout<<nums[j]<<" "<<nums[j+1]<<endl;
                }
                else
                {
                    break;
                }
            }
            ans=max(ans,c);
        }
        }
        return ans;
    }
};