class Solution {
public:
    int pivotInteger(int n) {
        if (n <= 1) {
            return 1;
        }
        int low = 1, high = n;
        int low_sum = 1; int high_sum = ((n * (n + 1)) / 2);
        while (low <= high) {
            int mid = low + ((high - low) / 2);
            int left_sum = (mid * (mid + 1)) / 2;
            int right_sum = (high_sum - left_sum) + mid;
            // std::cout << mid << ". " << left_sum << " <-> " << right_sum << std::endl;
            if (left_sum < right_sum) {
                low = mid + 1;
            } else if (left_sum > right_sum) {
                high = mid - 1;
            } else {
                return mid;
            }
        }
        return -1;
    }
};
