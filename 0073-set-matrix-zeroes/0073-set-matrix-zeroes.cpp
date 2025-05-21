class Solution {
    void makeZero(int i, int j, vector<vector<int>>& mat) {
        int row = mat.size(); int col = mat[0].size();
        for(int a = 0; a < row; a++) mat[a][j] = 0;
        for(int a = 0; a < col; a++) mat[i][a] = 0;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        queue<pair<int, int>> track;

        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++)
                if(matrix[i][j] == 0) track.push({i, j});
        }

        while (!track.empty()) {
            auto ele = track.front();
            track.pop();
            int i = ele.first;
            int j = ele.second;
            makeZero(i, j, matrix);
        }
    }
};