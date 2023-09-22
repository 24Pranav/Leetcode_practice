class Solution {
public:
    int maximum69Number (int num) {
        string str=to_string(num);
        // int i=0;
        // for(auto x:str)
        // {
        //     int num1=x-'0';
        //     if(num1!=9)
        //     {str[i]='9';
        //      break;
        //     }
        //     i++;
        // }
        // int ans=0;
        // for(int i=0;i<str.size();i++)
        // {
        //     ans=(ans*10)+str[i]-'0';
        // }
        // return ans;
        for(auto &x:str)
            if(x=='6')
            {
                x='9';
                break;
            }
        return stoi(str);
    }
};