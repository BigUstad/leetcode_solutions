class Solution {
public:
    int arrangeCoins(int n) {
        int low = 0, high = n;
        long n_l (n);
        while (low <= high) {
            long mid = low + ((high - low) / 2);
            long mid_val = (mid * (mid + 1)) / 2;
            // std::cout << mid_val << ", "  << mid << std::endl;
            if (mid_val == n_l) return (int) mid;
            if (n_l < mid_val) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        // std::cout << high << std::endl;
        return high;
    }
};
