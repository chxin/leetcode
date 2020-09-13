/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (50.18%)
 * Total Accepted:    41K
 * Total Submissions: 81.3K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 *
 * 请找出其中最小的元素。
 *
 * 你可以假设数组中不存在重复元素。
 *
 * 示例 1:
 *
 * 输入: [3,4,5,1,2]
 * 输出: 1
 *
 * 示例 2:
 *
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 *
 */
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int findMin(const vector<int> & nums) {
        if(nums.size() < 2) return nums.front();
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        while(left < right) {
            if(nums.at(mid) > nums.at(right)) {
                left = mid + 1;
            } else {
                right = mid;
            }
            mid = (left + right) / 2;
        }

        return nums.at(mid);
    }
};

// int main(void) {
//     Solution ins;
//     cout << ins.findMin({3, 4, 5, 1, 2});
//     return 0;
// }
