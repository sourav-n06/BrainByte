class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1e3;
        for(int i = 0; i < n; i++) {
            int k = (i+1) % n;
            if(abs(nums[i] - nums[k]) > maxi) 
                maxi = abs(nums[i] - nums[k]);
        }
        return maxi;
    }
};