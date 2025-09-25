class Solution {
public:
    bool isPerfectSquare(int num) {
        double f_num (num);
        double low_x = 1, high_x = INT_MAX;
        while (low_x <= high_x) {
            double mid_x = low_x + ((high_x - low_x) / 2);
            double prod_x = (mid_x * mid_x);
            if (prod_x == f_num) {
                return true;
            }
            if (prod_x < f_num) {
                low_x = mid_x + 1;
            } else {
                high_x = mid_x - 1;
            }

        }
        return false;
    }
};
