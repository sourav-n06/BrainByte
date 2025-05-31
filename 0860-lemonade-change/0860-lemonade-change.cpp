class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        int twenty = 0;

        for(int x : bills) {
            if(x == 5) five++;
            else if(x == 10) {
                if(five) five--;
                else return false;
                ten++;
            } else {
                if(five >= 1 & ten >= 1) {
                    five--; ten--;
                } else if(five >= 3) five -= 3;
                else return false;
                twenty++;
            }
        }

        return true;
    }
};