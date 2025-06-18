class Solution {
    bool isValidArray(vector<int>& nums, vector<int>& res, int i, int k) {
        for(int j = i; j < i+3; j++) {
            for(int n = i; n < i+3; n++) {
                if(abs(nums[j] - nums[n]) <= k) continue;
                else return false;
            }
            res.push_back(nums[j]);
        }
        return true;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i += 3) {
            vector<int> res;
            if(isValidArray(nums, res, i, k)) {
                ans.push_back(res);
            }
            else return {};
        }
        return ans;
    }
};