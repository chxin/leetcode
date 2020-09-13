/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (29.59%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 84.2K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */
// #include <string>
// #include <vector>
// using namespace std;
// // @lc code=start
// class Solution {
// public:
//     vector<int> findSubstring(string s, vector<string>& words) {
//         // cases: s null, short
        
//         // substring
//         string substr;
//         auto size = words.size();
//         auto leng = words.at(0).size();
//         // find substring

//         // pos, len
//         vector<vector<int>> pos;
//         vector<int> pos_tmp;
//         int flag = 0;
//         for (auto it = words.begin(); it < words.end(); ++it) {
//             for(auto it2 = s.begin(); it2 <= s.end() - leng; ++it2) {
//                 if(*it2 == (*it).at(0)) {
//                     flag = 1;
//                     for (int i = 0; i < (*it).size(); ++i)
//                     {
//                         if(*(it2 + i) != (*it).at(i)){
//                             flag = 0;
//                         }
//                     }
//                 }
//                 if(flag == 1) {
//                     pos_tmp.push_back(it2 - s.begin());
//                 }
//             }
//             pos.push_back(pos_tmp);
//             pos_tmp.clear();
//         }
        
//         // pos + len
//         // 递归
//         vector<int> result;
//         vector<int> can;
//         for(auto it1 = pos.begin(), int i = 0; it1 < pos.end(); ++it1, ++i){
//             for(int tmp = 0; tmp < size; ++tmp) {
//                 if(tmp != i) can.push_back(tmp);
//             }
//             for(auot it = (*it1).begin(); it < (*it1).end(); ++it){
//                 func(leng, *it, can, pos, result);
//             }
//         }
//     }

//     void func(int size, int value, vector<int> can, vector<vector<int>> & pos, vector<int> & result) {
//         if(can.empty()) {
//             result.push_back(value - 4 * 3;
//             return;
//         }
//         for(auto it = can.begin(); it < can.end(); ++it) {
//             int index = *it;
//             auto pos_v = pos.at(index);
//             for(auto f = pos_v.begin(); f < pos_v.end(); ++f) {
//                 if(*f == value){
//                     func(size, value + size, can.erase(it), pos);
//                 }
//             }
//         }
//     }
// };

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty() || s.empty() || s.length() < words.size()*words[0].length()) return res;	// 一定不行的情况

        int lenOfWord = words[0].length();    // 记录单词的长度
        unordered_map<string,int> dict; // 存最初的单词以及出现次数

        for(int i = 0;i < words.size();i++) {   // 初始化最初的dict
            if(dict.find(words[i]) == dict.end()) {
                dict.insert(make_pair(words[i],1));
            } else {
                dict[words[i]]++;
            }
        }
        // 以单词位单位进行遍历
        // strBeg: 每个单词串的开头
        for(int strBeg = 0;strBeg < lenOfWord;strBeg++) {   // 每一个单词串开头
            unordered_map<string,int> tempDict;
            int left = strBeg, len = 0;
            for(int cur = strBeg;cur <= s.length()-lenOfWord;cur += lenOfWord) {
                string substr = s.substr(cur,lenOfWord);
                if(dict.count(substr) == 0) {   // 非法单词
                    tempDict.clear();
                    len = 0;
                    left = cur + lenOfWord;
                } else {
                    if(tempDict[substr] < dict[substr]) { // 没有重复
                        tempDict[substr]++;
                        len++;
                    } else { // 有重复
                        string temp;
                        while((temp = s.substr(left,lenOfWord)) != substr) {
                            tempDict[temp]--;
                            left += lenOfWord;
                            len--;
                        }
                        left += lenOfWord;
                    }
                    if(len == words.size()) {	// 此时滑窗内为所要求串
                        res.push_back(left);
                        tempDict[s.substr(left,lenOfWord)]--;
                        len--;
                        left += lenOfWord;
                    }
                }
            }
        }
        return res;
    }
};

// @lc code=end
