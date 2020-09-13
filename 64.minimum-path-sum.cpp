/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (65.05%)
 * Total Accepted:    87.3K
 * Total Submissions: 133.2K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 *
 * 说明：每次只能向下或者向右移动一步。
 *
 * 示例:
 *
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 *
 *
 */
class Solution {
public:
    int minPathSum(vector<vector<int>> & grid) {
        row = grid.size();
        column = grid[0].size();
        if(row < 1 && column < 1) return 0;
        vector<int> result(row * column, -1);
        result[0] = grid[0][0];
        return dp_recurse(grid, result, row * column - 1);
    }

    // 只考虑往右下方向走，不用考虑左上方向
    int dp_recurse(vector<vector<int>> & grid, vector<int> & result, int pos) {
        // if(pos < 0) return 0;
        if(result[pos] != -1) return result[pos];

        int n1 = INT_MAX;
        int n2 = INT_MAX;
        if(pos % column != 0)
            n1 = dp_recurse(grid, result, pos - 1);
        if(pos >= column)
            n2 = dp_recurse(grid, result, pos - column);
        int smaller = n1 < n2 ? n1 : n2;
        result[pos] = smaller + grid[pos / column][pos % column];
        return result[pos];
    }
private:
    int row;
    int column;
};
