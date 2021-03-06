/*
 * @lc app=leetcode.cn id=572 lang=cpp
 *
 * [572] 另一个树的子树
 *
 * https://leetcode-cn.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (43.84%)
 * Total Accepted:    28.3K
 * Total Submissions: 61.3K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s
 * 也可以看做它自身的一棵子树。
 *
 * 示例 1:
 * 给定的树 s:
 *
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 *
 *
 * 给定的树 t：
 *
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 *
 * 返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
 *
 * 示例 2:
 * 给定的树 s：
 *
 *
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 *
 *
 * 给定的树 t：
 *
 *
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 *
 *
 * 返回 false。
 *
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(t == nullptr) return 1;
        if(s == nullptr) return 0;
        bool flag = 0;
        dfs(s, t, flag);
        return flag;
    }

    void dfs(TreeNode * s, TreeNode * t, bool & flag) {
        if(flag == 1) return;
        if(same(s, t)) {
            flag = 1;
            return;
        }
        if(s->left != nullptr)
        dfs(s->left, t, flag);
        if(s->right != nullptr)
        dfs(s->right, t, flag);
    }

    bool same(TreeNode * s, TreeNode * t) {
        if(t == nullptr) {
            if(s == nullptr) {
                return 1;
            }
            return 0;
        }
        if(s == nullptr) {
            return 0;
        }
        if(s->val == t->val) {
            if(same(s->left, t->left)) {
                if(same(s->right, t->right)) {
                    return 1;
                }
            }
        }
        return 0;
    }
};
