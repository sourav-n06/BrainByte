class Solution {
public:
    long long putMarbles(vector<int>& w, int k) {
        if(w.size()==k || k==1)return 0;
        int n=w.size();
        vector<int>vec;
        for(int i=0;i<n-1;i++){
            vec.push_back(w[i]+w[i+1]);
        }
        long long mini=0,maxi=0;
        sort(vec.begin(),vec.end());
        for(int i=0;i<k-1;i++){
            mini+=vec[i];
            maxi+=vec[n-2-i];
        }
return maxi-mini;
    }
};