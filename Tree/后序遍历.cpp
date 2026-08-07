#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
//后序遍历：左->右->根
vector<int>ans;
void helper(TreeNode* root) {
    if (root == nullptr)return;
    helper(root->left);       //左右都处理完再添值
    helper(root->right);
    ans.push_back(root->val);
}
vector<int>postOrder(TreeNode* root) {
    helper(root);
    return ans;
}

int main() {
    /*
                            1
                          2   3
                        4  5 nu 6
                 nu nu   nu nu    nu nu
        后序遍历后：4 5 2 6 3 1
    */
    TreeNode* root = new TreeNode{ 1 };
    root->left = new TreeNode{ 2 };
    root->right = new TreeNode{ 3 };
    root->left->left = new TreeNode{ 4 };
    root->left->right = new TreeNode{ 5 };
    root->right->right = new TreeNode{ 6 };


    vector<int> result = postOrder(root);

    cout << "遍历结果: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}