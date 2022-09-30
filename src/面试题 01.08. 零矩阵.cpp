class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> zero_row, zero_col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    zero_row.insert(i);
                    zero_col.insert(j);
                }
            }
        }
        for (auto item : zero_row) {
            fill(matrix[item].begin(), matrix[item].end(), 0);
        }
        for (auto item : zero_col) {
            for (int i = 0; i < m; i++) {
                matrix[i][item] = 0;
            }
        }
    }
};