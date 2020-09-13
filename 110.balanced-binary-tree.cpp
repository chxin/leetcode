/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 *
 * https://leetcode-cn.com/problems/balanced-binary-tree/description/
 *
 * algorithms
 * Easy (50.83%)
 * Total Accepted:    66.7K
 * Total Submissions: 130.1K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，判断它是否是高度平衡的二叉树。
 *
 * 本题中，一棵高度平衡二叉树定义为：
 *
 *
 * 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
 *
 *
 * 示例 1:
 *
 * 给定二叉树 [3,9,20,null,null,15,7]
 *
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 *
 * 返回 true 。
 *
 * 示例 2:
 *
 * 给定二叉树 [1,2,2,3,3,null,null,4,4]
 *
 * ⁠      1
 * ⁠     / \
 * ⁠    2   2
 * ⁠   / \
 * ⁠  3   3
 * ⁠ / \
 * ⁠4   4
 *
 *
 * 返回 false 。
 *
 *
 *
 */
/**
 * Definition for a binary tree node.
 * strict TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int balanced = 1;
        dfs(root, balanced);
        return balanced;
    }

    // int iteration() {
    //     TreeNode * node = root;
    //     stack<TreeNode *> node_stack;
    //     node_stack.push(nullptr);
    //     int depth = 0;
    //     int max_depth = 0;
    //     while(!node_stack.empty()) {
    //         while(node != nullptr) {
    //             // 金公；木母；刀圭
    //             node_stack.push(node);
    //             cout << node->val;
    //             node = node->left;
    //             ++depth;
    //         }
    //         if(max_depth < depth) max_depth = depth;
    //         // cout << "d" << depth << "m" << max_depth;
    //         node = node_stack.top();
    //         if(node == nullptr) break;
    //         if(depth + 1 < max_depth) return 0;
    //         node = node->right;
    //         node_stack.pop();
    //         --depth;
    //     }
    //     return 1;

    // }

    int dfs(TreeNode * node, int & balanced) {
        if(balanced == 0) {
            return 0;
        }
        if(node == nullptr) {
            return 1;
        }
        int dl = dfs(node->left, balanced);
        int dr = dfs(node->right, balanced);
        if(dl > dr + 1 || dr > dl + 1) {
            balanced = 0;
        }
        return dl > dr ? dl + 1: dr + 1;
    }

};
