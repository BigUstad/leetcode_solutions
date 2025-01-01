class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        tk = k;
        for (auto& n: nums) {
            addEle(n);
        }
    }
    void addEle(int& n) {
        if (pq.size() == tk) {
            if (n <= pq.top()) 
                return;
            if (n > pq.top())
                pq.pop();
        }
        pq.push(n);
    }
    int add(int val) {
        addEle(val);
        return pq.top();
    }
private:
    int tk;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
