class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int l_ret = 0, row_max = INT_MIN;
        std::vector<std::priority_queue<int>> v_pq;
        for(auto& vg: grid) {
            std::sort(vg.begin(), vg.end());
        }
        for (int n = 0; n < grid[0].size(); ++n) {
            for (int m = 0; m < grid.size(); ++m) {
                row_max = std::max(row_max, grid[m][n]);
            }
            l_ret += row_max;
        }
        return l_ret;
    }
};
