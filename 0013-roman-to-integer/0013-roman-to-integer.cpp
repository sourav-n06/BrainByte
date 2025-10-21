class Solution {
    int getValue(char c) {
        if(c == 'I') return 1;
        else if(c == 'V') return 5;
        else if(c == 'X') return 10;
        else if(c == 'L') return 50;
        else if(c == 'C') return 100;
        else if(c == 'D') return 500;
        else return 1000;
    }

public:
    int romanToInt(string s) {

        int res = 0;
        int n = s.length() - 1;
        res += getValue(s[n]);

        for(int i = n-1; i >= 0; i--) {
            if(getValue(s[i]) < getValue(s[i+1])) {
                res -= getValue(s[i]);
            } else {
                res += getValue(s[i]);
            }
        }

        return res;
    }
};