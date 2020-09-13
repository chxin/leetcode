using namespace std;
#include <string>
#include <map>

class Solution {
public:
    int romanToInt(string s) {
         map<char, int> roman_map = {
              {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
         };

         int result;
         for(auto it = s.begin(); it < s.end(); ++it) {
              result += roman_map[*(it)];
              if(roman_map[*(it+1)] > roman_map[*(it)]){
                   result -= roman_map[*(it)] * 2;
              }

         }
         return result;
    }
};
