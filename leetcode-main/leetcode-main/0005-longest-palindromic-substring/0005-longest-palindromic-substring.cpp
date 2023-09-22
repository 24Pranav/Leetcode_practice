class Solution {
public:
    // string fun(string s,int even)
    // {
    //     int n=s.size();
    //     string ans="";
    //     for(int i=0;i<n;i++)
    //     {
    //         int left=i;
    //         int right=i;
    //         if(even==1)
    //             right=i+1;
    //         string ans1="";
    //         while(left>=0 && right<n && s[left]==s[right])
    //         {
    //             cout<<left<<" "<<right<<endl;
    //             cout<<s[left]<<" "<<s[right]<<endl;
    //             ans1=s.substr(left,right-left+1);
    //             left--;
    //             right++;
    //             if(ans1.size()>ans.size())
    //                 ans=ans1;
    //         }
    //     }
    //     if(ans=="")
    //         ans+=s[0];
    //     return ans;
    // }
    // string longestPalindrome(string s) {
    //     if(s.size()==3)
    //     {
    //         string ans="";
    //         if(s[0]==s[2])
    //             return s;
    //         if(s[0]==s[1])
    //             return s.substr(0,2);
    //         if(s[1]==s[2])
    //             return s.substr(1,2);
    //     }
    //     return fun(s,s.size()%2==0);
    // }
    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        int max_len = 1;
        int n = s.length();
        int st = 0, end = 0;
        
        // Odd length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        // Even length
        for(int i = 0; i < n-1; ++i){
            int l = i, r = i+1;
            while(l >= 0 && r < n){
                if(s[l] == s[r]){
                    l--; r++;
                }else
                    break;
            }
            int len = r-l-1;
            if(len > max_len){
                max_len = len;
                st = l+1;
                end = r-1;
            }
        }
        
        return s.substr(st, max_len);
        
    }
};