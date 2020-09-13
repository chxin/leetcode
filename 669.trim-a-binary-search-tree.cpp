/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
 *
 * https://leetcode-cn.com/problems/trim-a-binary-search-tree/description/
 *
 * algorithms
 * Easy (64.72%)
 * Total Accepted:    12.1K
 * Total Submissions: 18.4K
 * Testcase Example:  '[1,0,2]\n1\n2'
 *
 * 给定一个二叉搜索树，同时给定最小边界L 和最大边界 R。通过修剪二叉搜索树，使得所有节点的值在[L, R]中 (R>=L)
 * 。你可能需要改变树的根节点，所以结果应当返回修剪好的二叉搜索树的新的根节点。
 *
 * 示例 1:
 *
 *
 * 输入:
 * ⁠   1
 * ⁠  / \
 * ⁠ 0   2
 *
 * ⁠ L = 1
 * ⁠ R = 2
 *
 * 输出:
 * ⁠   1
 * ⁠     \
 * ⁠      2
 *
 *
 * 示例 2:
 *
 *
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 0   4
 * ⁠  \
 * ⁠   2
 * ⁠  /
 * ⁠ 1
 *
 * ⁠ L = 1
 * ⁠ R = 3
 *
 * 输出:
 * ⁠     3
 * ⁠    /
 * ⁠  2
 * ⁠ /
 * ⁠1
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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        TreeNode * result = root;
        find_root(root, L, R, result);
        dfs(result, L, R);
        return result;
    }
    void find_root(TreeNode * root, int L, int R, TreeNode * & result) {
        if(root == nullptr) return;
        if(root->val > R) {
            root = root->left;
            result = root;
            find_root(root, L, R, result);
            return;
        }
        if(root->val < L) {
            root = root->right;
            result = root;
            find_root(root, L, R, result);
            return;
        }
    }
    void dfs(TreeNode * root, int L, int R) {
        if(root == nullptr) return;
        if(root->left != nullptr) {
            if(root->left->val > R) {
                root->left = nullptr;
                dfs(root, L, R);
            }
            else if(root->left->val < L) {
                root->left = root->left->right;
                dfs(root, L, R);
            } else
            dfs(root->left, L, R);
        }
        if(root->right != nullptr) {
            if(root->right->val < L) {
                root->right = nullptr;
                dfs(root, L, R);
            }
            else if(root->right->val > R) {
                root->right = root->right->left;
                dfs(root, L, R);
            } else
            dfs(root->right, L, R);
        }
    }
};
