/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 *
 * https://leetcode-cn.com/problems/house-robber/description/
 *
 * algorithms
 * Easy (43.54%)
 * Total Accepted:    114.6K
 * Total Submissions: 256.3K
 * Testcase Example:  '[1,2,3,1]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 *
 * 示例 1:
 *
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 偷窃 1 号房屋 (金额 = 1) ，然后偷窃 3 号房屋 (金额 = 3)。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 * 示例 2:
 *
 * 输入: [2,7,9,3,1]
 * 输出: 12
 * 解释: 偷窃 1 号房屋 (金额 = 2), 偷窃 3 号房屋 (金额 = 9)，接着偷窃 5 号房屋 (金额 = 1)。
 * 偷窃到的最高金额 = 2 + 9 + 1 = 12 。
 *
 *
 */
class Solution {
public:
    int rob(vector<int> & nums) {
// f(n) = f(n-1) or f(n-2) + n
        int n1 = nums.size();
        if(n1 == 0) return 0;
        if(n1 == 1) return nums[0];
        int bigger = nums[1] > nums[0] ? nums[1] : nums[0];
        if(n1 == 2) return bigger;
        vector<int> result(n1, -1);
        result[0] = nums[0];
        result[1] = bigger;
        return dp_recurse(nums, result, n1 - 1);
    }
    int dp_recurse(vector<int> & nums, vector<int> & result, int pos) {
        if(result[pos] != -1) return result[pos];
        int n1 = dp_recurse(nums, result, pos - 1);
        int n2 = dp_recurse(nums, result, pos - 2) + nums[pos];
        int bigger = n1 > n2 ? n1 : n2;
        result[pos] = bigger;
        return bigger;
    }
};
