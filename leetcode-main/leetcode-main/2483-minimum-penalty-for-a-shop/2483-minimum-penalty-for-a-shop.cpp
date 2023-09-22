class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<vector<int>> presuf(n+1,vector<int>(2,0));
        int mini=INT_MAX;
        int ind=0;
        bool flag1=false;
        for(int i=n-1;i>=0;i--)
        {
            presuf[i][1]=presuf[i+1][1];
            if(customers[i]=='Y')
            presuf[i][1]++;
        }
        mini=presuf[0][1];
        int prefix=0;
        for(int i=0;i<n;i++)
        {
            if(i-1>=0)
            presuf[i][0]=presuf[i-1][0];
            if(customers[i]=='N')
            presuf[i][0]++;
            if(presuf[i][0]+presuf[i+1][1]<mini)
            {
                mini=presuf[i][0]+presuf[i+1][1];
                ind=i+1;
            }
        }
        // for(auto &it:presuf)
        //     cout<<it[0]<<" "<<it[1]<<endl;
        return ind;
    }
};