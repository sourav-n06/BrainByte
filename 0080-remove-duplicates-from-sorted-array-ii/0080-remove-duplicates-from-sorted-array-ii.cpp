class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();
        int j = 0;
        for(int i = 1; i < nums.size()-1; i++) {
            if(nums[i-1] != nums[i] && nums[i] != nums[i+1]) {
                j++;
                nums[j] = nums[i];
            } else if(nums[i-1] == nums[i] && nums[i] != nums[i+1]) {
                j++;
                nums[j] = nums[i];
            } else if(nums[i-1] != nums[i] && nums[i] == nums[i+1]) {
                j++;
                nums[j] = nums[i];
            }
        }
        nums[j+1] = nums[nums.size() - 1];
        j++;
        return j + 1;
    }
};