/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (46.15%)
 * Total Accepted:    31.5K
 * Total Submissions: 68.2K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 *
 * 示例:
 *
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 *
 */

#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // recursion
        // condition: length, number > 255,
        string tmp(s.size() + 3, '0');
        vector<string> result;
        recursion(s, s.size(), 0, 0, 0, tmp, 0, result);
        return result;
    }

    void recursion(string & str, int size, int pos, int num, int count, string & ip, int ip_pos, vector<string> & result) {
        if(pos >= size) {
            if(count == 3){
                if(find(result.begin(), result.end(), ip) == result.end()) {
                    result.push_back(ip);
                }
            }
            return;
            // point_index.push_back(point);
        }
        if(count > 3) {
            return;
        }
        if(pos < size - 1 && (num == 0 && str.at(pos) == '0')) { // process 0: point follows 0
            ip.at(ip_pos) = str.at(pos);
            ip.at(ip_pos + 1) = '.';
            recursion(str, size, pos + 1, 0, count + 1, ip, ip_pos + 2, result);
            return;
        }
        if(str.at(pos) - '0' + num * 10 > 255) {
            ip.at(ip_pos) = '.';
            recursion(str, size, pos, 0, count + 1, ip, ip_pos + 1, result);
            return;
        }
        num = str.at(pos) - '0' + num * 10;
        ip.at(ip_pos) = str.at(pos);
        recursion(str, size, pos + 1, num, count, ip, ip_pos + 1, result);
        if(pos < size - 1) {
            // if(count == 0 && num == 0){
            //     return;
            // } else {
                ip.at(ip_pos) = str.at(pos);
                ip.at(ip_pos + 1) = '.';
                recursion(str, size, pos + 1, 0, count + 1, ip, ip_pos + 2, result);
            // }
        }
    }
};

// int main(void) {
//     Solution ins;
//     string s("0000");
//     auto result = ins.restoreIpAddresses(s);
//     for(auto w : result) {
//         cout << w << endl;
//     }

//     return 0;
// }
