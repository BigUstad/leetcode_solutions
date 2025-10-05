class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0, min = INT_MAX;
        if (prices.empty()) return m;
        for (auto& p: prices) {
            if (p < min) {
                min = p;
                continue;
            }
            if ((p - min) > m) {
                m = p - min;
            }
        }
        return m;
    }
};
