#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        // num 变为 str
        vector<long> v;
        string im = to_string(INT_MAX);
        int len = im.size() - 1;
        for(int i = 0; i < numbers.size(); ++i) {
            string s = to_string(numbers[i]);
            // for(int j = 0; j < len - s.size(); ++j) {
            while(len - s.size() > 0) {
                s.push_back(s.back());
            }
            v.push_back(stoll(s));
            cout << v.back() << " ";
        }
        cout << endl;
        // 高位到低位，比较找最小
        string result;
        for(int i = 0; i < numbers.size(); ++i) {
            int min = INT_MAX;
            int pos = 0;
            for(int j = 0; j < numbers.size(); ++j) {
                if(v[j] < min) {
                    min = v[j];
                    pos = j;
                }
            }
            result = result + to_string(numbers[pos]);
            v[pos] = INT_MAX;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> numbers({3,5,1,4,2});
    string result = s.PrintMinNumber(numbers);
    cout << result << endl;
    return 0;
}
