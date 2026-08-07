#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
};

vector<int>levelOrder(TreeNode* root) {
	vector<int>ans;
	queue<TreeNode*>que;
	if (root == nullptr) return ans;
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