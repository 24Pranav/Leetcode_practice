class Solution {
public:
    bool isValid(string &s,string &str,int n,int n1)
    {
        for(int i=0;i<n;i+=n1)
        {
            string sub=s.substr(i,n1);
            if(sub!=str)
                return false;
        }
        return true;
    }
    bool repeatedSubstringPattern(string s) {
        int n=s.size();
        int i=0;
        for(int j=1;j<n;j++)
        {
            string str=s.substr(i,j);
            int n1=str.size();
            if(isValid(s,str,n,n1))
                return true;
        }
        return false;
    }
};