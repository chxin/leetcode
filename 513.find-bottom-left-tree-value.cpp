/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 *
 * https://leetcode-cn.com/problems/find-bottom-left-tree-value/description/
 *
 * algorithms
 * Medium (68.79%)
 * Total Accepted:    13.8K
 * Total Submissions: 19.8K
 * Testcase Example:  '[2,1,3]'
 *
 * 给定一个二叉树，在树的最后一行找到最左边的值。
 *
 * 示例 1:
 *
 *
 * 输入:
 *
 * ⁠   2
 * ⁠  / \
 * ⁠ 1   3
 *
 * 输出:
 * 1
 *
 *
 *
 *
 * 示例 2:
 *
 *
 * 输入:
 *
 * ⁠       1
 * ⁠      / \
 * ⁠     2   3
 * ⁠    /   / \
 * ⁠   4   5   6
 * ⁠      /
 * ⁠     7
 *
 * 输出:
 * 7
 *
 *
 *
 *
 * 注意: 您可以假设树（即给定的根节点）不为 NULL。
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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode * > q;
        q.push(root);
        TreeNode * node = root;
        int result = root->val;
        int cur = 1;
        int next = 0;
        while(!q.empty()) {
            node = q.front();
            q.pop();
            --cur;
            if(node->left != nullptr) {
                q.push(node->left);
                ++next;
            }
            if(node->right != nullptr) {
                q.push(node->right);
                ++next;
            }
            if(cur <= 0) {
                if(!q.empty()) {
                    result = (q.front())->val;
                }
                cur = next;
                next = 0;
            }
        }
        return result;

    }
};
