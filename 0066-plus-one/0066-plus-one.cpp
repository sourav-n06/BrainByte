class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        if(digits[n-1] < 9) {
            digits[n-1] += 1;
            return digits;
        } else {

            int carry = 0;
            int sum = digits[n-1] + 1;
            for(int i = n - 1; i >= 0; i--) {
                
                if(sum == 10 && i != 0) {
                    digits[i] = 0;
                    carry = 1;
                } else if (sum == 10 && i == 0) {
                    digits[i] = 1;
                    digits.push_back(0);
                    return digits;
                } else {
                    digits[i] = sum;
                    return digits;
                }
                if(i != 0)
                    sum = digits[i-1] + carry;
            }
            return {};
        }
    }
};