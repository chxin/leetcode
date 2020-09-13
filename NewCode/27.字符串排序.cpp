#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> Permutation(string str) {
        // 循环每个，遍历剩余
        string result;
        vector<string> result_v;
        vector<bool> flags(str.size(), 1);
        add_one_recursely(str, flags, result, result_v);
        return result_v;
    }
    void add_one_recursely(string & str, vector<bool> flags, string result, vector<string> & result_v) {
        if(result.size() == str.size()) {
            result_v.push_back(result);
            return ;
        }
        for(int i = 0; i < flags.size(); ++i) {
            if(flags[i] != 0) {
                vector<bool> tmp = flags;
                string tmp_s = result;
                tmp[i] = 0;
                add_one_recursely(str, tmp, tmp_s + str[i], result_v);
            }
        }
    }
};

int main() {
    string str("abd");
    Solution s;
    vector<string> result;
    result = s.Permutation(str);
    for(auto s : result){
        cout << s << endl;
    }
    return 0;
}
