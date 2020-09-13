/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (64.73%)
 * Total Accepted:    103K
 * Total Submissions: 157.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 *
 * 示例:
 *
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * 输出: [1,2,3]
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        // ffo(root, result);
        ffo_iteration(root, result);
        return result;
    }

    void ffo(TreeNode * node, vector<int> & v) {
        if(node == nullptr) return;
        v.push_back(node->val);
        ffo(node->left, v);
        ffo(node->right, v);
    }
    void ffo_iteration(TreeNode * node, vector<int> & v) {
        if(node == nullptr) return;
        stack<TreeNode *> s;
        s.push(node);
        while(!s.empty()) {
            while(node != nullptr) {
                s.push(node);
                v.push_back(node->val);
                node = node->left;
            }
            node = s.top();
            s.pop();
            node = node->right;
        }
    }
};
