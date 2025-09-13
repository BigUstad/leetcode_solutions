class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        if (nums.size() == 1) {
            return {{}, {nums[0]}};
        }
        std::vector<std::vector<int>> v_ret;
        backtrack(nums, v_ret, 0 , {});
        return v_ret;
    }
private:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& result, int start, std::vector<int> current) {
        if (current.size() > 1) {
            std::sort(current.begin(), current.end());
        }
        /* std::cout << "Current size(" << current.size() << "): ";
        for(int& c: current) {
            std::cout << "  " << c;
        }
        std::cout << std::endl; */
        if (canAdd(current)) {
            result.push_back(current);
        }
        for (int i = start; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            backtrack(nums, result, i + 1, current);
            current.pop_back(); // We're done with i and we are going to the next one.
        }
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
};
