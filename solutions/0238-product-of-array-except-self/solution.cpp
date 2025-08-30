class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> prefix_product(nums.size(), 1);
        std::vector<int> suffix_product(nums.size(), 1);
        // Instead of adding prev.
        // Multiply prefix but current is 1.
        
        for (int index = 0; index < nums.size(); ++index) {
            if (index == 0) {
                prefix_product[index] = 1;
                continue;
            }
            prefix_product[index] = prefix_product[index - 1] * nums[index - 1];
        }
        suffix_product[nums.size() - 1] = 1;
        for (int index = (nums.size() - 2); index >= 0 ; --index) {
            suffix_product[index] = suffix_product[index + 1] * nums[index + 1];
        }
        for (int index = 0; index < nums.size(); ++index) {
            prefix_product[index] *= suffix_product[index];
        }
        return prefix_product;
    }
};
