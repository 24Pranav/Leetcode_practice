class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)
            return s;
        string ans="";
        for(int i=0;i<numRows;i++)
        {
            int j=2*(numRows-1);
            for(int k=i;k<s.size();k+=j)
            {
                ans+=s[k];
                if(i>0 && i< numRows-1 && k+j-(2*i)<s.size())
                {
                    ans+=s[k+j-(2*i)];
                }
            }
        }
        return ans;
    }
};