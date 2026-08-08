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
	while (!que.empty()) {// 循环队列，temp放队头（节点）当前节点有子节点，把子节点放到队列的后面，弹出队头
		TreeNode* temp = que.front();
		if (temp->left)que.push(temp->left);
		if (temp->right)que.push(temp->right);
		que.pop();
		ans.push_back(temp->val);
	}
	return ans;
}