/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长上升子序列
 *
 * https://leetcode-cn.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (43.92%)
 * Total Accepted:    77K
 * Total Submissions: 175.3K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * 给定一个无序的整数数组，找到其中最长上升子序列的长度。
 *
 * 示例:
 *
 * 输入: [10,9,2,5,3,7,101,18]
 * 输出: 4
 * 解释: 最长的上升子序列是 [2,3,7,101]，它的长度是 4。
 *
 * 说明:
 *
 *
 * 可能会有多种最长上升子序列的组合，你只需要输出对应的长度即可。
 * 你算法的时间复杂度应该为 O(n^2) 。
 *
 *
 * 进阶: 你能将算法的时间复杂度降低到 O(n log n) 吗?
 *
 */
class Solution {
public:
    int lengthOfLIS(vector<int> & nums) {
        int len = nums.size();
        if(len == 0) return 0;
        if(len == 1) return 1;
        vector<int> result(len, 1);
        result[0] = 1;
        int tmp = 0;

        for(int i = 1; i < len; ++i) {
            for(int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]) {
                    tmp = result[j] + 1;
                    result[i] = tmp > result[i] ? tmp : result[i];
                }
            }
        }

        int max = 0;
        for(auto i : result) {
            if(i > max) max = i;
        }
        return max;

    }
};
