class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> temp(2);
        sort(intervals.begin(),intervals.end());
        temp[0]=intervals[0][0];
        temp[1]=intervals[0][1];
        for(auto &x:intervals)
        {
            if(x[0]<=temp[1])
            {
                temp[1]=max(temp[1],x[1]);
            }
            else
            {
                ans.push_back(temp);
                temp[0]=x[0];
                temp[1]=x[1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};