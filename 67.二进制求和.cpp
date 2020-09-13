/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (52.19%)
 * Likes:    324
 * Dislikes: 0
 * Total Accepted:    69.6K
 * Total Submissions: 133.2K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */
#include <string>
#include <iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int a_size = a.size();
        int b_size = b.size();
        int max_size = 0;
        if(a_size > b_size) max_size = a_size;
        else max_size = b_size;

        int carrier = 0;
        int sum = 0;
        string result;
        for(int i = 0; i < max_size; ++i) {
            if(i < a_size) {
                sum = a[a_size - i - 1] - '0' + carrier;
            } else {
                sum = carrier;
            }

            if(i < b_size) {
                sum += b[b_size - i - 1] - '0';
            } else {
                sum = sum;
            }
            
            if(sum > 1) {
                carrier = 1;
                result.push_back(sum - 2);
            } else {
                carrier = 0;
                result.push_back(sum);
            }
        }
        if(carrier == 1)
            result.push_back('\1');

        string result_reverse;
        int size = result.size();
        for(int m = 0; m < size; ++m)
            result_reverse.push_back(result.at(size - 1 - m) + '0');

        return result_reverse;
    }
};

// int main(void) {
//     string a("11");
//     string b("1");
//     Solution ins;
//     cout << ins.addBinary(a, b);
// }
// @lc code=end

