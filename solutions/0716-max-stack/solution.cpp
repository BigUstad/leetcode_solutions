class MaxStack {
public:
    MaxStack() {
        index = 0;
    }
    
    // SplitStringOnDelimiter. Split input string, on input delimiter.
    std::vector<std::string> SplitStringOnDelimiter(const std::string& inputStr, const char& delimiter) {
        if (inputStr.empty()) {
            return {};
        }
        std::vector<std::string> lRet;
        std::stringstream lSS(inputStr);
        std::string lWord;

        while (getline(lSS, lWord, delimiter)) {
            lRet.push_back(lWord);
        }

        return lRet;
    }
    std::string GetStringCSV(const std::vector<std::string>& inVec) {
        if (inVec.size() == 0) {
            return "";
        }
        std::ostringstream ossCSV;
        std::copy(inVec.begin(), inVec.end(), std::ostream_iterator<std::string>(ossCSV, ","));
        std::string ret_str(ossCSV.str());
        if (ret_str.back() == ',') ret_str.pop_back();
        return ret_str;
    }
    void push(int x) {
        s[index] = x;
        std::string s = std::to_string(index);
        ++index;
        auto v_itr = v.find(x);
        if (v_itr == v.end()) {
            v[x] = s;
            return;
        }
        v_itr->second.append(",");
        v_itr->second.append(s);
        // std::cout << __FUNCTION__ << " v[" << x << "] = " << v_itr->second << std::endl;
    }
    
    int pop() {
        if (s.empty() || v.empty()) {
            std::cout << __FUNCTION__ << " s or v is empty" << std::endl;
        }
        auto v_itr = v.find(s.rbegin()->second);
        int l_ret = v_itr->first;
        
        if (v_itr != v.end()) {
            // Get the last index.
            auto s_itr = s.end(); --s_itr;
            s.erase(s_itr);
            std::vector<std::string> v_vec = SplitStringOnDelimiter(v_itr->second, ',');
            v_vec.pop_back();
            if (v_vec.empty()) {
                v.erase(v_itr);
            } else {
                v[l_ret] = GetStringCSV(v_vec);
            }
        }
        return l_ret;
    }
    
    int top() {
        if (s.empty()) {
            std::cout << __FUNCTION__ << " s Empty." << std::endl;
            return INT_MIN;
        }
        return s.rbegin()->second;;
    }
    
    int peekMax() {
        if (v.empty()) {
            std::cout << __FUNCTION__ << " v Empty." << std::endl;
            return INT_MIN;
        }
        return v.rbegin()->first;
    }
    
    int popMax() {
        auto v_itr = v.end(); --v_itr;
        int l_ret = v_itr->first;
        std::vector<std::string> v_vec = SplitStringOnDelimiter(v_itr->second, ',');
        int s_index = std::stoi(v_vec.back());
        auto s_itr = s.find(s_index);
        s.erase(s_itr);
        v_vec.pop_back();
        if (v_vec.empty()) {
            v.erase(v_itr);
        } else {
            v[l_ret] = GetStringCSV(v_vec);
        }
        return l_ret;
    }
private:
    std::map<int, int> s;
    std::map<int, std::string> v;
    int index;
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */
