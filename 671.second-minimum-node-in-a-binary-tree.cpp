/*
 * @lc app=leetcode.cn id=671 lang=cpp
 *
 * [671] 二叉树中第二小的节点
 *
 * https://leetcode-cn.com/problems/second-minimum-node-in-a-binary-tree/description/
 *
 * algorithms
 * Easy (45.91%)
 * Total Accepted:    10.8K
 * Total Submissions: 23.3K
 * Testcase Example:  '[2,2,5,null,null,5,7]'
 *
 * 给定一个非空特殊的二叉树，每个节点都是正数，并且每个节点的子节点数量只能为 2 或
 * 0。如果一个节点有两个子节点的话，那么这个节点的值不大于它的子节点的值。 
 *
 * 给出这样的一个二叉树，你需要输出所有节点中的第二小的值。如果第二小的值不存在的话，输出 -1 。
 *
 * 示例 1:
 *
 *
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   5
 * ⁠    / \
 * ⁠   5   7
 *
 * 输出: 5
 * 说明: 最小的值是 2 ，第二小的值是 5 。
 *
 *
 * 示例 2:
 *
 *
 * 输入:
 * ⁠   2
 * ⁠  / \
 * ⁠ 2   2
 *
 * 输出: -1
 * 说明: 最小的值是 2, 但是不存在第二小的值。
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
    int findSecondMinimumValue(TreeNode* root) {
        if(root == nullptr) return -1;
        vector<int> v;
        dfs(root, root->val, v);
        if(v.empty()) return -1;
        int result = v.front();
        for(auto i : v) {
            if(result > i) result = i;
        }

        return result;
    }

    void dfs(TreeNode * node, int num, vector<int> & v) {
        if(node == nullptr) {
            return;
        }
        if(node->val > num) {
            v.push_back(node->val);
            return;
        }
        dfs(node->left, node->val, v);
        dfs(node->right, node->val, v);
    }
};
