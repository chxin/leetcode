/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (24.89%)
 * Likes:    1672
 * Dislikes: 0
 * Total Accepted:    138.9K
 * Total Submissions: 556.4K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3)
            return result;
        for(int i = 0; i < nums.size() - 2; ++i) {
            for(int m = i + 1; m < nums.size() - 1; ++m) {
                for(int n = m + 1; n < nums.size(); ++n) {
                    if(nums.at(i)+nums.at(m)+nums.at(n)==0) {
                        vector<int> tmp = {nums.at(i),nums.at(m),nums.at(n)};
                        sort(tmp.begin(), tmp.end());
                        result.push_back(tmp);
                        break;
                    }
                }
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
// @lc code=end

