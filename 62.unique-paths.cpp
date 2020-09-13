/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (59.57%)
 * Total Accepted:    105.1K
 * Total Submissions: 173.7K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 *
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 *
 * 问总共有多少条不同的路径？
 *
 *
 *
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 *
 *
 *
 * 示例 1:
 *
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 *
 *
 * 示例 2:
 *
 * 输入: m = 7, n = 3
 * 输出: 28
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= m, n <= 100
 * 题目数据保证答案小于等于 2 * 10 ^ 9
 *
 *
 */
// 32bit int type is enough
class Solution {
public:
    int uniquePaths(int m, int n) {
        row = m;
        column = n;
        vector<int> result(m*n, 0);
        result[0] = 1;
        return dp_recurse(m*n-1, result);
    }

    int dp_recurse(int pos, vector<int> & result) {
        if(result[pos] != 0) return result[pos];
        if(pos % column == 0) return result[pos] = dp_recurse(pos - column, result);
        if(pos < column) return result[pos] = dp_recurse(pos - 1, result);
        return result[pos] = dp_recurse(pos - 1, result)  + dp_recurse(pos - column, result);
    }

private:
    int row;
    int column;
};