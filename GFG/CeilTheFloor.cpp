#include <bits/stdc++.h>
using namespace std;

int getCeil(vector<int>& arr, int left, int right, int x) {
    int ceil = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return arr[mid]; 
        else if (arr[mid] > x) {
            ceil = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ceil;
}

int getFloor(vector<int>& arr, int left, int right, int x) {
    int floor = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return arr[mid]; 
        else if (arr[mid] < x) {
            floor = arr[mid];
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return floor;
}

class Solution {
public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        sort(arr.begin(), arr.end());
        int left = 0, right = arr.size() - 1;

        int ceil = getCeil(arr, left, right, x);
        int floor = getFloor(arr, left, right, x);

        return {floor, ceil};  // ✅ Fixed: Correct syntax for vector return
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); 
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); 
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.getFloorAndCeil(x, arr);  // ✅ Fixed: Explicit type instead of 'auto'
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
