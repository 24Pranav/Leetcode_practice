//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string S){
        // code here
        int len=1;
        int st=0;
        int end=0;
        int n=S.size();
        //Odd len
        for(int i=0;i<n-1;i++)
        {
            int l=i;
            int r=i;
            while(l>=0 && r<n && S[l]==S[r])
            {
                l--;
                r++;
            }
             if(r-l-1 > len)
                {
                    len=r-l-1;
                    st=l+1;
                    end=r-1;
                }
        }
        //Even length
        for(int i=0;i<n-1;i++)
        {
            int l=i;
            int r=i+1;
            while(l>=0 && r<n && S[l]==S[r])
            {
                l--;
                r++;
            }
            if(r-l-1 > len)
                {
                    len=r-l-1;
                    st=l+1;
                    end=r-1;
                }
        }
        return S.substr(st,len);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends