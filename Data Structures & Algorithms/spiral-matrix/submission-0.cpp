class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> seq;
        seq.reserve(n * m);
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<vector<bool>> visited(n, vector<bool>(m));
        int i = 0, j = 0, d = 0;
        while (i >= 0 && j >= 0 && i < n && j < m && !visited[i][j]) {
            seq.push_back(matrix[i][j]);
            visited[i][j] = true;
            int nxt_i = i + dirs[d][0];
            int nxt_j = j + dirs[d][1];
            if (nxt_i < 0 || nxt_j < 0 || nxt_i >= n || nxt_j >= m || visited[nxt_i][nxt_j]) {
                ++d;
                d%=4;
                nxt_i = i + dirs[d][0];
                nxt_j = j + dirs[d][1];
            }
            i = nxt_i;
            j = nxt_j;
        }
        return seq;
    }
};
