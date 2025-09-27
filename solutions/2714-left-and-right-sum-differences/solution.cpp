class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        std::vector<int> ans(nums);
        for (int index = (nums.size() - 2); index >= 0 ; --index) {
            // std::cout << "  " << (nums[index] + nums_suffix_sum[index + 1]);
            ans[index] = nums[index] + ans[index + 1];
        }
        for (int index = 0; index < nums.size(); ++index) {
            // std::cout << "  " << (nums_prefix_sum[index - 1] + nums[index]);
            if (index) {
                nums[index] = nums[index - 1] + nums[index];
            }
            ans[index] = std::abs(nums[index] - ans[index]);
        }
        return ans;
    }
};
