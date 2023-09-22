class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        set<int> mp1(nums1.begin(),nums1.end());
        set<int> mp2(nums2.begin(),nums2.end());
        vector<int> temp;
        for(auto &x:mp1)
        {
            if(mp2.find(x)==mp2.end())
                temp.push_back(x);
        }
        ans.push_back(temp);
        temp.clear();
        for(auto &x:mp2)
        {
            if(mp1.find(x)==mp1.end())
            {
                temp.push_back(x);
            }
        }
        ans.push_back(temp);
        return ans;
    }
};