/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (35.59%)
 * Total Accepted:    29.5K
 * Total Submissions: 82.9K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 *
 * 示例：
 *
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 *
 * 说明：
 *
 *
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 *
 *
 */
#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        // find pos of each: [0, 11] [4, 10] [6, 13]
        // cal range according to index: max - min
        string::size_type slength = s.size();
        string::size_type tlength = t.size();
        vector<int> empty;
        vector<vector<int> > pos(tlength, empty);
        for(string::size_type m = 0; m < tlength; ++m) {
            for(string::size_type i = 0;i < slength; ++i) {
                if(s.at(i) == t.at(m))
                    pos[m].push_back(i);
            }
        }
        vector<int> size_vector;
        for(auto v : pos) {
            size_vector.push_back(v.size());
        }
        vector<int> index_vector(tlength, 0);
        map<int, vector<int> > range;
        func(0, tlength, pos, size_vector, index_vector, range);
        // what if duplicated in t;
        // the same index stop recursion
        string result;
        auto it = range.begin();
        // auto tmp = (*(--it)).second;
        auto tmp = (*(it)).second;
        result = s.substr(tmp.at(0), tmp.at(1));
        return result;

    }
    void func(int m, int len, vector<vector<int> > & pos, vector<int> & size_vector, vector<int> & index_vector, map<int, vector<int> > & range) {
        // recursion
        while(size_vector.at(m) != 0) {
            --size_vector.at(m);
            int tmp = pos.at(m).at(size_vector.at(m));
            if(find(index_vector.begin(), index_vector.end(), tmp) != index_vector.end())
                return;
            else
                index_vector.at(m) = pos.at(m).at(size_vector.at(m));
            if(m + 1 == len)
                cal_range(index_vector, range);
            else
                func(m + 1, len, pos, size_vector, index_vector, range);
        }
    }
    void cal_range(vector<int> & index_vector, map<int, vector<int> > & range) {
        // recursion
        int max = index_vector.at(0);
        int min = index_vector.at(0);
        for(auto it = index_vector.begin(); it != index_vector.end(); ++it) {
            if(*it > max) max = *it;
            if(*it < min) min = *it;
        }
        range[max - min].push_back(min);
        range[max - min].push_back(max);
    }
};

// int main(void) {
//     Solution ins;
//     string s("ADOBECODEBANC");
//     string t("ABC");
//     cout << ins.minWindow(s, t) << endl;
//     cout << "hello";

//     return 0;
// }
