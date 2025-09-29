class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        if (garbage.empty()) return 0;
        int time_taken = 0;
        std::vector<int> prefix_sum (travel);
        int index = 0, last_m_index = -1, last_p_index = -1, last_g_index = -1;
        std::vector<int> v_m_prefix_sum(garbage.size(), 0);
        std::vector<int> v_p_prefix_sum(garbage.size(), 0);
        std::vector<int> v_g_prefix_sum(garbage.size(), 0);
        for (; index < garbage.size(); ++index) {
            int m_count = std::count(garbage[index].begin(), garbage[index].end(), 'M');
            int p_count = std::count(garbage[index].begin(), garbage[index].end(), 'P');
            int g_count = std::count(garbage[index].begin(), garbage[index].end(), 'G');
            last_m_index = (m_count)? index : last_m_index;
            last_p_index = (p_count)? index : last_p_index;
            last_g_index = (g_count)? index : last_g_index;
            if (index) {
                if (index < travel.size()) {
                    prefix_sum[index] = prefix_sum[index - 1] + travel[index];
                }
                v_m_prefix_sum[index] = v_m_prefix_sum[index - 1] + m_count;
                v_p_prefix_sum[index] = v_p_prefix_sum[index - 1] + p_count;
                v_g_prefix_sum[index] = v_g_prefix_sum[index - 1] + g_count;
            } else {
                v_m_prefix_sum[index] = m_count;
                v_p_prefix_sum[index] = p_count;
                v_g_prefix_sum[index] = g_count;
            }
        }
        if (last_m_index >= 0) {
            int m_prefix_travel = (last_m_index) ? prefix_sum[last_m_index - 1] : 0;
            time_taken += v_m_prefix_sum[last_m_index] + m_prefix_travel;
        }
        if (last_p_index >= 0) {
            int p_prefix_travel = (last_p_index) ? prefix_sum[last_p_index - 1] : 0;
            time_taken += v_p_prefix_sum[last_p_index] + p_prefix_travel;
        }
        if (last_g_index >= 0) {
            int g_prefix_travel = (last_g_index) ? prefix_sum[last_g_index - 1] : 0;
            time_taken += v_g_prefix_sum[last_g_index] + g_prefix_travel;
        }
        
        return time_taken;
    }
};
