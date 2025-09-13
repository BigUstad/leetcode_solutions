class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        if (candidates.size() == 1) {
            if (target == candidates[0]) {
                return {{candidates[0]}};
            }
            return {};
        }
        std::vector<std::vector<int>> result;
        std::sort(candidates.begin(), candidates.end());
        // Special case
        /* if (specialCase1(candidates, target, result)) {
            return result;
        } */
        backtrack(candidates, target, 0, {}, result);
        prepResult(result);
        return result;
    }
private:
    void prepResult(std::vector<std::vector<int>>& result) {
        auto vector_hasher = [](const std::vector<int>& vec) {
            size_t vec_size = vec.size();
            std::hash<std::string> hasher;
            std::string s;
            for (int i : vec) {
                s.append(std::to_string(i));
                s.append(",");
            }
            std::size_t hashValue = hasher(s);
            return hashValue;
        };

        // Define a custom equality comparison function for std::vector<int> using a lambda
        auto vector_equal = [](const std::vector<int>& lhs, const std::vector<int>& rhs) {
            return lhs == rhs; // std::vector already has operator== defined
        };
        std::unordered_set<std::vector<int>, decltype(vector_hasher), decltype(vector_equal)> result_set;
        for (auto& r: result) {
            result_set.insert(r);
        }
        result.clear();
        std::copy(result_set.begin(), result_set.end(), std::back_inserter(result));
    }

    void backtrack(std::vector<int>& candidates, int need, int index, std::vector<int> cur, std::vector<std::vector<int>>& result) {
        if (need <= 0) {
            if (!need) {
                result.push_back(cur);
            }
            return;
        }
        // std::cout << cur.size() << std::endl;
        for (int i = index; i < candidates.size(); ++i) {
            // not adding duplicates?
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            cur.push_back(candidates[i]);
            backtrack(candidates, (need - candidates[i]), i + 1, cur, result);
            cur.pop_back();
        }
    }
};
