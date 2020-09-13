/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (60.97%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    57K
 * Total Submissions: 93.2K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */
#include<vector>
#include<string>
#include<iostream>

using namespace std;
// @lc code=start
// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         if(strs.empty()) return {{}};
//         vector<vector<string>> result({{strs.at(0)}});

//         int flag = 0;
//         for(auto it = strs.begin() + 1; it < strs.end(); ++it) {
//             flag = 0;
//             for(auto it1 = result.begin(); it1 < result.end(); ++it1) {
//                 if(similar((*it1).at(0), *it)) {
//                     (*it1).push_back(*it);
//                     flag = 1;
//                 }
//             }
//             if(flag == 0) {
//                 result.push_back({*it});
//             }
//         }
//         return result;
//     }

//     bool similar(string a, string b) {
//         if(a.size() != b.size()) return 0;
//         for(auto it = a.begin(); it < a.end(); ++it) {
//             auto pos = b.find(*it);
//             if(pos != string::npos) {
//                 b.erase(pos, 1);
//             } else {
//                 return 0;
//             }
//         }
//         return 1;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        for (string str : strs) {
            vector<int> cnt(26, 0);
            string t = "";
            for (char c : str) ++cnt[c - 'a'];
            for (int d : cnt) t += to_string(d) + "/";
            m[t].push_back(str);
        }
        for (auto a : m) {
            res.push_back(a.second);
        }
        return res;
    }
};

// int main(void)
// {
//     Solution ins;
//     vector<string> a({"eat","tea","tan","ate","nat","bat"});
//     vector<vector<string>> result = ins.groupAnagrams(a);
//     for(auto &i1 : result) {
//         for(auto &i2 : i1) {
//             cout << i2 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

// @lc code=end

