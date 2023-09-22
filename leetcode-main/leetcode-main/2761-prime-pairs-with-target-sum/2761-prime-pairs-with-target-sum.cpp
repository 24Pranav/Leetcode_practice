class Solution {
public:
    set<int> primes;
    void prime(int limit) {
  vector<bool> isPrime(limit + 1, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int p = 2; p * p <= limit; ++p) {
    if (isPrime[p]) {
      for (int i = p * p; i <= limit; i += p) {
        isPrime[i] = false;
      }
    }
  }
    for (int p = 2; p <= limit; ++p) {
    if (isPrime[p]) {
      primes.insert(p);
    }
  }
}
    vector<vector<int>> findPrimePairs(int n) {
        prime(n);
        vector<vector<int>> ans;
        for(auto &x:primes)
        {
            int tar=n-x;
            if(tar>=2)
            if(primes.find(tar)!=primes.end()){
                ans.push_back({x,tar});
                // primes.erase(x);
                primes.erase(tar);
            }
        }
        return ans;
    }
};