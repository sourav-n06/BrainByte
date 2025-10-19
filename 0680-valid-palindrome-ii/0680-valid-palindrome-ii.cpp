class Solution {
    bool checkByPart(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;

        while (left <= right) {
            if (s[left] == s[right]) {
                left++;
                right--;
            } else {
                return (checkByPart(s, left + 1, right) ||
                        checkByPart(s, left, right - 1));
            }
        }
        return true;
    }
};