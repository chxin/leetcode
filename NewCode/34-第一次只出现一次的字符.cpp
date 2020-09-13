#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> m;
        int pos = 0;
        for(int i = 0; i < str.size(); ++i) {
            m[str[i]]++;
            if(m[str[pos]] > 1) {
                while(m[str[pos]] > 1 && pos <= i) {
                    pos++;
                    // if(pos >= str.size() - 1)
                    //     break;
                }
            }
        }
        if(pos == str.size()) return -1;
        return pos;
    }

};

int main() {

    return 0;
}
