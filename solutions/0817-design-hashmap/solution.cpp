class MyHashMap {
public:
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        auto itr = map.begin();
        while (itr != map.end()) {
            if (itr->first == key) {
                break;
            }
            itr++;
        }
        if (itr == map.end()) {
            map.push_back(std::make_pair(key, value));
        } else {
            itr->second = value;
        }
    }
    
    int get(int key) {
        auto itr = map.begin();
        while (itr != map.end()) {
            if (itr->first == key) {
                break;
            }
            itr++;
        }
        if (itr == map.end()) {
            return -1;
        } else {
            return itr->second;
        }
    }
    
    void remove(int key) {
        auto itr = map.begin();
        while (itr != map.end()) {
            if (itr->first == key) {
                map.erase(itr);
                return;
            }
            itr++;
        }
    }
private:
    std::list<std::pair<int, int>> map;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
