class Solution {
public:
    int fun(int n,int k)
    {
        if(n==1)
            return 0;
        return (fun(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) {
        return fun(n,k)+1; // calculated for oth base indexing we have to change to 1 base indexing
    }
};