#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
};
//二叉搜索树用中序遍历->升序排列
//中序遍历：左 根 右
vector<int>ans;
void helper(TreeNode* root) {
    if (root == nullptr)return;
    helper(root->left);
    ans.push_back(root->val);      //左侧都处理完再添值
    helper(root->right);
}
vector<int>inOrder(TreeNode* root) {
    helper(root);
    return ans;
}

int main() {
    /*
                            1
                          2   3
                        4  5 nu 6
                 nu nu   nu nu    nu nu
        中序遍历后：4 2 5 1 3 6
    */
    TreeNode* root = new TreeNode{ 1 };
    root->left = new TreeNode{ 2 };
    root->right = new TreeNode{ 3 };
    root->left->left = new TreeNode{ 4 };
    root->left->right = new TreeNode{ 5 };
    root->right->right = new TreeNode{ 6 };


    vector<int> result = inOrder(root);

    cout << "遍历结果: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}