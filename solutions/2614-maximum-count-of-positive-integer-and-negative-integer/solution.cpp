class Solution {
public:
    int maximumCount(vector<int>& nums) {
        auto u_itr = std::upper_bound(nums.begin(), nums.end(), 0);
        auto e_range = std::equal_range(nums.begin(), nums.end(), 0);
        int p_count = (nums.end() - u_itr);
        int z_count = (e_range.second - e_range.first);
        int n_count = (nums.size() - z_count - p_count);
        return std::max(p_count, n_count);
    }
};
