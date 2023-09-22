class Solution {
public:
    bool isPossible(vector<int> &nums,int mid,int operations)
    {
        for(int i=0;i<nums.size();i++)
        {
            operations-=nums[i]/mid;
            if(nums[i]%mid==0)
                operations++; /* eg:- 8/2=4 but to divide 8 into 3 parts(2,2,2) requires only 3 operations not 4
                therefore we increament opeations by 1
                */
        }
        return operations>=0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int right=*max_element(nums.begin(),nums.end()); //Max Penalty
        int left=1; //Min Penalty
        int ans;
        while(left<=right)
        {
            int mid=left+(right-left)/2;
            if(isPossible(nums,mid,maxOperations))
            {
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;   
        }
        return ans;
    }
};