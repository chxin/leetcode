/*
 * @lc app=leetcode.cn id=653 lang=cpp
 *
 * [653] 两数之和 IV - 输入 BST
 *
 * https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/description/
 *
 * algorithms
 * Easy (54.31%)
 * Total Accepted:    15.7K
 * Total Submissions: 28.4K
 * Testcase Example:  '[5,3,6,2,4,null,7]\n9'
 *
 * 给定一个二叉搜索树和一个目标结果，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
 *
 * 案例 1:
 *
 *
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2  4   7
 *
 * Target = 9
 *
 * 输出: True
 *
 *
 *
 *
 * 案例 2:
 *
 *
 * 输入:
 * ⁠   5
 * ⁠  / \
 * ⁠ 3   6
 * ⁠/ \   \
 * 2  4   7
 *
 * Target = 28
 *
 * 输出: False
 *
 *
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
    bool findTarget(TreeNode* root, int k) {
        int result = 0;
        dfs(root, root, k, result);
        return result;
    }

    void dfs(TreeNode * node, TreeNode * root, int k, int & result) {
        if(node == nullptr) return;
        if(result == 1) return;
        int value = k - node->val;
        int flag = 0;
        if(value + value != k)
            result = find_val(root, value, flag);
        dfs(node->left, root, k, result);
        dfs(node->right, root, k, result);
    }

    bool find_val(TreeNode * node, int k, int & flag) {
        if(flag == 1) return 1;
        if(node == nullptr) return 0;
        if(node->val == k) return 1;
        if(node->val > k) return find_val(node->left, k, flag);
        if(node->val < k) return find_val(node->right, k, flag);
        return 0;
    }
};
