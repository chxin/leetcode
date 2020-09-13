/*
 * @lc app=leetcode.cn id=12 lang=cpp
 *
 * [12] 整数转罗马数字
 *
 * https://leetcode-cn.com/problems/integer-to-roman/description/
 *
 * algorithms
 * Medium (62.11%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    58.5K
 * Total Submissions: 94.1K
 * Testcase Example:  '3'
 *
 * 罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个整数，将其转为罗马数字。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: 3
 * 输出: "III"
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "IV"
 * 
 * 示例 3:
 * 
 * 输入: 9
 * 输出: "IX"
 * 
 * 示例 4:
 * 
 * 输入: 58
 * 输出: "LVIII"
 * 解释: L = 50, V = 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: 1994
 * 输出: "MCMXCIV"
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */
#include <string>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
    string intToRoman(int num) {
        // 得到各位的数值
        // 转换罗马
        // 对4和9的处理
        int value[7] = {0};
        // int value_base[7] = {1,5,10,50,100,500,1000};
        int value_base[7] = {1000,500,100,50,10,5,1};
        int value_index = 0;
        while(num) {
            value[value_index] = num /value_base[value_index];
            num = num - value[value_index] * value_base[value_index];
            ++value_index;
        }
        //vector<string> result ("I","II","III","IV","V","IX","X","XX");
        // vector<char> roman_base  = {'I','V','X','L','C','D','M'};
        vector<char> roman_base  = {'M','D','C','L','X','V','I'};
        string result;
        for(int i = 0; i < 7; ++i) {
            if(value[i] == 4){
                if(value[i-1] == 1){
                    result.erase(result.end()-1);
                    result.push_back(roman_base.at(i));
                    result.push_back(roman_base.at(i-2));
                } else {
                    result.push_back(roman_base.at(i));
                    result.push_back(roman_base.at(i-1));
                }
            } else {
                for(int m = value[i]; m > 0; --m) {
                    result.push_back(roman_base.at(i));
                }
            }
            
        }
        return result;
    }
};
// @lc code=end

