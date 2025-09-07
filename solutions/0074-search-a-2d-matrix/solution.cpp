class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low_x = 0, low_y = 0;
        size_t size_x = (matrix.size() - 1), size_y = (matrix[0].size() - 1); // highest indices
        int high_x = (matrix.size() - 1), high_y = (matrix[0].size() - 1);
        bool found = false, found_row = false;
        int mid_x, mid_y;
        while (!found && low_y <= high_y) {
            mid_y = low_y + ((high_y - low_y) / 2);
            while (!found_row && low_x <= high_x) {
                mid_x = low_x + ((high_x - low_x) / 2);
                if (matrix[mid_x][mid_y] == target) {
                    found_row = true; found = true;
                    break;
                }
                if (matrix[mid_x][0] <= target && matrix[mid_x][size_y] >= target) {
                    // Continue rest of the search below
                    found_row = true;
                    /* std::cout << "i. Found row: " << "[" << mid_x << "," << "0] & [" << mid_x << ", " << size_y << "]" << std::endl;  */
                    break;
                }
                if (matrix[mid_x][0] > target) {
                    high_x = mid_x - 1;
                } else if (matrix[mid_x][size_y] < target) {
                    low_x = mid_x  + 1;
                } else if (matrix[mid_x][0] == target || matrix[mid_x][size_y] == target) {
                    found = true;
                    found_row = true;
                    break;
                }
                /* std::cout << "i. Comparing: " << target << " <> [" << mid_x << "," << mid_y << "]" << std::endl;
                std::cout << "i. Comparing: " << target << " <> " <<  matrix[mid_x][mid_y] << std::endl;
                std::cout << "i. Searching: [" << low_x << "," << low_y << "][" << high_x << "," << high_y << "]" << std::endl; */
            }
            if (matrix[mid_x][mid_y] == target) {
                found = true;
                break;
            }
            if (matrix[mid_x][mid_y] > target) {
                high_y = mid_y - 1;
            } else {
                low_y = mid_y  + 1;
            }
            /* std::cout << "ii. Comparing: " << target << " <> [" << mid_x << "," << mid_y << "]" << std::endl;
            std::cout << "ii. Comparing: " << target << " <> " <<  matrix[mid_x][mid_y] << std::endl;
            std::cout << "ii. Searching: [" << low_x << "," << low_y << "][" << high_x << "," << high_y << "]" << std::endl; */
        }
        return found;
    }
};
