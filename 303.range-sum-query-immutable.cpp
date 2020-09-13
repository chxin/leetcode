/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 *
 * https://leetcode-cn.com/problems/range-sum-query-immutable/description/
 *
 * algorithms
 * Easy (60.54%)
 * Total Accepted:    39.6K
 * Total Submissions: 64.4K
 * Testcase Example:  '["NumArray","sumRange","sumRange","sumRange"]\n' +
  '[[[-2,0,3,-5,2,-1]],[0,2],[2,5],[0,5]]'
 *
 * 给定一个整数数组  nums，求出数组从索引 i 到 j  (i ≤ j) 范围内元素的总和，包含 i,  j 两点。
 *
 * 示例：
 *
 * 给定 nums = [-2, 0, 3, -5, 2, -1]，求和函数为 sumRange()
 *
 * sumRange(0, 2) -> 1
 * sumRange(2, 5) -> -1
 * sumRange(0, 5) -> -3
 *
 * 说明:
 *
 *
 * 你可以假设数组不可变。
 * 会多次调用 sumRange 方法。
 *
 *
 */

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size() == 0) return;
        for(int i = 0;i<nums.size();i++)
        {
            sum[i] = 0;
        }
        sum[0] = nums[0];
        for(int i = 1;i<nums.size();i++) sum[i] = sum[i-1]+nums[i];
    }

    int sumRange(int i, int j) {
        if(i == 0) return sum[j];
        return sum[j]-sum[i-1];
    }
private:
    int sum[10000];
};
