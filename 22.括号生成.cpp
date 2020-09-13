/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (73.45%)
 * Likes:    776
 * Dislikes: 0
 * Total Accepted:    79.5K
 * Total Submissions: 108.2K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        //  base 逐渐增长 二叉树： 树？ 栈？string
        //  candidate
        //  剪树？

        // cases： n = 0, 1(3)

        // Ot：
        // Os：
        
        
        vector<string> result;
        // if(n == 0) return result;
        func(n, n, "", result);
        return result;
        // vector<string> base = {"("};
        // vector<string> candidate = {"(", ")"};
        // int count = 1;

        // for(int i = 0; i < 2 * n - 1; ++i) {
        //     if(count < n){// n?
        //         for(auto it = base.begin(); it < base.end(); ++it) {
        //             (*it).push_back('(');
        //             (*it).push_back(')');
        //         }
        //     }
        // }
    }

    // 递归函数
    void func(int left, int right, string base, vector<string> &result) {
        // end
        if(left > right) return;
        if(left == 0 && right == 0) {
            result.push_back(base);
        }
        if(left > 0) {
            func(left - 1, right, base + '(', result);
        }

        if(right > 0) {
            func(left, right - 1, base + ')', result);
        }
    }
};
// @lc code=end

