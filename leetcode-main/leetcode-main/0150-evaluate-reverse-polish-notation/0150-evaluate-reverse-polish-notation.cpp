class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> st;
        for(string x: tokens)
        {
            if(x=="+" || x=="-" || x=="*" || x=="/")
            {
                if(x=="+")
                {
                    long num1=st.top();
                    st.pop();
                    long num2=st.top();
                    st.pop();
                    st.push(num1+num2);
                }
                else if(x=="-")
                {
                    long num1=st.top();
                    st.pop();
                    long num2=st.top();
                    st.pop();
                    st.push(num2-num1);
                }
                else if(x=="/")
                {
                    long num1=st.top();
                    st.pop();
                    long num2=st.top();
                    st.pop();
                    st.push(num2/num1);
                }
                else
                {
                    long num1=st.top();
                    st.pop();
                    long num2=st.top();
                    st.pop();
                    st.push(num1*num2);
                }
            }
            else
            {
                long num=stoi(x);
                st.push(num);
            }
        }
        return (int)st.top();
    }
};