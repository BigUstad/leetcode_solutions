class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int middle_index = -1;
        if (nums.empty()) return middle_index;
        if (nums.size() == 1) return 0;
        std::vector<int> prefix_sum(nums);
        std::vector<int> suffix_sum(nums);
        int i = 1, j = (nums.size() - 2);
        for (; i < nums.size(); ++i, --j) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
            suffix_sum[j] = suffix_sum[j + 1] + nums[j];
        }
        suffix_sum[0] = suffix_sum[1] + nums[0];
        for (i = 0; i < nums.size(); ++i) {
            int prefix_i = (prefix_sum[i] - nums[i]);
            int suffix_i = (suffix_sum[i] - nums[i]);
            if (prefix_i == suffix_i) {
                middle_index = i;
                break;
            }
        }
        return middle_index;
    }
};
