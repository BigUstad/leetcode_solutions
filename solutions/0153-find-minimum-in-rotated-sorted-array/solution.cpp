class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.size() <= 0) return INT_MIN;
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return std::min(nums[0], nums[1]);
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
                return nums[mid];
            }
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return std::min(nums[low], nums[high]);
    }
};
