class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        map<int,int> s;
        int sum=0;
        for(auto &x: nums)
            s[x]++;
        for(auto x:s)
            if(x.second==1)
                sum+=x.first;
        return sum;
    }
};