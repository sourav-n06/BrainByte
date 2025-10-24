class Solution {
private:
    long long total_time(vector<int> piles, int n)
    {
        long long total_hour = 0;
        for(int i = 0; i < piles.size(); i++)
            total_hour = total_hour + ceil((double)piles[i] / (double)n);
        return total_hour;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int left = 1;
        int right = *max_element(piles.begin(),piles.end());
        while(left <= right){
            int mid = (left + right) / 2;
            if(total_time(piles, mid) <= h) 
                right = mid - 1;
            else 
                left = mid + 1;
        }
        return left;
    }
};