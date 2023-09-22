class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rq,dq;
        int n=senate.size();
        int i=0;
        for(auto &x:senate)
        {
            (x=='R')?rq.push(i):dq.push(i);
            i++;
        }
        while(!rq.empty() && !dq.empty())
        {
            int f1=rq.front();
            int f2=dq.front();
            rq.pop();
            dq.pop();
            (f1<f2)?rq.push(f1+n):dq.push(f2+n);
        }
        return (rq.size()>dq.size())?"Radiant":"Dire";
    }
};