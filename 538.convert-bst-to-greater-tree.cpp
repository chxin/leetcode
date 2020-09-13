/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 *
 * https://leetcode-cn.com/problems/convert-bst-to-greater-tree/description/
 *
 * algorithms
 * Easy (59.57%)
 * Total Accepted:    25K
 * Total Submissions: 40.9K
 * Testcase Example:  '[5,2,13]'
 *
 * 给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater
 * Tree)，使得每个节点的值是原来的节点值加上所有大于它的节点值之和。
 *
 *
 *
 * 例如：
 *
 * 输入: 原始二叉搜索树:
 * ⁠             5
 * ⁠           /   \
 * ⁠          2     13
 *
 * 输出: 转换为累加树:
 * ⁠            18
 * ⁠           /   \
 * ⁠         20     13
 *
 *
 *
 *
 * 注意：本题和 1038:
 * https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/ 相同
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
    TreeNode* convertBST(TreeNode* root) {
        val_sum(root, nullptr, nullptr, nullptr, 0);
        return root;
    }

    // right child
    // val = val + right->val
    // left child
    // val = val + parent->val + right->val
    int right_sum(TreeNode * node) {
        if(node == nullptr) return 0;
        return right_sum(node->left) + right_sum(node->right) + node->val;
    }
    int val_sum(TreeNode * node, TreeNode * parent, TreeNode * grand, TreeNode * grandgrand, bool is_left) {
        if(node == nullptr) return 0;
        if(sum_status[node] == 1) return node->val;
        int tmp = right_sum(node->right);
        if(is_left) {
            node->val += tmp + val_sum(parent, grand, grandgrand, nullptr, 0);
            sum_status[node] = 1;
            val_sum(node->left, node, parent, grand, 1);
            val_sum(node->right, node, parent, grand, 0);
        } else {
            node->val += tmp + val_sum(grand, nullptr, nullptr, nullptr, 0);
            sum_status[node] = 1;
            val_sum(node->left, node, parent, grand, 1);
            val_sum(node->right, nullptr, grand, nullptr, 0);
        }
        return node->val;
    }
private:
    map<TreeNode *, bool> sum_status;
};
