/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (39.57%)
 * Likes:    371
 * Dislikes: 0
 * Total Accepted:    135.2K
 * Total Submissions: 341.7K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start

#include<string>
using namespace std;
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(haystack.size() < needle.size()) return -1;
        if(needle.empty() == 1) return 0;
        int flag = 1;
        int result = 0;
        
        for (auto it = haystack.begin(); it <= haystack.end() - needle.size() && flag == 1; it++)
        {
            if(*it == needle.at(0)) {
                flag = 0;
                for (auto it2 = needle.begin(), it3 = it; it2 < needle.end() && it3 < haystack.end(); it2++, it3++)
                {
                    if(*it2 != *it3) {
                        flag = 1;
                        break;
                    }
                }
                
            }
            result = it - haystack.begin();
            // cout << result << endl;
        }
        if(flag == 1) return -1;
        return result;
    }
};
// @lc code=end

