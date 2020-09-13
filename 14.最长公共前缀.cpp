/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (35.64%)
 * Likes:    822
 * Dislikes: 0
 * Total Accepted:    168.5K
 * Total Submissions: 471.8K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string common_prefix = strs.at(0); // note: .at(), must make sure not empty
        int flag = 0;
        int i = 0;
        for(auto it = strs.begin() + 1; it < strs.end() && common_prefix.size() != 0; ++it) {
            if((*it).size() == 0) {
                common_prefix = "";
                return common_prefix;
            }

            for(i = 0; i < (*it).size() && i < common_prefix.size(); i++) {
                if((*it).at(i) != common_prefix.at(i)) {
                    common_prefix.erase(i, common_prefix.size() - i); // note: pay attentio the usage of string.erase()
                    flag = 1;
                    break;
                }
            }

            if(flag == 0){ // note: most foolish error: if(flag = 0)
                common_prefix.erase(i, common_prefix.size() - i);
            }

            flag = 0;
            }
        return common_prefix;
    }
};
// @lc code=end

