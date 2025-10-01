class Logger {
public:
    Logger() {
        log_message_.clear();
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto itr = log_message_.find(message);
        if (itr == log_message_.end() || timestamp >= (itr->second + 10)) {
            log_message_[message] = timestamp;
            return true;
        }
        return false;
    }
private:
    std::unordered_map<std::string, int> log_message_;
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
