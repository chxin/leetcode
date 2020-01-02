/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
using std::string;
// @lc code=start
class Solution {
public:
    bool isPalindrome(string & str, int start_pos, int end_pos) { // &
        // 从头到尾
        int flag = 1;
        for(int i = 0; i <= (end_pos - start_pos)/2; ++i) { // ()/2
            if(str.at(i+start_pos) != str.at(end_pos - i)){
                flag = 0;
                break;
            }
        }
        return flag;
    }
    string longestPalindrome(string s) {
        // 从头到尾遍历
        // 从尾到当前位置
        // 判断是否是回文字符串
        int string_length = s.length();
        int length_max = 0; // =1 -> =0
        int pos_s = 0;
        int pos_e = 0;
        for(int i = 0; i < string_length - length_max; ++i) {
            for(int m = string_length - 1; m > i; --m) {
                if(isPalindrome(s, i, m)) {
                    // std::cout << i << m;
                    if(m - i > length_max) {
                        length_max = m - i;
                        pos_s = i;
                        pos_e = m;
                    }
                }
            }
        }
        return s.substr(pos_s, length_max+1);//+1
    }
};
// @lc code=end

