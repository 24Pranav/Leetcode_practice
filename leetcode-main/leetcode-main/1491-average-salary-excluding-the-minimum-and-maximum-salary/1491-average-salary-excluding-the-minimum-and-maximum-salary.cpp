class Solution {
public:
    double average(vector<int>& salary) {
      double avg=0;
        avg=accumulate(salary.begin(),salary.end(),0);
        avg-= (*max_element(salary.begin(),salary.end())+*min_element(salary.begin(),salary.end()));
        return avg/(salary.size()-2);
    }
};