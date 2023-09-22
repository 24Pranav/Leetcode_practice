#define pb push_back
class Solution {
public:
    bool isValid(char s)
    {
        if((s>='a' && s<='z') || (s>='A' && s<='Z') || (s>='0' &&  s<='9')) return true;
        return false;
    }
    bool isPalindrome(string s) {
        //Using Extra Space
    //      vector<char> v{};
    //     for(int i=0;i<s.length();i++)
    //     {
    //         if(isValid(s[i])) v.pb(s[i]); 
    //     }
    //     if(v.empty()) return true;
    //     return helper(v);
    //     int j=v.size()-1;
    // for(int i=0;i<v.size();i++)
    // {
    //       v[i]= tolower(v[i]);
    //       v[j]= tolower(v[j]);
    //     if(v[i]!=v[j--])
    //     {
    //         return false;
    //     }
    // }
    //     return true;

        //Without Extra Space
        for(int i=0,j=s.length()-1;i<j;i++,j--)
        {
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i])!=tolower(s[j])) return false;
        }
        return true;
    }
};