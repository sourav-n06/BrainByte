class Solution {
    bool canEatAllBanana(vector<int>& piles, int mid, int h) {
        int speed = 0;
        for(int p : piles) {
            speed += ceil((double)p / mid);
            if(speed > h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int speed = 0;
        int left = 1;
        int right = 0;
        for(int p : piles) right = max(p, right);

        while(left <= right) {
            int mid = (left + right) / 2;
            if(canEatAllBanana(piles, mid, h)) {
                speed = mid;
                right = mid - 1;
            } else 
                left = mid + 1;
        }

        return speed;
    }
};