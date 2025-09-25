class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int first_index = findFirstIndex(nums, target);
        int last_index = findLastIndex(nums, target);
        if (first_index == -1 || last_index == -1) {
            // std::cout << "last_index: " << last_index << ", first_index: " << first_index << std::endl;
            return false;
        }
        // std::cout << "last_index: " << last_index << ", first_index: " << first_index << std::endl;
        return (last_index - first_index + 1) > (nums.size() / 2);
    }
private:
    int findFirstIndex(vector<int>& nums, int& target) {
        int low = 0, high = (nums.size() - 1);
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            bool is_first = (mid == 0 && nums[mid] == target);
            bool is_mid = (mid > 0 && nums[mid] == target && nums[mid - 1] != target);
            if (is_first || is_mid) {
                return mid;
            }
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    int findLastIndex(vector<int>& nums, int& target) {
        int low = 0, high = (nums.size() - 1);
        int last = (nums.size() - 1);
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            bool is_last = (mid == last && nums[mid] == target);
            bool is_mid = (mid < last && nums[mid] == target && nums[mid + 1] != target);
            if (is_last || is_mid) {
                return mid;
            }
            if (nums[mid] <= target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
};
