class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x; // Base cases

        int low = 1, high = x, ans = 0;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;
            
            if (square == x) return mid;   // Found exact square root
            else if (square < x) {         // Move right, store possible answer
                ans = mid;
                low = mid + 1;
            } else {                        // Move left
                high = mid - 1;
            }
        }
        return ans; // Integer part of sqrt(x)
    }
};