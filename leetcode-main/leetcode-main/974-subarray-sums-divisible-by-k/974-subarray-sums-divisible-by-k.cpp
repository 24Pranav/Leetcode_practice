class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        if(nums.size()==0) return 0;
        //Pep Coding Method YT
        unordered_map<int,int> map;
        int i=0;
        int sum=0;
        int count=0;
        map[0]=1; //For edge case from 0 to 0 one sbarray
        while(i<nums.size())
        {
            sum+=nums[i++];
            int rem=sum%k;
            // No of count of remainders equal to number of subarrays
            //k*n+x , k*m+x where x is remainder
            if(rem<0) rem+=k; //k*n-y to make y positive we will add k (IMP)
            count+=map[rem];
            map[rem]++; //Inserting remainder inside map
        }
        return count;
    }
};