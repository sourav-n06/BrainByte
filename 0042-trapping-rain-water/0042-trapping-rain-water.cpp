class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;

        int left = 0, right = n - 1;
        int leftbar = 0, rightbar = 0;
        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                leftbar = max(leftbar, height[left]);
                water += leftbar - height[left];
                left++;
            } else {
                rightbar = max(rightbar, height[right]);
                water += rightbar - height[right];
                right--;
            }
        }

        return water;
    }
};

/*
TC O(N) , SC O(N)
class Solution {
public:
    int trap(vector<int>& height) {

        int water = 0;
        int n = height.size();

        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        lmax[0] = height[0];
        for(int i = 1; i < n; i++) {
            lmax[i] = max(lmax[i-1], height[i]);
        }
            
        rmax[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            rmax[i] = max(rmax[i+1], height[i]);
        }

        for(int i = 0; i < n; i++) {
            water += min(lmax[i], rmax[i]) - height[i];
        }

        return water;

    }
};

*/