class Solution {
public:
    // So, grids check up, down, left, right.
    bool islandCheck(vector<vector<char>>& grid,
        std::vector<std::vector<bool>>& check,
        int& row, int& col) {
        bool l_ret = true;
        if (!grid[row][col]) {
            std::cout << std::endl;
            return false;
        }
        check[row][col] = true;
        // Check Neighbors. The '1' at row, col has to be the one of may '1's to make it an island
        // left right
        if (col > 0) {
            if (!check[row][col - 1] && grid[row][col - 1] == '1') {
                q.push({row, col - 1});
            }
            check[row][col - 1] = true;
        }
        if (col <= (COLS - 1)) {
            if (!check[row][col + 1] && grid[row][col + 1] == '1') {
                q.push({row, col + 1});
            }
            check[row][col + 1] = true;
        }
        // up down
        if (row > 0) {
            if (!check[row - 1][col] && grid[row - 1][col] == '1') {
                q.push({row - 1, col});
            }
            check[row - 1][col] = true;
        }
        if (row <= (ROWS - 1)) {
            if (!check[row + 1][col] && grid[row + 1][col] == '1') {
                q.push({row + 1, col});
            }
            check[row + 1][col] = true;
        }
        return l_ret;
    }
    int numIslands(vector<vector<char>>& grid) {
        int num_islands = 0;
        if (grid.empty()) {
            return num_islands;
        }
        ROWS = (grid.size() - 1); COLS = (grid[0].size() - 1);
        std::vector<std::vector<bool>> check(grid.size(), std::vector<bool>(grid[0].size(), false));
        // Add the first one and break.
        for (int i = 0; i <= ROWS; ++i) {
            for (int j = 0; j <= COLS; ++j) {
                if (!check[i][j] && grid[i][j] == '1') {
                    ++num_islands;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto t = q.front();
                        // std::cout << num_islands << ". Island Check for: " << t.first << ", " << t.second;
                        // std::cout << (islandCheck(grid, check, t.first, t.second)?" Pass" : " Fail") << std::endl;
                        islandCheck(grid, check, t.first, t.second);
                        q.pop();
                    }
                }
            }
        }
        return num_islands;
    }
private:
    std::queue<std::pair<int, int>> q;
    int ROWS;
    int COLS;
};
