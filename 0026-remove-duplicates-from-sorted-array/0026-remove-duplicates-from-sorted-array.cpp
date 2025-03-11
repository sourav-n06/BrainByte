
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j = 0;
        for(int i = 1; i < nums.size(); i++){
            if(nums[j] != nums[i]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j+1;
    }
};

/*

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()) {
            if(i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                continue;
            }
            i++;
        }
        return nums.size();
    }
};

*/

