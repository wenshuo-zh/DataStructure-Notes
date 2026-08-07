#include<bits/stdc++.h>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> decorateRecord(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>que;
        if (root == nullptr)return ans;
        que.push(root);
        
        while (!que.empty()) {
            TreeNode* temp = que.front();
            if (temp->left)que.push(temp->left);
            if (temp->right)que.push(temp->right);
            que.pop();
            ans.push_back(temp->val);
        }
        return ans;
    }
};