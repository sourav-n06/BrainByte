class Solution {
    void dfs(int m, int n, int ele, vector<int>& res) {
        res.push_back(ele);

        if (n >= 9) {
            for (int i = 0; i <= m; i++) {
                int new_ele = ele * 10 + i;
                if (new_ele <= n)
                    dfs(m, n, new_ele, res);
            }

        } else {
            for (int i = 0; i <= n; i++) {
                int new_ele = ele * 10 + i;
                if (new_ele <= n)
                    dfs(m, n, new_ele, res);
            }
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        if (n >= 9) {
            for (int i = 1; i <= 9; i++)
                dfs(9, n, i, res);
        } else {
            for (int i = 1; i <= n; i++)
                dfs(9, n, i, res);
        }

        return res;
    }
};