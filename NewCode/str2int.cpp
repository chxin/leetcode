#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int len = str.size();
        if(len == 0) return 0;
        int pos = 0;
        while(pos < len && str[pos] == ' ') ++pos;
        if(pos == len) return 0;
        bool negate = 0;
        if(str[pos] == '+') {
            negate = 0;
            pos++;
        } else if(str[pos] == '-') {
            negate = 1;
            pos++;
        }
        if(pos == len) return 0;
        int result = 0;
        for(int i = pos; i< len; ++i) {
            if(str[i] >= '0' && str[i] <= '9') {
                if(result >= INT_MAX / 20) {result = INT_MAX / 2; break;}
                result = result * 10 + str[i] - '0';
            } else {
                return 0;
            }
        }
        return negate ? 0-result : result;
    }
};

int main()
{
    Solution ins;
    std::cout << ins.StrToInt("+123")<< std::endl;
    return 0;
}

