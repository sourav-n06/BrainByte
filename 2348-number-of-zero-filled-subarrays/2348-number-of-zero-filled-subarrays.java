class Solution {
    public long zeroFilledSubarray(int[] nums) {
        int n = nums.length;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                continue;
            } else {
                long count = 0;
                while (i < n && nums[i] == 0) {
                    count++;
                    i++;
                }
                ans += (count) * (count + 1) / 2;
            }
        }
        return ans;
    }
}