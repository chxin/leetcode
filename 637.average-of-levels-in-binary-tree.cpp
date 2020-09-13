/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 *
 * https://leetcode-cn.com/problems/average-of-levels-in-binary-tree/description/
 *
 * algorithms
 * Easy (63.62%)
 * Total Accepted:    18.2K
 * Total Submissions: 28.3K
 * Testcase Example:  '[3,9,20,15,7]'
 *
 * 给定一个非空二叉树, 返回一个由每层节点平均值组成的数组.
 *
 * 示例 1:
 *
 * 输入:
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 输出: [3, 14.5, 11]
 * 解释:
 * 第0层的平均值是 3,  第1层是 14.5, 第2层是 11. 因此返回 [3, 14.5, 11].
 *
 *
 * 注意：
 *
 *
 * 节点值的范围在32位有符号整数范围内。
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> result;
        queue<TreeNode *> st;
        st.push(root);
        TreeNode * node = root;
        int level_node = 1;
        int next_node = 0;
        long sum = 0;
        double nums = 1;
        while(!st.empty()) {
            node = st.front();
            st.pop();
            level_node--;
            sum += node->val;
            // cout << level_node << " ";
            if(node->left != nullptr) {
                st.push(node->left);
                next_node++;
            }
            if(node->right != nullptr) {
                st.push(node->right);
                next_node++;
            }
            if(level_node == 0) {
                level_node = next_node;
                result.push_back(sum/nums);
                nums = next_node;
                sum = 0;
                next_node = 0;
            }
        }
        return result;

    }
};
