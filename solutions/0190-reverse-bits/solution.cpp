class Solution {
public:
    int reverseBits(int n) {
        uint32_t reversed = 0;
        uint32_t times = 31;
        int one = 1, zero = 0;
        while (n) {
            if (n & one) {
                reversed += (one << times);
            } else {
                reversed += (zero << times);
            }
            n >>= one;
            --times;
            // std::cout << n  << ", " << reversed << std::endl;
        }
        return reversed;
    }
};
