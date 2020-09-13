/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.56%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    75.3K
 * Total Submissions: 229.9K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty()) return 0;
        int n = 0;

        auto pos = s.rfind(" ");
        while(pos == s.size() - 1 - n && pos != 0) {
            pos = s.rfind(" ", pos - 1);
            n++;
        }
        if(pos == string::npos)
            return s.size() - n;
        else if(pos == 0)
            return s.size() - n - 1;
        else
            return s.size() - n - 1 - pos;
    }


};
    // int main(void) {
    //     Solution a;
    //     string ins = "a   ";
    //     cout << a.lengthOfLastWord(ins);
    //     return 0;
    // }
// @lc code=end

