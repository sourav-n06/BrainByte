class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        int i = 0; int j = 0;
        int cntZero = 0;
        int maxOneLength = 0;

        while(j < N) {
            if(nums[j] == 0) cntZero++;

            while(cntZero >= 2) {
                if(nums[i] == 0) cntZero--;
                i++;
            }
            if(cntZero == 0 || cntZero == 1) {
                maxOneLength = max(maxOneLength, (j-i));
            }
            j++;
        }
        return maxOneLength;
    }
};