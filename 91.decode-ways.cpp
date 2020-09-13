/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.28%)
 * Total Accepted:    39.1K
 * Total Submissions: 168K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 *
 *
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 *
 * 示例 1:
 *
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 *
 *
 * 示例 2:
 *
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 *
 *
 */
// class Solution {
// public:
//     int numDecodings(string s) {
//         // single: 1
//         // double: [0, 26]
//         int result = 0;
//         recursion(s, 0, s.size(), result, 1);

//         return result;

//     }

//     void recursion(string & str, int pos, int str_size, int & result, int zero) {
//         if(pos >= str_size) {
//             if(zero != 0)
//                 ++result;
//         } else {
//             if(str.at(pos) != '0'){
//                 recursion(str, pos + 1, str_size, result, 1);
//                 if(pos + 2 <= str_size) {
//                     if((str.at(pos) - '0') * 10 + (str.at(pos + 1) - '0') <= 26) {
//                         recursion(str, pos + 2, str_size, result, 1);
//                     }
//                 }
//             } else {
//                 return;
//                 // if(pos + 1 < str_size){
//                 //     if(str.at(pos + 1) != '0') {
//                 //         recursion(str, pos + 2, str_size, result, 0);
//                 //     } else {
//                 //         return;
//                 //     }
//                 // } else {
//                 //     return;
//                 // }
//             }
//         }
//     }
// };
class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        vector<int> dp(s.size() + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (s[i - 1] != '0') dp[i] += dp[i - 1];
            if (i >= 2 && s.substr(i - 2, 2) <= "26" && s.substr(i - 2, 2) >= "10") {
                dp[i] += dp[i - 2];
            }
        }
        return dp.back();
    }
};
