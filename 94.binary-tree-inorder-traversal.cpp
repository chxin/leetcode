/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (70.40%)
 * Total Accepted:    117.3K
 * Total Submissions: 166.3K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的中序 遍历。
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
 * 输出: [1,3,2]
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        // recursion(root, result);
        loop(root, result);

        return result;
    }
    void recursion(TreeNode * node, vector<int> & result) {
        if(node->left != NULL) {
            recursion(node->left, result);
        }
        result.push_back(node->val);
        if(node->right != NULL) {
            recursion(node->right, result);
        }
    }
    void loop(TreeNode * node, vector<int> & result) {
        TreeNode * current(node);
        stack<TreeNode *> cache;
        while(current || !cache.empty()) {
            while(current) {
                cache.push(current);
                current = current->left;
            }
            if(!cache.empty())
            {
                current = cache.top();
                cache.pop();
                result.push_back(current->val);
                current = current->right;
            }
        }
    }
};
