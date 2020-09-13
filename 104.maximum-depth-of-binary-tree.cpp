/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (72.56%)
 * Total Accepted:    157.4K
 * Total Submissions: 216.2K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 *
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 *
 * 说明: 叶子节点是指没有子节点的节点。
 *
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回它的最大深度 3 。
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
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        int depth = 1;
        recursion(root, max_depth, depth);
        return max_depth;
    }
    void recursion(TreeNode * node, int & max_depth, int depth) {
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) {
            if(max_depth < depth) {
                max_depth = depth;
            }
            return;
        }

        if(node->left != nullptr) {
            // ++depth;
            recursion(node->left, max_depth, depth + 1);
        }
        if(node->right != nullptr) {
            // ++depth;
            recursion(node->right, max_depth, depth + 1);
        }
    }
};
