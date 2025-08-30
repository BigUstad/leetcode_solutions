class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> num_set;
        int index = 0;
        if (!nums.size()) return 0;
        if (nums.size() == 1) return 1;
        for (int& n: nums) {
            num_set.insert(n);
        }
        nums.clear();
        std::copy(num_set.begin(), num_set.end(), std::back_inserter(nums));
        int l_ret = 1, l_count = 1;
        int prev = nums[0];
        for (;index < nums.size(); ++index) {
            // std::cout << "n: " << n << ". Cond " << ((n == prev + 1)? "Yes" : "No") << std::endl;
            // Need to skip count for consecutive same elements
            if (nums[index] == prev) {
                continue;
            }
            if (nums[index] == (prev + 1)) {
                ++l_count;
                // std::cout << "cur: " << nums[index] << ". l_count: " << l_count << std::endl;
                prev = nums[index];
                continue;
            }
            // std::cout << "cur: " << nums[index] << ". l_count: " << l_count << std::endl;
            l_ret = std::max(l_count, l_ret);
            l_count = 1;
            prev = nums[index];
        }
        // In case we reached the end of the array before we could update
        // std::cout << "prev_l_count: " << prev_l_count << ", l_count: " << l_count << ", l_ret: " << l_ret << std::endl;
        if (l_count > l_ret) {
            l_ret = l_count;
            // std::cout << "prev_l_count: " << prev_l_count << ", l_ret: " << l_ret << std::endl;
        }

        return l_ret;
    }
};

