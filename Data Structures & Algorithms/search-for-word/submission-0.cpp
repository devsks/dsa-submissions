class Solution {
   public:
    bool dfsMatch(vector<vector<char>>& board, int i, int j, string word, int n, int m,
                  vector<vector<bool>>& visited, int ind) {
        if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || ind >= word.size() ||
            word[ind] != board[i][j])
            return false;

        if (ind + 1 == word.size()) return true;
        vector<vector<int>> dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        visited[i][j] = true;
        bool answer = false;

        for (auto dir : dirs) {
            int ni = i + dir[0], nj = j + dir[1];
            if (dfsMatch(board, ni, nj, word, n, m, visited, ind + 1)) {
                answer = true;
                break;
            }
        }
        visited[i][j] = false;
        return answer;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == word[0]) {
                    bool match = dfsMatch(board, i, j, word, n, m, visited, 0);
                    if (match) return true;
                }
            }
        }
        return false;
    }
};
