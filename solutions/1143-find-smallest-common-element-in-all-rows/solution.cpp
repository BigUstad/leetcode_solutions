class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        if (mat.empty()) return -1;
        if (mat.size() == 1) {
            return mat[0][1];
        }
        int last_row = (mat.size() - 1); 
        for (int i = 0; i < mat[0].size(); ++i) {
            int ele = mat[0][i];
            int j = 1;
            while (j <= last_row) {
                if (!std::binary_search(mat[j].begin(), mat[j].end(), ele)) {
                    // Next element.
                    break;
                }
                ++j;
            }
            if (j > last_row) {
                // Found in all rows.
                return ele;
            }
        }
        return -1;
    }
};
