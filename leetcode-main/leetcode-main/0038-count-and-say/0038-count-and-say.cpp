class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        //Recursion Call
        string str=countAndSay(n-1);
        string res="";
        int counter=0;
        for(int i=0;i<str.length();i++)
        {
            counter++;
            if(i==str.length()-1 || str[i]!=str[i+1])
            {
                res+=to_string(counter);
                res+=str[i];
                counter=0;
            }
        }
        return res;
    }
};