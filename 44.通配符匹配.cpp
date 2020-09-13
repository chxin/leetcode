/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 *
 * https://leetcode-cn.com/problems/wildcard-matching/description/
 *
 * algorithms
 * Hard (26.73%)
 * Likes:    284
 * Dislikes: 0
 * Total Accepted:    21.8K
 * Total Submissions: 81.3K
 * Testcase Example:  '"aa"\n"a"'
 *
 * 给定一个字符串 (s) 和一个字符模式 (p) ，实现一个支持 '?' 和 '*' 的通配符匹配。
 * 
 * '?' 可以匹配任何单个字符。
 * '*' 可以匹配任意字符串（包括空字符串）。
 * 
 * 
 * 两个字符串完全匹配才算匹配成功。
 * 
 * 说明:
 * 
 * 
 * s 可能为空，且只包含从 a-z 的小写字母。
 * p 可能为空，且只包含从 a-z 的小写字母，以及字符 ? 和 *。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * s = "aa"
 * p = "a"
 * 输出: false
 * 解释: "a" 无法匹配 "aa" 整个字符串。
 * 
 * 示例 2:
 * 
 * 输入:
 * s = "aa"
 * p = "*"
 * 输出: true
 * 解释: '*' 可以匹配任意字符串。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * s = "cb"
 * p = "?a"
 * 输出: false
 * 解释: '?' 可以匹配 'c', 但第二个 'a' 无法匹配 'b'。
 * 
 * 
 * 示例 4:
 * 
 * 输入:
 * s = "adceb"
 * p = "*a*b"
 * 输出: true
 * 解释: 第一个 '*' 可以匹配空字符串, 第二个 '*' 可以匹配字符串 "dce".
 * 
 * 
 * 示例 5:
 * 
 * 输入:
 * s = "acdcb"
 * p = "a*c?b"
 * 输入: false
 * 
 */
// #include <string>
// #include <vector>
// #include <iostream>
// using namespace std;
// // @lc code=start
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         // how to *
//         // since * can have mul candidates, so use recursive
        
//         // if(s.empty()) return 0;
//         int result = 0;
//         func(s, p, 0, 0, result);
//         return result;

//     }

//     void func(string &s, string &p, int i, int m, int & result) {
//         if(m >= p.size()) {
//             if(i == s.size()) {
//                 result = 1;
//                 return;
//             } else {
//                 // result = 0;
//                 return;
//             }
//         } else {
//             if(i >= s.size()) {
//                 if(p.at(m) != '*'){
//                     return;
//                 } else if(m == p.size() - 1) {
//                     result = 1;
//                     return;
//                 } else {
//                     func(s, p, i, ++m, result);
//                     return;
//                 }
//             } else{
//             if(p.at(m) == '*') {
//                 if(m < p.size() - 1) { // end with '*'
//                     if(p.at(m + 1) == '?') {
//                         int tmp1 = m + 1;
                        
//                         while(p.at(tmp1) == '?' && tmp1 < p.size() - 1) {
//                             tmp1++; // ? counts
//                         }
//                         if(tmp1 == p.size() - 1 && p.at(p.size() - 1) == '?') {
//                             if(tmp1 - m <= s.size() - i) {
//                                 result = 1;
//                                 return;
//                             }
//                             return;
//                         }
//                         m = tmp1 - 1;
//                         ++i;
//                     }
//                     auto tmp = s.find(p.at(m + 1), i);
//                     vector<int> pos;
//                     while(tmp != string::npos) {
//                         i = tmp + 1;
//                         pos.push_back(tmp);
//                         if(i >= s.size()) {
//                             break;
//                         }
//                         tmp = s.find(p.at(m + 1), i);
//                     }
//                     if(pos.empty()) {
//                         func(s, p, i, m + 1, result);
//                     } else {
//                         for(auto w : pos) {
//                             func(s, p, w + 1, m + 2, result);
//                         }
//                     }
//                 } else {
//                     // return 1;
//                     result = 1;
//                     return;
//                 }
//             } else if(p.at(m) == '?') {
//                 func(s, p, i + 1, m + 1, result);
//             } else {
//                 if(p.at(m) == s.at(i)){
//                     func(s, p, i + 1, m + 1, result);
//                 } else {
//                     // m = p.size();
//                     // i = 0;
//                     return;
//                 }
//             }
//             }
//         }
//     }
// };

// int main(void) {
//     string s("c");
//     string p("*?*");

//     Solution wildcard;
//     bool result = wildcard.isMatch(s, p);
//     cout << result;
//     return 0;
// }

// DP
// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         int m = s.length(), n = p.length();
// 	    int count = 0;  //*的个数
// 	    for (int i = 0; i < n; i++)
// 	        if (p[i] == '*') 
// 	            count++;    //统计*的个数
        
// 	    if (count == 0 && m != n)	return false;   //如果没有*且m!=n，肯定不匹配
// 	    else if (n - count > m)	return false;   //如果不是*的个数>m，则相等于没有*还是大于m，不匹配
 
// 	    bool* match = new bool[m+1];   //默认全为false
// 	    match[0] = true;    //第一个设为true
// 	    for (int i = 0; i < n; i++) {
// 	        if (p[i] == '*')    
//                 //如果为*，则s对应的之后所有数据默认匹配
// 	            for (int j = 0; j < m; j++) 
// 	                    match[j+1] = match[j] || match[j+1]; 
// 	        else {  
//                 //如果不为*，则用最后一位匹配
// 	            for (int j = m-1; j >= 0; j--)
// 	                match[j+1] = (p[i] == '?' || p[i] == s[j]) && match[j];
// 	            match[0] = false;
// 	        }
// 	    }
//         return match[m];
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(), n=p.size();
        vector<vector<int> >dp(m+1, vector<int>(n+1, 0));
        dp[0][0] = 1;//初始化
        for (int j = 1; j <= n; ++j){//初始化
            if (p[j-1] == '*') dp[0][j] = dp[0][j-1];
        }
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                if (p[j-1] != '*'){
                    if (p[j-1] == s[i-1] || p[j-1] == '?')
                        dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = dp[i-1][j] ||dp[i][j-1] || dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};

// @lc code=end

