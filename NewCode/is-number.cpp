#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

class Solution {
public:
    bool isNumeric(char* string)
    {
        char * tmp = string;
        if(*tmp == '+' || *tmp == '-') {
            ++tmp;
        }
        while(*tmp != '\0') {
            if(*tmp >= '0' && *tmp <= '9') {
                ++tmp;
            } else if(*tmp == 'E' || *tmp == 'e') {
                if(tmp == string) return 0;
                return check_signed_without_e(tmp + 1);
            } else if(*tmp == '.') {
                return check_unsigned_with_e(tmp + 1);
            } else {
                return 0;
            }
        }
        return 1;
    }

    bool check_signed_without_e(char * string) {
        char * tmp = string;
        if(*tmp == '+' || *tmp == '-') tmp++;
        if(*tmp == '\0') return 0;
        while(*tmp != '\0') {
            if(*tmp >= '0' && *tmp <= '9') {
                ++tmp;
            } else {
                return 0;
            }
        }
        return 1;
    }

    bool check_unsigned_with_e(char * string) {
        char * tmp = string;
        while(*tmp != '\0') {
            if(*tmp >= '0' && *tmp <= '9') {
                ++tmp;
            } else if(*tmp == 'e' || *tmp == 'E') {
                ++tmp;
                return check_signed_without_e(tmp);
            } else {
                return 0;
            }
        }
        return 1;
    }


};
