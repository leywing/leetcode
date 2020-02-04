#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include <queue>

//#include <math.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// // Definition for a Node.
// class Node {
// public:
// int val;
// Node* left;
// Node* right;
// Node* next;
//
// Node() : val(0), left(NULL), right(NULL), next(NULL) {}
//
// Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
//
// Node(int _val, Node* _left, Node* _right, Node* _next)
// : val(_val), left(_left), right(_right), next(_next) {}
// };

//class Node {
//public:
//    int val;
//    vector<Node*> neighbors;
//    
//    Node() {}
//    
//    Node(int _val, vector<Node*> _neighbors) {
//        val = _val;
//        neighbors = _neighbors;
//    }
//};
