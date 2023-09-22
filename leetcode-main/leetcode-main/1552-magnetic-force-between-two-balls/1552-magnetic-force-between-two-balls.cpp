class Solution {
public:
    bool isPossible(vector<int> &nums,int mid,int k)
    {
     int cnt=1;
     int cow_cor=nums[0];
     for(int i=1;i<nums.size();i++)
     {
         if(nums[i]-cow_cor>=mid)
         {
             cnt++;
             cow_cor=nums[i];
         }
         if(k==cnt)
         return true;
     }
     return false;
     }
    int maxDistance(vector<int>& stalls, int k) {
        sort(stalls.begin(),stalls.end());
        int left=1;
        int right=*max_element(stalls.begin(),stalls.end());
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(stalls,mid,k))
            {
                ans=mid;
                left=mid+1;
            }
            else
            right=mid-1;
        }
        return ans;
    }
};