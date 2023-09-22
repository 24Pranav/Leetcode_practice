class Solution {
public:
    int myAtoi(string s) {
        long long ans=0;
        // cout<<s.size()<<" "<<s;
        while(s[0]==' ')
            s.erase(0,1);
        int flag=1;
        if(s[0]=='+' && s[1]!='-')
            s.erase(0,1);
        if(s[0]=='-'){
            flag=!flag;
            s.erase(0,1);
        }
        for(int i=s.size()-1;i>=0;i--)
        {
            if(s[i]=='-' || s[i]=='+'){
                s[i]='a';
                cout<<s<<endl;
            }
            else
                break;
 
        }
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size())
            if((s[i]=='+' && s[i+1]=='-') || (s[i]=='-' && s[i+1]=='+'))
               return 0;
            if(s[i]=='-' && i>0)
                return 0;
            else if(s[i]>='0' && s[i]<='9')
            {
            ans=ans*10 +s[i]-'0';
                if(ans>INT_MAX)
                    return (flag)?INT_MAX:INT_MIN;
            }
            else
                break;
        }
        // cout<<ans;
        if(!flag)
            return -1L*ans;
        return ans;
    }
};