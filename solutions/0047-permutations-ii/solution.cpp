class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (!nums.size()) return {nums};
        if (nums.size() == 1) {
            return {{nums[0]}};
        }
        std::vector<std::vector<int>> v_ret;
        for (int i = 0; i < nums.size(); ++i) {
            backtrack(nums, {i}, v_ret);
        }
        std::vector<std::vector<int>> result;
        for (auto& v: v_ret) {
            if (canAdd(v)) {
                result.push_back(v);
            }
        }
        return result;

    }
private:
    std::unordered_set<std::string> us;
    std::string vectorHashString(std::vector<int>& vec) {
        std::string s;
        for (int i : vec) {
            s.append(std::to_string(i));
            s.append(",");
        }
        return s;
    }
    bool canAdd(std::vector<int>& v_cur) {
        auto p = us.insert(vectorHashString(v_cur));
        return p.second;
    }
    void backtrack(std::vector<int>& nums, std::vector<int> cur_indices, std::vector<std::vector<int>>& result) {
        // index is the item to skip as it was last inserted.
        //std::cout << "size: " << cur_indices.size() << std::endl;
        if (cur_indices.size() == nums.size()) {
            std::vector<int> cur;
            for (int& i: cur_indices) {
                cur.push_back(nums[i]);
            }
            result.push_back(cur);
            return;
        }
        for (int i = 0; i < nums.size() ; ++i) {
            bool found = false;
            for (int& c: cur_indices) {
                // Insert the one that isn't there.
                if (i == c) {
                    found = true;
                    break;
                }
            }
            if (!found && cur_indices.size() < nums.size()) {
                cur_indices.push_back(i);
                backtrack(nums, cur_indices, result);
                cur_indices.pop_back(); // Is this required? Yes
            }
        }
        
    }
};
