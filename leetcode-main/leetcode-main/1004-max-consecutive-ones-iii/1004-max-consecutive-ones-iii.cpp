class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int totflip=0;
        int maxlen=0;
        int n=nums.size();
        int s=0,e=0;
        while(e<n)
        {
            if(nums[e]==0)
                totflip++;
            while(totflip>k)
            {
                if(nums[s]==0)
                    totflip--;
                s++;
            }
            maxlen=max(maxlen,e-s+1);
            e++;
            
        }
        return maxlen;
    }
};