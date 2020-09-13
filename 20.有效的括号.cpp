/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (40.92%)
 * Likes:    1412
 * Dislikes: 0
 * Total Accepted:    213.4K
 * Total Submissions: 520.9K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include<string>
#include<vector>
using namespace std;
// cases：
// null
// []
// ([)]
class Solution {
public:
    bool isValid(string s) {
        // 是否闭合
        // cases: (()(()))
        // find index
        // string symbols = "(){}[]";
        // string::size_type pos = 0;
        // vector<int> tmp;
        // vector<int> tmp2;
        // for(auto it = symbols.begin(); it < symbols.end(); ++it) {
        //     tmp.empty();
        //     while(s.find(*it, pos) != string::npos {
        //         tmp.push_back(pos);
        //         pos = s.find(*it, pos);
        //     }
        //     ++it;
        //     tmp2.empty();
        //     while(s.find(*it, pos) != string::npos) {
        //         tmp2.push_back(pos);
        //         pos = s.find(*it,pos);
        //     }
        //     if(tmp.size() != tmp.size()) return 0;
        //     for(int i = 0; i < tmp.size(); ++i) {
        //         if(tmp.at(i) > tmp2.at(i)) return 0;
        //     }
        // }
        // // 是否错位
        stack<char> parentheses;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{') 
                    parentheses.push(s[i]);
                else {
                    if (parentheses.empty()) return false;
                    if (s[i] == ')' && parentheses.top() != '(') return false;
                    if (s[i] == ']' && parentheses.top() != '[') return false;
                    if (s[i] == '}' && parentheses.top() != '{') return false;
                    parentheses.pop();
                }
            }
            return parentheses.empty();
    }
};
// @lc code=end

