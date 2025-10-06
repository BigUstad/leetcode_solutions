class LRUCache {
public:
    LRUCache(int capacity) {
        count = (size_t) capacity;
    }
    
    // get key makes key the most recently used key
    int get(int key) {
        auto c_itr = m_cache.find(key);
        if (c_itr == m_cache.end()) {
            return -1;
        }
        int l_ret = c_itr->second->second;
        m_lru.erase(c_itr->second);
        m_lru.push_front(std::make_pair(key, l_ret));
        c_itr->second = m_lru.begin();
        return l_ret;
    }
    
    // put key, makes key the most recently used key
    void put(int key, int value) {
        auto c_itr = m_cache.find(key);
        m_lru.push_front({key, value});
        if (c_itr != m_cache.end()) {
            m_lru.erase(c_itr->second);
        }
        m_cache[key] = m_lru.begin();
        if (m_cache.size() <= count) {
            return;
        }
        // Delete the stale node
        auto l_itr = m_lru.back();
        // remove in cache
        c_itr = m_cache.find(l_itr.first);
        m_cache.erase(c_itr);
        m_lru.pop_back();
    }
private:
    size_t count;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;
    // Value of most recently used key in the front
    // Value of the stale key in the back.
    std::list<std::pair<int, int>> m_lru;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
