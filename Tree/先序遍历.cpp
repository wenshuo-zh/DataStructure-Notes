#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};
//先序遍历：根 左 右
vector<int>ans;
void helper(TreeNode* root) {
	if (root == nullptr)return;
	ans.push_back(root->val);
	helper(root->left);
	helper(root->right);
}
vector<int>preOrder(TreeNode* root) {
	helper(root);
	return ans;
}

int main() {
    /*
                            1
                          2   3
                        4  5 nu 6
                 nu nu   nu nu    nu nu
        先序遍历后：1 2 4 5 3 6
    */
    TreeNode* root = new TreeNode{ 1 };
    root->left = new TreeNode{ 2 };
    root->right = new TreeNode{ 3 };
    root->left->left = new TreeNode{ 4 };
    root->left->right = new TreeNode{ 5 };
    root->right->right = new TreeNode{ 6 };

  
    vector<int> result = preOrder(root);

    cout << "遍历结果: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}