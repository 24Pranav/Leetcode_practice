#define max(a,b) (a>b)?a:b
#define pb push_back
class Solution {
public:
    int maxArea(int h, int w, vector<int>& hi, vector<int>& v) {
        //Brute Force
        //Time Complexity nlog(n)
        //if(hi.size()==1 && v.size()==1) return hi[0]*v[0];
        hi.pb(0);
        hi.pb(h);
        v.pb(0);
        v.pb(w);
        sort(hi.begin(),hi.end());
        sort(v.begin(),v.end());
        long long maxh=hi[0];
        long long maxv=v[0];
        for(int i=1;i<hi.size();i++)
        {
            maxh=max(maxh,hi[i]-hi[i-1]);
        }
        for(int i=1;i<v.size();i++)
        {
            maxv=max(maxv,v[i]-v[i-1]);
        }
        return (maxh*maxv)%1000000007;
    }
};