class Twitter {
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // Add to tweets
        auto& user_feed = feeds[userId];
        tweets[userId].push_back({uid++, tweetId});
        user_feed.push({uid++, tweetId, userId});
        // Who all follows this user?
        std::vector<int> follower_list = followed_by[userId];
        // std::cout << userId << " followed by " << follower_list.size() << " users." << std::endl;
        for (const int& f: follower_list) {
            // std::cout << "Pushing " << tweetId << " on " << f << "'s feed with uid: " << uid << std::endl;
            feeds[f].push({uid, tweetId, userId});
        }
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<std::tuple<int, int, int>>& pq = feeds[userId];
        // std::cout << __FUNCTION__ << " for " << userId << ". Has " << pq.size() << " tweets" << std::endl;
        std::vector<int> v_ret;
        std::vector<std::tuple<int, int, int>> all_tweets;
        int total_tweets = 10;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            all_tweets.push_back({std::get<0>(t), std::get<1>(t), std::get<2>(t)});
            v_ret.push_back(std::get<1>(t));
            if (!--total_tweets) break;
        }
        for (auto t: all_tweets) {
            pq.push({std::get<0>(t), std::get<1>(t), std::get<2>(t)});
        }
        return v_ret;
    }
    
    void follow(int followerId, int followeeId) {
        auto& followings = follows[followerId];
        if (followings.find(followeeId) != followings.end()) {
            return;
        }
        followings.insert(followeeId);
        followed_by[followeeId].push_back(followerId);
        // Get followeeId's tweets and add to followerId's tweets
        std::vector<std::pair<int, int>>& to_add_tweets = tweets[followeeId];
        // std::cout << followerId << " follows " << followeeId << std::endl;
        // std::cout << followeeId << " has " << to_add_tweets.size() << " tweets" << std::endl;
        for (auto& t: to_add_tweets) {
            feeds[followerId].push({t.first, t.second, followeeId});
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        auto& followings = follows[followerId];
        if (followings.find(followeeId) == followings.end()) {
            return;
        }
        followings.erase(followeeId);
        auto f_itr = followed_by[followeeId].begin();
        for (; f_itr != followed_by[followeeId].end(); ++f_itr) {
            if (*f_itr == followeeId) {
                break;
            }
        }
        if (f_itr != followed_by[followeeId].end()) {
            followed_by[followeeId].erase(f_itr);
        }
        std::vector<std::tuple<int, int, int>> curated_tweets;
        std::priority_queue<std::tuple<int, int, int>>& pq = feeds[followerId];
        // TODO: Remove followeeId's tweets from followerId's feed
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            if (std::get<2>(t) != followeeId) {
                curated_tweets.push_back({std::get<0>(t), std::get<1>(t), std::get<2>(t)});
            }
        }
        for (auto& t: curated_tweets) {
            pq.push({std::get<0>(t), std::get<1>(t), std::get<2>(t)});
        }
    }
private:
    // user_id <-> 'following' list
    std::unordered_map<int, std::unordered_set<int>> follows;
    std::unordered_map<int, std::vector<int>> followed_by;
    // user_id <-> tweets in user_id's timeline
    // pq pair. tweetId <-> by user_id
    std::unordered_map<int, std::priority_queue<std::tuple<int, int, int>>> feeds;
    // List of tweets as posted by the user_id (key)
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
    int uid = 1;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
