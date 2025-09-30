class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int last = nums[nums.size() - 1];
        for (int i = 1; i <= last; ++i) {
            auto e_p = std::equal_range(nums.begin(), nums.end(), i);
            auto g_itr = std::upper_bound(nums.begin(), nums.end(), i);
            int e_count = (e_p.first == nums.end() && e_p.second == nums.end()) ? 0 : (e_p.second - e_p.first);
            int count = (nums.end() - g_itr) + e_count;
            // std::cout << i << ". " << count << ". e: " << e_count << std::endl;
            if (count == i) {
                return i;
            }
        }
        return -1;
    }
};
