class Solution {
public:
    // Custom hash function for std::pair
    struct PairHash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);
            return h1 ^ h2;  
        }
    };
    int countKDifference(vector<int>& nums, int k) {
        // std::unordered_set<std::pair<int, int>> v;
        std::unordered_map<int, int> m;
        std::unordered_set<std::pair<int, int>, PairHash> counted;
        // First pass
        for(auto& n: nums) {
            auto itr = m.find(n);
            if (itr != m.end()) {
                itr->second++;
            } else {
                m[n] = 1;
            }
        }
        int count = 0;
        
        // Second pass. Find unique pairs
        for(auto& it: m) {
            int find_n = it.first + k;
            auto itr = m.find(find_n);
            if (itr != m.end()) {
                int x = (it.first < itr->first)? it.first : itr->first;
                int y = (it.first > itr->first)? it.first : itr->first;
                auto p = std::make_pair(x, y);
                // Some elements could be duplicates
                if (counted.find(p) == counted.end()) {
                    count += (it.second * itr->second);
                    counted.insert(p);
                    //std::cout << "1. " << it.second << " * " << itr->second << std::endl;
                }
            }
            find_n = it.first - k;
            itr = m.find(find_n);
            if (itr != m.end()) {
                int x = (it.first < itr->first)? it.first : itr->first;
                int y = (it.first > itr->first)? it.first : itr->first;
                auto p = std::make_pair(x, y);
                // Some elements could be duplicates
                if (counted.find(p) == counted.end()) {
                    count += (it.second * itr->second);
                    counted.insert(p);
                    //std::cout << "2. " << it.second << " * " << itr->second << std::endl;
                }
            }
            //std::cout << "After " << it.first << ", count: " << count << std::endl;
        }
        return count;
    }
};
