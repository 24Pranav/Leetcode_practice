#define ll long long
#define MOD 1000000007
class Solution {
public:
    ll pow(ll x, ll n) {
        if(n==0)
            return 1;
        ll ans=pow(x,n/2); //x^n/2 * x^n/2
        ans*=ans;
        ans%=MOD;
        if(n%2) ans*=x;
        ans%=MOD;
        return ans%MOD;
        
    }
    int countGoodNumbers(long long n) {
         // prime_count=4; {2,3,5,7}
         // even_count=5; {0,2,4,6,8}
        if(n%2==0) //Even
        {
            //Even places n/2 ans odd places n/2
            ll x=pow(5,n/2);
            ll y=pow(4,n/2);
            return (x*y)%MOD;
            
        }
        else
        {
            //Odd
            //even places (n+1)/2 odd places n/2
            ll j=n/2;
            ll x=pow(5,n-j);
            ll y=pow(4,j);
            return (x*y)%MOD;
        }
        //Odd will always be n/2 therefore even will n-n/2;
        // ll ans=pow(20,n/2); // For even odd 20^n/2 will be common for odd case * 5 will be extra we can observe if we combine x and y
        // if(n%2)
        //     ans*=5;
        // return ans%MOD;
    }
};