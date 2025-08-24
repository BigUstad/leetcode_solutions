class OrderedStream {
public:
    OrderedStream(int n) {
        last_sent_id = 0;
        total = n;
    }
    
    vector<string> insert(int idKey, string value) {
        std::vector<string> v_ret;
        int need_to_send_id = last_sent_id + 1;
        int prev_id = last_sent_id;
        if (cache_for_stream.size() < total) {
            cache_for_stream.insert({idKey, value});
        }
        if (idKey == need_to_send_id) {
            v_ret.push_back(value);
            last_sent_id = need_to_send_id;
            ++need_to_send_id;
        }
        std::map<int, std::string>::iterator c_itr = cache_for_stream.begin();
        if (!cache_for_stream.empty() && need_to_send_id >= c_itr->first) {
            for (; c_itr != cache_for_stream.end(); ++c_itr) {
                if (c_itr->first < need_to_send_id) {
                    continue;
                }
                if (c_itr->first != need_to_send_id ) {
                    break;
                }
                v_ret.push_back(c_itr->second);
                last_sent_id = c_itr->first;
                ++need_to_send_id;
            }
        }
        return v_ret;
    }
private:
    std::map<int, std::string> cache_for_stream;
    int last_sent_id;
    int total;
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
