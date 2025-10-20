class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long revNumber = 0;
        int num = x;
        while(num) {
            int rem = num % 10;
            revNumber = revNumber * 10 + rem;
            num = num / 10;
        }

        if(revNumber == x) return true;
        else return false;
    }
};