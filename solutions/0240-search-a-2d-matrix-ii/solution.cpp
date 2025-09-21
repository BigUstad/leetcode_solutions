class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        bool found = false;
        int col = FindLastColumn(matrix, target, found);
        if (found) {
            return true;
        }
        return FoundInColumns(matrix, col, target);

    }
private:
    // Find the last column where the search can be performed
    // Found is updated if the element is found in the first row itself
    int FindLastColumn(vector<vector<int>>& matrix, int target, bool& found) {
        auto& first_row = matrix[0];
        int col_count = (first_row.size() - 1);
        int low = 0, high = col_count;
        if (first_row[high] <= target) {
            if (first_row[high] == target) found = true;
            return high;
        }
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            // std::cout << "mid: " << mid << std::endl;
            if (mid > 0 &&
                first_row[mid] >= target && first_row[(mid - 1)] < target) {
                if (first_row[mid] == target) {
                    found = true;
                }
                return mid;
            }
            if (first_row[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        // Only the first column?
        return 0;
    }

    int SearchColumn(vector<vector<int>>& matrix, int col, int target) {
        int low = 0, high = (matrix.size() - 1);
        while (low <= high) {
            int mid = low + ((high - low)/2);
            if (matrix[mid][col] == target) {
                return mid;
            }
            if (matrix[mid][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    bool FoundInColumns(vector<vector<int>>& matrix, int col_threshold, int target) {
        int last_row_index = (matrix.size() - 1);
        for (int col = 0; col <= col_threshold; ++col) {
            if (matrix[last_row_index][col] < target) {
                continue;
            }
            if (int row_index = SearchColumn(matrix, col, target);
                row_index != -1) {
                return true;
            }
        }
        return false;
    }
};
