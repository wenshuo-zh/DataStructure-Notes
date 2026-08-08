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

//递归
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)return true;
        else if (p == nullptr || q == nullptr)return false;
        else if (p->val != q->val)return false;
        //所有的返回到最后左右并到root都相同返回true && true 也就是true
        else return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

//数组
class Solution {
public:
    // 只检查结构是否相同
    bool sameStructure(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;   
        if (p == nullptr || q == nullptr) return false;  
        // 都非空，递归检查左右子树结构
        return sameStructure(p->left, q->left) && sameStructure(p->right, q->right);
    }

    void preOrder(TreeNode* root, vector<int>& vec) {
        if (root == nullptr) return;
        vec.push_back(root->val);
        preOrder(root->left, vec);
        preOrder(root->right, vec);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
   
        if (!sameStructure(p, q)) return false;

        
        vector<int> vecp, vecq;
        preOrder(p, vecp);
        preOrder(q, vecq);
        return vecp == vecq;  
    }
};