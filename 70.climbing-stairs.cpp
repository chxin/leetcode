/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (48.09%)
 * Total Accepted:    193.9K
 * Total Submissions: 398.3K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 *
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 *
 * 注意：给定 n 是一个正整数。
 *
 * 示例 1：
 *
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 *
 * 示例 2：
 *
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 *
 *
 */
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) {
            return 0;
        } else if(n == 1) {
            return 1;
        } else if(n == 2) {
            return 2;
        }

        // return dp_loop(n);
        // return loop(n);
        // return climbStairs(n - 1) + climbStairs(n - 2);

        // vector<int> dp(n, 0);
        // dp[0] = 1;
        // dp[1] = 2;
        // return dp_recurse(n, dp);

    }
    int dp_loop(int n) {
        // 当vector访问越界时
        // 1. 下标[]赋值会显示SIGSEGV段错误,越界错误.
        // 2. at赋值会显示 terminate called after throwing an instance of ‘std::out_of_range’
        // at会进行下标越界检查，会增加程序的性能开销
        vector<int> result(n);
        result[0] = 1;
        result[1] = 2;
        for(int i = 2; i < n; ++i) {
            result[i] = result[i - 1] + result[i - 2];
        }
        return result[n - 1];
    }
    int loop(int n) {
        int last = 2;
        int last_last = 1;
        int result;
        for(int i = 2; i < n; ++i) {
            result = last + last_last;
            last_last = last;
            last = result;
        }
        return result;
    }
    int dp_recurse(int n, vector<int> & dp) {
        if(dp[n - 1] != 0) return dp[n - 1];
        dp[n - 1] = dp_recurse(n - 1, dp) + dp_recurse(n - 2, dp);
        return dp[n - 1];
    }
};
