class Solution {
    bool isOperator(char c) {
        if(c == '+' || c == '-' || c == '*' || c == '/') return true;
        else return false;
    }
public:
    int calculate(string s) {

        int n = s.length();
        stack<int> st;

        int number = 0;
        char prevSign = '+';

        for(int i = 0; i < n; i++) {

            if(isdigit(s[i])) {
                number = number * 10 + (s[i] - '0');
            }

            if(isOperator(s[i]) || i == n-1) {
                if(prevSign == '+') {
                    st.push(number);

                } else if(prevSign == '-') {
                    st.push(-number);

                } else if(prevSign == '*') {
                    int res = st.top(); st.pop();
                    res = res * number;
                    st.push(res);


                } else if(prevSign == '/') {
                    int res = st.top(); st.pop();
                    res = res / number;
                    st.push(res);
                     
                }
                prevSign = s[i];
                number = 0;
            }
        }

        int ans = 0;
        while(!st.empty()) {
            ans += st.top(); st.pop();
        }

        return ans;
    }
};