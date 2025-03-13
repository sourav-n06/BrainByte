
class Solution {
    void Reverse(vector<int>& nums, int left, int right) {
        int siz = right - left + 1;
        for(int i = 0; i < siz/2; i++){
            int temp = nums[left];
            nums[left] = nums[right];
            nums[right] = temp;
            left++;
            right--;
        }

    }
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int rem = k % n;
        
        Reverse(nums, 0, n-1);
        Reverse(nums, 0, rem - 1);
        Reverse(nums, rem , n-1);

    }
};


// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         int N = nums.size();
//         int rem = k % N;
//         if (rem == 0) return;

//         vector<int> vec(nums.end() - rem, nums.end());
//         nums.erase(nums.end() - rem, nums.end());
//         nums.insert(nums.begin(), vec.begin(), vec.end());
//         return;
//     }
// };


    // void rotate(vector<int>& nums, int k) {
    //     int N = nums.size();
    //     int rem = k % N;
    //     if(rem == 0) return;

    //     vector<int> vec;
    //     int slow = N - rem;
    //     while(slow != nums.size()) {
    //         vec.push_back(nums[slow]);
    //         cout<<slow;
    //         nums.erase(nums.begin() + slow);
    //     }

    //     nums.insert(nums.begin(), vec.begin(), vec.end());
    //     return;
    // }