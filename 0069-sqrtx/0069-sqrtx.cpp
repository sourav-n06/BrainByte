class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;

        while(left <= right) {
            long long mid = (left + right) / 2;
            if(mid * mid == x) return mid;
            else if(mid * mid > x) right = mid - 1;
            else left = mid + 1;
        }

        return left-1;
    }
};