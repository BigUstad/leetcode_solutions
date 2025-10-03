class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) return true;
        std::vector<std::pair<int, bool>> v_mi;
        for (auto& v_i: intervals) {
            // Assumption:
            // meeting that starts at i, starts at 0th second of i.
            // meeting that ends at i, ends at 60th min of i - 1.
            v_mi.push_back({v_i[0], true});
            v_mi.push_back({v_i[1] - 1, false});
        }
        std::sort(v_mi.begin(), v_mi.end(),
            [](const std::pair<int, bool>& lhs, const std::pair<int, bool>& rhs) {
                return lhs.first < rhs.first ||
                       (lhs.first == rhs.first && lhs.second);
        });
        for (int i = 1; i < v_mi.size(); i += 2) {
            /* std::cout << "Start: " << v_mi[i - 1].first << ((v_mi[i - 1].second)?" Yes": " No") <<
                      " End: " << v_mi[i].first << ((!v_mi[i].second)?" Yes": " No") << std::endl; */
            if (!v_mi[i - 1].second || v_mi[i].second) {
                return false;
            }
        }
        return true;
    }
};
