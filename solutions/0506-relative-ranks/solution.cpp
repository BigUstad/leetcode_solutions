class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //  Index to Score mapping
        std::vector<std::string> l_ret(score.size());
        auto comparator = [&score] (int index1, int index2) {
            return score[index1] < score[index2];
        };
        // min-heap starts with the index with lowest score;
        std::priority_queue<int, std::vector<int>, decltype(comparator)> pq(comparator);
        int index = 0;
        for (; index < score.size(); ++index) {
            pq.push(index);
        }
        index = 0;
        while(!pq.empty()) {
            auto& i = pq.top();
            switch (index) {
                case 0:
                    l_ret[i] = "Gold Medal";
                    break;
                case 1:
                    l_ret[i] = "Silver Medal";
                    break;
                case 2:
                    l_ret[i] = "Bronze Medal";
                    break;
                default:
                    l_ret[i] = std::to_string(index + 1);
                    break;
            }
            ++index;
            pq.pop();
        }
        return l_ret;
    }
};
