/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 *
 * https://leetcode-cn.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (55.15%)
 * Total Accepted:    22.4K
 * Total Submissions: 40.3K
 * Testcase Example:  '2'
 *
 * 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。
 *
 * 示例 1:
 *
 * 输入: 2
 * 输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 *
 * 示例 2:
 *
 * 输入: 10
 * 输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 *
 * 说明: 你可以假设 n 不小于 2 且不大于 58。
 *
 */
// 2: 1 1 = 1
// 3: 1 2 = 2
// 4: 1 3 = 3; 2 2 = 4
// 5: 1 4 = 4; 2 3 = 6
// 6: 1 5 = 5; 2 4 = 8; 3 3 = 9
// 7: 1 6 = 6; 2 5 = 10; 3 4 = 12;
// 8: 1 7 = 7; 2 6 = 12; 3 5 = 15; 4 4 = 16
// f(n) = f(n - 2) * 2
// f(n) = f(n - 3) * 3
// n = 3m; f(n) = f(n - 3) * 3
// n = 3m + 1 = 3(m - 1) + 4
// n = 3m + 2; f(n) = f(n - 2) * 2 = f(n - 5) * 3 * 2
#include <cmath>
class Solution {
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;
        int a = n / 3;
        int b = n % 3;
        int c = 0;
        if(b == 0) c = 3;
        if(b == 1) c = 4;
        if(b == 2) c = 6;
        int result = pow(3, a - 1);
        result *= c;
        return result;
    }
};
