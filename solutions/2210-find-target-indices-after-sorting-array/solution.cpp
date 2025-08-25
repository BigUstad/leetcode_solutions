class Solution {
public:
    std::vector<int> performBinarySearch(std::vector<int>& nums, int& target) {
        std::vector<int> v_ret;
        int low = 0, high = (nums.size() - 1), mid;
        while (low <= high) {
            mid = low + ((high - low) / 2);
            if (mid && nums[mid] == target) {
                //std::cout << "A. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
                break;
            }
            if (nums[mid] < target) {
                // std::cout << "F. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
                low = mid + 1;
            } else {
                // std::cout << "f. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
                high = mid - 1;
            }
        }
        // std::cout << "o1. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
        while (mid && nums[mid - 1] == target) {
            --mid;
        }
        // std::cout << "o2. low: " << low << ", mid: " << mid << ", high: " << high << std::endl;
        while (mid < nums.size() && nums[mid] == target) {
            v_ret.push_back(mid);
            ++mid;
        }
        return v_ret;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        std::vector<int> v_ret;
        if (nums.size() == 0) {
            return v_ret;
        }
        if (nums.size() == 1) {
            if (target == nums[0]) {
                return {0};
            }
            return v_ret;
        }
        std::sort(nums.begin(), nums.end());
        if (nums.size() == 2) {
            int index = 0;
            while (nums[index] == target) {
                v_ret.push_back(index);
                ++index;
            }
            return v_ret;
        }

        return performBinarySearch(nums, target);
    }
};
