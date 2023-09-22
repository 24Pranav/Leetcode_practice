class Solution {
public:
    bool check(char c)
    {
        c=tolower(c);
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
            return true;
        return false;
    }
    bool halvesAreAlike(string s) {
        int v1=0,v2=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(check(s[i]))
                v1++;
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(check(s[i]))
                v2++;
        }
        return v1==v2;
    }
};