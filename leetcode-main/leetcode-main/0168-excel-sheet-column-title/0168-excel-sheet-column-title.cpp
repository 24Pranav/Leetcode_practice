class Solution {
public:
    string chars="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string convertToTitle(int n) {
    string res;
    char tmp;
    while(n){
        n -= 1;
        tmp = 'A' + n % 26;
        res = tmp + res;
        n /= 26;
    }
    return res;
    }
};