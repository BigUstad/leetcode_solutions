class FirstUnique {
public:
    FirstUnique(vector<int>& nums) {
        for(auto& n: nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        return ((uniques_.empty())? -1 : uniques_.front());
    }
    
    void add(int value) {
        auto m_itr = num_set_.find(value);
        
        num_set_.insert(value);
        if (m_itr == num_set_.end()) {
            uniques_.push_back(value);
            return;
        }
        for (auto l_itr = uniques_.begin(); l_itr != uniques_.end(); ++l_itr) {
            if ((*l_itr) == value) {
                uniques_.erase(l_itr);
                break;
            }
        }
    }
private:
    std::unordered_set<int> num_set_;
    std::list<int> uniques_;
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
