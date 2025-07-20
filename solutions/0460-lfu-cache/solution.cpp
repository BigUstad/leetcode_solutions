// Pair use_counter, list of elements with the same count
class LFUCache {
public:
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        auto itr = m_.find(key);
        if (itr == m_.end()) {
            return -1;
        }
        // Update the use_counter and update the map accordingly.
        // Updating the use_counter
        int prev_use_count = itr->second.second;
        int new_use_count = ++itr->second.second;
        updateUseCounterMap(key, prev_use_count, new_use_count);
        // Done with get?
        return itr->second.first;
    }
    
    void put(int key, int value) {
        // Update the use_counter and update the map accordingly.
        auto itr = m_.find(key);
        if (itr == m_.end()) {
            if (m_.size() == capacity_) {
                // If we are at capacity, we need to remove LRU in LFU;
                // Before insert.
                updateAtCapacity();
            }
            m_[key] = {value, 1};
            int prev_use_count = 0; // Will not be found.
            int new_use_count = 1;
            updateUseCounterMap(key, prev_use_count, new_use_count);
        } else {
            // First update value in map.
            itr->second.first = value;
            // Then update use_count in map & use_count map
            int prev_use_count = itr->second.second;
            int new_use_count = ++itr->second.second;
            updateUseCounterMap(key, prev_use_count, new_use_count);
        }
    }
private:
    // First element of the int is the "value", second element is the use_counter
    std::unordered_map<int, std::pair<int, int>> m_;
    // use_count map
    std::unordered_map<int, std::list<int>> lm_;
    int capacity_;
    void updateUseCounterMap(int& key, int& prev_use_count, int& new_use_count) {
        auto lm_itr = lm_.find(prev_use_count);
        if (lm_itr != lm_.end()) {
            auto& key_list = lm_itr->second;
            auto l_itr = key_list.begin();
            for(; l_itr != key_list.end(); ++l_itr) {
                if (*l_itr == key) {
                    break;
                }
            }
            // Remove from this use_count list for prev_use_count
            if (l_itr != key_list.end()) {
                key_list.erase(l_itr);
                if (!key_list.size()) {
                    // If the list is empty, remove it
                    // Not sure if this is correct.
                    lm_.erase(lm_itr);
                }
            }
        }
        // Add to the new use_count. If it doesn't exist create.
        lm_itr = lm_.find(new_use_count);
        if (lm_itr == lm_.end()) {
            lm_[new_use_count] = std::list({key});
        } else {
            auto& key_list = lm_itr->second;
            // Add to the front of the key.
            // This will be the "most recently used" key
            lm_itr->second.push_front(key);
        }
    }
    // updateAtCapacity. Already verified map is at capacity.
    // Erase the LRU key within the LFU use_count
    void updateAtCapacity() {
        // Find the least value of use_count
        int min_use = INT_MAX;
        int del_key = INT_MAX;
        std::unordered_map<int, std::list<int>>::iterator lm_itr = lm_.begin();
        std::unordered_map<int, std::list<int>>::iterator found_itr = lm_.end();
        
        for(auto& [u, pair]: lm_) {
            if (u < min_use) {
                min_use = u;
                found_itr = lm_itr;
            }
            ++lm_itr;
        }
        if (found_itr == lm_.end()) {
            std::cerr << "Error condition: min use_count ele not found" << std::endl;
            return;
        }
        // Found the LRU in LFU list.
        int lru_ele = found_itr->second.back();
        // Delete in use counter map
        found_itr->second.pop_back();
        // Delete in cache_map
        size_t del_size = m_.erase(lru_ele);
        if (del_size <= 0) {
            std::cerr << "Error condition: LRU ele not found in cache" << std::endl;
            return;
        }
    }
    LFUCache() = delete;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
