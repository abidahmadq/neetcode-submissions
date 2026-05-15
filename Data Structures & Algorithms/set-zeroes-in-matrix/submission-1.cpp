class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> locs;
        for(int i=0; i < matrix.size(); i++) {
            for(int j=0; j < matrix[i].size(); j++) {
                if(matrix[i][j] == 0) {
                    locs.push_back({i, j});
                }
            }
        }
        cout << "Here1";
        for(auto &l: locs) {
            cout << l.first << " " << l.second << endl;
            setter(matrix, l.first, l.second);
        }
    }
    void setter(vector<vector<int>>& matrix, int row, int col) {
        int rows = matrix.size();
        int cols = matrix[row].size();
        for(int j = 0; j < cols; j++) {
            matrix[row][j] = 0;
        }

        for(int i = 0; i < rows; i++) {
            matrix[i][col] = 0;
        }
    }
};
