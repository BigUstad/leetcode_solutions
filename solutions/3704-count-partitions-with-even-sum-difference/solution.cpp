class Solution {
public:
    int countPartitions(vector<int>& nums) {
        // std::vector<int> prefix_sum;
        int partition_count = 0;
        std::vector<int> suffix_sum(nums);
        for (int index = (nums.size() - 2); index >= 0 ; --index) {
            suffix_sum[index] = nums[index] + suffix_sum[index + 1];
        }
        for (int index = 1; index < nums.size(); ++index) {
            nums[index] = nums[index - 1] + nums[index];
        }
        int i = (nums.size() - 1) / 2, j = i + 2;
        while (i >= 0) {
            int diff = std::abs(nums[i] - suffix_sum[i + 1]);
            // std::cout << i << ". pre: " << nums[i] << ", suf: " << suffix_sum[i + 1] << std::endl;
            if (!(diff % 2)) {
                ++partition_count;
            }
            --i;
        }
        // std::cout << "========" << std::endl;
        while (j < nums.size()) {
            int diff = std::abs(nums[j - 1] - suffix_sum[j]);
            // std::cout << j << ". pre: " << nums[j - 1] << ", suf: " << suffix_sum[j] << std::endl;
            if (!(diff % 2)) {
                ++partition_count;
            }
            ++j;
        }
        return partition_count;
    }
};
