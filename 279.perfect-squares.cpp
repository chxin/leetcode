/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 *
 * https://leetcode-cn.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (54.96%)
 * Total Accepted:    61.8K
 * Total Submissions: 109.6K
 * Testcase Example:  '12'
 *
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 *
 * 示例 1:
 *
 * 输入: n = 12
 * 输出: 3
 * 解释: 12 = 4 + 4 + 4.
 *
 * 示例 2:
 *
 * 输入: n = 13
 * 输出: 2
 * 解释: 13 = 4 + 9.
 *
 */

// 1: 1
// 2: 1, 1: 2
// 3: 1, 1, 1: 3
// 4: 1
// 5: 4, 1: 2
// 6: 4, 1, 1: 3
// 7: 4
// 8: 4, 4: 2
// 9: 1
// 10: 9, 1: 2
// 11: 9, 1, 1: 3
// 12: 9
// (n+x)2 - (n)2 = 2nx+x2 < 2n + 1: x < 1
// n2: n=1 3 1 n=2 5 4 n=3 7 9
// (n+1)2 - (n-1)2 = 4n
class Solution {
public:
    int numSquares(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        vector<int> result(n + 1, INT_MAX);
        result[0] = 0;
        result[1] = 1;
        for(int i = 2; i <= n; ++i) {
            for(int j = 1; j * j <= i; ++j) {
                int tmp = result[i - j * j] + 1;
                if(tmp < result[i])
                    result[i] = tmp;
            }
        }
        return result.back();
        // return result[4];
    }
};
