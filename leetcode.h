#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <unordered_map>
#include <stack>
#include <algorithm>
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

