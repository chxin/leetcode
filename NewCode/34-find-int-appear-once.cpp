#include <iostream>
#include <map>
#include <queue>
using namespace std;
class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> char_map;
        queue<char> char_queue;
        for(int i = 0; i < str.size(); ++i) {
            char c = str[i];
            char_map[c]++;
            if(char_map[c] == 1) {
                char_queue.push(c);
            } else {
                if(c == char_queue.front()) {
                    char tmp = char_queue.front();
                    while(!char_queue.empty() && char_map[tmp] > 1) {
                        char_queue.pop();
                        tmp = char_queue.front();
                    }
                }
            }
        }
        if(char_queue.empty()) return -1;
        for(int i = 0; i < str.size(); ++i) {
            if(str[i] == char_queue.front())
                return i;
        }
    }
};

int main()
{
    /* string input{"NXWtnzyoHoBhUJaPauJaAitLWNMlkKwDYbbigdMMaYfkVPhGZcrEwp"}; */
    string input{"google"};
    Solution ins;
    std::cout << ins.FirstNotRepeatingChar(input) << std::endl;
    return 0;
}

