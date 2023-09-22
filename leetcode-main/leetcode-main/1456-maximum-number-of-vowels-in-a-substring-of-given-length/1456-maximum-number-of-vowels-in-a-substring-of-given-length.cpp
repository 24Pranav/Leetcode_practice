class Solution {
public:
    bool isvowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) {
        int vcount=0;
        int n=s.size();
        for(int i=0;i<k;i++)
        {
            if(isvowel(s[i]))
                vcount++;
        }
        if(vcount==k)
            return k;
        int maxi=vcount;
        int j=0;
        for(int i=k;i<n;i++)
        {
            if(isvowel(s[i]))
            {
                vcount++;
            }
            if(isvowel(s[j]))
            {
                vcount--;
            }
            j++;
            maxi=max(maxi,vcount);
        }
        return maxi;
    }
};