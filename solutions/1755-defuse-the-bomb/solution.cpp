class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int s = code.size();
        // std::cout << "s: " << s << std::endl;
        bool next = (k > 0);
        std::vector<int> v_ret(s, 0);
        // Special case
        if (!k) {
            return v_ret;
        }
        int s_start = 1, s_end = k, sum = 0;
        if (!next) {
            s_start = s - std::abs(k);
            s_end = s - 1;
        }
        // First sum
        int i = s_start;
        for (; i <= s_end; ++i) sum += code[i];
        for (i = 0; i < s; ++i) {
            v_ret[i] = sum;
            sum -= code[s_start % s];
            ++s_end;
            sum += code [s_end % s];
            ++s_start;
        }
        return v_ret;
    }
};
