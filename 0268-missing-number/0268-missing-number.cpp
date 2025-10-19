class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int xorr = 0;

        for(int i = 0; i <= nums.size(); i++) {
            xorr ^= i;
        }

        for(int n : nums) {
            xorr ^= n;
        }

        return xorr;
    }
};



/*

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int total = n * (n + 1) / 2;
        int sum = 0;
        for (int num : nums)
            sum += num;
        return total - sum;
    }
};

*/