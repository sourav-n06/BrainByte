class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // --- Lower-left diagonals (including main diagonal), sort descending ---
        for (int k = n - 2; k >= 0; k--) {
            int i = k, j = 0;
            vector<int> diag;
            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }
            sort(diag.begin(), diag.end(), greater<int>()); // descending
            i = k, j = 0;
            for (int x : diag) {
                grid[i][j] = x;
                i++; j++;
            }
        }

        // --- Top-right diagonals (excluding main diagonal), sort ascending ---
        for (int k = 1; k < n - 1; k++) {
            int i = 0, j = k;
            vector<int> diag;
            while (i < n && j < n) {
                diag.push_back(grid[i][j]);
                i++; j++;
            }
            sort(diag.begin(), diag.end()); // ascending
            i = 0, j = k;
            for (int x : diag) {
                grid[i][j] = x;
                i++; j++;
            }
        }

        return grid;
    }
};
