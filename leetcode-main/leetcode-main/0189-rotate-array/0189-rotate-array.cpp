class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        long long n=nums.size();
        k=k%n;
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end()-(nums.size()-k));
        reverse(nums.begin()+k,nums.end());
    }
};