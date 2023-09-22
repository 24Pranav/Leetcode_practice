class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()<=1)
            return nums.size();
        unordered_set<int> set;
        for(auto &x:nums)
            set.insert(x);
        int len=1;
        for(auto &x:set)
        {
            if(!(set.find(x-1)!=set.end()))
            {
                int tlen=1;
                int num=x+1;
                while(set.find(num)!=set.end())
                {
                    num++;
                    tlen++;
                    len=max(len,tlen);
                }
            }
        }
        return len;
    }
};