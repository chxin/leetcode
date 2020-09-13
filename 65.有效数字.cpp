/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 *
 * https://leetcode-cn.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (18.16%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    10.5K
 * Total Submissions: 56.8K
 * Testcase Example:  '"0"'
 *
 * 验证给定的字符串是否可以解释为十进制数字。
 * 
 * 例如:
 * 
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * 说明: 我们有意将问题陈述地比较模糊。在实现代码之前，你应当事先思考所有可能的情况。这里给出一份可能存在于有效十进制数字中的字符列表：
 * 
 * 
 * 数字 0-9
 * 指数 - "e"
 * 正/负号 - "+"/"-"
 * 小数点 - "."
 * 
 * 
 * 当然，在输入中，这些字符的上下文也很重要。
 * 
 * 更新于 2015-02-10:
 * C++函数的形式已经更新了。如果你仍然看见你的函数接收 const char * 类型的参数，请点击重载按钮重置你的代码。
 * 
 */
#include<string>
#include<iostream>
#include<vector>

using namespace std;
// @lc code=start
// class Solution {
// public:
//     bool isNumber(string s) {
//         // remove blank front and back
//         // find blank
//         // find -+ font or after e, pure num, no point after
//         // find e not fisrt and last
//         // find point
//         string::size_type i = 0;
//         int m = 0;
//         for(i = 0; i < s.size(); ++i) {
//             if(s.at(i) != ' ') break;
//         }
//         for(m = s.size() - 1; m >= 0; --m) {
//             if(s.at(m) != ' ') break;
//         }
//         string sub = s.substr(i, m - i + 1);
//         if(sub.empty()) return 0;
//         vector<int> vector_pos_e;
//         vector<int> vector_pos_sign;
//         vector<int> vector_pos_point;
//         int pos = 0;
//         for(auto c : sub) {
//             if(c == 'e') {
//                 vector_pos_e.push_back(pos);
//                 // cout << 1;
//             } else if(c == '+' || c == '-') {
//                 vector_pos_sign.push_back(pos);
//                 // cout << 2;
//             } else if(c == '.') {
//                 vector_pos_point.push_back(pos);
//                 // cout << 3;
//             } else if(c == ' '){
//                 // cout << 4;
//                 return 0;
//             } else if(c - '0' > 9 || c - '0' < 0) {
//                 // cout << 5;
//                 return 0;
//             }
//             pos++;
//         }
//         // cout << sub;
//         if(vector_pos_e.size() > 1) return 0;
//         if(vector_pos_point.size() > 1) return 0;

//         string::size_type pos_e = string::npos;
//         string::size_type pos_point = 0;
//         if(vector_pos_e.size() == 1) {
//             if(vector_pos_e.at(0) != 0 && vector_pos_e.at(0) != sub.size() - 1) {
//                 pos_e = vector_pos_e.at(0);
//             } else {
//                 return 0;
//             }
//         } 
//         if(vector_pos_point.size() == 1) {
//             if(vector_pos_point.at(0) == sub.size() - 1 && vector_pos_point.at(0) == 0)
//                 return 0;
//             else if(vector_pos_point.at(0) == sub.size() - 1 && vector_pos_point.at(0) - 1 == pos_e) {
//                 return 0;
//             } else {
//                 pos_point = vector_pos_point.at(0);
//                 if(pos_point - 1 > pos_e) return 0;
//             }
//         }

        

//         if(vector_pos_sign.size() > 2) return 0;
//         if(vector_pos_sign.size() == 1) {
//             if(vector_pos_sign.at(0) != 0 && vector_pos_sign.at(0) < pos_e)
//                 return 0;
//             if(vector_pos_sign.at(0) == sub.size() - 1)
//                 return 0;
//             if(pos_point - 1 == vector_pos_sign.at(0) && pos_point == sub.size() - 1)
//                 return 0;
//         }
//         if(vector_pos_sign.size() == 2) {
//             if(vector_pos_sign.at(0) != 0 || vector_pos_sign.at(1) < pos_e)
//                 return 0;
//         }


//         return 1;

//     }
// };

// int main(void) {
//     Solution ins;
//     string s("2e0");
//     auto result = ins.isNumber(s);
//     cout << result;
// }
 class Solution {
 public:
     bool isNumber(string s) {
         bool num = false, numAfterE = true, dot = false, exp = false, sign = false;
         int n = s.size();
         for (int i = 0; i < n; ++i) {
             if (s[i] == ' ') {
                 if (i < n - 1 && s[i + 1] != ' ' && (num || dot || exp || sign)) return false;
             } else if (s[i] == '+' || s[i] == '-') {
                 if (i > 0 && s[i - 1] != 'e' && s[i - 1] != ' ') return false;
                 sign = true;
             } else if (s[i] >= '0' && s[i] <= '9') {
                 num = true;
                 numAfterE = true;
             } else if (s[i] == '.') {
                 if (dot || exp) return false;
                 dot = true;
             } else if (s[i] == 'e') {
                 if (exp || !num) return false;
                 exp = true;
                 numAfterE = false;
             } else return false;
         }
         return num && numAfterE;
     }
 };
// @lc code=end

