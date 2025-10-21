class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(int n : nums) mp[n]++;

        for(auto m : mp) {

            int element = m.first;
            int count = m.second;

            pq.push({count, element});
            if(pq.size() > k) pq.pop();
        }
        
        vector<int> res;
        while(!pq.empty()) {
            pair<int, int> pr = pq.top();
            pq.pop();

            res.push_back(pr.second);
        }

        return res;
    }
};