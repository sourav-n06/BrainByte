class Solution {
public:
    int totalMoney(int n) {
        int term = n/7;  
        int first = 28;   //First Term of AP
        int last = first + (term - 1) * 7;   // Last Term Of AP
        int result = term * (first + last) / 2; // Sn(sum) for AP

        if(n % 7)
        {
            int extraMoney = term + 1;
            for(int i = 0; i < (n % 7); i++)
            {
                result += extraMoney;
                extraMoney++;
            }
        }
        return result;
    }
};