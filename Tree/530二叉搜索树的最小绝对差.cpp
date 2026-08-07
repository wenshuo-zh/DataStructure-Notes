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
    vector<int>arr;
    void inOrder(TreeNode* root) {
        if (root == nullptr)return;
        inOrder(root->left);
        arr.push_back(root->val);
        inOrder(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        inOrder(root);
        int ans = INT_MAX;
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            if ((arr[i + 1] - arr[i]) < ans)ans = (arr[i + 1] - arr[i]);
        }
        return ans;
    }
};