#include "leetcode.h"

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		while(userId<user_follow_list.size()){
			unordered_set<int> tmp_set;
			user_follow_list.push_back(tmp_set);
		}
    	pair<int,int> tmp(userId,tweetId);
		tw_history.push_back(tmp);    
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		while(userId<user_follow_list.size()){
			unordered_set<int> tmp_set;
			user_follow_list.push_back(tmp_set);
		}
        vector<int> ans;
		auto iter = tw_history.rbegin();
		while(ans.size()<10 && iter!=tw_history.rend()){
			if(user_follow_list[ userId ].find(iter->first) != user_follow_list.end()){
				ans.push_back(iter->second);
			}
			iter++;
		}

    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		while(userId<user_follow_list.size()){
			unordered_set<int> tmp_set;
			user_follow_list.push_back(tmp_set);
		}
		user_follow_list[ followerId ].push( followeeId );
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		while(userId<user_follow_list.size()){
			unordered_set<int> tmp_set;
			user_follow_list.push_back(tmp_set);
		}
		user_follow_list[ followerId ].erase( followeeId );
    }
private:
	vector<pair<int,int>> tw_history;
	vector<unordered_set<int>> user_follow_list;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
