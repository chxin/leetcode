/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (53.30%)
 * Total Accepted:    52.2K
 * Total Submissions: 87.9K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int> & nums) {
        // QuickSort(nums);
        MergingSort(nums);
        // print(nums);
        return nums;
    }

    void print(vector<int> & nums) {
        for(auto num : nums) {
            cout << num << " ";
        }
    }

    // Merging Sort
    void MergingSort(vector<int> & nums) {
        MergingSortRecursion(nums, 0, nums.size() - 1);
    }

    void MergingSortRecursion(vector<int> & nums, int start, int end) {
        if(end - start == 1) {
            if(nums.at(start) > nums.at(end)) {
                swap_value(nums.at(start), nums.at(end));
            }
            return;
        }
        if(end - start == 0) {
            return;
        }

        int mid = (start + end) / 2;

        MergingSortRecursion(nums, start, mid);
        MergingSortRecursion(nums, mid + 1, end);

        // 100, 101, 102; 1, 2, 203;
        // 1, 101, 102; 100, 2 ,203;
        // 1, 100, 102; 101, 2, 203;
        // 1, 100, 101; 102, 202, 203;

        // 1, 101, 102; 2, 103, 4;
        // 1, 101, 102; 2, 103, 4;
        // 1, 2, 102; 101, 103, 4;
        // 1, 2, 101; 102, 103, 4;
        // 1, 2, 101;

        vector<int> tmp;
        int posl = start;
        int posr = mid + 1;
        while(posl <= mid && posr <= end) {
            if(nums.at(posl) < nums.at(posr)) {
                tmp.push_back(nums.at(posl));
                ++posl;
            } else {
                tmp.push_back(nums.at(posr));
                ++posr;
            }
        }

        while(posl <= mid) {
            tmp.push_back(nums.at(posl++));
        }

        while(posr <= mid) {
            tmp.push_back(nums.at(posr++));
        }

        for(auto i : tmp) {
            nums.at(start++) = i;
        }
    }

    // Quick Sort
    void QuickSort(vector<int> & nums) {

        QuickSortRecursion(nums, 0, nums.size() - 1);
    }

    // void QuickSortRecursion(vector<int> & nums, vector<int>::size_type start, vector<int>::size_type end) {
    void QuickSortRecursion(vector<int> & nums, int start, int end) {
        // 5 1 1 2 0 0; 0 5; 2;
        // "1";
        // 0 0 1 2 5 1; 0 1; 0; 2 5; 3
        // "0";

        // "2";
        // less, swap;
        // 0 0 1 1 2 5;

        // stop condition
        if(end - start < 1) {
            return;
        }

        auto flag_pos = (start + end) / 2;
        auto flag_value = nums.at(flag_pos);
        swap(nums.at(flag_pos), nums.at(end));

        auto separator_pos = start;

        for(vector<int>::size_type i = start; i <= end; ++i) {
            if(nums.at(i) <= flag_value){
                swap_value(nums.at(i), nums.at(separator_pos));
                ++separator_pos;
            }
        }

        if(separator_pos > start) {
            QuickSortRecursion(nums, start, separator_pos - 2);
        }
        if(separator_pos < end) {
            QuickSortRecursion(nums, separator_pos, end);
        }
        return;
    }

    void swap_value(int & v1, int & v2) {
        int tmp = v1;
        v1 = v2;
        v2 = tmp;
    }
};

// int main(void) {
//     Solution ins;
//     vector<int> nums = {-1,2,-8,-10};
//     ins.sortArray(nums);
//     return 0;
// }
