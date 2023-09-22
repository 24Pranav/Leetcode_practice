class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int count=0;
        int i=0;
        int j=1;
        while(j<intervals.size())
        {
            if(intervals[i][1]<=intervals[j][0])
            {
                i=j;
                j++;
            }
            // else if(intervals[i][0]==intervals[j][0])
            // {
            //     count++;
            //     j++;
            // }
            else
            {
                if(intervals[i][1]<intervals[j][1])
                {
                    j++;
                    count++;
                }
                else
                {
                    i=j;
                    j++;
                    count++;
                }
            }
        }
        return count;
    }
};