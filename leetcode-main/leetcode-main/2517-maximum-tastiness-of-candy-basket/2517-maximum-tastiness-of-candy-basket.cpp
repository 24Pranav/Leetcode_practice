class Solution {
public:
    bool isPossible(vector<int> &nums,int mid,int k)
    {
        int cnt=1;
        int candy_pos=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]-candy_pos>=mid)
            {
                candy_pos=nums[i];
                cnt++;
            }
            if(cnt==k)
                return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int left=1;
        int right=INT_MAX;
        sort(price.begin(),price.end());
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(price,mid,k))
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