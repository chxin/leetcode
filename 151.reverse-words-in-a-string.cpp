/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 翻转字符串里的单词
 *
 * https://leetcode-cn.com/problems/reverse-words-in-a-string/description/
 *
 * algorithms
 * Medium (36.82%)
 * Total Accepted:    36.9K
 * Total Submissions: 99.7K
 * Testcase Example:  '"the sky is blue"'
 *
 * 给定一个字符串，逐个翻转字符串中的每个单词。
 *
 *
 *
 * 示例 1：
 *
 * 输入: "the sky is blue"
 * 输出: "blue is sky the"
 *
 *
 * 示例 2：
 *
 * 输入: "  hello world!  "
 * 输出: "world! hello"
 * 解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 *
 *
 * 示例 3：
 *
 * 输入: "a good   example"
 * 输出: "example good a"
 * 解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 说明：
 *
 *
 * 无空格字符构成一个单词。
 * 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
 * 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
 *
 *
 *
 *
 * 进阶：
 *
 * 请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
 *
 */
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        // traverse: get words
        // print reverse
        vector<string> words;
        string::size_type start = 0;
        string::size_type end = 0;
        for(auto c : s) {
            ++end;
            if(c == ' ') {
                if(end - start > 1) {
                    words.push_back(s.substr(start, end - start - 1));
                } else {

                }
                start = end;
                // ++end;
            } else {
                // ++end;
            }
        }

        if(end - start >= 1) {
            words.push_back(s.substr(start, end - start));
        }

        string result;
        for(int i = words.size() - 1; i >= 0; --i) {
            result += words.at(i);
            if(i != 0)
                result += ' ';
        }
        return result;
    }
};
// int main(void) {
//     Solution ins;
//     string s("the sky is blue");
//     cout << ins.reverseWords(s);

//     return 0;
// }
