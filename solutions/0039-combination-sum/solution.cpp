class Solution {
public:
    void backtrack(std::vector<int>& candidates, int need, int index, std::vector<int> cur, std::vector<std::vector<int>>& result) {
        if (need <= 0) {
            if (!need) {
                result.push_back(cur);
            }
            return;
        }
        for (int i = index; i < candidates.size(); ++i) {
            cur.push_back(candidates[i]);
            backtrack(candidates, (need - candidates[i]), i, cur, result);
            cur.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> l_ret;
        if (candidates.empty()) return l_ret;
        if (candidates.size() == 1) {
            if (target == candidates[0]) {
                l_ret.push_back({candidates[0]});
            }
            return l_ret;
        }
        backtrack(candidates, target, 0, {}, l_ret);
        return l_ret;
    }
};
