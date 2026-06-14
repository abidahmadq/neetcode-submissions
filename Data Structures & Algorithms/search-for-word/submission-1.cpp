class Solution {
public:
    int n, m;
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();

        for(int r = 0; r < n; r++) {
            for(int c=0; c < m; c++) {
                if(board[r][c] == word[0] && dfs(board, word, r, c, 0)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        if(i == word.size()) {
            return true;
        }

        if(r < 0 || c < 0 || r >= n || c >= m) {
            return false;
        }

        if(board[r][c] != word[i] || board[r][c] == '#') {
            return false;
        }
        board[r][c] = '#';
        bool res = dfs(board, word, r+1, c, i+1) || dfs(board, word, r-1, c, i+1) || dfs(board, word, r, c+1, i+1) || dfs(board, word, r, c-1, i+1);
        board[r][c] = word[i];
        return res;
    }
};
