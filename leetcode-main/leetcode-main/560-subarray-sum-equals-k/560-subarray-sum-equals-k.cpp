class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        unordered_map<int,int> map;
        int i=0;
        int sum=0;
        int count=0;
        while(i<nums.size())
        {
            sum+=nums[i];
            if(sum==k) count++;
            if(map.find(sum-k)!=map.end()) count+=map[sum-k];
            map[sum]++;
            i++;
        }
        return count;
    }
};