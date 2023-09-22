class Solution {
public:
    int strStr(string haystack, string needle) {
        int ptr1=0;
        int ptr2=0;
        int ans=0;
        for(int i=0;i<max(haystack.size(),needle.size());i++)
        {
            int ind=haystack.find(needle[ptr1]);
            cout<<ind<<endl;
            if(ind>=0)
            if(haystack.substr(ind,needle.size())==needle)
            {
                return ans+ind;
            }
            else
            {
                ans++;
                haystack.erase(ind,1);
                cout<<haystack;
            }
        }
        return -1;
    }
};