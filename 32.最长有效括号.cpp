/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (29.77%)
 * Likes:    535
 * Dislikes: 0
 * Total Accepted:    42.7K
 * Total Submissions: 143.2K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */
#include<string>
#include<stack>
using namespace std;
// @lc code=start
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         if(s.size() < 2) return 0;
//         int length_max = 0;
//         int length = 0;
//         // stack push
//         stack<char> base;
//         stack<char> empty;
//         for(int i = 0; i < s.size(); ++i) {
//             base = empty;
//             length = 0;
//             func(s, base, length, i);
//             if(length_max < length) {
//                 length_max = length;
//             }
//             // i = length + i;
//         }
//         // inc n
//         return length_max;
//     }
//     void func(const string & s, stack<char> & base, int & length, int pos) {
//         // if(base.empty()) return length;
//         if(pos >= s.size()) return;

//         if(s.at(pos) == '(') {
//             base.push('(');
//             func(s, base, length, pos + 1);
//         }
//         if(s.at(pos) == ')') {
//             if(base.top() == '(') {
//                 length += 2;
//                 base.pop();
//                 func(s, base, length, pos + 1);
//             } else {
//                 return;
//             }
//         }
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()==0) return 0;
        int res=0;
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') st.push(i);
            else{
                st.pop();
                if(!st.empty()) res=max(res,i-st.top());
                else st.push(i);
            }
        }
        return res;
    }
};
// @lc code=end

