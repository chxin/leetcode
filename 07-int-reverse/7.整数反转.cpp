/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (33.37%)
 * Likes:    1566
 * Dislikes: 0
 * Total Accepted:    247.5K
 * Total Submissions: 741.3K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−2^31,  2^31 − 1]。请根据这个假设，如果反转后整数溢出那么就返回
 * 0。
 * 
 */
#include <string>
using namespace std;
// @lc code=start
class Solution {
public:
    int reverse(long long x) {
        // 符号位
        // 各位
        // 字符串反转
        // 变整数
        // 加符号位
        if(x > INT32_MAX || x < INT32_MIN) // new add
            return 0; // new add

        string s_tmp;
        if(x < 0){
            s_tmp.push_back(1);
            x = -x;
        } else {
            s_tmp.push_back(0);
            x = x;
        }

        long long dividend = 1; // int -> long long
        while(x / dividend){
            s_tmp.push_back((x / dividend) % 10);
            dividend *= 10;
        }
        // cout << s_tmp;

        string s;
        for(auto it = --s_tmp.end(); it != s_tmp.begin(); --it){
            s.push_back(*it);
        }
        // cout << s;

        long long result = 0;  // int -> long 
        long long mul = 1;     // int -> long
        for(char c : s) {
            result += (c) * mul;
            mul *= 10;
        }
        
        if(s_tmp[0] == 1){
            result = -result;
        } else {
            result = result;
        }
        
        if(result > INT32_MAX || result < INT32_MIN) // new add
            result = 0; // new add

        return result;
    }
};
// @lc code=end

