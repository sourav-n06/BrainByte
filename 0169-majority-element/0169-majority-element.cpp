class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, res = 0;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[res] == nums[i]) 
                count++;
            else
                count--;

            if(count == 0) {
                res = i;
                count = 1;
            }
        }

        return nums[res];
    }
};