class Solution {
public:
    void findFirstAndLastOccurence(vector<int>& nums, int& target, int& low, int& mid, int& high) {
        int orig_low = low, orig_high = high, orig_mid = mid;
        int ret_low = low, ret_high = high;
        if (nums[low] == target) low = 0;
        if (nums[high] == target) high = (nums.size() - 1);
        // First occurence
        while (low <= high) {
            mid = low + ((high - low) / 2);
            bool lower_inflection = nums[mid] == target &&
                        ((mid && nums[mid - 1] < target) || !mid);
            // std::cout << "1. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
            if (lower_inflection) {
                break;
            }
            if (nums[mid] >= target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        ret_low = mid;
        low = orig_low; high = orig_high; mid = orig_mid;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            bool higher_inflection = nums[mid] == target && (
                        (mid < (nums.size() - 1) && nums[mid + 1] > target) ||
                        (mid == (nums.size() - 1)));
            // std::cout << "2. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
            if (higher_inflection) {
                break;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }

        }
        ret_high = mid;
        low = ret_low; high = ret_high;
    }
    int findBSTOccurence(vector<int>& nums, int& target, int& low, int& high) {
        int mid;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = (nums.size() - 1);
        int mid = findBSTOccurence(nums, target, low, high);
        std::cout << "mid: " << mid << std::endl;
        if (mid >= 0) {
            findFirstAndLastOccurence(nums, target, low, mid, high);
        } else {
            low = -1; high = -1;
        }
        return {low, high};
    }
};
