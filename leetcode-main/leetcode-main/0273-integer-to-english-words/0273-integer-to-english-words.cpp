class Solution {
public:
string one[20]={"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};

string ten[10]={"Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};


string fun(int n)
{
    if(n>=1000000000) return fun(n/1000000000)+" Billion"+fun(n%1000000000);
    
    if(n>=1000000) return fun(n/1000000)+" Million"+fun(n%1000000);
    
    if(n>=1000) return fun(n/1000)+" Thousand"+fun(n%1000);
    
    if(n>=100) return fun(n/100)+" Hundred"+fun(n%100);
    
    if(n>=20) return " "+ten[n/10-2]+fun(n%10);
    
    if(n>=1) return " "+one[n-1];
    
    return "";
}

string numberToWords(int num) {
    
    if(num==0)
        return "Zero";
    return fun(num).substr(1);
}
};