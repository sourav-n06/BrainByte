#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the floor of k in a sorted array
    int findFloor(vector<int>& arr, int k) {
        int largestNumberIndex = -1; // Stores the floor index
        int left  = 0, right = arr.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2; // Avoids overflow
            
            if (arr[mid] == k) 
                return mid; // If k is found, return its index
            
            else if (arr[mid] > k) 
                right = mid - 1; // Search in the left half
            
            else { 
                largestNumberIndex = mid; // Update floor index
                left = mid + 1; // Search in the right half
            }
        }
        
        return largestNumberIndex; // Return the floor index
    }
};

int main() {
    int t;
    cin >> t; // Number of test cases
    cin.ignore(); // Ignore the newline after reading t
    
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line of input
        
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number); // Store numbers in the array
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after reading k
        
        Solution ob;
        int ans = ob.findFloor(arr, k);
        cout << ans << endl; // Output the result
    }
    
    return 0;
}
