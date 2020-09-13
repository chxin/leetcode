/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (51.82%)
 * Likes:    533
 * Dislikes: 0
 * Total Accepted:    67.6K
 * Total Submissions: 130.2K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */
#include<string>
#include<vector>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {

        vector<string> m = {
            "",
            "", "abc","def",
            "ghi","jkl","mno",
            "pqrs","tuv","wxyz"
        };

        vector<string> res;
        if (digits.size() == 0) return res;
        string s;

        DFS(digits, 0, s, res,m);
        return res;
    }

    void DFS(string digits, int pos, string & s, vector<string> &res, vector<string>& m){
        if (pos == digits.size()){
            res.push_back(s);
            return ;
        }
        //获取对应键盘的字母
        string tmp = m[digits[pos] - '0'];
        for (int i = 0; i < tmp.size(); i++){
            s.push_back(tmp[i]);
            DFS(digits, pos+1, s, res, m);
            s.pop_back();
        }
        return ;
    }
};

// @lc code=end

