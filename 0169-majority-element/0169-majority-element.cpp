class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //Moor's voting algo
        int ele = nums[0];
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cnt == 0) {
                ele = nums[i];
                cnt = 1;
            } else if(ele == nums[i]) cnt++;
            else cnt--;
        }
        cnt = 0;
        for(auto x : nums) {
            if(x == ele) cnt++;
        }
        if(cnt > nums.size() / 2) return ele;
        else return -1;
    }
};