class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return 0;
        int pair_count = 0, last = INT_MAX;
        std::sort(nums.begin(), nums.end());
        last = nums[(nums.size() - 1)];
        for (auto num_itr = nums.begin();
             num_itr != nums.end();
             ++num_itr) {
            auto next_itr = (num_itr + 1);
            int t = (target - *num_itr) - 1;
            if (next_itr == nums.end() ||
                t < *num_itr) {
                break;
            }
            auto itr = std::upper_bound(next_itr, nums.end(), t);
            pair_count += (itr - next_itr);
        }
        return pair_count;
    }
};
