class Solution {
public:
    bool isPowerOfFour(int n) {
        // string s = bitset<64> (n).to_string();
        // if(n==1)
        //     return true;
        // if(s[s.size()-1]=='1' || n<=0 || __builtin_popcount(n)>1) //set bit should be 1 only
        //     return false;
        // int count=0;
        // // cout<<s<<endl;
        // for(int i=s.size()-1;i>=0;i--)
        // {
        //     if(s[i]=='1')
        //         break;
        //     if(s[i]=='0')
        //         count++;
        // }
        // // cout<<count;
        // return count%2==0; //o's before 1 should be even only
        return n>0 && (n&(n-1))==0 && (n-1)%3==0;
    }
};