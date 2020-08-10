class Twitter {
    struct Tweet {
        int id;
        int time;
        Tweet *next;
        Tweet() {};
        Tweet(int i, int t) : id(i), time(t), next(nullptr) {}
    };

    struct User {
        int id;
        Tweet *tweets;
        unordered_set<int> followees;
        User() {}
        User(int i) : id(i), tweets(nullptr) {
            followees.insert(id);
        }
    };

    // https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
    struct CompareTime { 
        bool operator()(Tweet* p1, Tweet* p2) { 
            // max heap
            return p1->time < p2->time; 
        } 
    };

    int timestamp;
    unordered_map<int, User> allUsers;
    
public:
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        Tweet* newTweet = new Tweet(tweetId, timestamp);
        if(allUsers.count(userId) == 0) {
            User* newU = new User(userId);
            newU->tweets = newTweet;
            allUsers[userId] = *newU; 
        }
        else {
            newTweet->next = allUsers[userId].tweets;
            allUsers[userId].tweets = newTweet;
        }
        ++timestamp;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted 
    by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(allUsers.count(userId) == 0)
            return vector<int>();
        // k sorted link-lists merge
        User u = allUsers[userId];
        priority_queue<Tweet*, vector<Tweet*>, CompareTime> pq;
        for(auto id : u.followees) {
            if(allUsers[id].tweets != nullptr)
                pq.push(allUsers[id].tweets);
        }
        vector<int> res;
        while(!pq.empty()) {
            if(res.size() == 10) break;
            Tweet* tmp = pq.top(); pq.pop();
            res.push_back(tmp->id);
            if(tmp->next != nullptr)
                pq.push(tmp->next);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        if(allUsers.count(followerId) == 0) {
            User *u1 = new User(followerId);
            allUsers[followerId] = *u1;
        }
        if(allUsers.count(followeeId) == 0) {
            User *u2 = new User(followeeId);
            allUsers[followeeId] = *u2;
        }
        allUsers[followerId].followees.insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        if(allUsers.count(followerId) == 0) {
            User *u1 = new User(followerId);
            allUsers[followerId] = *u1;
        }
        if(allUsers.count(followeeId) == 0) {
            User *u2 = new User(followeeId);
            allUsers[followeeId] = *u2;
        }
        if(allUsers[followerId].followees.count(followeeId) == 0)
            return;
        allUsers[followerId].followees.erase(followeeId);
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
