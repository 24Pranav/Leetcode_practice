//Prince Chaurasia
//https://leetcode.com/princeforcode/
#define pb push_back
#define pbb pop_back
class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> num;
        int fact=1;
        string ans="";
        for(int i=1;i<n;i++) // calculate for (n-1)
        {
            fact*=i;
            num.pb(i); //pushing elements inside vector nums
        }
        num.pb(n); // push last element
        k--; // because index starts from 0 so we need to find k-1 Ex:17 therefore we will find 16
        while(true)
        {
            ans+=to_string(num[k/fact]);
            num.erase(num.begin()+ k/fact);
            if(num.size()==0)
                break;
            k%=fact; // To find new k for new set of permutations
            fact/=num.size(); // or calculate factorial for size-1
        }
        return ans;
    }
};