/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (41.79%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    47.6K
 * Total Submissions: 113.8K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */
#include <string>
using namespace std;
// @lc code=start

class Solution {
public:
    string multiply(string num1, string num2) {
        int l1=num1.size(),l2=num2.size();
        string res(l1+l2,'0');
        if(l1==0||l2==0)
            return "";
        for(int i=l1-1;i>=0;i--){
            int add=0;
            for(int j=l2-1;j>=0;j--){
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=res[i+j+1]+add+mul%10-'0';
                res[i+j+1]='0'+sum%10;
                add=mul/10+sum/10;
            }
            res[i]+=add;
        }
        for(int i=0;i<l1+l2;i++)
            if(res[i]!='0')
                return res.substr(i);
        return "0";
    }
};


// class Solution {
// public:
//     string multiply(string num1, string num2) {
//         string result;
//         if(num1 == "0" || num2 == "0") {
            
//             result.push_back('0');
//             return result;
//         }
//         func(num1, num2, result);
//         return result;
//     }

//     void func(string & v1, string & v2, string & v) {
//         auto n1 = v1.size();
//         auto n2 = v2.size();
//         int mid2 = n2 / 2 + 1;
//         int mid1 = n1 / 2 + 1;
//         string left;
//         string right;
        
//         if(n1 < 5 && n2 < 5){
//             long result = str_to_int(v1) * str_to_int(v2);
//             // cout << str_to_int(v1) << ";" << str_to_int(v2);
//             int_to_str(result, v);
//         } else if(n1 < 5) { // n2 > 5, split
//             string v2_left1(v2.begin(), v2.begin() + mid2);
//             string v2_right1(v2.begin() + mid2, v2.end());
            
//             func(v1, v2_left1, left);
//             func(v1, v2_right1, right);
//             v = left + right;
//             // what is the carrier ??
//         } else if(n2 < 5) { // n1 > 5, split
//             string v1_left(v1.begin(), v1.begin() + mid1);
//             string v1_right(v1.begin() + mid1, v1.end());
            
//             func(v2, v1_left, left);
//             func(v2, v1_right, right);
//             v = left + right;
//         } else {
//             string v1_left2(v1.begin(), v1.begin() + mid1);
//             string v1_right2(v1.begin() + mid1, v1.end());
            
//             string v2_left2(v2.begin(), v2.begin() + mid2);
//             string v2_right2(v2.begin() + mid2, v2.end());
            
//             string ll;
//             string lr;
//             string rl;
//             string rr;
//             func(v1_left2, v2_left2, ll);
//             func(v1_left2, v2_right2, lr);
//             func(v1_right2, v2_left2, rl);
//             func(v1_right2, v2_right2, rr);
            
//             int sum_int = str_to_int(lr) + str_to_int(rl);
//             string sum_str;
//             int_to_str(sum_int, sum_str);

//             v = rr + sum_str + ll;
//         }
//     }

//     int str_to_int(string & s) {
//         int n1 = s.size();
//         int v1_int = 0;
//         long v1_base = 1;
//         for(int i = 0; i < n1; ++i) {
//             v1_int += (s.at(n1 - i - 1) - '0') * v1_base;
//             v1_base *= 10;
//         }
//         return v1_int;
//     }
//     void int_to_str(long n, string & s) {
//         // string s;
//         if(n == 0) {
//             s.push_back(n + '0');
//             return;
//         }
//         long tmp = 0;
//         long long base = 1;
//         while(base <= n) base *= 10;
//         base /= 10;
//         int flag = 0;
//         while(base != 0) {
//             tmp = (n / base) % 10;
//             base /= 10;
//             if(tmp != 0 || flag == 1) {
//                 s.push_back(tmp + '0');
//                 flag = 1;
//             }
//         }
//         // return & s;
//     }
// };

//     a b
//     c d

//     ad bd
//  ac bc 

//  ac ad+bc bd
// @lc code=end

