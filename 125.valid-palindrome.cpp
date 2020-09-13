/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (42.94%)
 * Total Accepted:    89.5K
 * Total Submissions: 208.2K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 *
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 *
 * 示例 1:
 *
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 *
 *
 * 示例 2:
 *
 * 输入: "race a car"
 * 输出: false
 *
 *
 */
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        // format: A a 0
        // n = size - n
        string format;
        for(auto c : s) {
            if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')) {
                format.push_back(c);
            } else if((c >= 'A' && c <= 'Z'))
                format.push_back(c - 'A' + 'a');
        }
        auto length = format.size();
        bool result = 1;
        int i = 0;
        for (i = 0; i < length / 2; ++i) {
            if(format.at(i) != format.at(length - 1 - i)) {
                result = 0;
                return result;
            }
        }
        return result;
    }
};

// int main(void) {
//     Solution ins;
//     string s("A man, a plan, a canal: Panama");
//     int a = ins.isPalindrome(s);
//     cout << a << endl;

//     return 0;
// }
