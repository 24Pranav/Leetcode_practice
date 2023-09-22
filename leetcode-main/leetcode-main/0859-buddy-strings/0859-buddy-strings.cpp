class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int count=0;
        // If size is not equal
        if(s.size()!=goal.size())
            return false;
        map<char,int> mp;
        // If s and goal is equal
        if(s==goal)
        {
            for(auto &x:s)
            {
                mp[x]++;
                if(mp[x]>=2)
                    return true;
            }
            return false;
        }
        int n=s.size();
        int f_c=-1; // first different char
        int l_c=-1; // last different char
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i]){
                count++;
                if(f_c==-1)
                {
                    f_c=i;
                }
                else
                    l_c=i;
            }
            if(count>2)
                return false;
        }
        if(count==1)
            return false;
        if(count==2)
        {
            //Eg:- "abcaa" "abcbb"
        swap(s[f_c],s[l_c]);
        if(s==goal)
            return true;
        }
        return false;
    }
};