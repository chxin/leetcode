/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 *
 * https://leetcode-cn.com/problems/merge-two-binary-trees/description/
 *
 * algorithms
 * Easy (75.43%)
 * Total Accepted:    47.2K
 * Total Submissions: 62.1K
 * Testcase Example:  '[1,3,2,5]\n[2,1,3,null,4,null,7]'
 *
 * 给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。
 *
 * 你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL
 * 的节点将直接作为新二叉树的节点。
 *
 * 示例 1:
 *
 *
 * 输入:
 * Tree 1                     Tree 2
 * ⁠         1                         2
 * ⁠        / \                       / \
 * ⁠       3   2                     1   3
 * ⁠      /                           \   \
 * ⁠     5                             4   7
 * 输出:
 * 合并后的树:
 * 3
 * / \
 * 4   5
 * / \   \
 * 5   4   7
 *
 *
 * 注意: 合并必须从两个树的根节点开始。
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == nullptr) return t2;
        if(t2 == nullptr) return t1;
        TreeNode * node1 = t1;
        TreeNode * node2 = t2;
        TreeNode * pre_node = t1;
        dfs(node1, node2, pre_node, 0);
        return t1;
    }

    void dfs(TreeNode * node1, TreeNode * node2, TreeNode * pre_node, int is_left) {
        if(node1 == nullptr && node2 == nullptr) {
            return;
        }
        if(node1 != nullptr && node2 != nullptr) {
            node1->val += node2->val;
            dfs(node1->left, node2->left, node1, 1);
            dfs(node1->right, node2->right, node1, 0);
            return;
        }
        if(node1 == nullptr) {
            if(is_left)
                pre_node->left = node2;
            else
                pre_node->right = node2;
            return;
        }
        if(node2 == nullptr) {
            return;
        }

    }
};
