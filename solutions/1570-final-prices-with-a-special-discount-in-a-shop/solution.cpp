class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        std::vector<int> discount_prices(prices);
        std::stack<int> p_stack;
        int index = 0;
        for (auto& p: prices) {
            while(!p_stack.empty() && discount_prices[index] <= discount_prices[p_stack.top()]) {
                discount_prices[p_stack.top()] = prices[p_stack.top()] - prices[index];
                p_stack.pop();
            }
            p_stack.push(index++);
        }
        return discount_prices;
    }
};
