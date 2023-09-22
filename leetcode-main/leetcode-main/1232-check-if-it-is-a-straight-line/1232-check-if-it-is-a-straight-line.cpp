class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(),coordinates.end());
        int n=coordinates.size();
        if(n==2)
            return true;
        int x1=coordinates[0][0];
        int y1=coordinates[0][1];
        int x2=coordinates[1][0];
        int y2=coordinates[1][1];
        int x_1=abs(x2-x1);
        int y_2=abs(y2-y1);
        // double ans=y_2/x_1;
        for(int i=1;i<n;i++)
        {
            int tx1=coordinates[i][0];
            int ty1=coordinates[i][1];
            int tx2=coordinates[i-1][0];
            int ty2=coordinates[i-1][1];
            int t11=abs(tx2-tx1);
            int t22=abs(ty2-ty1);
            // double ans1=t22/t11;
            // if(ans!=ans1)
            //     return false;
            if(y_2*t11 != t22*x_1)
                return false;
        }
        return true;
    }
};