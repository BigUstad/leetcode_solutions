class MyHashSet {
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        for(auto& k: set) {
            if (k == key) {
                // exists. return
                return;
            }
        }
        set.push_front(key);
    }
    
    void remove(int key) {
        set.remove(key);
    }
    
    bool contains(int key) {
        for(auto& k: set) {
            if (k == key) {
                // exists. return
                return true;
            }
        }
        return false;
    }
private:
    std::forward_list<int> set;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
