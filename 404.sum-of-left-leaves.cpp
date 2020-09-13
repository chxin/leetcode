/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
 *
 * https://leetcode-cn.com/problems/sum-of-left-leaves/description/
 *
 * algorithms
 * Easy (54.17%)
 * Total Accepted:    23.9K
 * Total Submissions: 43.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 计算给定二叉树的所有左叶子之和。
 *
 * 示例：
 *
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        // when only root node, should *not* take it as left or right child
        // if(root->left == nullptr && root->right == nullptr) return 1;
        stack<TreeNode *> st;
        st.push(root);
        TreeNode * node = root;
        int result = 0;
        bool flag = 0;
        while(!st.empty()) {
            flag = 0;
            while(node != nullptr) {
                st.push(node);
                if(flag == 1 && node->left == nullptr && node->right == nullptr) {
                    result += node->val;
                }
                node = node->left;
                flag = 1;
            }
            node = st.top();
            st.pop();
            node = node->right;
        }
        return result;
    }
};
