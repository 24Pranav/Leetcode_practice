class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i = 0 , j = 0 , nT = 0 , nF = 0 , n = answerKey.size() , len = 0;
        
        while(j<n)
        {
            answerKey[j]=='T'?nT++:nF++;
            int count = min(nT,nF);
            if(count<=k)
                len = max(len , j-i+1);
            else{
                while(count>k)
                {
                    answerKey[i]=='T'?nT--:nF--;
                    count = min(nT,nF);
                    i++;
                }
            }
            j++;
        }
        return len;
    }
};