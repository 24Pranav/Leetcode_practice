class Solution {
public:
    bool allsmall(string word)
    {
        for(auto x:word)
        {
            if(x>=97 && x<=122)
            {}
            else
                return false;
        }
        return true;
    }
    bool allcaps(string word)
    {
                for(auto x:word)
        {
            if(x>=65 && x<=90)
            {}
            else
                return false;
        }
        return true;
    }
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(allsmall(word))
            return true;
        if(allcaps(word))
            return true;
        if(word[0]>=65 && word[0]<=90)
        {
            for(int i=1;i<n;i++)
            {
            if(word[i]>=97 && word[i]<=122)
            {}
            else
            return false;
            }
            return true;
        }
        if(word[0]>=97 && word[0]<=122)
        {
            for(int i=1;i<n;i++)
            if(word[i]>=65 && word[i]<=90)
                return false;
        }
        for(int i=1;i<n;i++)
            if(word[i]>=97 && word[i]<=122)
                return false;
        return true;
        
    }
};