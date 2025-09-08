class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() <= 0) return -1;
        if (nums.size() == 1) return (nums[0] == target)? 0 : -1;
        if (nums.size() == 2) {
            if (nums[0] != target && nums[1] != target) {
                return -1;
            }
            if (nums[0] == target) {
                return 0;
            } else {
                return 1;
            }
        }
        int min_index = findMinIndex(nums);
        int max_index, num_rotations;
        if (min_index > 0 && min_index < nums.size()) {
            max_index = min_index - 1;
            num_rotations = min_index;
        } else {
            max_index = (nums.size() - 1);
            // Well, nums.size() rotations has the same effect of 0
            num_rotations = 0;
        }
        // std::cout << "target: " << target << ", num_rotations: " << num_rotations << std::endl;
        // low & high assigned accordingly
        int low = 0, high = (nums.size() - 1);
        int mid;
        int l_ret = -1;
        int loop_count = 1;
        while (loop_count == 1 || low <= high) {
            // Actual mid
            if (loop_count == 1 && num_rotations > 0) {
                // mid = low + ((high - low) / 2) - num_rotations ;
                // No need to calculate mid, I guess
                // Just need to get the currect range.
                // min_index - nums.size() - 1 OR
                // 0 - max_index
                if (nums[0] > target) {
                    low = min_index;
                    high = nums.size() - 1;
                } else {
                    low = 0;
                    high = max_index;
                }
            }
            mid = low + ((high - low) / 2);
            // std::cout << "mid: " << mid << std::endl;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
            // std::cout << __LINE__ <<  " 2. low: " << low << ", high: " << high << std::endl;
            ++loop_count;
        }
        if (low == high && nums[low] == target) {
            l_ret = low;
        } else if (low > high) {
            l_ret = -1;
        }
        return l_ret;
    }
private:
    int findMinIndex(vector<int>& nums) {
        if (nums.size() <= 0) return INT_MIN;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return (std::min(nums[0], nums[1]) == nums[0])? 0 : 1;
        int mid, low = 0, high = (nums.size() - 1);
        while (low < high) {
            mid = low + ((high - low) / 2);
            if (mid == 0) {
                // We can't deal with this case
                // Because it is likely that the number of rotations is equal to length
                break;
            }
            // Breaking condition for the inflection point
            // std::cout << "mid: " << mid << ", low: " << low << ", high: " << high << std::endl;
            if (nums[mid] < nums[mid - 1] &&
                nums[mid] < nums[mid + 1]) {
                return mid;
            }
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return (std::min(nums[low], nums[high]) == nums[low])? low : high;
    }
};
