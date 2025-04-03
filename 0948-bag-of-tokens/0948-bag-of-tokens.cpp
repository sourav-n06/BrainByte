class Solution {
public:
    int bagOfTokensScore(vector<int>& token, int power) {
        sort(token.begin(), token.end());
        int i = 0;
        int j = token.size() - 1;
        int scr = 0;

        while(i < j) {
            if(power >= token[i]) {
                scr++; power -= token[i];
                i++;
            } else {
                if(scr) {
                    scr--;
                    power += token[j];
                    j--;
                }
                else break;
            }
        }

        while(i <= j && power >= token[i]) {
            i++;
            power -= token[i];
            scr++;
        }

        return scr;
    }
};