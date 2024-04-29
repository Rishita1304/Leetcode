class Twitter {
public:
    unordered_map<int, set<int>> fol;
    unordered_map<int, vector<pair<int,int>>> tweet;
    long long time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweet[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for(auto i:tweet[userId]) pq.push(i);
        for(auto i1:fol[userId]){
            for(auto i2:tweet[i1]) pq.push(i2);
        }
        vector<int> ans;
        while(pq.size()>0){
            ans.push_back(pq.top().second);
            if(ans.size()==10) break;
            pq.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId)
            fol[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        fol[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */