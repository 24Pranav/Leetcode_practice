class Solution {
public:
    int jump(vector<int>& nums) {
        //Using Greedy Approach
        int jump=0;
        int pos=0;
        int max_reach=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            max_reach=max(max_reach,i+nums[i]);
            if(pos==i)
            {
                pos=max_reach;
                jump++;
            }
        }
        return jump;
    }
};