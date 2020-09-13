#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool match(char* str, char* pattern) {
        if(*str == '\0' ^ *pattern == '\0') {
            if((*(str+1) == '*' && *(str+2) == '\0') || (*(pattern+1) == '*' && *(pattern+2) == '\0'))
                return 1;
            return 0;
        }
        if(*str == '\0' && *pattern == '\0') {
            return 1;
        }

        if(*(pattern+1) == '*') { //如果是**，怎么处理
            if(*pattern == '.' || *pattern == *str)
                return match(str, pattern+2) || match(str+1, pattern+2) || match(str+1, pattern);
            return match(str, pattern+2);
        } else {
            if(*pattern == '.') {
                return match(str+1, pattern+1);
            } else if(*pattern == '*') { // 如果是***
                return match(str, pattern+1);
                // return match(str, pattern+1) || match(str+1, pattern+1) || match(str+1, pattern);
            } else if(*str == *pattern) {
                return match(str+1, pattern+1);
            } else {
                return 0;
            }
        }
    }
};

int main() {
    char str[] = "aaa";
    char pattern[] = "ab*ac*a";
    Solution s;
    cout << s.match(str, pattern);
    return 0;
}
