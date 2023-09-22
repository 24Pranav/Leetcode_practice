class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()<=1)
            return s.size();
        while(1)
        {
            int x=s.size();
            if(s[x-1]==' ')
                s.pop_back();
            else
                break;
        }
        int count=0;
        while(1)
        {
            int x=s.size();
            if(s!="")
            {
            if(s[x-1]!=' ')
                count++;
            else
                break;
            }
            else
                break;
            s.pop_back();
        }
        return count;
    }
};