/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.69%)
 * Total Accepted:    76.5K
 * Total Submissions: 107.2K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
 *
 * 示例:
 *
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * 输出: [3,2,1]
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        // pot(root, result);
        pot_iteration(root, result);
        return result;
    }
    void pot(TreeNode * node, vector<int> & v) {
        if(node == nullptr) return;
        pot(node->left, v);
        pot(node->right, v);
        v.push_back(node->val);
    }
    void pot_iteration(TreeNode * node, vector<int> & v) {
        map<TreeNode *, bool> node_status;
        stack<TreeNode *> s;
        if(node == nullptr) return;
        if(node->left == nullptr && node->right == nullptr) node_status[node] = 0;
        else node_status[node] = 1;
        s.push(node);
        while(!s.empty()) {
            while(node != nullptr) {
                if(node->left == nullptr && node->right == nullptr) node_status[node] = 0;
                else node_status[node] = 1;
                s.push(node);
                node = node->left;
            }
            node = s.top();
            while(!s.empty() && node_status[node] == 0) {
                s.pop();
                if(s.empty()) return;
                v.push_back(node->val);
                node = s.top();
            }
            if(node_status[node] == 1) {
                node_status[node] = 0;
            }
            node = node->right;
        }
    }
};
