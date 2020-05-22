//
//  295_find_median_from_data_stream.cpp
//  test
//
//  Created by ley on 2020/5/22.
//  Copyright © 2020 ley. All rights reserved.
//

#include <stdio.h>
#include "leetcode.h"

//others from discussion
//brilliant
//priority_queue  O(logn)

class MedianFinder {
public:
    /** initialize your data structure here. */
    
    //priority_queue    默认 大顶堆。
    //priority_queue<int,vector<int>,greater<int>> qe;          小顶堆
    //priority_queue<int,vector<int>,less<int>> qu;             大顶堆
    
    MedianFinder() {
        ;
    }
    
    void addNum(int num) {
        if(small.size()==0 || (small.size()==large.size() && num<=large.top()) ){
            small.push(num);
        }else if(small.size()>large.size() && num>=small.top()){
            large.push(num);
        }else{
            small.push(num);
            large.push(small.top());
            small.pop();
        }
        
        
        
        if(small.size()<large.size()){
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(small.size()>large.size()){
            return small.top();
        }else{
            //  small.size()==large.size()
            double t1=small.top();
            double t2=large.top();
            double tmp=(t1+t2)/2;
            return tmp;
        }
    }
private:
    priority_queue<int> small;
    priority_queue<int,vector<int>,greater<int>> large;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */




//time limit exceed..........why the pointer is too slow?
//  懂了。。。因为我每次插入数 都是O（n)的事件。。。。而discussion的优秀j解法只要 O(logn)

//class Node {
//public:
//    int val;
//    Node* left;
//    Node* right;
//
//    Node() : val(0), left(NULL), right(NULL) {}
//
//    Node(int _val) : val(_val), left(NULL), right(NULL){}
//
//    Node(int _val, Node* _left, Node* _right, Node* _next)
//    : val(_val), left(_left), right(_right){}
//};
//
//class MedianFinder {
//public:
//    /** initialize your data structure here. */
//    MedianFinder() {
//        ;
//    }
//
//    void addNum(int num) {
//        if(med==nullptr){
//            //empty
//            Node* tmp=new Node(num);
//            med=tmp;
//            isodd=true;
//        }else{
//            //not empty
//            Node* tmp=new Node(num);
//            if(num>=med->val){
//                Node* tt=med;
//                while(tt->right){
//                    if(tt->right->val<=num){
//                        tt=tt->right;
//                    }else{
//                        //tt->right->val > num
//                        Node* t1=tt->right;
//                        tt->right=tmp;
//                        tmp->left=tt;
//                        tmp->right=t1;
//                        t1->left=tmp;
//                    }
//                }
//                if(tt->right==nullptr){
//                    tt->right=tmp;
//                    tmp->left=tt;
//                }
//                if(!isodd){
//                    med=med->right;
//                }
//                isodd=!isodd;
//                cout<<med->val<<" "<<med->right->val<<endl;
//
//            }else{
//                //num < med->val
//                Node* tt=med;
//                while(tt->left){
//                    if(tt->left->val >= num){
//                        tt=tt->left;
//                    }else{
//                        //tt->left->val < num
//                        Node* t1=tt->left;
//                        tt->left=tmp;
//                        tmp->right=tt;
//                        tmp->left=t1;
//                        t1->right=tmp;
//                    }
//                }
//                if(tt->left==nullptr){
//                    tt->left=tmp;
//                    tmp->right=tt;
//                }
//
//                if(isodd){
//                    med=med->left;
//                }
//                isodd=!isodd;
//            }
//
//        }
//    }
//
//    double findMedian() {
//        if(isodd){
//            return med->val;
//        }else{
//            double t1=med->val;
//            double t2=med->right->val;
//            double tmp=(t1+t2)/2;
//            return tmp;
//        }
//    }
//private:
//    bool isodd;
//    Node* med=nullptr;
//
//};
//
///**
// * Your MedianFinder object will be instantiated and called as such:
// * MedianFinder* obj = new MedianFinder();
// * obj->addNum(num);
// * double param_2 = obj->findMedian();
// */
