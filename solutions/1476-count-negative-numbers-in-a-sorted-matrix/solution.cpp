class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        // single row array
        if (grid.size() == 1) {
            int col = findFirstHorizontal(grid, 0, 0);
            // Count this col & after
            return ((col >= 0)? (grid[0].size() - col) : 0);
        }
        int i_x = 0, i_y = 0;
        int last_x = (grid.size() - 1), last_y = (grid[0].size() - 1);
        int count = 0;
        while (i_x <= last_x && i_y <= last_y) {
            int f_y = findFirstHorizontal(grid, i_x, i_y);
            if (f_y >= 0) {
                // std::cout << "f_y: " << f_y << " adding: " << (last_y - f_y + 1) << std::endl;
                count += last_y - f_y + 1;
            }
            // element grid[i_x][i_y] has already been considered
            int f_x = findFirstVertical(grid, i_x + 1, i_y);
            if (f_x >= 0) {
                // std::cout << "f_x: " << f_x << " adding: " << (last_x - f_x + 1) << std::endl;
                count += last_x - f_x + 1;
            }
            // std::cout << "count at [" << i_x << "," << i_y << "] = " << count << std::endl;
            ++i_x; ++i_y;
        }
        return count;
    }
private:
    // Vertical search. Get index for first negative number in vertical search
    int findFirstVertical(vector<vector<int>>& grid, int row, int col) {
        int high_x = (grid.size() - 1), high_y = (grid[0].size() - 1);
        int last_x = (grid.size() - 1), last_y = (grid[0].size() - 1);
        if (row <= last_x && grid[row][col] < 0) {
            return row;
        }
        // The element at grid[row][col] has already been 'counted' in searchHorizontal
        int low_x = row, low_y = col;
        while (low_x <= high_x) {
            int mid_x = low_x + ((high_x - low_x) / 2);
            bool is_beg = (mid_x == 0 && grid[mid_x][col] < 0);
            bool is_mid = (mid_x > 0 &&
                grid[mid_x][col] < 0 && grid[mid_x - 1][col] >= 0);
            // std::cout << "mid_x: " << mid_x << ", ele: " << grid[mid_x][col] << std::endl;
            if (is_beg || is_mid) {
                return mid_x;
            } else if(grid[mid_x][col] >= 0) {
                low_x = mid_x + 1;
            } else {
                high_x = mid_x - 1;
            }
        }
        return -1;
    }
    // Horizontal search. Get index for first negative number in horizontal search
    int findFirstHorizontal(vector<vector<int>>& grid, int row, int col) {
        if (grid[row][col] < 0) {
            return col;
        }
        int low_x = row, low_y = col;
        int high_x = (grid.size() - 1), high_y = (grid[0].size() - 1);
        int last_x = (grid.size() - 1), last_y = (grid[0].size() - 1);
        while (low_y <= high_y) {
            int mid_y = low_y + ((high_y - low_y) / 2);
            // std::cout << "mid_y: " << mid_y << ", ele: " << grid[row][mid_y] << std::endl;
            bool is_mid = (mid_y > 0 &&
                grid[row][mid_y] < 0 && grid[row][mid_y - 1] >= 0);
            bool is_beg = (mid_y == 0 && grid[row][mid_y] < 0);
            if (is_mid || is_beg) {
                return mid_y;
            } else if(grid[row][mid_y] >= 0) {
                low_y = mid_y + 1;
            } else {
                high_y = mid_y - 1;
            }
        }
        return -1;
    }
};
