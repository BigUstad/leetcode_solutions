class Solution {
public:
    vector<int> countBits(int n) {
        int i = n;
        int check = 1;
        std::vector<int> l_ret;
        while (n >= 0) {
            int count = 0;
            while (i) {
                if (i & check) {
                    ++count;
                }
                i >>= check;
            }
            // std::cout << n << ". " << count << std::endl;
            i = --n;
            l_ret.insert(l_ret.begin(), count);
        }
        return l_ret;
    }
};
