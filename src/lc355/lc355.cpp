#include "lc.h"

class Twitter {
    unordered_map<int/*userId*/, vector<unsigned int>/*time-based id vec*/> _user_tbid_map;
    unordered_map<unsigned int/*time-based id*/, int/*tweetId*/> _tb_id_map;
    unordered_map<int/*userId*/, unordered_set<int>/*userId*/> _follow_map;
    
    typedef vector<unsigned int>::reverse_iterator Iterator;
    typedef pair<Iterator, Iterator> CMPELEM;
    struct cmp{
        bool operator()(const CMPELEM& lhs, const CMPELEM& rhs) const
        {
            return *(lhs.first) < *(rhs.first);
        }
    };
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /*generate time-based id*/
    unsigned int generateId()
    {
        static unsigned int id = 0;
        return id++;
    }
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        unsigned int tbid = generateId();
        _tb_id_map[tbid] = tweetId;
        _user_tbid_map[userId].emplace_back(tbid);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<CMPELEM, vector<CMPELEM>, cmp> pri_que;
        auto user_iter = _user_tbid_map.find(userId);
        if (user_iter != _user_tbid_map.end())
        {
            auto user_beg = user_iter->second.rbegin();
            auto user_end = user_iter->second.rend();
            if (user_beg != user_end)
            {
                pri_que.emplace(user_beg, user_end);
            }
        }
        auto fw_iter = _follow_map.find(userId);
        if (fw_iter != _follow_map.end())
        {
            for (int id : fw_iter->second)
            {
                auto u_iter = _user_tbid_map.find(id);
                if (u_iter == _user_tbid_map.end())
                {
                    continue;
                }
                auto u_beg = u_iter->second.rbegin();
                auto u_end = u_iter->second.rend();
                if (u_beg != u_end)
                {
                    pri_que.emplace(u_beg, u_end);
                }
            }
        }
        int k = 10;
        vector<int> ret;
        while (!pri_que.empty() && k-- > 0)
        {
            CMPELEM elem = pri_que.top();
            pri_que.pop();
            unsigned int tid = *(elem.first);
            ret.emplace_back(_tb_id_map[tid]);
            if (++(elem.first) != elem.second)
            {
                pri_que.push(elem);
            }
        }
        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
        {
            _follow_map[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        auto follower_iter = _follow_map.find(followerId);
        if (follower_iter == _follow_map.end())
        {
            return;
        }
        follower_iter->second.erase(followeeId);
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

 int main(int argc, char const *argv[])
 {
 	/* code */
 	return 0;
 }