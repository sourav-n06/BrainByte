class Solution {
    void DFS(vector<vector<int>>& isConnected, vector<int>& visit, int node) {
        visit[node] = 1;

        for (int j = 0; j < isConnected.size(); j++) {
            if (!visit[j] && isConnected[node][j] == 1) {
                DFS(isConnected, visit, j);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int N = isConnected.size();
        vector<int> visit(N, 0);
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            if (!visit[i]) {
                DFS(isConnected, visit, i);
                cnt++;
            }
        }
        
        return cnt;
    }
};
