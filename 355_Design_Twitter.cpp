#include "leetcode.h"

//others solution
//the pq   pair<.begin(),.end()>
//amazing!!!!!!!!!!!
class tweet{
public:
    int time;
    int userId;
    tweet(int time,int userId):time(time),userId(userId){}
};

class comp{
public:
    bool operator()(pair<vector<tweet>::iterator,vector<tweet>::iterator> a,pair<vector<tweet>::iterator,vector<tweet>::iterator> b){
        return a.first->time < b.first->time;
        //这样，小的排前面，  top就是最大的time
        
        //priority is 反的
        //他排序的是 按这个排
        //但是pop top是 T最后的。所以要大顶堆，要用less
        //小顶堆 要用greater<int>
    }
};

typedef pair<vector<tweet>::iterator,vector<tweet>::iterator> leypair;

class Twitter {
public:
    /** Initialize your data structure here. */
    //Twitter() {
    //    ;
    //}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        user_tw[userId].insert(user_tw[userId].begin(),(tweet(time++,tweetId)));
        //or push_back();
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<leypair,vector<leypair>,comp> pq;
        
        vector<int> ans;
        for(auto& a:user_follow[userId]){
            if(user_tw.count(a) && user_tw[a].size())       //exit and have tweet
                pq.push(make_pair(user_tw[a].begin(), user_tw[a].end()));
        }
        if(user_tw.count(userId) && user_tw[userId].size()){
            pq.push(make_pair(user_tw[userId].begin(), user_tw[userId].end()));
        }
        
        for(int i=0;i<10 && !pq.empty();i++){
            auto tmp=pq.top();
            pq.pop();
            ans.push_back(tmp.first->userId);
            if(++tmp.first != tmp.second) pq.push(tmp);
        }
        return ans;
        
        
        
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId!=followeeId){
            user_follow[followerId].insert(followeeId);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(user_follow.count(followerId)){
            //means the followerId is in the map
            user_follow[followerId].erase(followeeId);
        }
    }
private:
    unordered_map<int, vector<tweet>> user_tw;
    unordered_map<int, unordered_set<int>> user_follow; //easy to follow and unfollow
    int time=0;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */



////myself pass but too slow.....only 12% speed
//class Twitter {
//public:
//    /** Initialize your data structure here. */
//    Twitter() {
//        unordered_set<int> tmp_set2;
//        tmp_set2.insert(0);
//        user_follow_list.push_back(tmp_set2);
//    }
//
//    /** Compose a new tweet. */
//    void postTweet(int userId, int tweetId) {
//        //cout<<"post"<<endl;
//        while(userId > user_follow_list.size()-1){      //  userId :5     size need 6
//            unordered_set<int> tmp_set;
//            tmp_set.insert(user_follow_list.size());
//            user_follow_list.push_back(tmp_set);
//        }
//        pair<int,int> tmp(userId,tweetId);
//        tw_history.push_back(tmp);
//    }
//
//    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
//    vector<int> getNewsFeed(int userId) {
//        //cout<<"getNews"<<endl;
//        while(userId > user_follow_list.size()-1){
//            unordered_set<int> tmp_set;
//            tmp_set.insert(user_follow_list.size());
//            user_follow_list.push_back(tmp_set);
//        }
//        vector<int> ans;
//        auto iter = tw_history.rbegin();
//        //cout<<"1"<<endl;
//        while(ans.size() < 10 && iter!=tw_history.rend()){
//            //cout<<"2"<<endl;
//            if(user_follow_list[userId].find(iter->first)!=user_follow_list[userId].end()){
//                //cout<<"5"<<endl;
//                ans.push_back(iter->second);
//            }
//            //cout<<"3"<<endl;
//            iter++;
//        }
//        //cout<<"4"<<endl;
//        return ans;
//    }
//
//    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
//    void follow(int followerId, int followeeId) {
//        //cout<<"follow"<<endl;
//        int userId=max(followerId,followeeId);
//        while(userId > user_follow_list.size()-1){
//            unordered_set<int> tmp_set;
//            tmp_set.insert(user_follow_list.size());
//            user_follow_list.push_back(tmp_set);
//        }
//        user_follow_list[followerId].insert(followeeId);
//    }
//
//    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
//    void unfollow(int followerId, int followeeId) {
//        if(followerId==followeeId) return;
//        //cout<<"unfollow"<<endl;
//         int userId=max(followerId,followeeId);
//        while(userId > user_follow_list.size()-1){
//            unordered_set<int> tmp_set;
//            tmp_set.insert(user_follow_list.size());
//            user_follow_list.push_back(tmp_set);
//        }
//        user_follow_list[ followerId ].erase( followeeId );
//    }
//private:
//    vector<pair<int,int>> tw_history;
//    vector<unordered_set<int>> user_follow_list;
//
//};
//
///**
// * Your Twitter object will be instantiated and called as such:
// * Twitter* obj = new Twitter();
// * obj->postTweet(userId,tweetId);
// * vector<int> param_2 = obj->getNewsFeed(userId);
// * obj->follow(followerId,followeeId);
// * obj->unfollow(followerId,followeeId);
// */
