#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to find the first occurrence of the target
    int searchFirst(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, first = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow
            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // Continue searching left
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return first;
    }

    // Function to find the last occurrence of the target
    int searchLast(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1, last = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // Continue searching right
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return last;
    }

public:
    // Function to find the first and last position of target in the sorted array
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchFirst(nums, target), searchLast(nums, target)};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, target;
        cin >> n >> target;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        Solution sol;
        vector<int> result = sol.searchRange(nums, target);
        cout << result[0] << " " << result[1] << "\n";
    }
    return 0;
}
