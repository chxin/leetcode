/*
 * @lc app=leetcode.cn id=687 lang=cpp
 *
 * [687] 最长同值路径
 *
 * https://leetcode-cn.com/problems/longest-univalue-path/description/
 *
 * algorithms
 * Easy (39.40%)
 * Total Accepted:    15.8K
 * Total Submissions: 39.4K
 * Testcase Example:  '[5,4,5,1,1,5]'
 *
 * 给定一个二叉树，找到最长的路径，这个路径中的每个节点具有相同值。 这条路径可以经过也可以不经过根节点。
 *
 * 注意：两个节点之间的路径长度由它们之间的边数表示。
 *
 * 示例 1:
 *
 * 输入:
 *
 *
 * ⁠             5
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         1   1   5
 *
 *
 * 输出:
 *
 *
 * 2
 *
 *
 * 示例 2:
 *
 * 输入:
 *
 *
 * ⁠             1
 * ⁠            / \
 * ⁠           4   5
 * ⁠          / \   \
 * ⁠         4   4   5
 *
 *
 * 输出:
 *
 *
 * 2
 *
 *
 * 注意: 给定的二叉树不超过10000个结点。 树的高度不超过1000。
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
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
    void dfs(TreeNode * node, int & max) {
        if(node == nullptr) return;
        int path = len(node->left, node->val) + len(node->right, node->val);
        if(max < path) max = path;
        dfs(node->left, max);
        dfs(node->right, max);
    }

    int len(TreeNode * node, int num) {
        if(node == nullptr) return 0;
        int dl = 0;
        int dr = 0;
        // if(node->left != nullptr) {
            if(node->val == num) {
                dl = len(node->left, num) + 1;
            } else {
                dl = 0;
            }
        // }
        // if(node->right != nullptr) {
            if(node->val == num) {
                dr = len(node->right, num) + 1;
            } else {
                dr = 0;
            }
        // }
        return dl > dr ? dl : dr;
    }
};
