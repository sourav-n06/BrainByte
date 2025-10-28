class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
         int n = str.size();
    sort(str.begin(), str.end());

    string first = str[0];
    string last = str[n - 1];

    string res;

    for (int i = 0; i < min(first.size(), last.size()); i++)
    {
        if (first[i] == last[i])
        {
            res += first[i];
        }
        else
            break;
    }

    return res;
    }
};

