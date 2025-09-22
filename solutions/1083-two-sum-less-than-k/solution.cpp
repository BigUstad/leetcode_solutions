class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int last_index = (nums.size() - 1);
        if (last_index <= 0) {
            return - 1;
        }
        if (last_index == 1) {
            int l_sum = nums[0] + nums[1];
            if (l_sum < k) {
                return l_sum;
            }
            return -1;
        }
        std::sort(nums.begin(), nums.end());
        /* std::cout << "Sorted nums: ";
        for (auto& n: nums) {
            std::cout << "  " << n;
        }
        std::cout << std::endl; */
        // Special case - all elements equal.
        if (nums[0] == nums[last_index]) {
            int l_sum = (nums[0] + nums[last_index]);
            if (l_sum < k) {
                return l_sum;
            }
            return -1;
        }
        int cur_max = -1;
        for (int i = 0; i <= last_index; ++i) {
            int target_max = (k - nums[i]);
            // std::cout << nums[i] << ", " << target_max << std::endl;
            int target = binarySearch(nums, target_max);
            // std::cout << nums[i] << ", expected: " << target_max << " got: " << target << std::endl;
            if (target && target != nums[i] &&
                (target + nums[i]) > cur_max) {
                cur_max = (target + nums[i]);
                /* std::cout << "cur_max: " << cur_max <<
                    ". i: " << nums[i] << ", j: " << target << "." << std::endl; */
            }
        }
        return cur_max;
    }
private:
    int binarySearch(std::vector<int>& nums, int& target_max) {
        int low = 0, high = (nums.size() - 1);
        int max_index = (nums.size() - 1);
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            bool mid_max = (mid < max_index &&
                nums[mid] < target_max && nums[mid + 1] >= target_max);
            bool last_max = (mid == max_index &&
                nums[mid] <= target_max);
            if (mid_max || last_max) {
                /* std::cout << mid << ". ele: " << nums[mid] << ", next_ele: "
                      << ((mid < max_index)?nums[mid + 1]: -1) << std::endl; */
                return nums[mid];
            }
            if (nums[mid] < target_max) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return 0;
    }
};
