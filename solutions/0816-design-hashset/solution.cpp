class MyHashSet {
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
    }
    
    void add(int key) {
        if ( contains(key) )
            return;
        hashSetMap[key] = time(0);
    }
    
    void remove(int key) {
        auto itr = hashSetMap.find(key);
        if ( itr != hashSetMap.end() )
        {
            hashSetMap.erase(itr);
        }
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return ( hashSetMap.find(key) != hashSetMap.end() );
    }
private:
    std::map<int, time_t, std::less<int> > hashSetMap;
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
