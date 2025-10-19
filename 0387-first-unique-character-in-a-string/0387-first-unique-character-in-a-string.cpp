class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> vec(26, 0);

        for(char c : s) {
            vec[c-'a']++;
        }
        for(int i = 0; i < s.length(); i++) {
            if(vec[s[i] - 'a'] == 1) return i;
        }

        return -1;
    }
};