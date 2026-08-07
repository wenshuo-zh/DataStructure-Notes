/*
 * ============================================
 *  树 (Tree) 基础概念
 * ============================================
 *
 * 一、树的定义
 *   1. 每个节点都有零个或多个子节点
 *   2. 没有父节点的节点是根节点 (Root)
 *   3. 除根节点外，每个节点有且只有一个父节点
 *   4. 除根节点外，每个子节点可以分成多个不相交的子树 (Subtree)
 *
 * 二、基本术语
 *   节点的度 (Degree)：      拥有子节点的个数
 *   叶节点 (Leaf)：          度为 0 的节点
 *   分支节点 (Branch Node)： 度不为 0 的节点
 *   树的度：                 所有节点中最大的度
 *   层次 (Level)：           根节点为第 1 层，每向下一层 +1
 *   高度 (Height)：          树的最大层次
 *   深度 (Depth)：           从根到该节点的路径长度（根深度为 0 或 1，视定义而定）
 *
 * 三、二叉树 (Binary Tree)
 *   每个节点最多有两个子节点（左子节点、右子节点）
 *
 *   性质：
 *     1. 第 n 层最多有 2^(n-1) 个节点
 *     2. 深度为 k 的二叉树最多有 2^k - 1 个节点
 *     3. 对于任意二叉树，若叶节点数为 n0，度为 2 的节点数为 n2，则 n0 = n2 + 1
 *
 *   满二叉树 (Full Binary Tree)：
 *     除最后一层外，每层节点数都达到最大值；最后一层的节点集中在左侧
 *
 *   完全二叉树 (Complete Binary Tree)：
 *     除最后一层外，其余层都是满的，且最后一层的节点从左到右连续排列
 *
 * 四、二叉搜索树 (Binary Search Tree, BST)
 *   对任意节点：左子树所有节点值 < 当前节点值 < 右子树所有节点值
 *   中序遍历 BST 得到升序序列
 */

#include <bits/stdc++.h>
using namespace std;

// ============================================
// 二叉树节点定义
// ============================================
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ============================================
// 手动构建一棵示例二叉树（用于教学演示）
//
//           1
//          / \
//         2   3
//        / \   \
//       4   5   6
//
// ============================================
TreeNode* buildTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    return root;
}

// ============================================
// 前序遍历（Preorder）：根 → 左 → 右
// 应用场景：复制树、序列化、前缀表达式
// ============================================
void preorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;           // 递归终止条件
    result.push_back(root->val);           // 先访问根
    preorder(root->left, result);          // 再遍历左子树
    preorder(root->right, result);         // 最后遍历右子树
}

// ============================================
// 中序遍历（Inorder）：左 → 根 → 右
// 应用场景：BST 的中序遍历得到升序序列
// ============================================
void inorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    inorder(root->left, result);           // 先遍历左子树
    result.push_back(root->val);           // 再访问根
    inorder(root->right, result);          // 最后遍历右子树
}

// ============================================
// 后序遍历（Postorder）：左 → 右 → 根
// 应用场景：释放树的内存、计算目录大小、后缀表达式
// ============================================
void postorder(TreeNode* root, vector<int>& result) {
    if (root == nullptr) return;
    postorder(root->left, result);         // 先遍历左子树
    postorder(root->right, result);        // 再遍历右子树
    result.push_back(root->val);           // 最后访问根
}

// ============================================
// 层序遍历（Level-order / BFS）
// 借助队列，一层一层从左到右遍历
// 应用场景：最短路径、树的序列化/反序列化
// ============================================
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (root == nullptr) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();          // 当前层的节点数
        vector<int> currentLevel;
        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            currentLevel.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(currentLevel);
    }
    return result;
}

// ============================================
// 释放二叉树内存（后序遍历：先删子节点再删父节点）
// ============================================
void freeTree(TreeNode* root) {
    if (root == nullptr) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// ============================================
// 打印遍历结果的辅助函数
// ============================================
void printVector(const vector<int>& vec, const string& label) {
    cout << label;
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

// ============================================
// main() — 演示四种遍历
// ============================================
int main() {
    cout << "===== 二叉树基础演示 =====" << endl;

    TreeNode* root = buildTree();

    // 前序遍历
    vector<int> preResult;
    preorder(root, preResult);
    printVector(preResult, "前序遍历（根左右）: ");
    // 预期输出: 1 2 4 5 3 6

    // 中序遍历
    vector<int> inResult;
    inorder(root, inResult);
    printVector(inResult, "中序遍历（左根右）: ");
    // 预期输出: 4 2 5 1 3 6（BST 中序遍历 = 升序）

    // 后序遍历
    vector<int> postResult;
    postorder(root, postResult);
    printVector(postResult, "后序遍历（左右根）: ");
    // 预期输出: 4 5 2 6 3 1

    // 层序遍历
    cout << "层序遍历（BFS，按层输出）: " << endl;
    vector<vector<int>> levels = levelOrder(root);
    for (int i = 0; i < levels.size(); i++) {
        cout << "  第" << (i + 1) << "层: ";
        for (int val : levels[i]) {
            cout << val << " ";
        }
        cout << endl;
    }

    // 释放内存
    freeTree(root);
    cout << "内存已释放" << endl;

    return 0;
}
