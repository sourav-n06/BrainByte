#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        if (s.empty()) return s;

        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> maxHeap;
        for (auto& p : freq) {
            maxHeap.push({p.second, p.first});
        }

        string result;

        pair<int, char> prev = {0, '#'};

        while (!maxHeap.empty()) {
            auto [count, ch] = maxHeap.top();
            maxHeap.pop();

            result += ch;
            count--;

            if (prev.first > 0)
                maxHeap.push(prev);

            prev = {count, ch};
        }

        if (result.size() != s.size()) return "";

        return result;
    }
};
