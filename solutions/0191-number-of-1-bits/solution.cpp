class Solution {
public:
    int hammingWeight(int n) {
        int check = 1;
        int count = 0;
        while (n) {
            if (n & check) {
                ++count;
            }
            n >>= check;
        }
        return count;
    }
};
