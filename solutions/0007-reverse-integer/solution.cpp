class Solution {
public:
    int reverse(int x) {
        if (!x) return x;
        bool is_neg = (x < 0);
        if (is_neg && x == INT_MIN) {
            return 0;
        }
        if (!is_neg && x == INT_MAX) {
            return 0;
        }
        if (is_neg) x = std::abs(x);
        unsigned int y = 0;
        while (x) {
            int rem = (x % 10);
            x = (x / 10);
            if (y > (INT_MAX / 10)) {
                // std::cout << "** x: " << x << ", y: " << y << ", rem: " << rem << std::endl;
                return 0;
            }
            y = rem + ( y * 10 ) ;
            // std::cout << "x: " << x << ", y: " << y << ", rem: " << rem << std::endl;
        }
        y += x;
        return (is_neg)? (0 - y) : y;
    }
};
