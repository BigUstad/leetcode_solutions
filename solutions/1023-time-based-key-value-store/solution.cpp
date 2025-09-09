class TimeMap {
public:
    typedef std::pair<int, std::string> ValuePair;
    TimeMap() {
        //TODO: What goes here?
    }
    
    void set(string key, string value, int timestamp) {
        auto kv_itr = kv_store.find(key);
        if (kv_itr != kv_store.end()) {
            kv_itr->second.push_back({timestamp, value});
            return;
        }
        kv_store[key] = {{timestamp,value}};
    }
    
    string get(string key, int timestamp) {
        if (kv_store.empty()) {
            return "";
        }
        // TODO: Binary search for the closest value
        auto kv_itr = kv_store.find(key);
        if (kv_itr == kv_store.end() || kv_itr->second.size() == 0) {
            return "";
        }
        std::vector<std::pair<int, std::string>>& v_kv = kv_itr->second;
        size_t low = 0, high = v_kv.size();
        if (timestamp < v_kv[low].first) {
            return "";
        }
        while (low <= high) {
            size_t mid = low + ((high - low) / 2);
            bool eq = (v_kv[mid].first == timestamp);
            if (eq) {
                return v_kv[mid].second;
            }
            if (v_kv[mid].first > timestamp) {
                high = mid - 1;
            } else if (v_kv[mid].first < timestamp) {
                bool le_next_gt = (mid < (v_kv.size() - 1) &&
                    v_kv[mid].first <= timestamp && v_kv[mid + 1].first > timestamp);
                bool le_last = (mid == (v_kv.size() - 1) && v_kv[mid].first <= timestamp);
                if (le_last || le_next_gt) {
                    return v_kv[mid].second;
                }
                low = mid + 1;
            }
        }
        return v_kv[(v_kv.size() - 1)].second;
    }
private:
    std::unordered_map<std::string, std::vector<ValuePair>> kv_store;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
