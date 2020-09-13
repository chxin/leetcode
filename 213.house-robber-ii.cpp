/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (36.92%)
 * Total Accepted:    34.7K
 * Total Submissions: 91.9K
 * Testcase Example:  '[2,3,2]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 *
 * 示例 1:
 *
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 *
 *
 * 示例 2:
 *
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        //int ans=0;
        int dp[n + 1];
        dp[0] = 0;          //第0间

        //不偷第一间
        dp[1] = 0;
        int ans = nums[0];
        for(int i = 2; i <= n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
            ans = max(ans, dp[i]);
        }

        //偷第一间
        dp[1] = nums[0];
        for(int i = 2; i < n; ++i) {
            dp[i] = max(dp[i - 2] + nums[i - 1], dp[i - 1]);
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};
// class Solution {
// public:
//     int rob(vector<int> & nums) {
//         // f(n) = f(n-1) if 1
//         // f(n) = f(n-2) if 1
//         // f(n) = f(n-1) if 2

//         // f(n) = f(n-2) + n if 2 or 3

//         int len = nums.size();
//         if(len == 0) return 0;
//         if(len == 1) return nums[0];
//         vector<int> dp(len, -1);
//         dp[0] = 0;
//         dp[1] = nums[0];
//         int sum1 = dp_recurse(vector<int> tmp (nums.begin(), nums.end()-1), dp, len - 1);
//         vector<int> dp2(len, -1);
//         dp2[0] = 0;
//         dp2[1] = nums[1];
//         int sum2 = dp_recurse(vector<int> tmp (nums.begin()+1, nums.end()), dp2, len - 1);
//         return sum1 > sum2 ? sum1 : sum2;
//     }
//     int dp_recurse(vector<int> & nums, vector<int> & dp, int pos) {
//         if(dp[pos] != -1) return dp[pos];
//         int n1 = dp_recurse(nums, dp, pos - 1);
//         int n2 = dp_recurse(nums, dp, pos - 2) + nums[pos];
//         int bigger = n1 > n2 ? n1 : n2;
//         dp[pos] = bigger;
//         return bigger;
//     }
// };
