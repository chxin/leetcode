#include <iostream>

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        // 判断丑数
        int count = 0;
        for(int i = 1; i < INT_MAX; ++i) {
            bool flag = 0;
            judge_ugly(i, flag);
            if(flag == 1) ++count;
            if(count == index) return i;
        }
        return 0;
    }
    void judge_ugly(int n, bool & flag) {
        if(flag == 1) return;
        if(n == 1) {flag = 1; return;}
        if(n % 2 == 0) judge_ugly(n/2, flag);
        if(n % 3 == 0) judge_ugly(n/3, flag);
        if(n % 5 == 0) judge_ugly(n/5, flag);
    }
};

int main() {
    Solution s;
    int index = 8;
    std::cout << s.GetUglyNumber_Solution(index);
    return 0;
}
