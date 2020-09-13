/*
 * @lc app=leetcode.cn id=543 lang=cpp
 *
 * [543] 二叉树的直径
 *
 * https://leetcode-cn.com/problems/diameter-of-binary-tree/description/
 *
 * algorithms
 * Easy (48.88%)
 * Total Accepted:    45.8K
 * Total Submissions: 92.2K
 * Testcase Example:  '[1,2,3,4,5]'
 *
 * 给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。
 *
 *
 *
 * 示例 :
 * 给定二叉树
 *
 * ⁠         1
 * ⁠        / \
 * ⁠       2   3
 * ⁠      / \
 * ⁠     4   5
 *
 *
 * 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。
 *
 *
 *
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
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
    int diameterOfBinaryTree(TreeNode* root) {
        // 叶子结点
        // 两个叶子结点的距离怎么算？ 有公共父节点，无公共父节点是两者之和
        // 最深的结点。该结点到其它所有叶子结点的距离
        int max = 0;
        dfs(root, max);
        return max;
    }
    int dfs(TreeNode * node, int & max) {
        if(node == nullptr) return 0;
        int dl = dfs(node->left, max);
        int dr = dfs(node->right, max);
        if(dl + dr > max) {
            max = dl + dr;
        }
        return dl > dr ? dl + 1: dr + 1;
    }
};
