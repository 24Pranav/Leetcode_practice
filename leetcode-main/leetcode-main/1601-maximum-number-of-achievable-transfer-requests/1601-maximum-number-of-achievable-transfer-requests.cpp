class Solution {
public:
        int answer = 0;
    int maximumRequests(int n, vector<vector<int>>& requests) {
        answer = 0;
        vector<int> inDegree(n, 0);
        fun(0, 0, inDegree, requests);
        return answer;
    }
    void fun(int index, int count, vector<int>& inDegree, vector<vector<int>>& requests) {
        if (index == requests.size()) {
            for (int i : inDegree) {
                if (i != 0)
                    return;
            }
            answer = max(answer, count);
            return;
        }
        inDegree[requests[index][0]]++;
        inDegree[requests[index][1]]--;
        fun(index + 1, count + 1, inDegree, requests);
        inDegree[requests[index][0]]--;
        inDegree[requests[index][1]]++;
        fun(index + 1, count, inDegree, requests);
    }
};