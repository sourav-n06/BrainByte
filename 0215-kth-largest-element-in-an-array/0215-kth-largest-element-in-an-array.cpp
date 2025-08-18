class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int ele;
        priority_queue<int> pq(nums.begin(), nums.end());

        for(int i = 1; i <= k; i++) {
            ele = pq.top();
            pq.pop();
        }

        return ele;
    }
};