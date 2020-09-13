/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
 *
 * https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/description/
 *
 * algorithms
 * Easy (55.93%)
 * Total Accepted:    15.1K
 * Total Submissions: 26.5K
 * Testcase Example:  '[1,null,3,2]'
 *
 * 给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
 *
 *
 *
 * 示例：
 *
 * 输入：
 *
 * ⁠  1
 * ⁠   \
 * ⁠    3
 * ⁠   /
 * ⁠  2
 *
 * 输出：
 * 1
 *
 * 解释：
 * 最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 树中至少有 2 个节点。
 * 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/
 * 相同
 *
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
    int getMinimumDifference(TreeNode* root) {
        int result = INT_MAX;
        wfs(root, result);
        return result;
    }

    void wfs(TreeNode * node, int & min) {
        if(node->right != nullptr) {
            int right_value = most_left(node->right);
            int diff1 = right_value - node->val;
            if(diff1 < min)
                min = diff1;
            wfs(node->right, min);
        }
        if(node->left != nullptr) {
            int left_value = most_right(node->left);
            int diff2 = node->val - left_value;
            if(diff2 < min)
                min = diff2;
            wfs(node->left, min);
        }
    }

    int most_left(TreeNode * node) {
        while(node->left != nullptr) {
            node = node->left;
        }
        return node->val;
    }

    int most_right(TreeNode * node) {
        while(node->right != nullptr) {
            node = node->right;
        }
        return node->val;
    }
};
