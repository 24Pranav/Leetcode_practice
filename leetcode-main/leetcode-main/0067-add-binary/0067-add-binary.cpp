class Solution {
public:
    int bintodec(string str)
    {
    int ans=0;
    int n=str.size();
    for(auto &x:str)
    {
        if(x=='1')
        ans+=pow(2,n-1);
        n--;
    }
    return ans;
    }
    string dectobin(int n)
    {
    string ans=bitset<128>(n).to_string();
    int i=0;
    for(auto &x:ans)
    {
        if(x=='0')
        i++;
        else
        break;
    }
    ans.erase(0,i);
    return ans;
    }
    string addBinary(string a, string b) {
        // int ans=0;
        // ans+=bintodec(a);
        // ans+=bintodec(b);
        // if(a=="0" && b=="0")
        //     return a;
        // return dectobin(ans);
          int i = a.size()-1, j = b.size()-1;
    int carry = 0;
    string ret = "";
    while (i >= 0 || j >= 0 || carry!=0) {
        if (i >= 0) {
            carry += a[i]=='0'?0:1;
            i--;
        }
        if (j >= 0) {
            carry += b[j]=='0'?0:1;
            j--;
        }
        ret = ((carry%2)==0?"0":"1") + ret;
        carry /= 2;
    }
    return ret;
    }
};