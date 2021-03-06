/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (50.54%)
 * Total Accepted:    131.2K
 * Total Submissions: 257.6K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 *
 *
 *
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3 4 4  3
 *
 *
 *
 *
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 *
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 *
 *
 *
 *
 * 进阶：
 *
 * 你可以运用递归和迭代两种方法解决这个问题吗？
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
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) return 1;
        bool result = 1;
        dfs(root->left, root->right, result);
        return result;
    }

    void dfs(TreeNode * node1, TreeNode * node2, bool & flag) {
        if(flag == 0) return;
        if(node1 == nullptr && node2 == nullptr) return;
        if(node1 == nullptr && node2 != nullptr) {
            flag = 0;
            return;
        }
        if(node1 != nullptr && node2 == nullptr) {
            flag = 0;
            return;
        }
        if(node1->val == node2->val) {
            dfs(node1->left, node2->right, flag);
            dfs(node1->right, node2->left, flag);
        } else {
            flag = 0;
        }
    }
};
