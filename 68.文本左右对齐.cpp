/*
 * @lc app=leetcode.cn id=68 lang=cpp
 *
 * [68] 文本左右对齐
 *
 * https://leetcode-cn.com/problems/text-justification/description/
 *
 * algorithms
 * Hard (42.51%)
 * Likes:    55
 * Dislikes: 0
 * Total Accepted:    6.9K
 * Total Submissions: 16.1K
 * Testcase Example:  '["This", "is", "an", "example", "of", "text", "justification."]\n16'
 *
 * 给定一个单词数组和一个长度 maxWidth，重新排版单词，使其成为每行恰好有 maxWidth 个字符，且左右两端对齐的文本。
 * 
 * 你应该使用“贪心算法”来放置给定的单词；也就是说，尽可能多地往每行中放置单词。必要时可用空格 ' ' 填充，使得每行恰好有 maxWidth 个字符。
 * 
 * 要求尽可能均匀分配单词间的空格数量。如果某一行单词间的空格不能均匀分配，则左侧放置的空格数要多于右侧的空格数。
 * 
 * 文本的最后一行应为左对齐，且单词之间不插入额外的空格。
 * 
 * 说明:
 * 
 * 
 * 单词是指由非空格字符组成的字符序列。
 * 每个单词的长度大于 0，小于等于 maxWidth。
 * 输入单词数组 words 至少包含一个单词。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * words = ["This", "is", "an", "example", "of", "text", "justification."]
 * maxWidth = 16
 * 输出:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * words = ["What","must","be","acknowledgment","shall","be"]
 * maxWidth = 16
 * 输出:
 * [
 * "What   must   be",
 * "acknowledgment  ",
 * "shall be        "
 * ]
 * 解释: 注意最后一行的格式应为 "shall be    " 而不是 "shall     be",
 * 因为最后一行应为左对齐，而不是左右两端对齐。       
 * ⁠    第二行同样为左对齐，这是因为这行只包含一个单词。
 * 
 * 
 * 示例 3:
 * 
 * 输入:
 * words =
 * ["Science","is","what","we","understand","well","enough","to","explain",
 * "to","a","computer.","Art","is","everything","else","we","do"]
 * maxWidth = 20
 * 输出:
 * [
 * "Science  is  what we",
 * ⁠ "understand      well",
 * "enough to explain to",
 * "a  computer.  Art is",
 * "everything  else  we",
 * "do                  "
 * ]
 * 
 * 
 */
#include<vector>
#include<string>
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int pos = 0;
        int count = 0;
        int index = 0;
        int space_num;
        int left = maxWidth;
        int flag = 0;
        vector<string> result({""});
        vector<string> word_tmp;
        // vector<int> space_tmp;
        // vector<string> space(" ", "  ", "   ", "    ", "     ",)
        for(auto w : words) {
            if(pos + w.size() < maxWidth) {
                pos += w.size() + 1;
                word_tmp.push_back(w);
                count++;
                left = left - w.size();
            } else {
                for(int i = 0, ctmp = count; i < count; ++i) {
                    // result.at(index).push_back(' ');
                    // result.at(index).clear();
                    result.at(index) += word_tmp.at(i);
                    if(ctmp <= 1){
                        space_num = left;
                    } else {
                        // if(ctmp == 2) {
                        //     space_num = left;
                        // }
                        space_num = (left + ctmp - 2) / (ctmp - 1);
                    }
                    
                    left -= space_num;
                    for(int m = 0; m < space_num; ++m){
                        result.at(index).push_back(' ');
                    }
                    ctmp--;
                }
                // if(count != 1) {
                    // result.at(index) += word_tmp.at(word_tmp.size() - 1);
                // }

                ++index;
                result.push_back("");
                // result.at(index).push_back(' ');
                // result.at(index).clear();
                
                
                word_tmp.clear();
                word_tmp.push_back(w);

                count = 1;
                pos = w.size();
                left = maxWidth - w.size();
            }
        }
        for(int i = 0, ctmp = count; i < count; ++i) {
            // result.at(index).push_back(' ');
            // result.at(index).clear();
            result.at(index) += word_tmp.at(i);
            if(ctmp <= 1){
                space_num = left;
            } else {
                space_num = 1;
                // space_num = (left + ctmp - 2) / (ctmp - 1);
            }

            
            left -= space_num;
            for(int m = 0; m < space_num; ++m){
                result.at(index).push_back(' ');
            }
            ctmp--;
        }

        return result;
    }
};

int main(void) {
    Solution ins;
    vector<string> a({"This", "is", "an", "example", "of", "text", "justification."});
    int w(16);
    auto r = ins.fullJustify(a, w);
    for(auto rc: r) {
        cout << rc << endl;
    }
}

// @lc code=end

