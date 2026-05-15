class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i=0; i < grid.size(); i++) {
            for(int j=0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    count++;
                    numIslandsH(grid, i, j);
                }
            }
        }
        return count;
    }
    void numIslandsH(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 || i >= grid.size()) return;
        if(j < 0 || j >= grid[i].size()) return;
        if(grid[i][j] == '0') return;

        grid[i][j] = '0';
        numIslandsH(grid, i+1, j);
        numIslandsH(grid, i, j+1);
        numIslandsH(grid, i-1, j);
        numIslandsH(grid, i, j-1);

    }
};
